#include <iostream>
#include <string>
#include "Creature.h"

int main() {

	//initialize names for clarity, names not final
	std::string creatureOne = "Megalos";
	std::string creatureTwo = "Brachios";
	std::string creatureThree = "Tryos";

	std::string chosenCreature;
	Creature *partner;

	std::cout << "Hello! welcome to the first prototype of [CODE CREATURES](temp name)" << std::endl;
	std::cout << "Please choose your partner!"<< std::endl;
	std::cout << "Possible partners:" << std::endl;
	std::cout << creatureOne << std::endl;
	std::cout << creatureTwo << std::endl;
	std::cout << creatureThree << std::endl;

	//Here we teach the player that capitalizing names is important,
	//When they enter a name we correct them after they mess up,
	//if they don't mess up spelling or capitalization then we don't mention anything

	//loop to correct player on names, confirm choice, and make sure player has chosen
	do{
		std::cout << "(Enter in name of selected creature):"<< std::endl;
		std::cin >> chosenCreature;
		//double check!!! to make sure == can compare strings in C++
		if(chosenCreature == creatureOne){
			//check to make sure player is certain:
			std::cout << "choose " << creatureOne << "?(Y/N)\n";

			//function for yesNo
			//if check yes or no returns FALSE, we set chosen creature to null, so the loop starts over
			if(checkYesOrNo()){
				//assign partner to chosen creature
				partner = new Megalos();
			}else{
				chosenCreature = "NULL";
			}

		}else if(chosenCreature == creatureTwo){
			//check to make sure player is certain:
			std::cout << "choose " << creatureTwo << "?(Y/N)\n";
			//function for yesNo

			//if check yes or no returns FALSE, we set chosen creature to null, so the loop starts over
			if(checkYesOrNo()){
				//assign partner to chosen creature
				partner = new Brachios();
			}else{
				chosenCreature = "NULL";
			}

		}else if(chosenCreature == creatureThree){
			//check to make sure player is certain:
			std::cout << "choose " << creatureThree << "?(Y/N)\n";

			//function for yesNo
			//if check yes or no returns FALSE, we set chosen creature to null, so the loop starts over
			if(checkYesOrNo()){
				//assign partner to chosen creature
				partner = new Tryos();
			}else{
				chosenCreature = "NULL";
			}

		}else{ //this else only runs if false input is given
			std::cout << "Invalid input, please input chosen creature name with proper capitalization:" << std::endl;
			chosenCreature = "NULL";
		}//end the certainty check



	}while(chosenCreature=="NULL");

	std::cout << "Congratulations! You have chosen: " << partner->name << std::endl << partner->looks << std::endl;

	std::cout << std::endl << "Now your journey can begin! let's start by-- wait, we aren't ready yet!!" << std::endl;

	//Create new creature for the purpose of new battle
	Creature *enemy = new Brachios();
	if(partner->getName() == enemy->getName()){
		enemy->setName(enemy->getName() +"B");
	}

	battleMode(partner,enemy);

	// Clean up dynamically allocated memory
	delete partner;
	delete enemy;

	std::cout << "bye bye :)" << std::endl;
	return 0;
}