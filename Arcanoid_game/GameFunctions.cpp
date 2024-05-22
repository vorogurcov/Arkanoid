#include "GameFunctions.h"
#include "Block.h"

namespace GameElements
{

    bool checkWallCollision(const sf::Shape& sh, const sf::RenderWindow& window) {
        sf::FloatRect shBounds = sh.getGlobalBounds();
        sf::Vector2u windowSize = window.getSize();

        if (shBounds.left < 0 || shBounds.top < 0 ||
            shBounds.left + shBounds.width > windowSize.x ||
            shBounds.top + shBounds.height > windowSize.y) {
            return true;
        }
        return false;
    }

    static Block* CreateOneBlock(sf::Vector2f size)
    {
        int num = rand() % 13;
        sf::Color BlockColor;
        if (num >= 0 && num < 5)
            return new WhiteBlock(size);
        else if (num >= 5 && num < 9)
            return new BlueBlock(size);
        else if (num >= 9 && num < 12)
            return new RedBlock(size);
        else
            return new MagentaBlock(size);
    }

    std::list<Block*> CreateBlocks()
    {
        sf::Vector2f size(80, 40);
        sf::Vector2f Position(0, 0);
        std::list<Block*> Blocks;
        for (size_t i = 0; i < 5; i++)
        {
            Position.x = 0;

            for (size_t j = 0; j < 10; j++)
            {
                Block* bl = CreateOneBlock(size);
                bl->setPosition(Position.x, Position.y);
                Blocks.push_back(bl);
                Position.x += 80;
            }
            Position.y += 40;
        }
        return Blocks;
    }

    bool checkCollision(const sf::Shape& shape1, const sf::Shape& shape2) {
        return shape1.getGlobalBounds().intersects(shape2.getGlobalBounds());
    }


}