#include <iostream>
#include "registry.hpp"

int main()
{
    ecg::registry reg;
    auto entt = reg.create_entity();
    auto entt1 = reg.create_entity();
    auto entt2 = reg.create_entity();
    std::cout << entt << entt1 << entt2 << '\n';
    return 0;
}
