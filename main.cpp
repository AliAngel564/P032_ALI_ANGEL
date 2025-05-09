
#include <iostream>
#include <string>

class Characters
{
    private:
    std::string name;
    std::string background;
    int health;
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
   

};

int main()
{
    Characters cyrilla("Cyrilla","A young knight from an Erstonian noble family, since she was young Cyrilla always knew it was her calling to protect her people,one achievement after the other Cyrilla quickly cemented herself as an iconic knight, she now wants to go afterthe biggest achievement there is, coming out of the Necromancer's dungeon alive.",30);
    
    std::cout<<cyrilla.getBackground();

    return 0;
}