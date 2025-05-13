
#include <iostream>
#include <string>
#include <conio.h>

class Characters
{
    private:
    std::string name;
    std::string background;
    int health;
    bool setToCyrilla;
    bool setToPetrou;
    bool setToEphraim;

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

};

class Rooms
{
    private:
    std::string roomName;
    std::string roomDescription;
    std::string extraDescription;

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
};

void titleScreen();
void gameStart(Characters *allCharacters,int size);
void getCharacterNames(Characters *allCharacters, int size);
void getCharacterInfo(Characters *allCharacters, int size);
void pressAnyKey();

int main()
{
    Characters cyrilla("Cyrilla","A young knight from an Erstonian noble family, since she was young Cyrilla always knew it was her calling to protect her people,one achievement after the other Cyrilla quickly cemented herself as an iconic knight, she now wants to go afterthe biggest achievement there is, coming out of the Necromancer's dungeon alive.",30);
    Characters petrou("Petrou","A humble botanist from Erstonia, Petrou noticed the soil was being poisoned by the necromancer's lair, he decided to embark on a journey to stop the necromancer, if nobody does anything, Erstonia's crops and water will be forever poisoned",15);
    Characters ephraim("Ephraim","Ephraim grew up in a cult that worships a cruel goddess that asks that their followers give her their eyes as an act of faith, in exchange for guiding their path, so Ephraim has always lived in communion with the dark, having always been talented in the arcane arts, he was asked to go to ne necromancer's lair with no further instructions",10);

    Characters allCharacters[3] = {cyrilla,petrou,ephraim};

    Rooms initialRoom("Dungeon Beginning","You finished going down the stairs and find yourself in a dimly lit room, at first glance it seems quite empty","You notice a small chest sitting in the middle of the room ");
    
    gameStart(allCharacters,3);

    return 0;
}

void titleScreen()
{
    std::string opt;
    std::cout<<"//////////NECROMANCER//////////\n\n1.-Start\n2.-Exit\n\nopt: ";
    std::cin>>opt;

}

void gameStart(Characters *allCharacters,int size)
{
    bool whileLoop = true;
    int opt;
    std::cout<<"\n~~~~~OPTIONS~~~~~\n1.-Select Character\n2.-View Character Details\n9.-Exit Program\n\nOPT: ";
    std::cin>>opt;
   
    
    if(opt==1)
    {
        while(whileLoop)
        {
        system("cls");
        std::cout<<"\nYou can enter the dungeon with the following characters\n";
        getCharacterNames(allCharacters,size);
        std::cout<<"\n\nOPT: ";
        std::cin>>opt;
        switch(opt)
        {
        case 1:
        std::cout<<"You chose Cyrilla as your character";
        allCharacters[1].selectCyrilla();
        whileLoop = false;
        break;
        case 2:
        std::cout<<"You chose Petrou as your character";
        allCharacters[2].selectPetrou();
        whileLoop = false;
        break;
        case 3:
        std::cout<<"You chose Ephraim as your character";
        allCharacters[3].selectEphraim();
        whileLoop = false;
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
    }
    

}

void getCharacterNames(Characters *allcharacters, int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<i+1<<".-"<<(allcharacters+i)->getName()<<"\n";
    }
    std::cout<<"\n9.-END PROGRAM";
}

void getCharacterInfo(Characters *allCharacters, int character)
{

}

void pressAnyKey()
{
    std::cout<<"PRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");
}