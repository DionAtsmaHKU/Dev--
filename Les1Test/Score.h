#pragma once
#include <SFML/Graphics.hpp>

// The score class contains the amount of enemies the player has caught in the
// score integer, and displays this score on the screen during the game,
// and a win screen after the game.
class Score
{
public:
	int score = 0;
	bool gameOver = false;

	sf::Text text;
	sf::Font font;

	Score(sf::Font f);
	void showScore(sf::RenderWindow& window);
};

