#include "Creature.h"
#include <iostream>
#include <string>
#include <cstring>

//Creature constructor
Creature::Creature(std::string name, std::string type, float lvl, float xp, float hp, float maxhp,
         float atk, float def, float spd, float xpReward,std::string image)
    : name(name), type(type), LVL(lvl), XP(xp), HP(hp), maxHP(maxhp), ATK(atk),
      DEF(def), SPD(spd), xpReward(xpReward), looks(image){}


//Getters:
	float Creature::getLVL(){
		return LVL;
	}
	float Creature::getXP(){
		return XP;
	}
	float Creature::getHP(){
		return HP;
	}
	float Creature::getMaxHP(){
		return maxHP;
	}
	float Creature::getATK(){
		return ATK;
	}
	float Creature::getDEF(){
		return DEF;
	}
	float Creature::getSPD(){
		return SPD;
	}
	std::string Creature::getLooks(){
		return looks;
	}
	std::string Creature::getName(){
		return name;
	}

	std::string Creature::getType(){
		return type;
	}
	float Creature::getMem(){
		return memory;
	}

	float Creature::getXPReward(){
		return xpReward;
	}

	//we have a stter for name so that
	//the player can name their creature and we can name enemies,
	//this avoids confusion if the player chooses a creature that they encounter
	void Creature::setName(std::string newName){
		this->name = newName;
	}

	//Info command
	void Creature::info(){
		std::cout << "=== " << this->getName() << " Info ===" << std::endl;
		std::cout << "Type: " << this->getType() << std::endl;
		std::cout << "HP: " << this->getHP() << "/" << this->getMaxHP() << std::endl;
		std::cout << "Memory: " << this->getMem() << "/" << memMax << std::endl;
		std::cout << "ATK: " << this->getATK() << std::endl;
		std::cout << "DEF: " << this->getDEF() << std::endl;
		std::cout << "SPD: " << this->getSPD() << std::endl;
		std::cout << "Level: " << this->getLVL() << std::endl;
	}

	//every turn the player will gain some memory,
	//memory is to be used for resource management
	//we have a function to pay memory,
	//returns a boolean to make sure user could pay the cost
	bool Creature::payMemory(int cost){
		bool hadEnoughMem = false;

		std::cout << this->getName() << " payed " << cost << " memory for action" << std::endl;
		memory -= cost;
		//make sure player hs enough memory to pay
		if (memory < 0 ){
			memory = 0;
			std::cout << "memory cost too high! action invalid" << std::endl;
			hadEnoughMem = false;
		}else{
			hadEnoughMem = true;
		}
		return hadEnoughMem;
	}
	//this one resets the memory to 100 after battle
	void Creature::resetMemory(){
		memory = 100;
	}
	//this is how we add memory, to a maximum of 150
	void Creature::gainMem(){
		memory += memGain;
		if (memory >= memMax){
			memory = memMax;
			std::cout << "max memory!!\n";
		}

		std::cout << this->getName() <<"'s memory: " << memory << std::endl;
	}

	//might remove the hp restore function, 'drink'
    void Creature::drink(){
        // Implement what drink does, e.g., restores HP
        HP = maxHP;
        std::cout << name << " drank and restored health to " << HP << "!\n";
    }

    // Helper function to apply damage
    void Creature::takeDamage(Creature *attacker,float damage) {

    	//variable to hold the multiplier associated with type advantages
    	float mult = 1;
    	//compare the type of this creature to the others,
    	//Malware > Data > Security > Malware
    	if(this->getType() == "Data" && attacker->getType() == "Malware"){
    		std::cout << "Malware type attackers corrupts Data!\n" ;
    		mult = 1.5;
    	} else if(this->getType() == "Malware" && attacker->getType() == "Security"){
    		std::cout << "Security type attackers hunts Malware!\n";
    		mult = 1.5;
    	} else if(this->getType() == "Security" && attacker->getType() == "Data"){
    		std::cout << "Data type attackers hinder security!";
    		mult = 1.5;
    	}//end of multiplier check


    	//check to make sure the damage taken isn't less than the defense,
    	//else the defending creature still takes 1 damage
    	if(damage*mult > this->getDEF()){
        HP -= damage*mult - (this->getDEF());

    	}else{
    		std::cout << this->getName() << "'s defense is really high!\n";
    		HP -= 1;
    	}

        // Ensure HP doesn't go below zero
        if (HP < 0) {
        	HP = 0;
        }
        //display how much damage was taken
        std::cout << name << " took " << damage << " damage! Remaining HP: " << HP << std::endl;
    }//end of take damage function

    // Attack function for basic attacks
    void Creature::attack(Creature *defender){
    	//cost of this basic attack
    	int memCost = 30;

    	if(payMemory(memCost)){

        std::cout << this->getName() << " attacks " << defender->getName() << "!" << std::endl;
        // Calculate damage
        float damage = 2 * this->ATK;

        // Apply damage to the defender directly using takeDamage function
        defender->takeDamage(this,damage);

    	}//end if statement
    }
    void Creature::blockeddAttack(Creature *defender){
        std::cout << this->name << " attacks " << defender->getName() << "!" << std::endl; // Use getName()
        float damage = this->ATK; // Calculate damage

        // Apply damage to the defender directly using its takeDamage function
        defender->takeDamage(this,damage);
    }

    void Creature::resetHP(){
        HP = maxHP;
    }

// Megalos class implementations
Megalos::Megalos() : Creature("Megalos","Security",1,0,50,50,5,2,3,20,".........................................................................................\n"
					"........................................................................................\n"
					".................%#.....@..................................@@-....:%@....................\n"
					"..............+............#.......................................*.....@............\n"
					".........................@...@.............................................@.............\n"
					"...........@....................@@=-%@:...............................#.....@............\n"
					"..........+.........%+@@.:............................................................\n"
					".........@.........@=@%..................%.......@:@..................#..................\n"
					".........:......@.@@@..=..................::........@................-......-............\n"
					".........@.......@@:.@.-...........................................:........+............\n"
					"..........-..*@@@..+.........@...+............#@@+......@......=@..........@.............\n"
					".............@=-@................+.........@..............................=..............\n"
					".......................@...@....:.......................................%................\n"
					"......................:..+:=..........................................%..................\n"
					".......................-@.@...+@........@.............:............@.....................\n"
					"........................@...@.....#.....@.............@........@.........................\n"
					"...........................@+.........+@.............:....@:.............................\n"
					".........................................=..........@....................................\n"
					"...................................*....-.:.......@..@...................................\n"
					"...........................................%#............................................\n"
					".....................................@......=.#..........................................\n"
					".......................................@....@....@-......................................\n"
					"...........................................:......@....@.................................\n"
					"...................................#..:..........@.......................................\n"
					"....................................#.@%.......%......@..................................\n"
					".............................................#..:-...%....................................\n"
					"................................................-..*.....................................\n"
					"...............................................:%........................................\n"
					".........................................................................................\n"){}

void Megalos::getAttacks(){

	std::cout << "Attacks:\n"
				"Bite: mult: 3, memory: 30\n"
				"Stomp: mult: 5, memory: 50\n"
				"Headbutt: mult 7, memory: 70\n"
				"Emit: creates fog in the arena, memory: 80\n";

}
void Megalos::bite(Creature *defender){
    std::cout << this->getName() << " attacks " << defender->getName() << "!" << std::endl;
    // Calculate damage
    float damage = 2 * this->ATK;

    // Apply damage to the defender directly using takeDamage function
    defender->takeDamage(this,damage);

};

void Megalos::stomp(){

};

void Megalos::headbutt(){

};

void Megalos::emitt(){
	//when Megalos enters the field, he emits enough mist to create a dense fog,
			//enemies become disoriented,
};

// Brachios class implementations
Brachios::Brachios()
    : Creature("Brachios", "Malware", 1, 0, 75, 75, 3, 4, 1, 20,"===========+++++++++++++++++***************************##################################\n"
    			"=====================================================================+===++++++++++++++++\n"
"===========================================*+====+#+================+++++++++++++++++++++\n"
"=======================================#======#%+===#===============++++++++++++++++++*##\n"
"====================================+=#=========*====+#+=============++++++++++++++++++++\n"
"======================================#=+===*#=+===#===#++===========++++++++++++++++++++\n"
"+++++++++++++++++++++++=+===========+=+#+=++===+%#*==##=+%===+++++++++++++++++++++++++++*\n"
"=======================================+###*==*=+*+======++===========+++++++++++++++++++\n"
"========+=========================================#=======*===========+++++++++++++++++++\n"
"========+==========================================#====%+=#======+++++++++++++++++++++++\n"
"========+==========================================*=======%=====++++++++++++++++++++++++\n"
"======================-===========================**======*=======++++++++++++++++++++++\n"
"==========================*##%%##%*+++*#%#++++====*+=======#==+=+++++++++++++++++++++++++\n"
"===========++++++++#*###*+++++++++++++++++++*%***++++++++++#+++++++++++++++++++++++++++**\n"
"=================%#=======================================**==++++++++++++++++++++++++++*\n"
"==============*#+=========================================#====++++++++++++++++++++++++**\n"
"=============*==================================++========*=++++++++++++++++++++++++*+***\n"
"============*=========+======+#================+=++======%+===+++++++++++++++++++++++****\n"
"===========+===================*=============*%======+=+++*===+++#+%++++++*++++++++******\n"
"==========*+===========#=======#*===========#+====++#==++#++=++++%#+++*#+++#+#*++%*%**%**\n"
"+++++++++*+++++++++++++*++++++++#++++++++++**++++++**++#+++*+++++#++*+%**%++%#*+%#***#*#*\n"
"=========#+============*========+*========#*=====++#+@%++++++++++++++++++++++************\n"
"=========#=========%+===========+#========+====+++*+%%++*+++#++++++++********************\n"
"=======+=**=======+*+=*=*=======*%=====+=%==+=+*+%*+#%+*+++++*%*+************************\n"
"=======+=**========+===+=#====++=***=###****===+%+++%+++*#%*@#********************#######\n"
"=======+==+*+========##=#*======#+=======%====+++%#%%%*+*%%******************************\n"
"=======+===++*=========++++*=+=+======+=++++=++++++++*#%%********************************\n"
"======+====++*#=====++++======++++++++++++++++++*@**#****##***#********************##*##\n"
"=======+=====+=++##*+*++======+=+=+++==++*%**+++***%*%*****#*************************###*\n"
"=======+======*====**##*+*+==+#+=+++++++++%%@@@***##*****#************************###***#\n"
"================++===+++++++++++++++++++++*****#*******************************########*#\n"
"==================+++++++++++++++++********####**###########%#%#%#%##%%###%%%#%%%%%%%%%%\n"
"======================+++++++++++++++******************************######################\n"
"==================++++++++++++++++**********************#*******#########################\n"
"===========+++++++++++++++++***************************##################################\n"
"===========+++++++++++++++++***************************##################################\n"){}

void Brachios::getAttacks(){

	std::cout << "Attacks:\n"
				"Stomp: mult: 5, memory: 50\n"
				"Headbutt: mult 7, memory: 70\n"
				"Tailwhip"
				"Emit: creates fog in the arena, memory: 80\n";

}

//Hmm, ig since they inheret from creature this might need to be different
//or replace 'Creature' here \/ with  generic type?
void Brachios::stomp(Creature attacker,Creature defender){

};

void Brachios::headbutt(){

};

void Brachios::tailWhip(){

};
void Brachios::roar(){

};

// Tryos class implementations
Tryos::Tryos() : Creature("Tryos", "Data", 1, 0, 65, 65, 3, 3, 3, 20,"=======++=+++++++=++==+++++++++++++++++++******#*#****++++++++++=+++=++=+==++++++++++++++++++++++\n"
"================%+*#========================================++++++===+++=+#=++++++++++++++++++++*\n"
"===============+*==%+=**==+#*========+#%%*==================+++++++==+++#+#=++++++++++++++++++++*\n"
"====+#%%#+==+#%#*+*=+*#===+==============**+===========+====+++++++++++#+#+=++++++++++++**#******\n"
"======#++++++#*++==##*+*%===#====+=+++=++++#%####**+++++++++++******%%#**#+==++++++++++++++++****\n"
"=======+++++++=++#+==+##*+%==+*=====++======%#+=+==++*%+=======+++*#++++**+=++++++++++++++++*****\n"
"==================+*#+++#*=%=+=#+=+===+===+==%+======+++*%*==+*%%+++++++#+++++++++++++++++*******\n"
"=================+++==*%==#+%**+%*+===+#==+++%#=======+++++#%%+++++++++#*++++++++++++++++********\n"
"=================**=++++%#+#+++++**++++++#+++#%+===+=+++++++++%+++++++*+++++**####*+++++*********\n"
"=========+#%%%#%#**++##=#*+=++++##+++++++*++++%+===+==+++++++++++++++**+++++++++++++++++*********\n"
"\n"
"===============+%++#**+*++==++++##+++=========#%====++*+++++#%++++++%++++++++++++++++++**********\n"
"============++++++#*#%#+**+=+=++++*+++*++++%%%*#===++#+++++++#*+++#%++++++++++++++++++***********\n"
"==============++++#**++++++++#**++++++*++*+++=+#*=++**+++++++*%*+#*++++++++++++++++++*********###\n"
"+=+====+++++++++++#*++%*%###****%%%##*#%##*+***+#*++#*+++++++*##++++++++++++++++++++*************\n"
"==================++%**+##+*%#=+#+#++++++#+==+*++%++#*+++**+*#+++++++++++++++++++++**************\n"
"===================+++#*==+=====##+*%*#++*#+++*+++#++#+++*+*#*++++++++++++++++++++***************\n"
"===================+====++====+=+#++++++###*+++*++*++*#++++*+#++++++++++++++++++++***************\n"
"====================++++++++++++*#++++++#+#++++*+#*#+++#*+++**%+++*+**************###############\n"
"=========================+++++++%+++++*#+*++++++#+++*+++%#+*##*#+++++++++++++++*****************#\n"
"=========================+++=++%%###*+++*%#++++*+++++++++++++++++++++++++%++%*******************#\n"
"========================+++++++++++++++++++++++++++++++++++++++++++++++++%+#%*%*%##**************\n"){};


//battle mode from internet:
void battleMode(Creature *partner, Creature *enemy){

    // No need for local partnerHP/enemyHP copies if you directly access the objects
    // float partnerHP = partner->HP;
    // float enemyHP = enemy->HP;
    std::string action = "";

    std::cout << "[BATTLE START!!]" << std::endl;
    std::cout << "Challenger: " << enemy->getName() << std::endl << std::endl;

    // Reset HP at the start of a new battle
    partner->resetHP();
    enemy->resetHP();

    // Display initial HP
    std::cout << partner->getName() << " HP: " << partner->getHP() << std::endl;
    std::cout << enemy->getName() << " HP: " << enemy->getHP() << std::endl;

    do{

        std::cout << std::endl << "Would you like to: Attack, Block, or Flee?\n";
        std::cout << "Enter in your choice in format: (Partner's name)->(action)->(Enemy's Name)\n";
		std::cout << "Example: " << partner->getName() << "->Block->" << enemy->getName() << std::endl;
		std::cout << "(You can use the \"Info\" action to learn about your partner's actions!)\n";
        std::cout << std::endl <<"Make your move:" << std::endl;

        std::cin >> action;

        if(action == "Info"){
        	//partner->Info();

        }

        //If-else statement for battle actions
        //currently we only have attack, drink, and run, but soon
        //I'll change it so the attack option lets the player choose which of the creature's attack to use
        if(action == ((partner->getName()).append("->Attack->")).append(enemy->getName())){

        	partner->attack(enemy); // Pass the enemy pointer directly

        } else if (action == ((partner->getName()).append("->Block->")).append(enemy->getName())) { // Example of another action
            std::cout << "Your partner" << partner->getName()  << " is blocking!" << std::endl;

        } else if (action == ((partner->getName()).append("->Flee->")).append(enemy->getName())) { // Example of another action
            std::cout << "You and " << partner->getName() << " try to flee!" << std::endl;
            break; // Exit loop if player runs

        } else {
            std::cout << "Invalid action. Please choose Attack, Drink, or Run." << std::endl;
            continue; // Skip the rest of the loop and ask for input again

        }

        // Check if enemy is defeated after partner's attack
        if(enemy->getHP() <= 0){
            std::cout << enemy->getName() << " has been defeated!" << std::endl;
            break; // Exit battle loop
        }

        // Enemy's turn (simple auto-attack)
        std::cout << std::endl << enemy->getName() << "'s turn!" << std::endl;
        if(action == ((partner->getName()).append("->Block->")).append(enemy->getName())){
        	enemy->attack(partner);

        }else{
            enemy->attack(partner); // Enemy attacks partner
        }
        // Check if partner is defeated after enemy's attack
        if(partner->getHP() <= 0){
            std::cout << "Oh no! Your partner, " << partner->getName() << " is fading!\n";
            break; // Exit battle loop
        }

        // Display current HP after both turns
        std::cout << std::endl << partner->getName() << " HP: " << partner->getHP() << std::endl;
        std::cout << enemy->getName() << " HP: " << enemy->getHP() << std::endl;

        //player gains memory
        partner->gainMem();

    }while(partner->getHP() > 0 && enemy->getHP() > 0); // Use getHP() for loop condition

    // Battle conclusion messages
    if(partner->getHP() <= 0){
        std::cout << "Your partner " << partner->getName() << " was defeated!" << std::endl;
    }else if(enemy->getHP() <= 0){
        std::cout << "Woohoo! You defeated: " << enemy->getName() << std::endl;
    } else {
        std::cout << "The battle ended." << std::endl; // For cases like 'Run'
    }
}

//AUTO RETURNS FALSE(for now)
bool checkYesOrNo(){
	bool answer = false;
	char yesNo = '0';
	std::cin >> yesNo;

	//check input, and assign boolean as directed
	if (yesNo == 'N'){
		answer = false;

	}else {
		if(yesNo == 'Y'){
			answer = true;

		}else{
			std::cout << "ERROR: invalid syntax, enter a single character, Y or N \n\n";
		}
	}

	return answer;
}//END OF CHECK YES OR NO func
