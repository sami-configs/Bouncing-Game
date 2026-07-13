#include "Game.h"

#include<algorithm>


Game::Game() :
    window_(sf::VideoMode({600 , 800}), "Bounce")
{
    window_.setFramerateLimit(60);

}

bool Game::IsRunning() const
{
    return window_.isOpen();
}

void Game ::ProcessEvents()
{
    while (std::optional<sf::Event> event = window_.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window_.close();
        }
        
    }
    
}

void Game::Update()
{
    float deltaTime = clock_.restart().asSeconds();
     if (ballSpawnClock_.getElapsedTime().asSeconds() > 2)
     {
        balls_.emplace_back();
        ballSpawnClock_.restart();
     }
     
    paddle_.Move(deltaTime);
    for (Ball& ball : balls_)
    {
        ball.Move(deltaTime);
    }

    HandleCollisions();
    if (stats_.Getlives() <= 0)
    {
        Restart();
    }
    
}

void Game::Render()
{
    background_.Draw(window_);  
    // window_.clear();
    paddle_.Draw(window_);
    for (const Ball& ball : balls_)
    {
        ball.Draw(window_);
    }
    stats_.Draw(window_);
    window_.display();
}
void Game::HandleCollisions()
{
    sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();
    for (Ball& ball : balls_)
    {
        sf::FloatRect ballBounds = ball.GetGlobalBounds();     
        bool isColiding = ballBounds.findIntersection(paddleBounds).has_value();    
        if (isColiding && ball.GetDirection().y > 0)
        {
            ball.Bounce(); 
            stats_.Setscore(stats_.Getscore() + 1);
            sounds_.PlayBounceSound();

        }
    }
    int ballsMissed = (int)std::erase_if(balls_, [] (const Ball& ball) {return ball.IsOutside(); });
    if (ballsMissed > 0)
    {
        stats_.Setlives(stats_.Getlives() - ballsMissed);
    }
}
void Game::Restart()
{
    balls_.clear();
    ballSpawnClock_.restart();
    stats_.Reset();
}
