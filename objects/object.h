#pragma once

#include <SFML/Graphics.hpp>

class Object {
public:
    virtual ~Object() = default;
private:
    virtual std::vector<sf::Sprite> getSpriteVector(sf::Vector2i window_size) = 0;
<<<<<<< HEAD
};
=======
};
>>>>>>> 28fdcd3e57a0ae174faaa878338147c54890bb09
