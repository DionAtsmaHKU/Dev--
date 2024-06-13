// Dion Atsma, 1a, Game Development
// This program is a game where the goal is for the player to catch a number
// of falling parachute guys. The player moves with the arrow keys, and gets
// a point for every guy caught, which is displayed at the end of the game.
// A total of 20 guys fall from the sky, so 20 is the maximum score.

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Circle.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector2.h"
#include "RigidBody.h"
#include "Score.h"

int main()
{
    // Initialising window
    sf::RenderWindow window(sf::VideoMode(1280, 960), "Parachute");

    // Initialising sprites
    sf::Texture bgTexture;
    sf::Texture enemyTexture;
    sf::Texture playerTexture;
    bgTexture.loadFromFile("Sprites/ParachuteBG.png");
    enemyTexture.loadFromFile("Sprites/ParachuteGuy.png");
    playerTexture.loadFromFile("Sprites/ParachuteBoat.png");
    sf::Sprite bgSprite(bgTexture);
    sf::Sprite enemySprite(enemyTexture);
    sf::Sprite playerSprite(playerTexture);

    // Initialising player and enemies, enemies get spawned at random x-positions
    auto player = Player{playerSprite};
    Enemy enemies[20];
    for (int i = 0; i < 20; i++) 
    {
        int range = 1200 - 80 + 1;
        int num = rand() % range + 200;
        enemies[i].enemyPos.x = num;
        enemies[i].enemyPos.y = -200 - i * 250;
        enemies[i].timer = num - 200;
        enemies[i].enemySprite = enemySprite;
    }

    // Initialising font and score
    sf::Font font;
    font.loadFromFile("Fonts/RetroGaming.ttf");
    auto score = Score{font};
    
    // Run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(bgSprite);
        score.showScore(window);
        player.updatePlayer(window);

        for (int i = 0; i < 20; i++) 
        {        
            enemies[i].updateEnemy(window);
            enemies[i].checkCollion(player, score);
        }
        if (enemies[19].enemyPos.y > 1100) { // gameOver after all 20 enemies have fallen
            score.gameOver = true;
        }
        
        window.display();
    }
    return 0;
}
