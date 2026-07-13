#include "Paddle.h"

Paddle::Paddle() :

shape_({120 , 20}),
speed_(750)
{
    shape_.setFillColor(sf::Color::Green);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({600 * 0.50f, 800 * 0.85f});

}

void Paddle::Draw(sf::RenderWindow& window ) const
{
    window.draw(shape_);
}

void Paddle::Move(float deltaTime)
{
    float halfWidth = shape_.getSize().x / 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
    shape_.getPosition().x < 600 - halfWidth)
        {
            shape_.move({speed_ * deltaTime, 0});   
        }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
    shape_.getPosition().x > halfWidth)
        {
            shape_.move({-speed_ * deltaTime, 0});  
        }
        
}

sf::FloatRect Paddle::GetGlobalBounds() const
     {
        return shape_.getGlobalBounds();
     }