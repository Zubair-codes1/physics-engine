#pragma once

#include "Vector2.hpp"
#include "RigidBody.hpp"

namespace physics {
    // object collision
    struct ObjectCollision {
        // both objects
        RigidBody* first_body{nullptr};
        RigidBody* second_body{nullptr};

        // overlap region
        Vector2 object_normal{0.0f, 0.0f};
        float overlap{0.0f};
        bool has_collided{false};
    };

    // Circle
    struct Circle {
        float radius{1.0f};
        Circle() = default;
        explicit Circle(float new_radius) : radius(new_radius) {}
    };

    inline ObjectCollision circle_collisions(RigidBody* first_body, const Circle* circle_a, RigidBody* second_body, Circle* circle_b) {
        ObjectCollision collision;

        collision.first_body = first_body;
        collision.second_body = second_body;
    }
}