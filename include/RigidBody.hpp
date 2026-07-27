#pragma once

#include "Vector2.hpp"

namespace physics {
    struct RigidBody {

        // linear motion base values
        Vector2 position{0.0f, 0.0f};
        Vector2 velocity{0.0f, 0.0f};
        Vector2 resultant_force{0.0f, 0.0f};

        // mass properties
        float mass{1.0f}; // initial mass of 1
        float inverse_mass{1.0f}; // 1/mass

        float bounciness{0.5f};

        RigidBody() = default;
        RigidBody(Vector2 pos, float new_mass) : position(pos) {
            set_mass(new_mass);
        }

        /**
         * Makes sure to set the correct values for mass
         * Cant be negative
         * 
         * @param new_mass the new mass of the body
         */
        void set_mass(float new_mass) {
            if (new_mass > 0.0f) {
                mass = new_mass;
                inverse_mass = 1.0f / mass;
            }else {
                mass = 0.0f;
                inverse_mass = 0.0f;
            }
        }

        /**
         * Changing the resultant force
         */
        void apply_force(Vector2 new_force) {
            resultant_force += new_force;
        }

        // set forces to 0
        void clear_forces() {
            resultant_force = {0.0f, 0.0f};
        }

    };
}
