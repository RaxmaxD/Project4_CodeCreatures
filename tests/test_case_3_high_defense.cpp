#include "../Creature.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "--- Running Test Case 3: High Defense Scenario ---" << std::endl;

    // Preconditions
    Creature *megalos = new Megalos();
    // Temporarily modify Megalos's ATK for this test to ensure low damage
    megalos->ATK = 1; 

    Creature *brachios = new Brachios();
    // Temporarily modify Brachios's DEF for this test to ensure high defense
    brachios->DEF = 10;

    std::cout << "Initial HP:" << std::endl;
    std::cout << megalos->getName() << " HP: " << megalos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    // Action: Megalos attacks Brachios
    std::cout << "\n--- Megalos attacks Brachios (Low ATK vs High DEF) ---" << std::endl;
    megalos->attack(brachios);
    std::cout << megalos->getName() << " HP: " << megalos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    std::cout << "\n--- Test Case 3 Complete ---" << std::endl;

    delete megalos;
    delete brachios;
    return 0;
}
