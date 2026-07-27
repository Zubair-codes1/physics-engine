#include <iostream>
#include <iomanip>
#include "../include/Vector2.hpp"
#include "../include/RigidBody.hpp"
#include "../include/World.hpp"

using namespace physics;
using namespace std;

int main() {
    World world({0.0f, -9.81f});

    // Create a falling dynamic body (mass = 2.0 kg, pos = 0, 10)
    RigidBody ball({0.0f, 10.0f}, 2.0f);
    world.add_body(&ball);

    // Create a static ground plane (mass = 0.0)
    RigidBody ground({0.0f, 0.0f}, 0.0f);
    world.add_body(&ground);

    float dt = 0.1f; // 100ms time step for easy viewing

    cout << std::fixed << std::setprecision(2);
    cout << "Starting Simulation Loop...\n";
    cout << "-----------------------------\n";

    for (int frame = 0; frame <= 10; ++frame) {
        cout << "Frame " << frame 
                  << " | Ball Pos Y: " << ball.position.y << " m"
                  << " | Ball Vel Y: " << ball.velocity.y << " m/s\n";

        world.step(dt);
    }

    return 0;
}
