#pragma once

#include <string>

namespace Menu {

	//Easy way to solicit instructions from cin.
	std::string SolicitInst(const std::string& text);

	// compares first character of s to char compare. compare should be lowercase, and 
	// will match with lower or upercase version of that character. 
	bool CharCompare(const std::string& s, char compare);
}
