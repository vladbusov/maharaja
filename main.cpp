#include <iostream>
#include "maharaja.h"

int main() {
    Maharaja m = Maharaja(32,32);
    std::cout << "Всего " << m.greedy_filling() << " позиции" << std::endl;
    for (auto pos : m.get_results())
        std::cout << "(" << pos.first << "," << pos.second << ") ";
    return 0;
}
