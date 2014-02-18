/* 
 * File:   Game.cpp
 * Author: Jeremy Shantz
 * 
 * Created on February 17, 2014, 2:12 PM
 */

#include <cstdlib>
#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

int Game::Play(std::string input)
{
        vector<string> cards = loadCards(input);

        if (cards.size() == 0)
        {
                return -1;
        }

        return generateSets(cards);
}

int Game::generateSets(std::vector<string> cards)
{
    int count = 0;
    
        for (int i = 0; i < cards.size(); i++)
        {
                for (int j = i + 1; j < cards.size(); j++)
                {
                        for (int k = j + 1; k < cards.size(); k++)
                        {
                                string card1 = cards[i];
                                string card2 = cards[j];
                                string card3 = cards[k];

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
        cout << card1 << ";" << card2 << ";" << card3 << endl;
}

std::vector<std::string> Game::loadCards(std::string path)
{
        std::vector<string> list;

                 ifstream file(path.c_str());



        std::string line;

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
        if (!endsWith(val1, "s"))
        {
                val1 += "s";
        }

        if (!endsWith(val2, "s"))
        {
                val2 += "s";
        }

        if (!endsWith(val3, "s"))
        {
                val3 += "s";
        }

        return ((val1 == val2 && val2 == val3) || (val1 != val2 && val2 != val3 && val1 != val3));
}

bool Game::validSet(std::string card1, std::string card2,std::string card3)
{
        vector<string> vcard1;
        vector<string> vcard2;
        vector<string> vcard3;

        split(card1, ' ', vcard1);
        split(card2, ' ', vcard2);
        split(card3, ' ', vcard3);

        for (int i = 0; i < vcard1.size(); i++)
        {
                if (!validProperty(vcard1[i], vcard2[i], vcard3[i]))
                {
                        return false;
                }
        }

        return true;
}

std::vector<std::string> Game::split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
                elems.push_back(item);
        }
        return elems;
}

bool Game::endsWith(std::string value, std::string end)
{
        if (value.length() >= end.length()) {
                return (0 == value.compare(value.length() - end.length(), end.length(), end));
        }
        else {
                return false;
        }
}
