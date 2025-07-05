#include "../Creature.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "--- Running Test Case 2: Type Advantage (Malware attacking Data) ---" << std::endl;

    // Preconditions
    Creature *tryos = new Tryos(); // Data type
    Creature *brachios = new Brachios(); // Malware type

    std::cout << "Initial HP:" << std::endl;
    std::cout << tryos->getName() << " HP: " << tryos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    // Action 1: Tryos attacks Brachios (No type advantage)
    std::cout << "\n--- Tryos attacks Brachios (Data vs Malware) ---" << std::endl;
    tryos->attack(brachios);
    std::cout << tryos->getName() << " HP: " << tryos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    // Action 2: Brachios attacks Tryos (Malware vs Data - Type Advantage)
    std::cout << "\n--- Brachios attacks Tryos (Malware vs Data - Type Advantage) ---" << std::endl;
    brachios->attack(tryos);
    std::cout << tryos->getName() << " HP: " << tryos->getHP() << std::endl;
    std::cout << brachios->getName() << " HP: " << brachios->getHP() << std::endl;

    std::cout << "\n--- Test Case 2 Complete ---" << std::endl;

    delete tryos;
    delete brachios;
    return 0;
}