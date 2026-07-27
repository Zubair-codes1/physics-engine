#pragma once

#include <vector>
#include "RigidBody.hpp"

using namespace std;

namespace physics {

    class World {
        private:
            vector<RigidBody*> bodies;
            Vector2 gravity{0.0f, -9.81f};
        
        public:
            World() = default;
            explicit World(Vector2 new_gravity) : gravity(new_gravity) {}

            void add_body(RigidBody* body) {
                bodies.push_back(body);
            }

            void step(float dt) {
                for (auto* body : bodies) {
                    if (body->inverse_mass == 0.0f) continue;

                    body->apply_force(gravity * body->mass);
                }

                for (auto* body: bodies) {
                    if (body->inverse_mass == 0.0f) continue;

                    // F = ma // a = F / m
                    Vector2 acceleration = body->resultant_force * body->inverse_mass;
                    body->velocity += acceleration * dt;

                    body->position += body->velocity * dt;
                    body->clear_forces();
                }


            };
    };
}
