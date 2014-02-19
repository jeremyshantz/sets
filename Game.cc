/* 
 * File:   Game.cpp
 * Author: Jeremy Shantz
 * 
 * Created on February 17, 2014, 2:12 PM
 */

#include <cstdlib>
#include "Game.h"
#include "StringUtility.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

const std::string  S_CHAR = "s";
const int FAILED_TO_LOAD_HAND = -1;
std::string input;

Game::Game(std::string path)
{
    input = path;
}

Game::~Game()
{
}

int Game::play()
{
    std::vector<std::string> cards = loadCards(input);

    // If no cards were loaded, return failure code.
    if (cards.size() == 0)
    {
            return FAILED_TO_LOAD_HAND;
    }

    return generateSets(cards);
}

int Game::generateSets(std::vector<std::string> cards)
{
    int count = 0;

    // Loop through all combinations of cards
    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = i + 1; j < cards.size(); j++)
        {
            for (int k = j + 1; k < cards.size(); k++)
            {
                std::string card1 = cards[i];
                std::string card2 = cards[j];
                std::string card3 = cards[k];

                // Test each set for validity and print if valid
                if (validSet(card1, card2, card3))
                {
                    count = count + 1;
                    printSet(card1, card2, card3);
                }       
             }
        }
    }

  return count;
}

void Game::printSet(std::string card1, std::string card2,std:: string card3)
{
    std::cout << card1 << ";" << card2 << ";" << card3 << std::endl;
}

std::vector<std::string> Game::loadCards(std::string path)
{
    std::vector<std::string> list;
    std:: ifstream file(path.c_str());
    std::string line;

    // Read all non-empty lines into a vector
    while (std::getline(file, line))
    {
        if (line != "")
        {
            list.push_back(line);
        }
    }

    file.close();
    return list;
}

bool Game::validProperty(std::string val1, std::string val2, std::string val3)
{  
    // Let's be permissive in our comparison to account for different pluralization: eg. one oval; two ovals
    // Ensure all values end in an 's' if they don't already
    if (!StringUtility::endsWith(val1, S_CHAR))
    {
            val1 += S_CHAR;
    }

    if (!StringUtility::endsWith(val2, S_CHAR))
    {
            val2 +=S_CHAR;
    }

    if (!StringUtility::endsWith(val3, S_CHAR))
    {
            val3 += S_CHAR;
    }

    // The property is valid if all values are the same, or all values are different.
    return ((val1 == val2 && val2 == val3) || (val1 != val2 && val2 != val3 && val1 != val3));
}

bool Game::validSet(std::string card1, std::string card2,std::string card3)
{
    std::vector<std::string> vcard1;
    std::vector<std::string> vcard2;
    std::vector<std::string> vcard3;

    // Split each card  string on space. 
    StringUtility::split(card1, ' ', vcard1);
    StringUtility::split(card2, ' ', vcard2);
    StringUtility::split(card3, ' ', vcard3);

    // Test each resulting property from each card for validity
    for (int i = 0; i < vcard1.size(); i++)
    {
            if (!validProperty(vcard1[i], vcard2[i], vcard3[i]))
            {
                    return false; // since all properties must be valid, return false on first failure
            }
    }

    return true;
}