#include "../Include/utils.h"

//remove spaces at beginning and end of string
std::string Utils::trimBothEnds(const std::string& str)
{
	unsigned int beg = 0;
	unsigned int end = str.size() - 1;
	while (beg < str.size() && isBlank(str.at(beg)))
		++beg;
	if (beg >= str.size()) //only spaces
		return str.substr(0, 0); //returning empy string
	while (end > 0 && isBlank(str.at(end)))
		--end;
	return str.substr(beg, end - beg + 1);
}

//returns if a charcater is blank
bool Utils::isBlank(char c)
{
	return c == SPACE_CHAR || (int) c == CR_CHAR || (int) c == NL_CHAR;
}

//transform a string with elements separated by a delimiter to a vector of these elements
std::vector<std::string> Utils::splitString(const std::string& str, const char delim)
{
	int posFind = -1;
	unsigned int seekPos = 0;
	std::string extracted;
	std::vector<std::string> list;

	do
	{
		posFind = str.find_first_of(delim, seekPos);
		if (posFind == -1)
			extracted = str.substr(seekPos, str.size() - seekPos);
		else
		{
			extracted = str.substr(seekPos, posFind - seekPos);
			extracted = trimBothEnds(extracted);
			seekPos = posFind + 1;
		}
		extracted = trimBothEnds(extracted);
		list.push_back(extracted);
	} while (posFind != -1 && seekPos < str.size());
	return list;
}

//returns abs of a float
float Utils::abs(float a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

