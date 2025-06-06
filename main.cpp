
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
    std::string attackAction;
    int health;
    bool setToCyrilla = false;
    bool setToPetrou = false;
    bool setToEphraim = false;
    int damageFloor;
    int damageCeiling;

    public:
    Characters(std::string usrName = "Default", std::string usrBackground = "Default",std::string usrAttackAction = "Default" ,int usrHealth = 0, int usrDamageFloor = 0, int usrDamageCeiling = 0)
    {
        name = usrName;
        background = usrBackground;
        attackAction = usrAttackAction;
        health = usrHealth;
        damageFloor = usrDamageFloor;
        damageCeiling = usrDamageCeiling;
    }
    std::string getName()
    {
        return name;
    }
    std::string getBackground()
    {
        return background;
    }
    std::string getAttackAction()
    {
        return attackAction;
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
        damageCeiling = damageCeiling + abilityModifier;
        damageFloor = damageFloor + abilityModifier;
    }
    int characterAttack()
    {  
        srand(time(0));
        int damage = rand() % (damageCeiling - damageFloor +1) + damageFloor;

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
    std::string ephraimDescription;
    std::string ephraimExtraDescription;

    public:
    Rooms(std::string usrRoomName = "Default", std::string usrDescription = "Default",std::string usrExtraDescription = "DEFAULT",std::string usrEphraimDescription = "DEFAULT",std::string usrEphraimExtra = "DEFAULT")
    {
        roomName = usrRoomName;
        roomDescription = usrDescription;
        extraDescription = usrExtraDescription;
        ephraimDescription = usrEphraimDescription;
        ephraimExtraDescription = usrEphraimExtra;
    }
    std::string getRoomName()
    {
        return roomName;
    }
    std::string getRoomDescription()
    {
        return roomDescription;
    }
    std::string getExtraDescription()
    {
        return extraDescription;
    }
    std::string getEphraimDescription()
    {
        return ephraimDescription;
    }
    //añadir getters que faltan
};

class Monster
{
    private:
    std::string monsterName;
    std::string monsterDescription;
    std::string monsterAttackAction;
    std::string monsterCue;
    int monsterHealth;
    int damageFloor;
    int damageCeiling;

    public:
    Monster(std::string usrName="MONSTER",int usrHealth = 10, std::string usrDescription = "DEFAULT",std::string usrMonsterAttackAction = "default" ,std::string usrCue = "DEFAULT", int usrDamageFloor = 0, int usrDamageCeiling = 0)
    {
        monsterName = usrName;
        monsterHealth = usrHealth;
        monsterDescription = usrDescription;
        monsterAttackAction = usrMonsterAttackAction;
        monsterCue = usrCue;
        damageFloor = usrDamageFloor;
        damageCeiling = usrDamageCeiling;
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
    std::string getMonsterAttack()
    {
        return monsterAttackAction;
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



//We declared the functions that we're going to use throughout the program
void titleScreen(std::vector<Characters>& allCharacters);
void gameStart(std::vector<Characters>& allCharacters);
void getCharacterNames(std::vector<Characters>& allCharacters);
void getCharacterInfo(std::vector <Characters>& allCharacters, int character);
void textBox(std::string text);
void combatHealth(std::vector <Characters>& allCharacters, Monster &thisMonster, int &currentCharacter);
void pressAnyKey();
void combatEncounter(std::vector <Characters>& allCharacters, Monster &thisMonster, int &currentCharacter);
void monsterAttack(Monster &thisMonster);
void setCurrentCharacter(std::vector <Characters>& allCharacters, int &currentCharacter);

int main()
{
    int currentCharacter;
    std::string playerOpt;
    bool whileLoop = true;
    bool whileLoop2 = true;

    Characters cyrilla("Cyrilla","A young knight from an Erstonian noble family, since she was young Cyrilla always knew it was her calling\n to protect her people,one achievement after the other Cyrilla quickly cemented herself as an iconic knight, she now wants\n to go after the biggest achievement there is, coming out of the Necromancer's dungeon alive.","You attack with your sword",25,8,10);
    Characters petrou("Petrou","A humble botanist from Erstonia, Petrou noticed the soil was being poisoned by the necromancer's lair, he decided to embark on a \njourney to stop the necromancer, if nobody does anything, Erstonia's crops and water will be forever poisoned","You attack with your bare fists" ,20,4,9);
    Characters ephraim("Ephraim","Ephraim grew up in a cult that worships a cruel goddess that asks that their followers\n give her their eyes as an act of faith, in exchange for guiding their path, so Ephraim has always lived\n in communion with the dark, having always been talented in the arcane arts, he was asked to go to the necromancer's lair\n with no further instructions","You cast a spell" ,23,8,10);

    std::vector <Characters> allCharacters = {cyrilla,petrou,ephraim};
    allCharacters.shrink_to_fit();

    Monster undeadAdventurer("Undead Adventurer",15,"You see what once was a joyful adventurer, they look gaunt, they fell to the\ncurse of the Necromancer, you have to put them out of their misery","attacks with his broken sword" ,"You hear heavy footsteps, someone is walking towards you, the footsteps sound clumsy and uncoordinated\n must be one of the many undead that guard this dungeon",2,5);

    Rooms initialRoom("Dungeon Beginning","Down the stairs you find yourself in a dimly lit room, at first glance it seems quite empty","You notice two doors opposite to each other at the end of the room, one on the right side, the other on the left side.","You finished going down the stairs, as your foot leaves the last step you hear your footstep\nreverberate, the way the sound travels in this room makes you think its small","You pace around the room while listening intently, you use your staff to asses the terrain\na few steps into the room your staff hits something its a door, you keep going and hit another door");

    Rooms leftRoom1("Weapons Room", "You slowly open the door and peek through the gap, it looks like the coast is clear","You notice a door straight ahead, it's your only way of moving forward","idk","idk");

    Rooms rightRoom1("Butchery","As you open the door a foul stench overwhelms you, this room resembles a butchery with meat hooks and metal tables","Amidst all the gore you can see a door at the end of the room, it's your only way forward","idk","idk");

    std::vector <Rooms> leftRooms = {leftRoom1};
    std::vector <Rooms> rightRooms = {rightRoom1};
    
    titleScreen(allCharacters);
    setCurrentCharacter(allCharacters,currentCharacter);
    //combatEncounter(allCharacters,cyrillaAbilities, undeadAdventurer, currentCharacter);
    if(currentCharacter == 0 || currentCharacter == 1)
    {
    while(whileLoop)
    {
    textBox("You've been traveling by horse for days now, just when you're starting to lose hope you finally see it, the necromancer's lair");
    std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
    std::cin>>playerOpt;
    if (playerOpt == "1")
    {
        system("cls");
        whileLoop = false;
        playerOpt = "";
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop = true;
    while(whileLoop)
    {
    textBox("You get down from your horse and tie it to a nearby tree, finally, you head toward the lair's entrance");
    std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
    std::cin>>playerOpt;
    if(playerOpt =="1")
    {
        system("cls");
        whileLoop = false;
        playerOpt = "";
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop = true;
    while(whileLoop)
    {
    system("cls");
    textBox("You reach what looks like a mine entrance, but a lot smaller, there's a set of stairs directly after the entrance");
    std::cout<<"\n\nDO YOU WANT TO HEAD INTO THE NECROMANCER'S LAIR?";
    std::cout<<"\n\n1.-Enter the dungeon\n2.-Go back home\n9.-End Program\nOPT: ";
    std::cin>>playerOpt; 
    if(playerOpt == "1")
    {
        system("cls");
        whileLoop = false;
        playerOpt = "";
    }else if(playerOpt == "2")
    {
        system("cls");
        textBox("The lair's heavy atmosphere weighs down on you, suddenly you begin to think about the people you love most, you decide risking your life isn't worth it");
        pressAnyKey();
        textBox("You head back to your horse and ride towards Erstonia, maybe a brave enough person will banish the curse once and for all, but that person isn't you");
        pressAnyKey();
        textBox("ENDING NO 1. THE COWARD'S ENDING");
        return 0;  
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop= true;
    while(whileLoop)
    {
    textBox("You start going down the stairs, you can't help but wonder what awaits you once you reach the end");
    std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
    std::cin>>playerOpt;
    if(playerOpt == "1")
    {
        system("cls");
        whileLoop = false;
        playerOpt = "";
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop = true;
    while(whileLoop)
    {
    std::cout<<initialRoom.getRoomName();
    std::cout<<"\n";
    textBox(initialRoom.getRoomDescription());
    std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
    std::cin>>playerOpt;
    if(playerOpt == "1")
    {
        system("cls");
        whileLoop = false;
        playerOpt = "";
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop = true;
    while(whileLoop)
    {
    textBox(initialRoom.getExtraDescription());
    std::cout<<"\n\nWHAT DOOR DO YOU WANT TO GO THROUGH?\n1.-LEFT DOOR\n2.-RIGHT DOOR\n9.-EXIT PROGRAM\nOPT: ";
    std::cin>>playerOpt;
    //Start of left door thingy
    if(playerOpt == "1")
    {
        playerOpt = "";
        whileLoop = false;

        while(whileLoop2)
        {
        system("cls");
        std::cout<<leftRooms[0].getRoomName();
        std::cout<<"\n";
        textBox(leftRooms[0].getRoomDescription());
        std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            system("cls");
            whileLoop2 = false;
            playerOpt = "";
        }else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
        }
        whileLoop2 = true;
        
        std::cout<<leftRooms[0].getRoomName()<<"\n";
        textBox("You enter the room carefully, closing the door behind you. Suddenly, you see something rise from a corner of the room, it looks like a person");
        pressAnyKey();
        textBox("BATTLE START");
        pressAnyKey();
        combatEncounter(allCharacters,undeadAdventurer,currentCharacter);

        while(whileLoop2)
        {
        textBox("The adventurer plummets to the ground, you decide not to take anything from their body as a sign of respect");
        std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            system("cls");
            whileLoop2 = false;
            playerOpt = "";
        }else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
        }

        whileLoop2 = true;
        while (whileLoop2)
        {
        std::cout<<leftRooms[0].getRoomName()<<"\n";
        textBox(leftRooms[0].getExtraDescription());
        std::cout<<"\n\n1.-Go through the door\n9.-End Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            system("cls");
            whileLoop2 = false;
            playerOpt = "";
        }else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
        }

        whileLoop2 = true;
        while(whileLoop2)
        {
        textBox("You get to the door and open it, the next room is completely empty, aside from a single door to the right of the room");
        std::cout<<"\n\n1.-Go through the door\n9.-End Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            system("cls");
            whileLoop2 = false;
            playerOpt = "";
        }else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
        }

        whileLoop2 = true;
        while(whileLoop2)
        {
        textBox("You go towards the door, you can feel a heavy presence on the other side");
        std::cout<<"\n\n1.-Go through the door\n9.-End Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            system("cls");
            whileLoop2 = false;
            playerOpt = "";
        }else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }

        whileLoop2 = true;
        while(whileLoop2)
        {
        textBox("You slowly open the door. Before you is a throne room, and at the base of the throne, you see it, a black boned skeleton lying on the ground.");
        pressAnyKey();
        textBox("You approach it carefully, ready to attack, and the closer you get to it, the more you're filled with an undescribable dread");
        pressAnyKey();
        textBox("You get the closest you can, you're filled with dread and anguish, yet nothing happens.");
        pressAnyKey();
        textBox("The necromancer's body is on the floor, nothing but a hollow carcass, but you can feel his former might, each passing second feels like an eternity near his corpse");
        pressAnyKey();
        textBox("You dont know why he's dead, but you now understand you would've been no match for him when he was alive");
        pressAnyKey();
        textBox("You trace back your steps and return to Erstonia, taking his body with you, the journey is grueling, but you get there");
        pressAnyKey();
        textBox("You enter the town and are immediately stopped by its guards, you explain yourself and they lead you to the wizard's guild");
        pressAnyKey();
        textBox("The wizards commend you on your bravery. It seems the remnants of the necromancer's magic, still in corpse, were poisoning the land and rising the dead");
        pressAnyKey();
        textBox("You will be forever hailed as the town hero, even if you weren't the one to end him, you were the only one brave enough to enter his lair");
        pressAnyKey();
        textBox("THE END");
        std::cout<<"\nENDING NO.2 ~ Breaking the curse";
        whileLoop2 = false;
        }
        }

    }else if (playerOpt == "2")
    {
    system("cls");
    playerOpt = "";
    whileLoop = false;
    whileLoop2 = true;
    while(whileLoop2)
    {
    std::cout<<rightRooms[0].getRoomName()<<"\n";
    textBox(rightRooms[0].getRoomDescription());
    std::cout<<"\n\n1.-Continue\n9.-End Program\nOPT: ";
    std::cin>>playerOpt;
    if(playerOpt == "1")
    {
        playerOpt = "";
        whileLoop2 = false;
        system("cls");
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
    playerOpt = "";
    std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
    pressAnyKey();
    }
    }
    whileLoop2 = true;
    while(whileLoop2)
    {
    std::cout<<rightRooms[0].getRoomName()<<"\n";
    textBox("This room is as disturbing as it is empty, there is nothing to do here but admire, or cringe at the bloody mess before you");
    std::cout<<"\n\n1.Continue\n9.Exit Program\nOPT: ";
    std::cin>>playerOpt;
    if(playerOpt == "1")
    {
        playerOpt = "";
        whileLoop2 = false;
        system("cls");
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop2 = true;
    while (whileLoop2)
    {
    std::cout<<rightRooms[0].getRoomName()<<"\n";
    textBox(rightRooms[0].getExtraDescription());
    std::cout<<"\n\n1.Continue\n9.Exit Program\nOPT: ";
    std::cin>>playerOpt;
    if(playerOpt == "1")
    {
        playerOpt = "";
        whileLoop2 = false;
        system("cls");
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop2 = true;
    while(whileLoop2)
    {
        textBox("You slightly open the next door, the next room seems to be a kitchen, with a large cauldron and a dining table");
        std::cout<<"\n\n1.Continue\n9.Exit Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
    {
        playerOpt = "";
        whileLoop2 = false;
        system("cls");
    }else if(playerOpt == "9")
    {
        return 0;
    }else
    {
        playerOpt = "";
        std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
        pressAnyKey();
    }
    }
    whileLoop2 = true;
    while(whileLoop2)
    {
        textBox("You walk inside the room closing the door behind you, inside the room you notice a towering knight with their back toward you");
        pressAnyKey();
        textBox("They're holding a staff almost as tall as themself, using it like a cane, they are standing completely still");
        pressAnyKey();
        textBox("You cautiously walk around them, as you circle the knight you get in front of them, they have their visor all the way up");
        pressAnyKey();
        textBox("You are met with a blank expression and lifeless eyes, the knight is standing there, facing you, dead, but still standing");
        pressAnyKey();
        textBox("You notice a familiar crest on their chestplate, it's the mark of the Downom sistherhood, a respected group of mages. She's clutching a religious symbol near her chest with her free hand");
        pressAnyKey();
        textBox("You pay respects to the fallen sister towering over you and head on to the next room");
        std::cout<<"\n\n1.Continue\n9.Exit Program\nOPT: ";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            playerOpt = "";
            whileLoop2 = false;
            system("cls");
        }else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
    }
    whileLoop2 = true;
    while(whileLoop2)
    {
        textBox("You slowly open the door. Before you is a throne room, and at the base of the throne, you see it, a black boned skeleton lying on the ground.");
        pressAnyKey();
        textBox("You approach it carefully, ready to attack, and the closer you get to it, the more you're filled with an undescribable dread");
        pressAnyKey();
        textBox("You get the closest you can, you're filled with dread and anguish, yet nothing happens.");
        pressAnyKey();
        textBox("The necromancer's body is on the floor, nothing but a hollow carcass, but you can feel his former might, each passing second feels like an eternity near his corpse");
        pressAnyKey();
        textBox("You dont know why he's dead, but you now understand you would've been no match for him when he was alive");
        pressAnyKey();
        textBox("You look behind you to the previous room, the knight still standing there, lifeless, you come to the conclusion that it was her");
        pressAnyKey();
        textBox("She was the one to end the necromancer, at the cost of her life");
        pressAnyKey();
        textBox("You trace back your steps and return to Erstonia, taking the necromancer's body with you, the journey is grueling, but you get there");
        pressAnyKey();
        textBox("You enter the town and are immediately stopped by its guards, you explain yourself and they lead you to the wizard's guild");
        pressAnyKey();
        textBox("The wizards commend you on your bravery, but you tell them the truth. A member of the Downom sisterhood ended him");
        pressAnyKey();
        textBox("They commend you on your bravery anyways, they then send a letter to the Downom sisterhood letting them know what happened");
        pressAnyKey();
        textBox("It seems the remnants of the necromancer's magic, still in corpse, were poisoning the land and rising the dead");
        pressAnyKey();
        textBox("You and sister Brunhilde will be forever remembered as heroes");
        pressAnyKey();
        textBox("ENDING NO.3 ~~ THE TRUE HERO");
        return 0;
    }
    }
    }
    }else
    {
        whileLoop = false;
        textBox("You've been traveling by horse for days now, then you come to a sudden stop, the person tasked with taking you safely to the necromancer's lair speaks");
        pressAnyKey();
        textBox("-Looks like we're here! Let me help you get off the horse");
        pressAnyKey();
        textBox("You hear him get off the horse, he ten grabs you by the hand and leads you off the horse. You thank him.");
        pressAnyKey();
        textBox("-Hey, I never asked. How'd you lose your sight anyways?");
        pressAnyKey();
        textBox("You ignore his question and begin walking toward the dungeon using your staff to assess the terrain, you can feel a powerfull magic emanating from within. It feels magnetic");
        pressAnyKey();
        textBox("You hit the lair's entrance with your staff, you feel the dungeon calling your name.");
        std::cout<<"\n\nDO YOU WISH TO GO INSIDE THE DUNGEON?\n1.-YES\n2.-NO\n9.-EXIT PROGRAM\nOPT:";
        std::cin>>playerOpt;
        if(playerOpt == "1")
        {
            playerOpt = "";
            whileLoop2 = false;
            system("cls");
        }else if(playerOpt == "2")
        {
            system("cls");
            textBox("The lair's heavy atmosphere weighs down on you, suddenly you begin to feel immense dread");
            pressAnyKey();
            textBox("You head back to the person tending to the horse and ask him to take you back, you think your life isn't worth wasting even if it means upsetting your goddess.");
            pressAnyKey();
            textBox("ENDING NO 1. THE COWARD'S ENDING");
            return 0;
        return 0;  
        } else if(playerOpt == "9")
        {
            return 0;
        }else
        {
            playerOpt = "";
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
        whileLoop2 = false;
        while(whileLoop2)
        {

        }
    }
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
    std::string characterSelect;
    std::cout<<"~~~~~OPTIONS~~~~~\n1.-View Character Details\n2.-Select Character\n9.-Exit Program\n\nOPT: ";
    std::cin>>opt;
   
    
    if(opt=="2")
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
        
        if(characterSelect == "1")
        {
        textBox("You chose Cyrilla as your character");
        allCharacters[0].selectCyrilla();
        pressAnyKey();
        whileLoop = false;
        }else if(characterSelect == "2")
        {
        textBox("You chose Petrou as your character");
        allCharacters[1].selectPetrou();
        pressAnyKey();
        whileLoop = false;
        }else if(characterSelect == "3")
        {
        textBox("You chose Ephraim as your character");
        allCharacters[2].selectEphraim();
        pressAnyKey();
        whileLoop = false;
        }else if(characterSelect =="8")
        {
        system("cls");
        gameStart(allCharacters);
        }else if (characterSelect == "9")
        {
        whileLoop = false;
        }else
        {
        std::cout<<"INVALID OPTION, TRY AGAIN\n\n";
        pressAnyKey();
        }
        }
    }else if(opt=="1")
    {
        while(whileLoop)
        {
            int characterSelect = 0;
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

/*We use a string constructor to make a textbox*/
void textBox(std::string text)
{
    int size = text.size();
    char box = '~';

    std::string multiplyBox(size,box);
    std::cout<<multiplyBox<<"\n"<<text<<"\n"<<multiplyBox;
}

void combatEncounter(std::vector <Characters>& allCharacters, Monster &thisMonster, int &currentCharacter)
{
    bool whileLoop = true;
    bool abilityCooldown = true;
    std::string opt;

    
    while(whileLoop)
    {
        combatHealth(allCharacters, thisMonster, currentCharacter);
        textBox(thisMonster.getMonsterDescription());
        if(thisMonster.getMonsterHealth()<=0)
          {
            system("cls");
            std::cout<<"With a final attack, you take down the "<<thisMonster.getMonsterName();
            pressAnyKey();
            break;
            
          }else if (allCharacters[currentCharacter].getHealth()<=0)
          {
            std::cout<<"You were slain by the "<<thisMonster.getMonsterName();
          }
        std::cout<<"\n~~~~~~~~~~~~~~~~~~~~\n1.-Attack\n9.-END PROGRAM\nOPT: ";
        std::cin>>opt;
        if(opt == "1")
        {
          if(allCharacters[currentCharacter].getHealth() > 0 && thisMonster.getMonsterHealth() > 0)
          {
             int attackDamage = allCharacters[currentCharacter].characterAttack();
             std::cout<<allCharacters[currentCharacter].getAttackAction() <<" dealing " << attackDamage << " damage to the " << thisMonster.getMonsterName();
             thisMonster.substractHealth(attackDamage);
             pressAnyKey();
             if(thisMonster.getMonsterHealth()>0)
             {
             int monsterDamage = thisMonster.monsterAttack();
             monsterAttack(thisMonster);
             std::cout<<" dealing " << monsterDamage << " damage.";
             allCharacters[currentCharacter].substractHealth(monsterDamage);
             pressAnyKey();
             }
          }
        }else if (opt == "9")
        {
            exit(0);
        }else 
        {
            std::cout<<"INVALID OPTION, PLEASE TRY AGAIN";
            pressAnyKey();
        }
    }
}

void monsterAttack(Monster &thisMonster)
{
 std::cout<<"The "<<thisMonster.getMonsterName()<<" "<<thisMonster.getMonsterAttack();
}

void combatHealth(std::vector <Characters>& allCharacters, Monster &thisMonster, int &currentCharacter)
{
    std::cout<<allCharacters[currentCharacter].getName()<<" ~~~~HP: "<<allCharacters[currentCharacter].getHealth();
    std::cout<<" ~~~~"<<thisMonster.getMonsterName()<<" ~~~~HP: "<<thisMonster.getMonsterHealth()<<"\n\n";
}

