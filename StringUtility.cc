/* 
 * File:   StringUtility.cc
 * Author: Jeremy Shantz
 * 
 * Created on February 18, 2014, 12:55 PM
 */

#include "StringUtility.h"
#include <string>
#include <vector>
#include <sstream>

StringUtility::StringUtility() {
}

StringUtility::~StringUtility() {
}

std::vector<std::string> StringUtility::split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
            elems.push_back(item);
    }
    return elems;
}

bool StringUtility::endsWith(std::string value, std::string end)
{
    if (value.length() >= end.length()) {
            return (0 == value.compare(value.length() - end.length(), end.length(), end));
    }
    else {
            return false;
    }
}
