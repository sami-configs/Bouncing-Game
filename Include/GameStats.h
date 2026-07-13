#pragma once

#include <SFML/Graphics.hpp>

class GameStats
{
    private: 
        sf::Font font_;

        sf::Text scoreText_;
        sf::Text livesText_;
        sf::Text highScoreText_;

        int score_;
        int lives_;
        int highScore_;
        
        public:
           GameStats();
           void Draw(sf::RenderWindow& window) const;

           void Setscore(int score);
           void Setlives(int lives);
           void SetHighScore(int highScore);    
           
           
           int Getscore() const;
           int Getlives() const;
           int GetHighScore() const;      
           void Reset();
};