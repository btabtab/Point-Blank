#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */

#include "../headers/sfml_variables_header.h"
#include "../headers/class_mouse.h"
#include "../headers/RAND_MOVE_HEADER.h"
#include "../headers/target_class.h"


using namespace std;

sf::VertexArray cameraline(sf::Lines, 4);// the line from the current point to the camera

sf::Clock time_elapsed; //main_clock


void draw()
{

    window.clear();
    window.draw(easy.body);
    window.draw(X_hair.body);

    window.display();
    window.setView(camera);

}

int main()
{
//camera.zoom(0.02);

X_hair.sprite_load_apply();

window.setMouseCursorVisible(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// ////////////////////////////////////////////

        easy.sprite_load_apply();
        easy.position = camera.getCenter();
        easy.shoot();

        X_hair.pos_apply();

        draw();

        /*this will randomize the rand function with a new seed dependant on the time passed
        since the program was started.*/
        srand(easy.life_time.getElapsedTime().asMilliseconds());

        window.setSize(sf::Vector2u(600, 600));

        /// ////////////////////////////////////////////
    }

    return 0;
}
