const fs = require('fs');
const CSource = require('./source.js');

let license = 
`/**
 * Copyright (C) 2021-${new Date().getFullYear()}, by Wu Jianhua (toqsxw@outlook.com)
 *
 * This library is distributed under the Apache-2.0 license.
 */
`

if (process.argv[2] == undefined) {
    console.log('ERROR: please input the Intrinsics header files directory');
    return;
}

let path = process.argv[2];
let source = new CSource();

let sources = ['intrin.h', 'xmmintrin.h', 'zmmintrin.h', 'immintrin.h'];
for (s in sources) {
    source.load(`${path}/${sources[s]}`);
}
function levelDown(mmType) {
    let chain = {     
         '__m512' :  '__m256',
         '__m256' :  '__m128',
         '__m128' :  '__m128',
        '__m512i' : '__m256i',
        '__m256i' : '__m128i',
        '__m128i' : '__m128i',
        '__m512d' : '__m256d',
        '__m256d' : '__m128d',
        '__m128d' : '__m128d',
    };

    return chain[mmType];
}

function hasEntry(entry) {
    return source.hasEntry(entry);
}

let BytesMap = {
    'uint8_t': 1,
    'uint16_t': 2,
    'uint32_t': 4,
    'uint64_t': 8,
    'int8_t': 1,
    'int16_t': 2,
    'int32_t': 4,
    'int64_t': 8,
    'float': 4,
    'double': 8,
    '__m128': 16,
    '__m128i': 16,
    '__m128d': 16,
    '__m256': 32,
    '__m256i': 32,
    '__m256d': 32,
    '__m512': 64,
    '__m512i': 64,
    '__m512d': 64
};

let FunctionTypeMap = {
    '__m128':  '_mm',
    '__m128i': '_mm',
    '__m128d': '_mm',
    '__m256':  '_mm256',
    '__m256i': '_mm256',
    '__m256d': '_mm256',
    '__m512':  '_mm512',
    '__m512i': '_mm512',
    '__m512d': '_mm512',
};

function getSuffix(mmType, cType) {
    let suffixes = {
        '__m128': {
            'float': 'ps',
        },

        '__m128i': {
            'int8_t': 'epi8',
            'int16_t': 'epi16',
            'int32_t': 'epi32',
            'int64_t': 'epi64',
            'uint8_t': 'epi8',
            'uint16_t': 'epi16',
            'uint32_t': 'epi32',
            'uint64_t': 'epi64',
        },

        '__m128d': {
            'double': 'pd',
        },

        '__m256': {
            'float': 'ps',
        },

        '__m256i': {
            'int8_t': 'epi8',
            'int16_t': 'epi16',
            'int32_t': 'epi32',
            'int64_t': 'epi64',
            'uint8_t': 'epi8',
            'uint16_t': 'epi16',
            'uint32_t': 'epi32',
            'uint64_t': 'epi64',
        },

        '__m256d': {
            'double': 'pd',
        },

        '__m512': {
            'float': 'ps',
        },

        '__m512i': {
            'int8_t': 'epi8',
            'int16_t': 'epi16',
            'int32_t': 'epi32',
            'int64_t': 'epi64',
            'uint8_t': 'epi8',
            'uint16_t': 'epi16',
            'uint32_t': 'epi32',
            'uint64_t': 'epi64',
        },

        '__m512d': {
            'double': 'pd',
        }
    };

    return suffixes[mmType][cType];
}

class CPPParam {
    constructor(type, name) {
        this.type = type,
        this.name = name
    }
}

class CPPFunction {
    constructor(funcName, ret = '', params=[], qualifiers=[], initializer_list=null) {
        // generate prologue
        if (ret == undefined) {
            let i = 0;
        }
        if (ret) {
            ret += ' ';
        }
        this.body = `    ${ret}${funcName}(${params.join(', ')})`;

        if (initializer_list) {
            this.body += ` ${qualifiers.join(' ')} :\n        ${initializer_list.join(',\n    ')}\n`;
        } else {
            this.body += ` ${qualifiers.join(' ')}\n`;
        }
    
        this.BB();
    }

    /**
     * @brief Add Statement
     * @param {*} line 
     */
    S(line) {
        this.body += `        ${line};\n`;
    }

    L(line) {
        this.body += `        ${line}\n`;
    }

    BB() {
        this.body += '    {\n';
    }

    EB() {
        this.body += '    }\n\n';
    }

    toString() {
        this.EB();
        return this.body;
    }
}

class CPPCLASS {

    constructor(mmType, cType, name = undefined) {
        this.mmType   = mmType;
        this.cType    = cType;
        this.suffix   = getSuffix(mmType, cType);
        this.size     = BytesMap[mmType] / BytesMap[cType];
        this.funcType = FunctionTypeMap[mmType];

        if (name == undefined) {
            this.name = `${this.cType}X${this.size}`;
        } else {
            this.name = `${name}X${this.size}`;
        }
    }

    getOperation(operation) {
        let operations = {
            'add': 'add',
            'sub': 'sub',
            'mul': 'mul',
            'div': 'div',
        };
    
        if (this.suffix == 'epi32' || this.suffix == 'epi16') {
            operations.mul = 'mullo';
        }
    
        return operations[operation];
    }

    operator(operation) {
        let tokens = {
            'add': '+',
            'sub': "-",
            'mul': '*',
            'div': '/',
        };

        let entry = `${this.funcType}_${this.getOperation(operation)}_${this.suffix}`;
        if (!hasEntry(entry)) {
            return;
        }

        let params = [
            `const ${this.name} &other`
        ];

        let f = new CPPFunction(`operator${tokens[operation]}`, `${this.name} &`, params, ['noexcept']);
        f.S(`${entry}(this->v, other.v)`);
        f.S(`return *this`);

        return f;
    }

    generate() {
        let functionList = {
            valueType: () => {
                return `    using value_type = ${this.mmType};\n\n`;
            },

            defaultConstructor: () => {      
                return new CPPFunction(`${this.name}`, '', [], ['noexcept']);
            },

            primitive: () => {
                return new CPPFunction(`${this.name}`, '', [`${this.mmType} other`], ['noexcept'], ['v{ other }']);
            },

            set1 : () => {
                let entry = `${this.funcType}_set1_${this.suffix}`;
                if (hasEntry(entry)) {
                    let list = [
                        `v{ ${entry}(value) }`,
                    ];
    
                    let params = [
                        `${this.cType} value`, 
                    ];
        
                    return new CPPFunction(this.name, '', params, ['noexcept'], list);
                }
            },

            add: () => {
                return this.operator('add');
            },

            mul: () => {
                return this.operator('mul');
            },

            sub: () => {
                return this.operator('sub');
            },

            div: () => {
                return this.operator('div');
            },

            handle: () => {
                let f = new CPPFunction(`operator ${this.mmType} &`, '', [], ['noexcept']);
                f.S('return v');
                return f;
            },

            const_handle: () => {
                // const must before noexcept
                let f = new CPPFunction(`operator const ${this.mmType} &`, '', [], ['const', 'noexcept']);
                f.S('return v');
                return f;
            },

            load: () => {       
                let f = new CPPFunction('load', 'void', [`const ${this.cType} *src`], ['noexcept']);

                let entry = `${this.funcType}_load_${this.suffix}`;
                if (hasEntry(entry)) {
                    f.S(`v = ${entry}(src)`);
                } else {
                    f.S('loadu(src)');
                }

                return f;
            },

            store: () => {
                let f = new CPPFunction('store', 'void', [`${this.cType} *dst`], ['noexcept']);

                let entry = `${this.funcType}_store_${this.suffix}`;
                if (hasEntry(entry)) {
                    f.S(`${entry}(dst, v)`);
                } else {
                    f.S('storeu(dst)');
                }

                return f;
            },

            loadu: () => {       
                let entry = `${this.funcType}_loadu_${this.suffix}`;
                if (hasEntry(entry)) {
                    let f = new CPPFunction('loadu', 'void', [`const ${this.cType} *src`], ['noexcept']);
                    f.S(`v = ${entry}(src)`);
                    return f;
                }
            },

            storeu: () => {
                let entry = `${this.funcType}_storeu_${this.suffix}`;
                if (hasEntry(entry)) {
                    let f = new CPPFunction('storeu', 'void', [`${this.cType} *dst`], ['noexcept']);
                    f.S(`${entry}(dst, v)`);
                    return f;
                }
            },

            toUint8: () => {
                if (this.suffix == 'epi16') {
                    let entry = `${this.funcType}_cvt${this.suffix}_epi8`;
                    if (hasEntry(entry)) {
                        let f = new CPPFunction('cvt2uint8', levelDown(this.mmType), [], ['const', 'noexcept']);
                        f.S(`return ${entry}(v)`);
    
                        return f;
                    }
                }
            }
        };

        let str = `class ${this.name}\n{\n`;
        str += `public:\n@`;
        str += `private:\n    ${this.mmType} v;\n`;
        str += `};\n\n`;

        let text = '';
        for (let f in functionList) {
            let cppFunc = functionList[f]();
            if (cppFunc == undefined) {
                continue;
            }
            text += functionList[f]();
        }

        return str.replace('@', text);
    }
}

class CPPFile {
    constructor(name) {
        this.name = name;
        this.body = `${license}\n`;
    }

    Include(file, property) {
        if (property == 'internal') {
            this.body += `#include "${file}"\n\n`;
        } else if(property == 'external') {
            this.body += `#include <${file}>\n\n`;
        }
    }

    addClass(c) {
        this.body += c;
    }
}

let classes = [
    new CPPCLASS( '__m128',    'float',  'FLOAT'),
    new CPPCLASS( '__m256',    'float',  'FLOAT'),
    new CPPCLASS( '__m512',    'float',  'FLOAT'),
    new CPPCLASS('__m128i',   'int8_t',   'INT8'),
    new CPPCLASS('__m128i',  'uint8_t',  'UINT8'),
    new CPPCLASS('__m128i',  'int16_t',  'INT16'),
    new CPPCLASS('__m128i', 'uint16_t', 'UINT16'),
    new CPPCLASS('__m128i',  'int32_t',  'INT32'),
    new CPPCLASS('__m128i', 'uint32_t', 'UINT32'),
    new CPPCLASS('__m256i',   'int8_t',   'INT8'),
    new CPPCLASS('__m256i',  'uint8_t',  'UINT8'),
    new CPPCLASS('__m256i',  'int16_t',  'INT16'),
    new CPPCLASS('__m256i', 'uint16_t', 'UINT16'),
    new CPPCLASS('__m256i',  'int32_t',  'INT32'),
    new CPPCLASS('__m256i', 'uint32_t', 'UINT32'),
    new CPPCLASS('__m512i',   'int8_t',   'INT8'),
    new CPPCLASS('__m512i',  'uint8_t',  'UINT8'),
    new CPPCLASS('__m512i',  'int16_t',  'INT16'),
    new CPPCLASS('__m512i', 'uint16_t', 'UINT16'),
    new CPPCLASS('__m512i',  'int32_t',  'INT32'),
    new CPPCLASS('__m512i', 'uint32_t', 'UINT32'),
];

let cpp = new CPPFile('../slimmintrin.h');
cpp.Include('immintrin.h', 'external');

for (c in classes) {
    cpp.addClass(classes[c].generate());
}

let f = fs.writeFileSync(cpp.name, cpp.body);
