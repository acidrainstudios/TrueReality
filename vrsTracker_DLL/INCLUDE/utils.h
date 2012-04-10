#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#define SPACE_CHAR ' '
#define NL_CHAR 10
#define CR_CHAR 13

//general purpose utilities (string, file...)
class Utils
{
public:
	//remove spaces at beginning and end of string
	static std::string trimBothEnds(const std::string& str);
	//transform a string with elements separated by a delimiter to a vector of these elements
	static std::vector<std::string> splitString(const std::string& str, const char delim);
	//returns if a charcater is blank
	static bool isBlank(char c);
	//try to extract something (int, float...) from a string, returns false if error
	template <class T> static bool stringTo(T& n, const std::string& s);
	//converts something into a string
	template <class T> static std::string toString (const T& t);
	//returns abs of a float
	static float Utils::abs(float a);

private:



};

#include "utils.hxx"

#endif