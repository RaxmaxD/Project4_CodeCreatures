# Project4_CodeCreatures - Battle System

This README summarizes the recent refactoring of the C++ text-based adventure game's battle system and outlines the test cases created to verify its functionality.

## Code Refactoring Summary

**Original State:**

Initially, the entire battle system, including class definitions (`Creature`, `Megalos`, `Brachios`, `Tryos`), function implementations (`battleMode`, `checkYesOrNo`), and the main application logic, resided within a single file (`WorkingAttempt.cpp`). This monolithic structure made it challenging to isolate components for testing and maintenance.

**Refactored Structure:**

To improve modularity and testability, the codebase has been refactored into the following files:

*   `Creature.h`: This header file now contains the declarations for the `Creature` base class, its derived classes (`Megalos`, `Brachios`, `Tryos`), and the prototypes for shared functions like `checkYesOrNo` and `battleMode`.
*   `Creature.cpp`: This source file provides the implementations for all the classes and functions declared in `Creature.h`.
*   `main.cpp`: The original `WorkingAttempt.cpp` has been renamed to `main.cpp`. It now serves as the primary application entry point, including `Creature.h` and utilizing the battle system components.

**Benefits of Refactoring:**

*   **Modularity:** Code is now organized into logical units, making it easier to understand and navigate.
*   **Testability:** Separating declarations and implementations allows for independent compilation and testing of individual components.
*   **Maintainability:** Changes to one part of the system are less likely to impact unrelated parts, reducing the risk of introducing bugs.
*   **Reusability:** Classes and functions can be more easily reused in other parts of the project or in different projects.

## Test Cases

A `tests` directory has been created to house individual test files for the battle system. Each test case is implemented in its own `.cpp` file, includes `Creature.h`, and contains a `main` function to set up and execute a specific scenario. The output of these tests can be manually verified against the expected outcomes.

Here are the test cases created:

### Test Case 1: Basic Attack Exchange (No Type Advantage, Normal Damage)

*   **File:** `tests/test_case_1_basic_attack.cpp`
*   **Purpose:** Verifies the fundamental attack and damage calculation for both player and enemy creatures in a straightforward scenario without type advantages.
*   **Preconditions:** Megalos (Security type) and Brachios (Malware type) are initialized with their default stats.
*   **Actions:** Megalos attacks Brachios, and then Brachios attacks Megalos.
*   **Expected Outcome:** Both creatures take damage based on their ATK and DEF, and their HP is updated accordingly. The battle continues.

### Test Case 2: Type Advantage (Malware attacking Data)

*   **File:** `tests/test_case_2_type_advantage.cpp`
*   **Purpose:** Verifies the correct application of the damage multiplier when a type advantage is present (Malware attacking Data).
*   **Preconditions:** Tryos (Data type) and Brachios (Malware type) are initialized with their default stats.
*   **Actions:** Tryos attacks Brachios (no type advantage), and then Brachios attacks Tryos (type advantage).
*   **Expected Outcome:** Brachios takes normal damage from Tryos. Tryos takes increased damage from Brachios due to the Malware > Data type advantage. The battle continues.

### Test Case 3: High Defense Scenario (Damage <= Defense)

*   **File:** `tests/test_case_3_high_defense.cpp`
*   **Purpose:** Verifies that a creature with very high defense still takes a minimum of 1 damage, even if the calculated damage is less than or equal to its defense.
*   **Preconditions:** Megalos's ATK is temporarily set low, and Brachios's DEF is temporarily set high for this test.
*   **Actions:** Megalos attacks Brachios.
*   **Expected Outcome:** Brachios takes exactly 1 damage, demonstrating that damage cannot be completely negated by defense.

### Test Case 4: Fleeing

*   **File:** `tests/test_case_4_fleeing.cpp`
*   **Purpose:** Verifies that the battle correctly terminates when the player chooses the 'Flee' action.
*   **Preconditions:** Any valid creature states.
*   **Actions:** The `battleMode` function is called, and the input stream is mocked to simulate the player entering the 'Flee' command.
*   **Expected Outcome:** The battle loop breaks, and a message indicating that the battle ended (due to fleeing) is displayed.

To compile and run these tests, you would typically use a C++ compiler (like g++) and link `Creature.cpp` with each test file. For example:

```bash
g++ tests/test_case_1_basic_attack.cpp Creature.cpp -o tests/test_case_1_basic_attack
./tests/test_case_1_basic_attack
```

This process would be repeated for each test case.