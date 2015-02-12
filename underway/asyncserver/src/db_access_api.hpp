
#ifndef _HEADER_FILE_DB_ACCESS_API_HPP_
#define _HEADER_FILE_DB_ACCESS_API_HPP_

#include "cppfoundation/cf_root.hpp"
#include "common.hpp"
#include <mysql.h>

#define MAXBYTES_EVERY_ELEMENT 64
#define SIZE_UNSIGNED sizeof(unsigned)

typedef std::vector < std::string > T_ROW;
typedef std::vector < T_ROW > T_TABLE;
typedef std::vector < T_TABLE > T_TABLES;

class VectorSerialize
{
public:
    VectorSerialize(){}
    ~VectorSerialize(){}
    static int Serialize(const T_TABLES & input_data,std::string & output_data);
    static int Deserialize(const char * input_data, T_TABLES & output_data);
};

int MyConnect(MYSQL & mysql,std::string host,std::string user,std::string passwd,std::string database,unsigned port);

int MyQuery(MYSQL & mysql, const char *stmt_str, unsigned long length);

T_TABLE MyGetResult(MYSQL & mysql, MYSQL_RES * result);

int MyGetResults(MYSQL & mysql,T_TABLES & v_tables);

void MyClose(MYSQL & mysql);

#endif // _HEADER_FILE_DB_ACCESS_API_HPP_
