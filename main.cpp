
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>

/*We have a class named Characters that have different attributes, like the character's name, their background, their health, and a bool for each
character that can be selected, our class methods are, a constructor to more easily make characters, a getter for every variable, and three methods
that change the character bools to true, also two more class functions that modify the character's health*/
class Characters
{
    private:
    std::string name;
    std::string background;
    int health;
    bool setToCyrilla = false;
    bool setToPetrou = false;
    bool setToEphraim = false;
    int knightDamageFloor = 4;
    int knightDamageCeiling = 8;

    public:
    Characters(std::string usrName = "Default", std::string usrBackground = "Default", int usrHealth = 0)
    {
        name = usrName;
        background = usrBackground;
        health = usrHealth;
    }
    std::string getName()
    {
        return name;
    }
    std::string getBackground()
    {
        return background;
    }
    int getHealth()
    {
        return health;
    }
    void selectCyrilla()
    {
        setToCyrilla = true;
    }
    void selectPetrou()
    {
        setToPetrou = true;
    }
    void selectEphraim()
    {
        setToEphraim = true;
    }
    bool checkEphraim()
    {
        return setToEphraim;
    }
    bool checkCyrilla()
    {
        return setToCyrilla;
    }
    bool checkPetrou()
    {
        return setToPetrou;
    }
    void addHealth(int positiveHealth)
    {
        health = health + positiveHealth;
    }
    void substractHealth(int negativeHealth)
    {
        health = health - negativeHealth;
    }
    void strenghtCyrilla(int abilityModifier)
    {
        knightDamageCeiling = knightDamageCeiling + abilityModifier;
        knightDamageFloor = knightDamageFloor + abilityModifier;
    }
    int cyrillaAttack()
    {  
        srand(time(0));
        int damage = rand() % (knightDamageCeiling - knightDamageFloor +1) + knightDamageFloor;

        return damage;
    }

};
/*Another Class called Rooms that has the room name, room description, an extra inspection, and Ephraim's unique perspective of the room
we also have a constructor for this class, and a getter for each variable*/
class Rooms
{
    private:
    std::string roomName;
    std::string roomDescription;
    std::string extraDescription;
    //añadir el de Ephraim 

    public:
    Rooms(std::string usrRoomName = "Default", std::string usrDescription = "Default",std::string usrExtraDescription = "DEFAULT")
    {
        roomName = usrRoomName;
        roomDescription = usrDescription;
        extraDescription = usrExtraDescription;
    }
    std::string getRoomName()
    {
        return roomName;
    }
    std::string getRoomDescription()
    {
        return roomDescription;
    }
    //añadir getters que faltan
};

class Monster
{
    private:
    std::string monsterName;
    int monsterHealth;
    std::string monsterDescription;
    std::string monsterCue;
    int damageFloor;
    int damageCeiling;

    public:
    Monster(std::string usrName="MONSTER",int usrHealth = 10, std::string usrDescription = "DEFAULT",std::string usrCue = "DEFAULT")
    {
        monsterName = usrName;
        monsterHealth = usrHealth;
        monsterDescription = usrDescription;
        monsterCue = usrCue;
    }
    int getMonsterHealth()
    {
        return monsterHealth;
    }
    std::string getMonsterDescription()
    {
        return monsterDescription;
    }
    std::string getMonsterCue()
    {
        return monsterCue;
    }
    std::string getMonsterName()
    {
        return monsterName;
    }
    void substractHealth(int usrDamage)
    {
        monsterHealth = monsterHealth - usrDamage;
    }
    int monsterAttack()
    {  
        srand(time(0));
        int damage = rand() % (damageCeiling - damageFloor +1) + damageFloor;

        return damage;
    }
};

class CharacterAbilities : public Characters
{
    private:
    std::string abilityName;
    std::string abilityDescription;
    int abilityCooldown;
    int abilityModifier;
    public:
    CharacterAbilities(std::string usrabilityName = "DEFAULT",std::string usrabilityDescription = "DEFAULT",int usrabilityCooldown = 0, int usrabilityModifier = 0)
    {
        abilityName = usrabilityName;
        abilityDescription = usrabilityDescription;
        abilityCooldown = usrabilityCooldown;
        abilityModifier = usrabilityModifier;
    }
    std::string getAbilityName()
    {
        return abilityName;
    }
    std::string getAbilityDescription()
    {
        return abilityDescription;
    }
    int getAbilityCooldown()
    {
        return abilityCooldown;
    }
    int getAbilityModifier()
    {
        return abilityModifier;
    }
};


//We declared the functions that we're going to use throughout the program
void titleScreen(std::vector<Characters>& allCharacters);
void gameStart(std::vector<Characters>& allCharacters);
void getCharacterNames(std::vector<Characters>& allCharacters);
void getCharacterInfo(std::vector <Characters>& allCharacters, int character);
void getCharacterAbilities(std::vector <CharacterAbilities>& characterInventory);
void textBox(std::string text);
void pressAnyKey();
void cyrillaCombat(std::vector <Characters>& allCharacters,std::vector <CharacterAbilities>& characterAbilities, Monster &thisMonster, int &currentCharacter);
void setCurrentCharacter(std::vector <Characters>& allCharacters, int &currentCharacter);

int main()
{
    int currentCharacter;

    Characters cyrilla("Cyrilla","A young knight from an Erstonian noble family, since she was young Cyrilla always knew it was her calling\n to protect her people,one achievement after the other Cyrilla quickly cemented herself as an iconic knight, she now wants\n to go after the biggest achievement there is, coming out of the Necromancer's dungeon alive.",25);
    Characters petrou("Petrou","A humble botanist from Erstonia, Petrou noticed the soil was being poisoned by the necromancer's lair, he decided to embark on a \njourney to stop the necromancer, if nobody does anything, Erstonia's crops and water will be forever poisoned",20);
    Characters ephraim("Ephraim","Ephraim grew up in a cult that worships a cruel goddess that asks that their followers\n give her their eyes as an act of faith, in exchange for guiding their path, so Ephraim has always lived\n in communion with the dark, having always been talented in the arcane arts, he was asked to go to the necromancer's lair\n with no further instructions",23);

    std::vector <Characters> allCharacters = {cyrilla,petrou,ephraim};

    Monster undeadAdventurer("Undead Adventurer",20,"You see what once was a joyful adventurer, they look gaunt, they fell to the\ncurse of the Necromancer, you have to put them out of their misery","You hear heavy footsteps, someone is walking towards you, the footsteps sound clumsy and uncoordinated\n must be one of the many undead that guard this dungeon");

    Rooms initialRoom("Dungeon Beginning","You finished going down the stairs and find yourself in a dimly lit room, at first glance it seems quite empty","You notice a small chest sitting in the middle of the room ");
    
    CharacterAbilities strenghtAbility("Knight's Courage","Cyrilla gathers all her strenght and  greatly increases her strenght for three turns",3,10);
    CharacterAbilities healingPotion("Healing Potion", "A small tube filled with a thick green fluid", 5, 10);

    std::vector <CharacterAbilities> cyrillaAbilities = {strenghtAbility};
    std::vector <CharacterAbilities> petrouInventory = {healingPotion};
    
    titleScreen(allCharacters);
    setCurrentCharacter(allCharacters,currentCharacter);
    cyrillaCombat(allCharacters,cyrillaAbilities, undeadAdventurer, currentCharacter);
    

    return 0;
}

void setCurrentCharacter(std::vector <Characters>& allCharacters,int &currentCharacter)
{
    if(allCharacters[0].checkCyrilla() == true)
    {
        currentCharacter = 0;
    }else if(allCharacters[1].checkPetrou() == true)
    {
        currentCharacter = 1;
    }else if(allCharacters[2].checkEphraim() == true)
    {
        currentCharacter = 2;
    }
}

/*The main menu, the game's title is displayed along with the starting options*/
void titleScreen(std::vector<Characters>& allCharacters)
{
    std::string opt;
    std::cout<<"NECROMANCER\n~~~~~~~~~~~~~~~~~~~~\n1.-Game Start\n9.-End Program\n\nopt: ";
    std::cin>>opt;
    if(opt=="1")
    {
        gameStart(allCharacters);
    }else if (opt != "1" && opt != "9")
    {
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
        titleScreen(allCharacters);
    }

}

/*What happens after the game stars, there are 3 options, to select a character, view the details about
a character and exit the program.                                                                      */
void gameStart(std::vector <Characters> &allCharacters)
{
    system("cls");
    bool whileLoop = true;
    std::string opt;
    int characterSelect;
    std::cout<<"~~~~~OPTIONS~~~~~\n1.-Select Character\n2.-View Character Details\n9.-Exit Program\n\nOPT: ";
    std::cin>>opt;
   
    
    if(opt=="1")
    {
        while(whileLoop)
        {
        system("cls");
        std::cout<<"\nYOU CAN EMBARK ON YOUR JOURNEY WITH THE FOLLOWING CHARACTERS\n~~~~~~~~~~~~~~~~~~~~\n";
        getCharacterNames(allCharacters);
        std::cout<<"~~~~~~~~~~~~~~~~~~~~\n8.-Return to Previous Menu";
        std::cout<<"\n9.-END PROGRAM";
        std::cout<<"\n\nOPT: ";
        std::cin>>characterSelect;
        switch(characterSelect)
        {
        case 1:
        std::cout<<"You chose Cyrilla as your character\n";
        allCharacters[0].selectCyrilla();
        system("cls");
        whileLoop = false;
        break;
        case 2:
        std::cout<<"You chose Petrou as your character";
        allCharacters[1].selectPetrou();
        whileLoop = false;
        break;
        case 3:
        std::cout<<"You chose Ephraim as your character";
        allCharacters[2].selectEphraim();
        whileLoop = false;
        break;
        case 8:
        system("cls");
        gameStart(allCharacters);
        break;
        case 9:
        whileLoop = false;
        break;
        default:
        std::cout<<"INVALID OPTION, TRY AGAIN\n\n";
        pressAnyKey();
        break;
        }
        }
    }else if(opt=="2")
    {
        while(whileLoop)
        {
            characterSelect=0;
            system("cls");
            std::cout<<"What character do you want to get info About?\n\n~~~~~CHARACTERS~~~~~\n";
            getCharacterNames(allCharacters);
            std::cout<<"~~~~~~~~~~~~~~~~~~~~\n8.-Return to Previous Menu";
            std::cout<<"\n9.-END PROGRAM\n\nOPT: ";
            std::cin>>characterSelect;
            if(characterSelect > 0 && characterSelect < 4)
            {
             system("cls");
             getCharacterInfo(allCharacters,characterSelect-1);
             pressAnyKey();
            }else if(characterSelect == 9)
            {
             whileLoop = false;
            }else if(characterSelect == 8)
            {
             system("cls");
             whileLoop =  false;
             gameStart(allCharacters);
            }else
            {
             system("cls");
             std::cout<<"That is not a valid option";
             pressAnyKey();
            }
            
        }

    }
}

/*This function prints the names of our playable characters, I decided
to challenge myself to learn how vectors work for this project, so I'm
implementing vectors here, I'm using a range based for loop, at the start of the loop
a variable is declared that gets passed the first element of the vector through
reference, and as the for loop iterates through allCharacters the variable
i prints each position of the vector, we also call the class function getName()
to print the name of each Character as the loop iterates through the vector */
void getCharacterNames(std::vector<Characters> &allcharacters)
{
    int indexNum = 1;
    for(Characters& i : allcharacters)
    {
        std::cout<<indexNum<<".-"<< i.getName()<<"\n";
        indexNum++;
    }
}

void getCharacterAbilities(std::vector <CharacterAbilities>& characterAbilities)
{
    int indexNum = 1;
    for(CharacterAbilities& i : characterAbilities)
    {
        std::cout<<indexNum<<".-"<<i.getAbilityName()<<"\n";
    }
}

/*Kinda like the previous function but simpler, we ask the user to pick
the character from a list, the vector gets passed through reference and we
also use the character's list number as an argument and print each character
accordingly*/
void getCharacterInfo(std::vector<Characters>& allCharacters, int character)
{
    std::cout<<"Name: "<< allCharacters[character].getName()<<"\n~~~~~~~~~~~~~~~~~~~~"<<"\nBackground: "<<allCharacters[character].getBackground()<<"\n~~~~~~~~~~~~~~~~~~~~\n"<<"HP: "<<allCharacters[character].getHealth()<<"\n~~~~~~~~~~~~~~~~~~~~";
}

void pressAnyKey()
{
    std::cout<<"\n\nPRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");
}

/*We use a string construnctor to make a textbox*/
void textBox(std::string text)
{
    int size = text.size();
    char box = '~';

    std::string multiplyBox(size,box);
    std::cout<<multiplyBox<<"\n"<<text<<"\n"<<multiplyBox;
}

void cyrillaCombat(std::vector <Characters>& allCharacters,std::vector <CharacterAbilities>& characterAbility, Monster &thisMonster, int &currentCharacter)
{
    bool whileLoop = true;
    bool abilityCooldown = true;
    int opt;

    while(whileLoop)
    {
        textBox(thisMonster.getMonsterDescription());
        std::cout<<"\n~~~~~~~~~~~~~~~~~~~~\n1.-Attack\n2.-Inventory\n9.-END PROGRAM\nOPT: ";
        std::cin>>opt;
        if(opt == 1)
        {
         int attackDamage = allCharacters[currentCharacter].cyrillaAttack();
         std::cout<<"You attack with your sword dealing " << attackDamage << " damage to the " << thisMonster.getMonsterName();
         thisMonster.substractHealth(attackDamage);
         pressAnyKey();
            
        }else if(opt == 2)
        {
             
        }
    
    }
}

void useAbilities(std::vector <CharacterAbilities>& characterAbility, bool &abilityCooldown)
{
    int abilityOption;
    int useAbility;
    bool whileLoop = true;

    while(whileLoop)
    {
    textBox("ABILITIES");
    std::cout<<"\n";
    getCharacterAbilities(characterAbility);
    std::cout<<"\n\nOPT: ";
    std::cin >> abilityOption;
    system("cls");
    textBox(characterAbility[abilityOption-1].getAbilityDescription());
    std::cout<<"\nUse Ability?\n1.YES\t2.NO\n\nOPT: ";
    std::cin>>useAbility;
    switch(useAbility)
    {
    case 1:
    if(abilityCooldown)
    {
        int buff = characterAbility[0].getAbilityModifier();
        std::cout<<"Cyrilla gathers all the strenght within her using her " << characterAbility[abilityOption].getAbilityName();
        allCharacters[currentCharacter].strenghtCyrilla(buff);
        whileLoop2 = false;
    }else
    {
        std::cout<<"Cyrilla is exhausted and can't use "<<characterAbility[abilityOption].getAbilityName()<<"right now";
        whileLoop2 = false;
    }
    break;
    case 2:
    whileLoop2 = false;
    break;
    default:
    std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
    pressAnyKey();
    break;
    }

    }
}