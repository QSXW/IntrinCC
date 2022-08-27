/**
 * Copyright (C) 2021-2022, by Wu Jianhua (toqsxw@outlook.com)
 *
 * This library is distributed under the Apache-2.0 license.
 */

#include <immintrin.h>

class FLOATX4
{
public:
    using value_type = __m128;

    FLOATX4() noexcept
    {
    }

    FLOATX4(__m128 other) noexcept :
        v{ other }
    {
    }

    FLOATX4(float value) noexcept :
        v{ _mm_set1_ps(value) }
    {
    }

    FLOATX4 & operator+(const FLOATX4 &other) noexcept
    {
        _mm_add_ps(this->v, other.v);
        return *this;
    }

    FLOATX4 & operator*(const FLOATX4 &other) noexcept
    {
        _mm_mul_ps(this->v, other.v);
        return *this;
    }

    FLOATX4 & operator-(const FLOATX4 &other) noexcept
    {
        _mm_sub_ps(this->v, other.v);
        return *this;
    }

    FLOATX4 & operator/(const FLOATX4 &other) noexcept
    {
        _mm_div_ps(this->v, other.v);
        return *this;
    }

    operator __m128 &() noexcept
    {
        return v;
    }

    operator const __m128 &() const noexcept
    {
        return v;
    }

    void load(const float *src) noexcept
    {
        v = _mm_load_ps(src);
    }

    void store(float *dst) noexcept
    {
        _mm_store_ps(dst, v);
    }

    void loadu(const float *src) noexcept
    {
        v = _mm_loadu_ps(src);
    }

    void storeu(float *dst) noexcept
    {
        _mm_storeu_ps(dst, v);
    }

private:
    __m128 v;
};

class FLOATX8
{
public:
    using value_type = __m256;

    FLOATX8() noexcept
    {
    }

    FLOATX8(__m256 other) noexcept :
        v{ other }
    {
    }

    FLOATX8(float value) noexcept :
        v{ _mm256_set1_ps(value) }
    {
    }

    FLOATX8 & operator+(const FLOATX8 &other) noexcept
    {
        _mm256_add_ps(this->v, other.v);
        return *this;
    }

    FLOATX8 & operator*(const FLOATX8 &other) noexcept
    {
        _mm256_mul_ps(this->v, other.v);
        return *this;
    }

    FLOATX8 & operator-(const FLOATX8 &other) noexcept
    {
        _mm256_sub_ps(this->v, other.v);
        return *this;
    }

    FLOATX8 & operator/(const FLOATX8 &other) noexcept
    {
        _mm256_div_ps(this->v, other.v);
        return *this;
    }

    operator __m256 &() noexcept
    {
        return v;
    }

    operator const __m256 &() const noexcept
    {
        return v;
    }

    void load(const float *src) noexcept
    {
        v = _mm256_load_ps(src);
    }

    void store(float *dst) noexcept
    {
        _mm256_store_ps(dst, v);
    }

    void loadu(const float *src) noexcept
    {
        v = _mm256_loadu_ps(src);
    }

    void storeu(float *dst) noexcept
    {
        _mm256_storeu_ps(dst, v);
    }

private:
    __m256 v;
};

class FLOATX16
{
public:
    using value_type = __m512;

    FLOATX16() noexcept
    {
    }

    FLOATX16(__m512 other) noexcept :
        v{ other }
    {
    }

    FLOATX16(float value) noexcept :
        v{ _mm512_set1_ps(value) }
    {
    }

    FLOATX16 & operator+(const FLOATX16 &other) noexcept
    {
        _mm512_add_ps(this->v, other.v);
        return *this;
    }

    FLOATX16 & operator*(const FLOATX16 &other) noexcept
    {
        _mm512_mul_ps(this->v, other.v);
        return *this;
    }

    FLOATX16 & operator-(const FLOATX16 &other) noexcept
    {
        _mm512_sub_ps(this->v, other.v);
        return *this;
    }

    FLOATX16 & operator/(const FLOATX16 &other) noexcept
    {
        _mm512_div_ps(this->v, other.v);
        return *this;
    }

    operator __m512 &() noexcept
    {
        return v;
    }

    operator const __m512 &() const noexcept
    {
        return v;
    }

    void load(const float *src) noexcept
    {
        v = _mm512_load_ps(src);
    }

    void store(float *dst) noexcept
    {
        _mm512_store_ps(dst, v);
    }

    void loadu(const float *src) noexcept
    {
        v = _mm512_loadu_ps(src);
    }

    void storeu(float *dst) noexcept
    {
        _mm512_storeu_ps(dst, v);
    }

private:
    __m512 v;
};

class INT8X16
{
public:
    using value_type = __m128i;

    INT8X16() noexcept
    {
    }

    INT8X16(__m128i other) noexcept :
        v{ other }
    {
    }

    INT8X16(int8_t value) noexcept :
        v{ _mm_set1_epi8(value) }
    {
    }

    INT8X16 & operator+(const INT8X16 &other) noexcept
    {
        _mm_add_epi8(this->v, other.v);
        return *this;
    }

    INT8X16 & operator-(const INT8X16 &other) noexcept
    {
        _mm_sub_epi8(this->v, other.v);
        return *this;
    }

    INT8X16 & operator/(const INT8X16 &other) noexcept
    {
        _mm_div_epi8(this->v, other.v);
        return *this;
    }

    operator __m128i &() noexcept
    {
        return v;
    }

    operator const __m128i &() const noexcept
    {
        return v;
    }

    void load(const int8_t *src) noexcept
    {
        loadu(src);
    }

    void store(int8_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int8_t *src) noexcept
    {
        v = _mm_loadu_epi8(src);
    }

    void storeu(int8_t *dst) noexcept
    {
        _mm_storeu_epi8(dst, v);
    }

private:
    __m128i v;
};

class UINT8X16
{
public:
    using value_type = __m128i;

    UINT8X16() noexcept
    {
    }

    UINT8X16(__m128i other) noexcept :
        v{ other }
    {
    }

    UINT8X16(uint8_t value) noexcept :
        v{ _mm_set1_epi8(value) }
    {
    }

    UINT8X16 & operator+(const UINT8X16 &other) noexcept
    {
        _mm_add_epi8(this->v, other.v);
        return *this;
    }

    UINT8X16 & operator-(const UINT8X16 &other) noexcept
    {
        _mm_sub_epi8(this->v, other.v);
        return *this;
    }

    UINT8X16 & operator/(const UINT8X16 &other) noexcept
    {
        _mm_div_epi8(this->v, other.v);
        return *this;
    }

    operator __m128i &() noexcept
    {
        return v;
    }

    operator const __m128i &() const noexcept
    {
        return v;
    }

    void load(const uint8_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint8_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint8_t *src) noexcept
    {
        v = _mm_loadu_epi8(src);
    }

    void storeu(uint8_t *dst) noexcept
    {
        _mm_storeu_epi8(dst, v);
    }

private:
    __m128i v;
};

class INT16X8
{
public:
    using value_type = __m128i;

    INT16X8() noexcept
    {
    }

    INT16X8(__m128i other) noexcept :
        v{ other }
    {
    }

    INT16X8(int16_t value) noexcept :
        v{ _mm_set1_epi16(value) }
    {
    }

    INT16X8 & operator+(const INT16X8 &other) noexcept
    {
        _mm_add_epi16(this->v, other.v);
        return *this;
    }

    INT16X8 & operator*(const INT16X8 &other) noexcept
    {
        _mm_mullo_epi16(this->v, other.v);
        return *this;
    }

    INT16X8 & operator-(const INT16X8 &other) noexcept
    {
        _mm_sub_epi16(this->v, other.v);
        return *this;
    }

    INT16X8 & operator/(const INT16X8 &other) noexcept
    {
        _mm_div_epi16(this->v, other.v);
        return *this;
    }

    operator __m128i &() noexcept
    {
        return v;
    }

    operator const __m128i &() const noexcept
    {
        return v;
    }

    void load(const int16_t *src) noexcept
    {
        loadu(src);
    }

    void store(int16_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int16_t *src) noexcept
    {
        v = _mm_loadu_epi16(src);
    }

    void storeu(int16_t *dst) noexcept
    {
        _mm_storeu_epi16(dst, v);
    }

    __m128i cvt2uint8() const noexcept
    {
        return _mm_cvtepi16_epi8(v);
    }

private:
    __m128i v;
};

class UINT16X8
{
public:
    using value_type = __m128i;

    UINT16X8() noexcept
    {
    }

    UINT16X8(__m128i other) noexcept :
        v{ other }
    {
    }

    UINT16X8(uint16_t value) noexcept :
        v{ _mm_set1_epi16(value) }
    {
    }

    UINT16X8 & operator+(const UINT16X8 &other) noexcept
    {
        _mm_add_epi16(this->v, other.v);
        return *this;
    }

    UINT16X8 & operator*(const UINT16X8 &other) noexcept
    {
        _mm_mullo_epi16(this->v, other.v);
        return *this;
    }

    UINT16X8 & operator-(const UINT16X8 &other) noexcept
    {
        _mm_sub_epi16(this->v, other.v);
        return *this;
    }

    UINT16X8 & operator/(const UINT16X8 &other) noexcept
    {
        _mm_div_epi16(this->v, other.v);
        return *this;
    }

    operator __m128i &() noexcept
    {
        return v;
    }

    operator const __m128i &() const noexcept
    {
        return v;
    }

    void load(const uint16_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint16_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint16_t *src) noexcept
    {
        v = _mm_loadu_epi16(src);
    }

    void storeu(uint16_t *dst) noexcept
    {
        _mm_storeu_epi16(dst, v);
    }

    __m128i cvt2uint8() const noexcept
    {
        return _mm_cvtepi16_epi8(v);
    }

private:
    __m128i v;
};

class INT32X4
{
public:
    using value_type = __m128i;

    INT32X4() noexcept
    {
    }

    INT32X4(__m128i other) noexcept :
        v{ other }
    {
    }

    INT32X4(int32_t value) noexcept :
        v{ _mm_set1_epi32(value) }
    {
    }

    INT32X4 & operator+(const INT32X4 &other) noexcept
    {
        _mm_add_epi32(this->v, other.v);
        return *this;
    }

    INT32X4 & operator*(const INT32X4 &other) noexcept
    {
        _mm_mullo_epi32(this->v, other.v);
        return *this;
    }

    INT32X4 & operator-(const INT32X4 &other) noexcept
    {
        _mm_sub_epi32(this->v, other.v);
        return *this;
    }

    INT32X4 & operator/(const INT32X4 &other) noexcept
    {
        _mm_div_epi32(this->v, other.v);
        return *this;
    }

    operator __m128i &() noexcept
    {
        return v;
    }

    operator const __m128i &() const noexcept
    {
        return v;
    }

    void load(const int32_t *src) noexcept
    {
        loadu(src);
    }

    void store(int32_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int32_t *src) noexcept
    {
        v = _mm_loadu_epi32(src);
    }

    void storeu(int32_t *dst) noexcept
    {
        _mm_storeu_epi32(dst, v);
    }

private:
    __m128i v;
};

class UINT32X4
{
public:
    using value_type = __m128i;

    UINT32X4() noexcept
    {
    }

    UINT32X4(__m128i other) noexcept :
        v{ other }
    {
    }

    UINT32X4(uint32_t value) noexcept :
        v{ _mm_set1_epi32(value) }
    {
    }

    UINT32X4 & operator+(const UINT32X4 &other) noexcept
    {
        _mm_add_epi32(this->v, other.v);
        return *this;
    }

    UINT32X4 & operator*(const UINT32X4 &other) noexcept
    {
        _mm_mullo_epi32(this->v, other.v);
        return *this;
    }

    UINT32X4 & operator-(const UINT32X4 &other) noexcept
    {
        _mm_sub_epi32(this->v, other.v);
        return *this;
    }

    UINT32X4 & operator/(const UINT32X4 &other) noexcept
    {
        _mm_div_epi32(this->v, other.v);
        return *this;
    }

    operator __m128i &() noexcept
    {
        return v;
    }

    operator const __m128i &() const noexcept
    {
        return v;
    }

    void load(const uint32_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint32_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint32_t *src) noexcept
    {
        v = _mm_loadu_epi32(src);
    }

    void storeu(uint32_t *dst) noexcept
    {
        _mm_storeu_epi32(dst, v);
    }

private:
    __m128i v;
};

class INT8X32
{
public:
    using value_type = __m256i;

    INT8X32() noexcept
    {
    }

    INT8X32(__m256i other) noexcept :
        v{ other }
    {
    }

    INT8X32(int8_t value) noexcept :
        v{ _mm256_set1_epi8(value) }
    {
    }

    INT8X32 & operator+(const INT8X32 &other) noexcept
    {
        _mm256_add_epi8(this->v, other.v);
        return *this;
    }

    INT8X32 & operator-(const INT8X32 &other) noexcept
    {
        _mm256_sub_epi8(this->v, other.v);
        return *this;
    }

    INT8X32 & operator/(const INT8X32 &other) noexcept
    {
        _mm256_div_epi8(this->v, other.v);
        return *this;
    }

    operator __m256i &() noexcept
    {
        return v;
    }

    operator const __m256i &() const noexcept
    {
        return v;
    }

    void load(const int8_t *src) noexcept
    {
        loadu(src);
    }

    void store(int8_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int8_t *src) noexcept
    {
        v = _mm256_loadu_epi8(src);
    }

    void storeu(int8_t *dst) noexcept
    {
        _mm256_storeu_epi8(dst, v);
    }

private:
    __m256i v;
};

class UINT8X32
{
public:
    using value_type = __m256i;

    UINT8X32() noexcept
    {
    }

    UINT8X32(__m256i other) noexcept :
        v{ other }
    {
    }

    UINT8X32(uint8_t value) noexcept :
        v{ _mm256_set1_epi8(value) }
    {
    }

    UINT8X32 & operator+(const UINT8X32 &other) noexcept
    {
        _mm256_add_epi8(this->v, other.v);
        return *this;
    }

    UINT8X32 & operator-(const UINT8X32 &other) noexcept
    {
        _mm256_sub_epi8(this->v, other.v);
        return *this;
    }

    UINT8X32 & operator/(const UINT8X32 &other) noexcept
    {
        _mm256_div_epi8(this->v, other.v);
        return *this;
    }

    operator __m256i &() noexcept
    {
        return v;
    }

    operator const __m256i &() const noexcept
    {
        return v;
    }

    void load(const uint8_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint8_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint8_t *src) noexcept
    {
        v = _mm256_loadu_epi8(src);
    }

    void storeu(uint8_t *dst) noexcept
    {
        _mm256_storeu_epi8(dst, v);
    }

private:
    __m256i v;
};

class INT16X16
{
public:
    using value_type = __m256i;

    INT16X16() noexcept
    {
    }

    INT16X16(__m256i other) noexcept :
        v{ other }
    {
    }

    INT16X16(int16_t value) noexcept :
        v{ _mm256_set1_epi16(value) }
    {
    }

    INT16X16 & operator+(const INT16X16 &other) noexcept
    {
        _mm256_add_epi16(this->v, other.v);
        return *this;
    }

    INT16X16 & operator*(const INT16X16 &other) noexcept
    {
        _mm256_mullo_epi16(this->v, other.v);
        return *this;
    }

    INT16X16 & operator-(const INT16X16 &other) noexcept
    {
        _mm256_sub_epi16(this->v, other.v);
        return *this;
    }

    INT16X16 & operator/(const INT16X16 &other) noexcept
    {
        _mm256_div_epi16(this->v, other.v);
        return *this;
    }

    operator __m256i &() noexcept
    {
        return v;
    }

    operator const __m256i &() const noexcept
    {
        return v;
    }

    void load(const int16_t *src) noexcept
    {
        loadu(src);
    }

    void store(int16_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int16_t *src) noexcept
    {
        v = _mm256_loadu_epi16(src);
    }

    void storeu(int16_t *dst) noexcept
    {
        _mm256_storeu_epi16(dst, v);
    }

    __m128i cvt2uint8() const noexcept
    {
        return _mm256_cvtepi16_epi8(v);
    }

private:
    __m256i v;
};

class UINT16X16
{
public:
    using value_type = __m256i;

    UINT16X16() noexcept
    {
    }

    UINT16X16(__m256i other) noexcept :
        v{ other }
    {
    }

    UINT16X16(uint16_t value) noexcept :
        v{ _mm256_set1_epi16(value) }
    {
    }

    UINT16X16 & operator+(const UINT16X16 &other) noexcept
    {
        _mm256_add_epi16(this->v, other.v);
        return *this;
    }

    UINT16X16 & operator*(const UINT16X16 &other) noexcept
    {
        _mm256_mullo_epi16(this->v, other.v);
        return *this;
    }

    UINT16X16 & operator-(const UINT16X16 &other) noexcept
    {
        _mm256_sub_epi16(this->v, other.v);
        return *this;
    }

    UINT16X16 & operator/(const UINT16X16 &other) noexcept
    {
        _mm256_div_epi16(this->v, other.v);
        return *this;
    }

    operator __m256i &() noexcept
    {
        return v;
    }

    operator const __m256i &() const noexcept
    {
        return v;
    }

    void load(const uint16_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint16_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint16_t *src) noexcept
    {
        v = _mm256_loadu_epi16(src);
    }

    void storeu(uint16_t *dst) noexcept
    {
        _mm256_storeu_epi16(dst, v);
    }

    __m128i cvt2uint8() const noexcept
    {
        return _mm256_cvtepi16_epi8(v);
    }

private:
    __m256i v;
};

class INT32X8
{
public:
    using value_type = __m256i;

    INT32X8() noexcept
    {
    }

    INT32X8(__m256i other) noexcept :
        v{ other }
    {
    }

    INT32X8(int32_t value) noexcept :
        v{ _mm256_set1_epi32(value) }
    {
    }

    INT32X8 & operator+(const INT32X8 &other) noexcept
    {
        _mm256_add_epi32(this->v, other.v);
        return *this;
    }

    INT32X8 & operator*(const INT32X8 &other) noexcept
    {
        _mm256_mullo_epi32(this->v, other.v);
        return *this;
    }

    INT32X8 & operator-(const INT32X8 &other) noexcept
    {
        _mm256_sub_epi32(this->v, other.v);
        return *this;
    }

    INT32X8 & operator/(const INT32X8 &other) noexcept
    {
        _mm256_div_epi32(this->v, other.v);
        return *this;
    }

    operator __m256i &() noexcept
    {
        return v;
    }

    operator const __m256i &() const noexcept
    {
        return v;
    }

    void load(const int32_t *src) noexcept
    {
        loadu(src);
    }

    void store(int32_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int32_t *src) noexcept
    {
        v = _mm256_loadu_epi32(src);
    }

    void storeu(int32_t *dst) noexcept
    {
        _mm256_storeu_epi32(dst, v);
    }

private:
    __m256i v;
};

class UINT32X8
{
public:
    using value_type = __m256i;

    UINT32X8() noexcept
    {
    }

    UINT32X8(__m256i other) noexcept :
        v{ other }
    {
    }

    UINT32X8(uint32_t value) noexcept :
        v{ _mm256_set1_epi32(value) }
    {
    }

    UINT32X8 & operator+(const UINT32X8 &other) noexcept
    {
        _mm256_add_epi32(this->v, other.v);
        return *this;
    }

    UINT32X8 & operator*(const UINT32X8 &other) noexcept
    {
        _mm256_mullo_epi32(this->v, other.v);
        return *this;
    }

    UINT32X8 & operator-(const UINT32X8 &other) noexcept
    {
        _mm256_sub_epi32(this->v, other.v);
        return *this;
    }

    UINT32X8 & operator/(const UINT32X8 &other) noexcept
    {
        _mm256_div_epi32(this->v, other.v);
        return *this;
    }

    operator __m256i &() noexcept
    {
        return v;
    }

    operator const __m256i &() const noexcept
    {
        return v;
    }

    void load(const uint32_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint32_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint32_t *src) noexcept
    {
        v = _mm256_loadu_epi32(src);
    }

    void storeu(uint32_t *dst) noexcept
    {
        _mm256_storeu_epi32(dst, v);
    }

private:
    __m256i v;
};

class INT8X64
{
public:
    using value_type = __m512i;

    INT8X64() noexcept
    {
    }

    INT8X64(__m512i other) noexcept :
        v{ other }
    {
    }

    INT8X64(int8_t value) noexcept :
        v{ _mm512_set1_epi8(value) }
    {
    }

    INT8X64 & operator+(const INT8X64 &other) noexcept
    {
        _mm512_add_epi8(this->v, other.v);
        return *this;
    }

    INT8X64 & operator-(const INT8X64 &other) noexcept
    {
        _mm512_sub_epi8(this->v, other.v);
        return *this;
    }

    INT8X64 & operator/(const INT8X64 &other) noexcept
    {
        _mm512_div_epi8(this->v, other.v);
        return *this;
    }

    operator __m512i &() noexcept
    {
        return v;
    }

    operator const __m512i &() const noexcept
    {
        return v;
    }

    void load(const int8_t *src) noexcept
    {
        loadu(src);
    }

    void store(int8_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int8_t *src) noexcept
    {
        v = _mm512_loadu_epi8(src);
    }

    void storeu(int8_t *dst) noexcept
    {
        _mm512_storeu_epi8(dst, v);
    }

private:
    __m512i v;
};

class UINT8X64
{
public:
    using value_type = __m512i;

    UINT8X64() noexcept
    {
    }

    UINT8X64(__m512i other) noexcept :
        v{ other }
    {
    }

    UINT8X64(uint8_t value) noexcept :
        v{ _mm512_set1_epi8(value) }
    {
    }

    UINT8X64 & operator+(const UINT8X64 &other) noexcept
    {
        _mm512_add_epi8(this->v, other.v);
        return *this;
    }

    UINT8X64 & operator-(const UINT8X64 &other) noexcept
    {
        _mm512_sub_epi8(this->v, other.v);
        return *this;
    }

    UINT8X64 & operator/(const UINT8X64 &other) noexcept
    {
        _mm512_div_epi8(this->v, other.v);
        return *this;
    }

    operator __m512i &() noexcept
    {
        return v;
    }

    operator const __m512i &() const noexcept
    {
        return v;
    }

    void load(const uint8_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint8_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint8_t *src) noexcept
    {
        v = _mm512_loadu_epi8(src);
    }

    void storeu(uint8_t *dst) noexcept
    {
        _mm512_storeu_epi8(dst, v);
    }

private:
    __m512i v;
};

class INT16X32
{
public:
    using value_type = __m512i;

    INT16X32() noexcept
    {
    }

    INT16X32(__m512i other) noexcept :
        v{ other }
    {
    }

    INT16X32(int16_t value) noexcept :
        v{ _mm512_set1_epi16(value) }
    {
    }

    INT16X32 & operator+(const INT16X32 &other) noexcept
    {
        _mm512_add_epi16(this->v, other.v);
        return *this;
    }

    INT16X32 & operator*(const INT16X32 &other) noexcept
    {
        _mm512_mullo_epi16(this->v, other.v);
        return *this;
    }

    INT16X32 & operator-(const INT16X32 &other) noexcept
    {
        _mm512_sub_epi16(this->v, other.v);
        return *this;
    }

    INT16X32 & operator/(const INT16X32 &other) noexcept
    {
        _mm512_div_epi16(this->v, other.v);
        return *this;
    }

    operator __m512i &() noexcept
    {
        return v;
    }

    operator const __m512i &() const noexcept
    {
        return v;
    }

    void load(const int16_t *src) noexcept
    {
        loadu(src);
    }

    void store(int16_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const int16_t *src) noexcept
    {
        v = _mm512_loadu_epi16(src);
    }

    void storeu(int16_t *dst) noexcept
    {
        _mm512_storeu_epi16(dst, v);
    }

    __m256i cvt2uint8() const noexcept
    {
        return _mm512_cvtepi16_epi8(v);
    }

private:
    __m512i v;
};

class UINT16X32
{
public:
    using value_type = __m512i;

    UINT16X32() noexcept
    {
    }

    UINT16X32(__m512i other) noexcept :
        v{ other }
    {
    }

    UINT16X32(uint16_t value) noexcept :
        v{ _mm512_set1_epi16(value) }
    {
    }

    UINT16X32 & operator+(const UINT16X32 &other) noexcept
    {
        _mm512_add_epi16(this->v, other.v);
        return *this;
    }

    UINT16X32 & operator*(const UINT16X32 &other) noexcept
    {
        _mm512_mullo_epi16(this->v, other.v);
        return *this;
    }

    UINT16X32 & operator-(const UINT16X32 &other) noexcept
    {
        _mm512_sub_epi16(this->v, other.v);
        return *this;
    }

    UINT16X32 & operator/(const UINT16X32 &other) noexcept
    {
        _mm512_div_epi16(this->v, other.v);
        return *this;
    }

    operator __m512i &() noexcept
    {
        return v;
    }

    operator const __m512i &() const noexcept
    {
        return v;
    }

    void load(const uint16_t *src) noexcept
    {
        loadu(src);
    }

    void store(uint16_t *dst) noexcept
    {
        storeu(dst);
    }

    void loadu(const uint16_t *src) noexcept
    {
        v = _mm512_loadu_epi16(src);
    }

    void storeu(uint16_t *dst) noexcept
    {
        _mm512_storeu_epi16(dst, v);
    }

    __m256i cvt2uint8() const noexcept
    {
        return _mm512_cvtepi16_epi8(v);
    }

private:
    __m512i v;
};

class INT32X16
{
public:
    using value_type = __m512i;

    INT32X16() noexcept
    {
    }

    INT32X16(__m512i other) noexcept :
        v{ other }
    {
    }

    INT32X16(int32_t value) noexcept :
        v{ _mm512_set1_epi32(value) }
    {
    }

    INT32X16 & operator+(const INT32X16 &other) noexcept
    {
        _mm512_add_epi32(this->v, other.v);
        return *this;
    }

    INT32X16 & operator*(const INT32X16 &other) noexcept
    {
        _mm512_mullo_epi32(this->v, other.v);
        return *this;
    }

    INT32X16 & operator-(const INT32X16 &other) noexcept
    {
        _mm512_sub_epi32(this->v, other.v);
        return *this;
    }

    INT32X16 & operator/(const INT32X16 &other) noexcept
    {
        _mm512_div_epi32(this->v, other.v);
        return *this;
    }

    operator __m512i &() noexcept
    {
        return v;
    }

    operator const __m512i &() const noexcept
    {
        return v;
    }

    void load(const int32_t *src) noexcept
    {
        v = _mm512_load_epi32(src);
    }

    void store(int32_t *dst) noexcept
    {
        _mm512_store_epi32(dst, v);
    }

    void loadu(const int32_t *src) noexcept
    {
        v = _mm512_loadu_epi32(src);
    }

    void storeu(int32_t *dst) noexcept
    {
        _mm512_storeu_epi32(dst, v);
    }

private:
    __m512i v;
};

class UINT32X16
{
public:
    using value_type = __m512i;

    UINT32X16() noexcept
    {
    }

    UINT32X16(__m512i other) noexcept :
        v{ other }
    {
    }

    UINT32X16(uint32_t value) noexcept :
        v{ _mm512_set1_epi32(value) }
    {
    }

    UINT32X16 & operator+(const UINT32X16 &other) noexcept
    {
        _mm512_add_epi32(this->v, other.v);
        return *this;
    }

    UINT32X16 & operator*(const UINT32X16 &other) noexcept
    {
        _mm512_mullo_epi32(this->v, other.v);
        return *this;
    }

    UINT32X16 & operator-(const UINT32X16 &other) noexcept
    {
        _mm512_sub_epi32(this->v, other.v);
        return *this;
    }

    UINT32X16 & operator/(const UINT32X16 &other) noexcept
    {
        _mm512_div_epi32(this->v, other.v);
        return *this;
    }

    operator __m512i &() noexcept
    {
        return v;
    }

    operator const __m512i &() const noexcept
    {
        return v;
    }

    void load(const uint32_t *src) noexcept
    {
        v = _mm512_load_epi32(src);
    }

    void store(uint32_t *dst) noexcept
    {
        _mm512_store_epi32(dst, v);
    }

    void loadu(const uint32_t *src) noexcept
    {
        v = _mm512_loadu_epi32(src);
    }

    void storeu(uint32_t *dst) noexcept
    {
        _mm512_storeu_epi32(dst, v);
    }

private:
    __m512i v;
};

