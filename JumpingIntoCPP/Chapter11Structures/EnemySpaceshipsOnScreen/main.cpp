/*

Creator: Shaun McRae
Jumping into C++ by Alex Allain
Chapter 11 Structures
Problem 2

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct enemySpaceship
{
    int name;
    int x_coordinate;
    int y_coordinate;
    int power;
    int speedX;
    int speedY;
    bool tracker = 0;
};

enemySpaceship getShips(int i)
{
    enemySpaceship ship;
    ship.name = i;
    ship.x_coordinate = rand () % 1024;
    ship.y_coordinate = rand () % 768;
    ship.power = rand () % 20;
    ship.speedX = rand () % 100;
    ship.speedY = rand () % 100;
    if (ship.speedX % 2 == 0)
        ship.speedX *= -1;
    if (ship.speedY % 2 == 0)
        ship.speedY *= -1;
    return ship;
};



int main()
{
    srand(time(NULL));
    enemySpaceship ships[10];
    int offScreen;
    for (int i = 0; ; i++)
    {
        for (int j = 0; j < i && j < 10; j++)
        {
            ships[j].x_coordinate += ships[j].speedX;
            ships[j].y_coordinate += ships[j].speedY;
            if (ships[j].x_coordinate < 0 || ships[j].x_coordinate > 1024 ||
                ships[j].y_coordinate < 0 || ships[j].y_coordinate > 768)
            {
                ships[j].tracker = 1;
            }
        }
        if (i < 10)
            ships[i] = getShips (i);
        for (int j = 0; j < i && j < 10; j++)
        {
            if (ships[j].tracker == 0)
            {
                cout << "Name: " <<ships[j].name << endl;
                cout << "X: "<< ships[j].x_coordinate << endl;
                cout << "Y: " << ships[j].y_coordinate << endl;
            }

        }
        if (i > 9)
        {
            for (int j = 0; j < 10; j++)
            {
                if (ships[j].tracker)
                {
                    offScreen++;
                }
            }
            if (offScreen != 10)
                offScreen = 0;
            else
                return 0;
        }
    }
}
