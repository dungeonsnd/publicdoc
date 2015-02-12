#ifndef _HEADER_FILE_UTIL_HPP_
#define _HEADER_FILE_UTIL_HPP_

#include <string>

std::string GenerateRandString(unsigned int stringLength)
{
	std::string output(stringLength,'\0');
	unsigned int i=0;
	for(i=0;i<stringLength;i++)
		output[i] =rand()%26+'A';
	return output;
}

#endif  // _HEADER_FILE_UTIL_HPP_
