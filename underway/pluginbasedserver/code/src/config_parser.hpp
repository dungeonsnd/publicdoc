#ifndef _HEADER_FILE_CONFIG_PARSER_HPP_
#define _HEADER_FILE_CONFIG_PARSER_HPP_

#include <fstream>
#include <iostream>
#include "common.hpp"
using namespace std::tr1;
class ConfigParser
{
public:
    typedef unordered_map < std::string , std::string > T_MAPCONFIG;
    
    ConfigParser(const std::string & cfgFile):_cfgFile(cfgFile)
    {
    }
    ~ConfigParser()
    {
    }
    int GetVal(const std::string & key,std::string & val)
    {
        Parse();
        T_MAPCONFIG::const_iterator it =_config.find(key);
        if(it!=_config.end())
        {
            val =it->second;
            return 0;
        }
        return -1;
    }
private:
    int Parse()
    {
        _config.clear();
        if(0!=IsFileExist(_cfgFile.c_str()))
            throw "error";
        std::ifstream fi(_cfgFile.c_str());
        std::string line,k,v;
        while(!fi.eof())
        {
            fi>>line;
            std::size_t found = line.find_first_of("=");
            if(found!=std::string::npos)
            {
                k =line.substr(0,found);
                v =line.substr(found+1);
                _config[k] =v;
            }
        }
        fi.close();
        return 0;
    }
    
    T_MAPCONFIG _config;
    const std::string _cfgFile;
};

#endif // _HEADER_FILE_CONFIG_PARSER_HPP_
