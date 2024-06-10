// Main file
#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Player.h"
#include "Vector2.h"
#include "RigidBody.h"
#include <SFML/Graphics.hpp>

/*
Zorg ervoor dat je een speler hebt die aan de onderkant heen en weer kan bewegen door middel van pijltjestoetsen.
- PLAYER CLASS

Zorg ervoor dat bovenin het scherm objecten (enemies) spawnen die heen en weer bewegen terwijl ze naar beneden vallen.
- ENEMY CLASS   

Zorg ervoor dat zowel de speler als de enemies versnellen (en vertraging) door middel van forces en friction.
- VECTOR2 CLASS, RIGIDBODY CLASS

Zorg ervoor dat er onderin collision is tussen de speler en de objecten.
- COLLISION CALC FUNCTION

Zorg ervoor dat je punten kunt krijgen voor het vangen of ontwijken, afhankelijk van je gekozen spelvorm. 
Zorg ervoor dat je score ergens in beeld zichtbaar is.
- SCORE CLASS

Zorg ervoor dat de game eindigt met een win/verlies scherm.
- WINSCREEN FUNCTION

Zorg ervoor dat je een eigen implementatie gebruikt van de wiskundige principes, 
        zoals een eigen Vector2 class en Rigidbody. Je mag van SFML enkel de 'setters' (zoals setPosition) 
        gebruiken als het gaat om berekeningen, de rest 
        (zoals vermenigvuldigen, optellen, addforce, etc) moet in je eigen implementatie gebeuren. 
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    auto testRectangle = Rectangle{ 100, 75 };
    auto testCircle = Circle{ 30 };
    auto player = Player{ 5 };
    
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

        // testRectangle.draw(window);
        // testCircle.draw(window);
        player.updatePlayer(window);
        window.display();
    }
    return 0;
}
