//============================================================================
// Name        : Prototype1_Classes-and-design.cpp
// Author      : Isaiah
// Version     : 0.0
// Copyright   : All rights reserved to Isaiah M douglas
// Description : Trying out what a class should look like for a creature object,
// in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <string>
using namespace std;


//function prototypes
bool checkYesOrNo();

void battleMode();

//Main class prototype
class Creature{

public:
	//variables for constant values of any given creature
	float memory = 100;
	float memGain = 80;
	float memMax= 180;

	string name = "default";
	string type = "Data";
	float LVL = 1;
	float XP = 1;
	float HP = 1;
	float maxHP = 1;
	float ATK = 1;
	float DEF = 1;
	float SPD = 1;
	float xpReward = 20;

	string looks = "**************************************@@************************************************************"
					"**********************************#@@@@@@@###################@@@@@@@@*******************************"
					"@@@@@@@@@#**************************@******@********************************************************"
					"*********@@@***********************@********@********************************#@@@@@@@@@@@@@*********"
					"************%#@*******************@**********@*********************@@*******************************"
					"***************@*@@***************************@*****************@*************************@*****%@**"
					"******************@***@**********@*************@**************************@@************%***********"
					"*****@*************@*@@***************#@@@******@*@************@********@*************@#************"
					"******@*********@*****@*****@@@@@***%@%#*****@@@@****@************@***************%@****************"
					"*******@******@*******@@**@*****@@@@@@@@@%****@**%**@@@@@@@@@@******@*@@********@*******************"
					"********@***@****@%**@**@@****@@@**@******@@@@@*@@**@***@**#@%**@@********#@************************"
					"*********@***#@#********@***@***@*@******@**@*@**@@@********@*@%**@@#***********@#******************"
					"********%%@*********@*@@@@@@#***@%*****@@@****@@%@*@@@#*******@#@*%@@%****************@@@***********"
					"***********@@******@***@@******@@%****@*@****%*@@@@***@@**#@@@###@@***#@@*************#%************"
					"*************@%**@****@@@*****@**@@*@@%@%@@@@@*@@@@@@@@#@**@*****@@@*%*****%@*******%***************"
					"***************@*#**@**@*****@***%@@@@@@*@@@@*#@@%*%*###@@***#@****@@%*********@**##****************"
					"****************@@@****@****#*****@@@%**@@*@@@**%@**#*%**@@@*****@@*@@%*********%#@*****************"
					"****************@@@****@@***#**@@##@***@@*@@**@@@*@#@**#@@@@@@@@@@%#@*#*******@****#****************"
					"***************@@**@***#*@***@@**@*@*@@@@@@*@@*#**%@@*******#@*@**@**@@@***@*****@*@****************"
					"*****@**********@***#***%#@@%@@@@@@@@@@%#@@@**@*@@@@@#*@****@#@*@*@***@@*@****@****@****************"
					"*****@********@*@*****%@**@#@**%@@@@@@@@*@@@@%@*%**@*@**@@#*%@*@%@****@@***@*******@****************"
					"*****@*********@@@@****%*****%@*@*@*@@@@@@#%@@@@@@@@@@@%#**@*@%%#***@*@@%**********@****************"
					"*****@************@@@*********@***@@@@@@@@@@@@*@***@@*****@*@*%*@**@@@@@***********@****************"
					"*****@**************@**@@***@@@***@*@@@@**@@**@****@#**@@@@@@*@*@***@@@************@****************"
					"*****@****************@**@*@@****@@%@@*@**********@*****@@**@***@***@#*************@****************"
					"*****@*******************@%*@**@@@*@@@@******@***@****@@***@***@@@@%***************@****************"
					"*************@************@@@@@*@**#*@@*@##@#*@@***#@%****@**@@*@@*@**************@***************@*"
					"******************#@****@**@*@@**#*@*@***@@@@@#*@@@*##%@@@@@@@******@************%***********@@*****"
					"********************@@@****@#****#@@@@%%@@@@@@@%@@@@@@*@#@@@@****@*@**%*********%****@@@************"
					"*************************@@*@***********%@@@@@@@@@@@*@@@#*********@**%*@**#@@@%@********************"
					"*****************************@@******#*#******@@%@**%@*****@#@@@@@@**@**@*****@*********************"
					"**************************@@************@#@#**@****@***********@*#*@**@**@***@**********************"
					"************************@*****#@***@#@@**@***@******@***********@*@@@*****@**@**********************"
					"********************@@********@*@@@*******@**********#*********@*****%*@*****@*****************@****"
					"*******************#**********#@*@*********@@**********#*******#*******#@**@@**@***************@****"
					"******************@*************************************@***************#*******%**************@****"
					"*****************@***************************************@***%*********************@**********@*****";

	 // Base constructor
	    Creature(string name, string type, float lvl, float xp, float hp, float maxhp,
	             float atk, float def, float spd, float xpReward,string image)
	        : name(name), type(type), LVL(lvl), XP(xp), HP(hp), maxHP(maxhp), ATK(atk),
	          DEF(def), SPD(spd), xpReward(xpReward), looks(image){}


	//Getters:
		float getLVL(){
			return LVL;
		}
		float getXP(){
			return XP;
		}
		float getHP(){
			return HP;
		}
		float getMaxHP(){
			return maxHP;
		}
		float getATK(){
			return ATK;
		}
		float getDEF(){
			return DEF;
		}
		float getSPD(){
			return SPD;
		}
		string getLooks(){
			return looks;
		}
		string getName(){
			return name;
		}

		string getType(){
			return type;
		}
		float getMem(){
			return memory;
		}

		float getXPReward(){
			return xpReward;
		}

		//we have a stter for name so that
		//the player can name their creature and we can name enemies,
		//this avoids confusion if the player chooses a creature that they encounter
		void setName(string newName){
			this->name = newName;
		}

		//Info command
		void info(){
			cout << "=== " << this->getName() << " Info ===" << endl;
			cout << "Type: " << this->getType() << endl;
			cout << "HP: " << this->getHP() << "/" << this->getMaxHP() << endl;
			cout << "Memory: " << this->getMem() << "/" << memMax << endl;
			cout << "ATK: " << this->getATK() << endl;
			cout << "DEF: " << this->getDEF() << endl;
			cout << "SPD: " << this->getSPD() << endl;
			cout << "Level: " << this->getLVL() << endl;
		}

		//every turn the player will gain some memory,
		//memory is to be used for resource management
		//we have a function to pay memory,
		//returns a boolean to make sure user could pay the cost
		bool payMemory(int cost){
			bool hadEnoughMem = false;

			cout << this->getName() << " payed " << cost << " memory for action" << endl;
			memory -= cost;
			//make sure player hs enough memory to pay
			if (memory < 0 ){
				memory = 0;
				cout << "memory cost too high! action invalid" << endl;
				hadEnoughMem = false;
			}else{
				hadEnoughMem = true;
			}
			return hadEnoughMem;
		}
		//this one resets the memory to 100 after battle
		void resetMemory(){
			memory = 100;
		}
		//this is how we add memory, to a maximum of 150
		void gainMem(){
			memory += memGain;
			if (memory >= memMax){
				memory = memMax;
				cout << "max memory!!\n";
			}

			cout << this->getName() <<"'s memory: " << memory << endl;
		}

		//might remove the hp restore function, 'drink'
	    void drink(){
	        // Implement what drink does, e.g., restores HP
	        HP = maxHP;
	        cout << name << " drank and restored health to " << HP << "!\n";
	    }

	    // Helper function to apply damage
	    void takeDamage(Creature *attacker,float damage) {

	    	//variable to hold the multiplier associated with type advantages
	    	float mult = 1;
	    	//compare the type of this creature to the others,
	    	//Malware > Data > Security > Malware
	    	if(this->getType() == "Data" && attacker->getType() == "Malware"){
	    		cout << "Malware type attackers corrupts Data!\n" ;
	    		mult = 1.5;
	    	} else if(this->getType() == "Malware" && attacker->getType() == "Security"){
	    		cout << "Security type attackers hunts Malware!\n";
	    		mult = 1.5;
	    	} else if(this->getType() == "Security" && attacker->getType() == "Data"){
	    		cout << "Data type attackers hinder security!";
	    		mult = 1.5;
	    	}//end of multiplier check


	    	//check to make sure the damage taken isn't less than the defense,
	    	//else the defending creature still takes 1 damage
	    	if(damage*mult > this->getDEF()){
	        HP -= damage*mult - (this->getDEF());

	    	}else{
	    		cout << this->getName() << "'s defense is really high!\n";
	    		HP -= 1;
	    	}

	        // Ensure HP doesn't go below zero
	        if (HP < 0) {
	        	HP = 0;
	        }
	        //display how much damage was taken
	        cout << name << " took " << damage << " damage! Remaining HP: " << HP << endl;
	    }//end of take damage function

	    // Attack function for basic attacks
	    void attack(Creature *defender){
	    	//cost of this basic attack
	    	int memCost = 30;

	    	if(payMemory(memCost)){

	        cout << this->getName() << " attacks " << defender->getName() << "!" << endl;
	        // Calculate damage
	        float damage = 2 * this->ATK;

	        // Apply damage to the defender directly using takeDamage function
	        defender->takeDamage(this,damage);

	    	}//end if statement
	    }
	    void blockeddAttack(Creature *defender){
	        cout << this->name << " attacks " << defender->getName() << "!" << endl; // Use getName()
	        float damage = this->ATK; // Calculate damage

	        // Apply damage to the defender directly using its takeDamage function
	        defender->takeDamage(this,damage);
	    }

	    void resetHP(){
	        HP = maxHP;
	    }

	    // Virtual destructor for proper polymorphic deletion
	    virtual ~Creature() = default;

}; // end main creature class

class Megalos : public Creature{
public:

	//create megalos object using constructor,
	//Name, type, level, xp, hp, maxHP, attack, defense, speed, xpReward, looks
	Megalos() : Creature("Megalos","Security",1,0,50,50,5,2,3,20,".........................................................................................\n"
					"........................................................................................\n"
					".................%#.....@..................................@@-....:%@....................\n"
					"..............+............#.......................................*.....@...............\n"
					".........................@...@.............................................@.............\n"
					"...........@....................@@=-%@:...............................#.....@............\n"
					"..........+.........%+@@.:...............................................................\n"
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
					".............................................#..:-...%...................................\n"
					"................................................-..*.....................................\n"
					"...............................................:%........................................\n"
					".........................................................................................\n"){}


	void getAttacks(){

		cout << "Attacks:\n"
				"Bite: mult: 3, memory: 30\n"
				"Stomp: mult: 5, memory: 50\n"
				"Headbutt: mult 7, memory: 70\n"
				"Emit: creates fog in the arena, memory: 80\n";

	}
	void bite(Creature *defender){
        cout << this->getName() << " attacks " << defender->getName() << "!" << endl;
        // Calculate damage
        float damage = 2 * this->ATK;

        // Apply damage to the defender directly using takeDamage function
        defender->takeDamage(this,damage);

	};

	void stomp(){

	};

	void headbutt(){

	};

	void emitt(){
		//when Megalos enters the field, he emits enough mist to create a dense fog,
				//enemies become disoriented,
	};

private:
	//might remove this--------------
	//void fog(){

		//when Megalos enters the field, he emits enough mist to create a dense fog,
				//enemies become disoriented,
	//}
};

class Brachios : public Creature{
public:


	//Might come back and try to collapse all of these art lines for simplicity

	//create Brachios object using constructor,
	//Name, type, level, xp, hp, attack, defense, speed, xpReward, looks
    Brachios()
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
"=======================-===========================**======*=======++++++++++++++++++++++\n"
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
"==================+++++++++++++++++********####**###########%#%#%#%##%%###%%%#%%%%%%%%%%%\n"
"======================+++++++++++++++******************************######################\n"
"==================++++++++++++++++**********************#*******#########################\n"
"===========+++++++++++++++++***************************##################################\n"
"===========+++++++++++++++++***************************##################################\n"){}

	void getAttacks(){

		cout << "Attacks:\n"
				"Stomp: mult: 5, memory: 50\n"
				"Headbutt: mult 7, memory: 70\n"
				"Tailwhip"
				"Emit: creates fog in the arena, memory: 80\n";

	}

	//Hmm, ig since they inheret from creature this might need to be different
	//or replace 'Creature' here \/ with  generic type?
	void stomp(Creature attacker,Creature defender){

	};

	void headbutt(){

	};

	void tailWhip(){

	};
	void roar(){

	};

private:

};// end brachios class

class Tryos : public Creature{
public:

	//create Tryos object using constructor,
	//Name, type, level, xp, hp, attack, defense, speed, xpReward, looks
	Tryos() : Creature("Tryos", "Data", 1, 0, 65, 65, 3, 3, 3, 20,"=======++=+++++++=++==+++++++++++++++++++******#*#****++++++++++=+++=++=+==++++++++++++++++++++++\n"
"================%+*#========================================++++++===+++=+#=++++++++++++++++++++*\n"
"===============+*==%+=**==+#*========+#%%*==================+++++++==+++#+#=++++++++++++++++++++*\n"
"====+#%%#+==+#%#*+*=+*#===+==============**+===========+====+++++++++++#+#+=++++++++++++**#******\n"
"======#++++++#*++==##*+*%===#====+=+++=++++#%####**+++++++++++******%%#**#+==++++++++++++++++****\n"
"=======+++++++=++#+==+##*+%==+*=====++======%#+=+==++*%+=======+++*#++++**+=++++++++++++++++*****\n"
"==================+*#+++#*=%=+=#+=+===+===+==%+======+++*%*==+*%%+++++++#+++++++++++++++++*******\n"
"=================+++==*%==#+%**+%*+===+#==+++%#=======+++++#%%+++++++++#*++++++++++++++++********\n"
"=================**=++++%#+#+++++**++++++#+++#%+===+=+++++++++%+++++++*+++++**####*+++++*********\n"
"=========+#%%%#%#**++##=#*+=++++##+++++++*++++%+===+==+++++++++++++++**+++++++++++++++++*********\n"
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


};// end of tryos class



//Creature *partner, Creature *enemy
void battleMode(Creature *partner, Creature *enemy);

int main() {

	//initialize names for clarity, names not final
	string creatureOne = "Megalos";
	string creatureTwo = "Brachios";
	string creatureThree = "Tryos";

	string chosenCreature;
	Creature *partner;

	//maybe?? battle input will work like:
	//switch(){
	//case attack:
	//case drink:

	//dunno, this might be too combersome
	// I want input to look more like:
	//attack(Allo,Stego)
	//for 'Allo' to attack 'Stego'
	//but idk if input can work like that

	cout << "Hello! welcome to the first prototype of [CODE CREATURES](temp name)" << endl;
	cout << "Please choose your partner!"<< endl;
	cout << "Possible partners:" << endl;
	cout << creatureOne << endl;
	cout << creatureTwo << endl;
	cout << creatureThree << endl;

	//Here we teach the player that capitalizing names is important,
	//When they enter a name we correct them after they mess up,
	//if they don't mess up spelling or capitalization then we don't mention anything

	//loop to correct player on names, confirm choice, and make sure player has chosen
	do{
		cout << "(Enter in name of selected creature):"<< endl;
		cin >> chosenCreature;
		//double check!!! to make sure == can compare strings in C++
		if(chosenCreature == creatureOne){
			//check to make sure player is certain:
			cout << "choose " << creatureOne << "?(Y/N)\n";

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
			cout << "choose " << creatureTwo << "?(Y/N)\n";
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
			cout << "choose " << creatureThree << "?(Y/N)\n";

			//function for yesNo
			//if check yes or no returns FALSE, we set chosen creature to null, so the loop starts over
			if(checkYesOrNo()){
				//assign partner to chosen creature
				partner = new Tryos();
			}else{
				chosenCreature = "NULL";
			}

		}else{ //this else only runs if false input is given
			cout << "Invalid input, please input chosen creature name with proper capitalization:" << endl;
			chosenCreature = "NULL";
		}//end the certainty check



	}while(chosenCreature=="NULL");

	cout << "Congratulations! You have chosen: " << partner->name << endl << partner->looks << endl;

	cout << endl << "Now your journey can begin! let's start by-- wait, we aren't ready yet!!" << endl;

	//Create new creature for the purpose of new battle
	Creature *enemy = new Brachios();
	if(partner->getName() == enemy->getName()){
		enemy->setName(enemy->getName() +"B");
	}

	battleMode(partner,enemy);

	// Clean up dynamically allocated memory
	delete partner;
	delete enemy;

	//}while();

	cout << "bye bye :)" << endl;
	return 0;
}//END OF MAIN

//FUNCTIONS

//battle mode from internet:
void battleMode(Creature *partner, Creature *enemy){

    // No need for local partnerHP/enemyHP copies if you directly access the objects
    // float partnerHP = partner->HP;
    // float enemyHP = enemy->HP;
    string action = "";

    cout << "[BATTLE START!!]" << endl;
    cout << "Challenger: " << enemy->getName() << endl << endl;

    // Reset HP at the start of a new battle
    partner->resetHP();
    enemy->resetHP();

    // Display initial HP
    cout << partner->getName() << " HP: " << partner->getHP() << endl;
    cout << enemy->getName() << " HP: " << enemy->getHP() << endl;

    do{

        cout << endl << "Would you like to: Attack, Block, or Flee?\n";
        cout << "Enter in your choice in format: (Partner's name)->(action)->(Enemy's Name)\n";
		cout << "Example: " << partner->getName() << "->Block->" << enemy->getName() << endl;
		cout << "(You can use the \"Info\" action to learn about your partner's actions!)\n";
        cout << endl <<"Make your move:" << endl;

        cin >> action;

        if(action == "Info"){
        	//partner->Info();

        }

        //If-else statement for battle actions
        //currently we only have attack, drink, and run, but soon
        //I'll change it so the attack option lets the player choose which of the creature's attack to use
        if(action == ((partner->getName()).append("->Attack->")).append(enemy->getName())){

        	partner->attack(enemy); // Pass the enemy pointer directly

        } else if (action == ((partner->getName()).append("->Block->")).append(enemy->getName())){ // Example of another action
            cout << "Your partner" << partner->getName()  << " is blocking!" << endl;

        } else if (action == ((partner->getName()).append("->Flee->")).append(enemy->getName())){ // Example of another action
            cout << "You and " << partner->getName() << " try to flee!" << endl;
            break; // Exit loop if player runs

        } else {
            cout << "Invalid action. Please choose Attack, Drink, or Run." << endl;
            continue; // Skip the rest of the loop and ask for input again

        }

        // Check if enemy is defeated after partner's attack
        if(enemy->getHP() <= 0){
            cout << enemy->getName() << " has been defeated!" << endl;
            break; // Exit battle loop
        }

        // Enemy's turn (simple auto-attack)
        cout << endl << enemy->getName() << "'s turn!" << endl;
        if(action == ((partner->getName()).append("->Block->")).append(enemy->getName())){
        	enemy->attack(partner);

        }else{
            enemy->attack(partner); // Enemy attacks partner
        }
        // Check if partner is defeated after enemy's attack
        if(partner->getHP() <= 0){
            cout << "Oh no! Your partner, " << partner->getName() << " is fading!\n";
            break; // Exit battle loop
        }

        // Display current HP after both turns
        cout << endl << partner->getName() << " HP: " << partner->getHP() << endl;
        cout << enemy->getName() << " HP: " << enemy->getHP() << endl;

        //player gains memory
        partner->gainMem();

    }while(partner->getHP() > 0 && enemy->getHP() > 0); // Use getHP() for loop condition

    // Battle conclusion messages
    if(partner->getHP() <= 0){
        cout << "Your partner " << partner->getName() << " was defeated!" << endl;
    }else if(enemy->getHP() <= 0){
        cout << "Woohoo! You defeated: " << enemy->getName() << endl;
    } else {
        cout << "The battle ended." << endl; // For cases like 'Run'
    }
}

//AUTO RETURNS FALSE(for now)
bool checkYesOrNo(){
	bool answer = false;
	char yesNo = '0';
	cin >> yesNo;

	//check input, and assign boolean as directed
	if (yesNo == 'N'){
		answer = false;

	}else {
		if(yesNo == 'Y'){
			answer = true;

		}else{
			cout << "ERROR: invalid syntax, enter a single character, Y or N \n\n";
		}
	}

	return answer;
}//END OF CHECK YES OR NO func
