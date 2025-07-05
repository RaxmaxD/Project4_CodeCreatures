#include "../Creature.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "--- Running Test Case 1: Basic Attack Exchange ---" << std::endl;

    // Preconditions
    Creature *megalos = new Megalos();
    Creature *brachios = new Brachios();

    std::cout << "Initial HP:" << std::endl;
    std::cout << megalos->getName() << " HP: " << megalos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    // Action 1: Megalos attacks Brachios
    std::cout << "\n--- Megalos attacks Brachios ---" << std::endl;
    megalos->attack(brachios);
    std::cout << megalos->getName() << " HP: " << megalos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    // Action 2: Brachios attacks Megalos
    std::cout << "\n--- Brachios attacks Megalos ---" << std::endl;
    brachios->attack(megalos);
    std::cout << megalos->getName() << " HP: " << megalos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    std::cout << "\n--- Test Case 1 Complete ---" << std::endl;

    delete megalos;
    delete brachios;
    return 0;
}
