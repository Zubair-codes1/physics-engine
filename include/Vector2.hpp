#pragma once

#include <cmath>

namespace physics {
    struct Vector2{
        float x_pos{0.0f};
        float y_pos{0.0f};

        constexpr Vector2() = default; // set to default values
        constexpr Vector2(float x, float y) : x_pos(x), y_pos(y) {} // new vals

        // operators
        Vector2 operator+(const Vector2 &rhs) const {
            return {x_pos + rhs.x_pos, y_pos + rhs.y_pos}; 
        }
        Vector2 operator-(const Vector2 &rhs) const {
            return {x_pos - rhs.x_pos, y_pos - rhs.y_pos};
        }
        Vector2 operator*(float scalarMultiply) const {
            return {x_pos * scalarMultiply, y_pos * scalarMultiply};
        }
        Vector2 operator/(float scalarDivide) const {
            return {x_pos / scalarDivide, y_pos / scalarDivide};
        }
        

        Vector2 operator+=(const Vector2 &rhs) { 
            x_pos += rhs.x_pos;
            y_pos += rhs.y_pos;
            return *this;
        }

        Vector2 operator-=(const Vector2 &rhs) {
            x_pos -= rhs.x_pos;
            y_pos -= rhs.y_pos;
            return *this;
        }

        Vector2 operator*=(float scalarMultiply) {
            x_pos *= scalarMultiply;
            y_pos *= scalarMultiply; 
            return *this; 
        }

        Vector2 operator-() {return {-x_pos, -y_pos};}

        // math functions

        [[nodiscard]] float length_squared() const { return x_pos * x_pos + y_pos * y_pos; }
        [[nodiscard]] float length() const { return std::sqrt(length_squared());}

        [[nodiscard]] Vector2 normalised() const {
            float len = length();
            return (len > 0.00001f) ? (*this/len) : Vector2{0.0f, 0.0f};
        }

        [[nodiscard]] float dot_product(const Vector2 &rhs) const {
            return x_pos * rhs.x_pos + y_pos * rhs.y_pos;
        }

        [[nodiscard]] float cross_product(const Vector2 &rhs) {
            return x_pos * rhs.y_pos - y_pos * rhs.x_pos;
        }
    };

    inline Vector2 operator*(float scalar, Vector2 &vector) {
        return vector * scalar; 

    }
}