// Main file
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector2.h"
#include "RigidBody.h"
#include "Score.h"

/*
Zorg ervoor dat je punten kunt krijgen voor het vangen of ontwijken, afhankelijk van je gekozen spelvorm. 
Zorg ervoor dat je score ergens in beeld zichtbaar is.
- SCORE CLASS

Zorg ervoor dat de game eindigt met een win/verlies scherm.
- WINSCREEN FUNCTION
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 960), "Parachute");
    auto player = Player{ 5 };
    Enemy enemies[20];
    for (int i = 0; i < 20; i++) 
    {
        int range = 1200 - 80 + 1;
        int num = rand() % range + 200;
        enemies[i].enemyPos.x = num;
        enemies[i].enemyPos.y = -200 - i * 250;
        enemies[i].timer = num - 800;
    }
    auto score = Score{};
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        player.updatePlayer(window);
        for (int i = 0; i < 20; i++) 
        {        
            enemies[i].updateEnemy(window);
            enemies[i].checkCollion(player, score);
        }

        window.display();
    }
    return 0;
}
