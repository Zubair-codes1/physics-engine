#pragma once

#include <cmath>

namespace physics {
    struct Vector2{
        float x{0.0f};
        float y{0.0f};

        constexpr Vector2() = default; // set to default values
        constexpr Vector2(float x, float y) : x(x), y(y) {} // new vals

        // operators
        Vector2 operator+(const Vector2 &rhs) const {
            return {x + rhs.x, y + rhs.y}; 
        }
        Vector2 operator-(const Vector2 &rhs) const {
            return {x - rhs.x, y - rhs.y};
        }
        Vector2 operator*(float scalarMultiply) const {
            return {x * scalarMultiply, y * scalarMultiply};
        }
        Vector2 operator/(float scalarDivide) const {
            return {x / scalarDivide, y / scalarDivide};
        }
        

        Vector2 operator+=(const Vector2 &rhs) { 
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        Vector2 operator-=(const Vector2 &rhs) {
            x -= rhs.x;
            x -= rhs.y;
            return *this;
        }

        Vector2 operator*=(float scalarMultiply) {
            x *= scalarMultiply;
            y *= scalarMultiply; 
            return *this; 
        }

        Vector2 operator-() {return {-x, -y};}

        // math functions

        [[nodiscard]] float length_squared() const { return x * x + y * y; }
        [[nodiscard]] float length() const { return std::sqrt(length_squared());}

        [[nodiscard]] Vector2 normalised() const {
            float len = length();
            return (len > 0.00001f) ? (*this/len) : Vector2{0.0f, 0.0f};
        }

        [[nodiscard]] float dot_product(const Vector2 &rhs) const {
            return x * rhs.x + y * rhs.y;
        }

        [[nodiscard]] float cross_product(const Vector2 &rhs) {
            return x * rhs.y - y * rhs.x;
        }
    };

    inline Vector2 operator*(float scalar, Vector2 &vector) {
        return vector * scalar; 
    }
}