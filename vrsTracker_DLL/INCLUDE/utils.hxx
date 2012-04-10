#ifndef UTILS_HXX_
# define UTILS_HXX_

//string to smth
template <class T>
bool Utils::stringTo(T& n, const std::string& s)
{
	std::istringstream iss(s);
	return !(iss >> n).fail();
}

//smth to string
template <class T>
std::string Utils::toString(const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

#endif