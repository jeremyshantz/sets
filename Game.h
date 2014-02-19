/* 
 * File:   Games.h
 * Author: Jeremy Shantz
 *
 * Created on February 17, 2014, 2:12 PM
 */

#include <cstdlib>
#include <string>
#include<vector>

#ifndef GAME_H
#define GAME_H

/*!  Generates a list of valid sets from a list of cards
 */
class Game
{
public:
    
    //! Constructs an instance of Game using the supplied path to an input file.
    Game(std::string path);
    
    //! Destructor
    virtual ~Game();
    
    //! Loads the input file and prints valid sets, returning the count of valid sets.
    int play();
	
private:
    //! Generates all of the valid sets from the supplied list of cards.
    int generateSets(std::vector<std::string> cards);
    
    //! Prints a set of cards to standard output
    void printSet(std::string card1, std::string card2, std::string card3);
    
    //! Returns true of the three parameters are all the same or are all different. Otherwise, returns false.
    bool validProperty(std::string val1, std::string val2, std::string val3);
    
    //! Returns true if the three card parameters form a valid set.
    bool validSet(std::string card1, std::string card2, std::string card3);
    
    //! Loads a hand of cards from a file.
    std::vector<std::string> loadCards(std::string path);
};

#endif	/* GAME_H */

