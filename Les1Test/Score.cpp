#include "Score.h"
Score::Score(sf::Font f): font(f), text("Score: ", font, 30)
{
}

// Displays the score in the top left of the screen, or
// displays the win screen when the game is over.
void Score::showScore(sf::RenderWindow& window)
{
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 50);
    sf::String scoreText = std::to_string(score);
    text.setString("Score: " + scoreText);

    // Displays win screen when the game ends.
    if (gameOver) {
        if (score == 1) {
            text.setString("Congrats! You got " + scoreText + " point!");
        }
        else if (score == 0) {
            text.setString(scoreText + " points... Better luck next time!");
        }
        else { text.setString("Congrats! You got " + scoreText + " points!"); }
        text.setCharacterSize(50);
        text.setPosition(150, 400);
    }
    
    window.draw(text);
}