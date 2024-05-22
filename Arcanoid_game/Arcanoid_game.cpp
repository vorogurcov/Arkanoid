#include <SFML/Graphics.hpp>
#include "GameElements.h"
#include "IMovable.h"
namespace ge = GameElements;



int main()
{
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "Arcanoid", sf::Style::Close);
    
    ge::Ball startBall;
    std::vector<ge::Ball> Balls;
    std::list<ge::Block*> Blocks = ge::CreateBlocks();
    Balls.push_back(startBall);
    
    while (window.isOpen())
    {
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            

        }
            
        window.clear(sf::Color(217, 221, 220));

        for (auto& el : Blocks)
        {
            window.draw(*el);
        }


        for (auto& ball : Balls)
        {
            ball.move();
        }

        for (auto& ball : Balls)
        {
            if (checkWallCollision(ball, window))
                ball.Collide();
            else
            {
              
                for (std::list<ge::Block*>::iterator it = Blocks.begin();it != Blocks.end(); it++)
                {

                    if (checkCollision(ball, **it))
                    {
                        ball.Collide();
                        if ((**it).WasHitAndDestroyed())
                            Blocks.remove(*it);
                        break;
                    }
                    
                }
            }
                
        }
        
        for (auto& ball : Balls)
        {
            window.draw(ball);
        }

        window.display();
         
        sf::Time tm(sf::seconds(0.01));
            
        sf::sleep(tm);

        

           

    }

    return 0;
}