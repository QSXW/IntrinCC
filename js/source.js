const fs = require('fs');
const readLine = require('readline');

class CSource {

    constructor(path) {
        this.definePattern = RegExp(/#define\s+([\w]+)(?:\([\w,\s]+\)){0,}[\s\\]+([\w]+)(?:\([\(\)\w,\s]+\)){0,}/g);
        this.externPattern = RegExp(/extern\s+([\s\w]+)\s{0,}(__cdecl){0,}\s{0,}(_mm\w+_[\w]+)\s?\([\w\s\,*]+\);/g);
        this.wrapPattern = RegExp(/__MACHINE[\w]{0,}\(([\w\s*]+\s)(_[\w]+)\s{0,}\([\w\s,*]+\)\)/g);

        this.mmTypeReg = RegExp(/__m[128|256|512]\w+/);
        this.funcNameReg = RegExp(/_m(m|m\d+)_\w+/);
        this.path = path;
        this.content = []
        this.vtbl = {};
    }

    hasEntry(entry) {
        return this.vtbl[entry] != undefined;
    }

    load(path) {
        this.path = path;

        let text = fs.readFileSync(path, {encoding: 'utf-8'});
        this.content.push(text);
        
        let match;
        while ((match = this.externPattern.exec(text)) != null) {
            this.vtbl[match[3]] = {
                'RetType': match[1],
                'CC': match[2]
            };
        }

        while ((match = this.definePattern.exec(text)) != null) {
            this.vtbl[match[1]] = this.vtbl[match[2]];
        }

        while ((match = this.wrapPattern.exec(text)) != null) {
            this.vtbl[match[2]] = {
                'RetType': match[1],
            };
        }
    }

}

module.exports = CSource;
