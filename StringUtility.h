/* 
 * File:   StringUtility.h
 * Author: Jeremy Shantz
 *
 * Created on February 18, 2014, 12:55 PM
 */

#include <string>
#include <vector>

#ifndef STRINGUTILITY_H
#define	STRINGUTILITY_H

/*! A collection of useful string functions 
 */
class StringUtility {
public:
    StringUtility();
    virtual ~StringUtility();    
    
    //! True when the first string ends with the second string
    static bool endsWith(std::string value, std::string end);
    
    //! Splits a string using the delimiter and populates the supplied vector of string
    static std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
private:
};

#endif	/* STRINGUTILITY_H */

