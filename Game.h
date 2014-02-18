/* 
 * File:   Games.h
 * Author: Jeremy Shantz
 *
 * Created on February 17, 2014, 2:12 PM
 */

#include <cstdlib>
#include <string>
#include<vector>

using namespace std; 

class Game
{
public:
        Game();
        ~Game();
        int Play(std::string path);
	
private:
    int generateSets(std::vector<string> cards);
    void printSet(std::string card1, std::string card2, std::string card3);
    bool validProperty(std::string val1, std::string val2, std::string val3);
    bool validSet(std::string card1, std::string card2, std::string card3);
    std::vector<std::string> loadCards(std::string path);
    bool endsWith(std::string value, std::string end);
    std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
};
