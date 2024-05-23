#include <SFML/Graphics.hpp>
#include "GameElements.h"
#include "IMovable.h"

namespace ge = GameElements;

void LoseStickness(ge::Ball& b,int& time)
{
    ge::Carriage* car = ge::Carriage::getInstance();
    if (time > 500) {
        car->MakeNotSticky();
        b.MakeNotSticky();
        time = 0;
    }
}

int main()
{
    srand(time(0));
    int PlayerScore = 0;
    int time = 0;
   

    sf::RenderWindow window(sf::VideoMode(800, 800), "Arcanoid", sf::Style::Close);
    ge::Ball startBall;
    ge::Ball::setBalls();
    std::vector<ge::Ball>& Balls = ge::Ball::getBalls();
    std::list<ge::Block*> Blocks = ge::CreateBlocks();
    std::list<ge::Bonus*> Bonuses;
    Balls.push_back(startBall);

    
    ge::Carriage* carriage = ge::Carriage::getInstance();

    sf::Font font;
    if (!font.loadFromFile("D:/Projects/cpp/Arcanoid_game/font/Roboto-Black.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    while (window.isOpen())
    {
     
        sf::Text text;
        text.setString(std::to_string(PlayerScore));
        text.setCharacterSize(30);
        text.setPosition(750, 750);
        text.setFont(font);
        text.setFillColor(sf::Color::Black);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            

        }
            
        window.clear(sf::Color(217, 221, 220));

        window.draw(*carriage);

        for (auto& el : Blocks)
        {
            window.draw(*el);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            carriage->MoveLeft();
            carriage->move();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            carriage->MoveRight();
            carriage->move();
        }

        
        for (auto& ball : Balls)
        {
            if (!ball.isSticky)
                ball.move();
            else {
                ball.setPosition(carriage->getPosition());
                time++;
                LoseStickness(ball,time);

            }
        }

        for (auto& bonus : Bonuses)
        {
            (*bonus).move();
        }

        for (auto& ball : Balls)
        {
            if (checkCollision(ball, *carriage))
            {
                float overlap = (ball.getPosition().x - carriage->getPosition().x) - (carriage->getSize().x / 2.f);
                float reflectionAngle = (overlap / (carriage->getSize().x / 2.f)) * 60.f; 
                if (!carriage->isSticky())
                    ball.Collide(reflectionAngle);
                else
                    ball.Stick();
            }
            else if (checkWallCollision(ball, window))
            {
                if (ball.getPosition().x - ball.getRadius() <= 0 || ball.getPosition().x + ball.getRadius() >= 800) {
                    ball.Collide(180 - 2 * ball.getDirection());
                }
                if (ball.getPosition().y - ball.getRadius() <= 0) {
                    ball.Collide(-180);
                }
                if (ball.getPosition().y - ball.getRadius() >= 800) {

                    if (carriage->HasTemporaryBottom != true)
                    {
                        carriage->Shrink();
                        ball.setPosition(400.f, 700.f);
                        ball.Collide(90.f);
                    }
                    else
                    {
                        int WillDissapear = rand() % 4;
                        if (WillDissapear == 1)
                            carriage->HasTemporaryBottom = false;
                        ball.Collide(180.f);
                    }
                    
                }
                if (ball.getPosition().y - ball.getRadius() <= 0) {
                    ball.setPosition(ball.getPosition().x, ball.getRadius());
                    ball.Collide(-180);
                }
            }
            else
            {
              
                for (std::list<ge::Block*>::iterator it = Blocks.begin();it != Blocks.end(); it++)
                {

                    if (checkCollision(ball, **it))
                    {
                        ball.Collide(90);
                        PlayerScore++;
                        if ((**it).getFillColor() == sf::Color::Yellow)
                            ball.setSpeed(ball.getSpeed() + 0.05);
                        if ((**it).WasHitAndDestroyed())
                        {
                            Blocks.remove(*it);
                            PlayerScore += 5;
                            break;
                        }
                        if ((**it).GetBonus() != NULL)
                            Bonuses.push_back((**it).GetBonus());
                        break;
                    }
                    
                }
            }
                
        }
        
        for (auto& ball1 : Balls)
        {
            for (auto& ball2 : Balls)
            {
                if (ge::checkCollision(ball1, ball2))
                {
                    float overlap = (ball1.getPosition().x - ball2.getPosition().x) - (ball2.getRadius() / 2.f);
                    float reflectionAngle = (overlap / (ball2.getRadius() / 2.f)) * 60.f;
                    ball1.Collide(-reflectionAngle);
                    ball2.Collide(reflectionAngle);
                }
            }
        }

        std::list<ge::Bonus*>::iterator it = Bonuses.begin();
        while(it != Bonuses.end() )
        {
            if (ge::checkCollision(**it, *carriage))
            {
                carriage->collidesWithBonus(*it);
                it = Bonuses.erase(it);

            }
            else if (ge::checkWallCollision(**it, window))
            {
                delete* it;
                it = Bonuses.erase(it);

            }
            else
                ++it;
            
        }

        for (auto& ball : Balls)
        {
            window.draw(ball);
        }
        for (auto& bonus : Bonuses)
        {
            window.draw(*bonus);
        }
        window.draw(text);

        window.display();
         
        sf::Time tm(sf::seconds(0.001));
            
        sf::sleep(tm);

        

           

    }

    return 0;
}