#ifndef M_VEC_H
#define M_VEC_H

#include "egg/math/eggVector.h"
#include "rvl/MTX.h"
#include <common.h>

class mVec3_c : public EGG::Vector3f {
public:
    /// @brief Constructs an empty vector.
    mVec3_c() {}

    /// @brief Constructs a vector from a float array.
    mVec3_c(const f32 *p) {
        x = p[0];
        y = p[1];
        z = p[2];
    }
    mVec3_c(const mVec3_c &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    /// @brief Constructs a vector from three floating point values.
    mVec3_c(f32 fx, f32 fy, f32 fz) {
        x = fx;
        y = fy;
        z = fz;
    }

    void set(f32 fx, f32 fy, f32 fz) {
        x = fx;
        y = fy;
        z = fz;
    }
    mVec3_c &operator=(const mVec3_c &r) {
        x = r.x;
        y = r.y;
        z = r.z;
        return *this;
    }

    /// @brief Constructs a new vector from an existing vector from the MTX library.
    mVec3_c(const Vec &v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    /// @brief Constructs a new vector from an existing vector from the nw4r::math library.
    mVec3_c(const nw4r::math::VEC3 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
    }

    /// @brief Float cast operator.
    operator f32 *() {
        return &x;
    }

    /// @brief Const float cast operator.
    operator const f32 *() const {
        return &x;
    }

    /// @brief Vec cast operator.
    operator Vec *() {
        return (Vec *)&x;
    }

    /// @brief Const Vec cast operator.
    operator const Vec *() const {
        return (const Vec *)&x;
    }

    /// @brief nw4r::math::VEC3 cast operator.
    operator nw4r::math::VEC3 *() {
        return (nw4r::math::VEC3 *)&x;
    }

    /// @brief Const nw4r::math::VEC3 cast operator.
    operator const nw4r::math::VEC3 *() const {
        return (const nw4r::math::VEC3 *)&x;
    }

    /// @brief Augmented addition operator.
    mVec3_c &operator+=(const mVec3_c &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    /// @brief Augmented subtraction operator.
    mVec3_c &operator-=(const mVec3_c &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    /// @brief Augmented scalar product operator.
    mVec3_c &operator*=(f32 f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    /// @brief Augmented scalar division operator.
    mVec3_c &operator/=(f32 f) {
        return operator*=(1.0f / f);
    }

    /// @brief Positive operator.
    mVec3_c operator+() const {
        return *this;
    }

    /// @brief Negative operator.
    mVec3_c operator-() const {
        return mVec3_c(-x, -y, -z);
    }

    /// @brief Addition operator.
    mVec3_c operator+(const mVec3_c &v) const {
        return mVec3_c(x + v.x, y + v.y, z + v.z);
    }

    /// @brief Subtraction operator.
    mVec3_c operator-(const mVec3_c &v) const {
        return mVec3_c(x - v.x, y - v.y, z - v.z);
    }

    /// @brief Scalar product operator.
    mVec3_c operator*(f32 f) const {
        return mVec3_c(f * x, f * y, f * z);
    }

    /// @brief Scalar division operator.
    mVec3_c operator/(f32 f) const {
        f32 r = 1.0f / f;
        return operator*(r);
    }

    /// @brief Equality operator.
    bool operator==(const mVec3_c &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    /// @brief Inequality operator.
    bool operator!=(const mVec3_c &v) const {
        return x != v.x || y != v.y || z != v.z;
    }
};

#endif
