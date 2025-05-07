
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
    Characters Cyrilla("Cyrilla",30,"knight");
    
}