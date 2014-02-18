/* 
 * File:   main.cpp
 * Author: Jeremy Shantz
 *
 * Created on February 17, 2014, 2:03 PM
 */

#include "Game.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{     
        if (argc < 2)
        {
                std::cout << "Provide the path to an input file." << endl;
                return -1;
        }

        std::string input(argv[1]);

        Game game = Game();

        return game.Play(input);	
}
