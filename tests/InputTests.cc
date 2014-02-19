/* 
 * File:   InputTests.cc
 * Author: Jeremy Shantz
 *
 * Created on 18-Feb-2014, 4:22:55 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Game.h"

/*
 * Simple C++ Test Suite
 */

const std::string NATURAL_DECK_OF_81_CARDS = "input.txt";
const std::string MV_SAMPLE_INPUT = "sample-input";

void testKnownGoodInput() {
    
    int expected = 1080;
    Game game = Game(NATURAL_DECK_OF_81_CARDS);
    int actual = game.play();
    if (expected == actual) {
        std::cout << "%TEST_PASSED% time=0 testname=testKnownGoodInput (InputTests) message=" << std::endl;
    }
    else  {
        std::cout << "%TEST_FAILED% time=0 testname=testKnownGoodInput (InputTests) message=set count was: " << actual << std::endl;
    }
}

void testMVInput() {
    
    int expected = 1739;
    Game game = Game(MV_SAMPLE_INPUT);
    int actual = game.play();
    if (expected == actual) {
        std::cout << "%TEST_PASSED% time=0 testname=testMiovisionInput (InputTests) message=" << std::endl;
    }
    else  {
        std::cout << "%TEST_FAILED% time=0 testname=testMiovisionInput (InputTests) message=set count was: " << actual << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% InputTests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    
    std::cout << "%TEST_STARTED% testKnownGoodInput (InputTests)" << std::endl;
    testKnownGoodInput();
    std::cout << "%TEST_FINISHED% time=0 testKnownGoodInput (InputTests)" << std::endl;

    
    std::cout << "%TEST_STARTED% testMVInput (InputTests)" << std::endl;
    testMVInput();
    std::cout << "%TEST_FINISHED% time=0 testMVInput (InputTests)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

