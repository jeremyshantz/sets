/* 
 * File:   main.cpp
 * Author: Jeremy Shantz
 *
 * Created on February 17, 2014, 2:03 PM
 */

#include "Game.h"
#include <cstdlib>
#include <iostream>

/*!
 Entry point of the application. 
 */
int main(int argc, char* argv[])
{     
        // Caller must provide the path to an input file
        if (argc < 2)
        {
                std::cout << "Provide the path to an input file." << std::endl;
                return -1;
        }

        std::string input(argv[1]);

        Game game = Game(input);

        return game.play();	
}
