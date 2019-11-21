#ifndef CLASS_MOUSE_H_INCLUDED
#define CLASS_MOUSE_H_INCLUDED
#include <SFML/System.hpp>

#include <iostream>

class mouse
{
public:
    sf::Vector2f position;/*position of cursor*/

    sf::Sprite body;
    sf::Texture texture;
    sf::Image image;

    /*this code will load a image, make it transparent and then it will apply
    the newly modified image to a sprite that will be used to then work with
    display and collision of the mouse cursor against the target.*/

    void sprite_load_apply()
    {
        if(!image.loadFromFile("images/cursor.bmp"));

        /*this FOR loop will run through the image's rows downward after
        the embedded for loop goes through the row and makes it transparent.*/

        for(int y = 0; y <=30; y++)
        {
            for(int x = 0; x <= 30; x++)
            {
                std::cout << "x = " << x << " y = " << y << std::endl;
                /*this line will, if pixel colour is black
                make that pixel completely transparent.*/
                if(image.getPixel(x, y) == sf::Color::Black)
                    image.setPixel(x, y, sf::Color(0, 0, 0, 0));
            }
        }

        texture.loadFromImage(image);/*loads the image in memory as a texture*/
        body.setTexture(texture);/*loads the texture into the sprite*/

        body.setOrigin(15, 15);/*the centre of the sprite used for the cursor.*/
    }

    void pos_apply()
    {
        /*this will set the position of the cursor sprite relative to the position of
        the window.*/
        body.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
    }
};

mouse X_hair;/*abbreviation of cross hair (cross=X)
#endif // CLASS_MOUSE_H_INCLUDED
