#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

//function prototypes
bool checkYesOrNo();

//Main class prototype
class Creature{

public:
	//variables for constant values of any given creature
	float memory = 100;
	float memGain = 80;
	float memMax= 180;

	std::string name = "default";
	std::string type = "Data";
	float LVL = 1;
	float XP = 1;
	float HP = 1;
	float maxHP = 1;
	float ATK = 1;
	float DEF = 1;
	float SPD = 1;
	float xpReward = 20;

	std::string looks = "**************************************@@************************************************************"
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
	    Creature(std::string name, std::string type, float lvl, float xp, float hp, float maxhp,
	             float atk, float def, float spd, float xpReward,std::string image);


	//Getters:
		float getLVL();
		float getXP();
		float getHP();
		float getMaxHP();
		float getATK();
		float getDEF();
		float getSPD();
		std::string getLooks();
		std::string getName();

		std::string getType();
		float getMem();

		float getXPReward();

		//we have a stter for name so that
		//the player can name their creature and we can name enemies,
		//this avoids confusion if the player chooses a creature that they encounter
		void setName(std::string newName);

		//Info command
		void info();

		//every turn the player will gain some memory,
		//memory is to be used for resource management
		//we have a function to pay memory,
		//returns a boolean to make sure user could pay the cost
		bool payMemory(int cost);
		//this one resets the memory to 100 after battle
		void resetMemory();
		//this is how we add memory, to a maximum of 150
		void gainMem();

		//might remove the hp restore function, 'drink'
	    void drink();

	    // Helper function to apply damage
	    void takeDamage(Creature *attacker,float damage);

	    // Attack function for basic attacks
	    void attack(Creature *defender);
	    void blockeddAttack(Creature *defender);

	    void resetHP();

	    // Virtual destructor for proper polymorphic deletion
	    virtual ~Creature() = default;

}; // end main creature class

class Megalos : public Creature{
public:

	//create megalos object using constructor,
	//Name, type, level, xp, hp, maxHP, attack, defense, speed, xpReward, looks
	Megalos();


	void getAttacks();
	void bite(Creature *defender);
	void stomp();
	void headbutt();
	void emitt();

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
    Brachios();

	void getAttacks();

	//Hmm, ig since they inheret from creature this might need to be different
	//or replace 'Creature' here \/ with  generic type?
	void stomp(Creature attacker,Creature defender);

	void headbutt();

	void tailWhip();
	void roar();

private:

};// end brachios class

class Tryos : public Creature{
public:

	//create Tryos object using constructor,
	//Name, type, level, xp, hp, attack, defense, speed, xpReward, looks
	Tryos();


};// end of tryos class



//Creature *partner, Creature *enemy
void battleMode(Creature *partner, Creature *enemy);

#endif // CREATURE_H