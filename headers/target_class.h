#ifndef TARGET_CLASS_H_INCLUDED
#define TARGET_CLASS_H_INCLUDED

#include "class_mouse.h"
#include "RAND_MOVE_HEADER.h"

class target
{

private:
    float avg_count;
    float time_avg;
    float time_total;

public:
    sf::Sprite body;
    sf::Texture texture;

    sf::Vector2f position;
    sf::Clock life_time;

    void sprite_load_apply()
    {
        if(!texture.loadFromFile("images/target2.bmp"));

        body.setTexture(texture);
    }


    void shoot()
    {
/*this subroutine will check if the cursor and target intersect, if they do
then the time since last target click will be printed in the console and the
target position will then be moved to another part of the screen within the
window boundaries*/
        if(X_hair.body.getGlobalBounds().intersects(body.getGlobalBounds()))/*collision check*/
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))/*mouse button check*/
            {
                time_total = time_total + life_time.getElapsedTime().asSeconds();/*counts total time for click delays*/
                avg_count++;/*increases the amount of numbers to divide by to find the AVG*/
                time_avg = time_total / avg_count;
                cout << "time (in seconds) = " << life_time.getElapsedTime().asSeconds() << " score = " << avg_count << " avg_time: " << time_avg << endl;

                /*this code will move the target
                to a random point on the screen*/
                rand_move_generate();
                position.x = rand() % 580 + 0;
                position.y = rand() % 580 + 0;
                body.setPosition(position.x, position.y);

                life_time.restart();



            }
        }

    }

};

target easy;

#endif // TARGET_CLASS_H_INCLUDED
