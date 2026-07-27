#include <iostream>
#include "Vector2.hpp"

using namespace physics;
using namespace std;

int main() {
    Vector2 position{0.0f, 10.0f};
    Vector2 velocity{5.0f, -2.0f};

    position += velocity;

    cout << "Vector Math Ready!\n";
    cout << "New Position: (" << position.x << ", " << position.y << ")\n";

    return 0;
}
