
#include "common.hpp"
#include "db_access_api.hpp"

int VectorSerialize::Serialize(const T_TABLES & input_data,std::string & output_data)
{
    std::string tmpdata(SIZE_UNSIGNED,'\0');
    output_data.clear();
    unsigned resNum =unsigned(input_data.size());        
    memcpy(&tmpdata[0],&resNum,tmpdata.size());
    output_data =tmpdata;
    for(T_TABLES::const_iterator it0 =input_data.begin(); it0!=input_data.end();it0++)
    {
        T_TABLE tbl1 =*it0; // tbl1 is a row-colume table.
        unsigned rowNum =unsigned(tbl1.size());  
        for(T_TABLE::const_iterator it1 =tbl1.begin(); it1!=tbl1.end();it1++)
        {
            T_ROW oneRow =*it1;
            unsigned colNum =unsigned(oneRow.size());  
            if(it1==tbl1.begin())
            {
                memcpy(&tmpdata[0],&rowNum,tmpdata.size());
                output_data +=tmpdata;
                memcpy(&tmpdata[0],&colNum,tmpdata.size());
                output_data +=tmpdata;
            }
            for(T_ROW::iterator it2 =oneRow.begin(); it2!=oneRow.end();it2++)
            {
                std::string element =*it2;
                output_data +=element;
            }
        }
    }
    return 0;
}
int VectorSerialize::Deserialize(const char * input_data, T_TABLES & output_data)
{
    const char * p =&input_data[0];
    unsigned resNum =*((unsigned*)p);  
    for(unsigned i=0;i<resNum;i++)
    {
        unsigned rowNum =*((unsigned*)p); 
        p +=SIZE_UNSIGNED;
        unsigned colNum =*((unsigned*)p);              
        
        T_TABLE v_table;
        for(unsigned j=0;j<rowNum;j++)
        {
            T_ROW v_row;
            for(unsigned k=0;k<colNum;k++)
            {
                std::string element(p,MAXBYTES_EVERY_ELEMENT);
                v_row.push_back(element);
                if(k<colNum-1)
                    p +=MAXBYTES_EVERY_ELEMENT;
            }
            v_table.push_back(v_row);
        }
        output_data.push_back(v_table);
    }
    return 0;
}


int MyConnect(MYSQL & mysql,std::string host,std::string user,std::string passwd,std::string database,unsigned port)
{
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql,host.c_str(),user.c_str(),passwd.c_str(),database.c_str(),port,NULL,0))
    {
        fprintf(stderr, "Failed to connect to database: Error: %s\n",mysql_error(&mysql));
        return -1;
    }
    return 0;
}

int MyQuery(MYSQL & mysql, const char *stmt_str, unsigned long length)
{
    int rt =mysql_real_query(&mysql,stmt_str,length);
    if (rt)
    {
      printf("Could not execute statement(s),%s \n",stmt_str);
      return -1;
    }
    return 0;
}

T_TABLE MyGetResult(MYSQL & mysql, MYSQL_RES * result)
{
    T_TABLE v_table;
    MYSQL_ROW row;
    unsigned num_fields = mysql_num_fields(result);
    while ((row = mysql_fetch_row(result)))
    {
        T_ROW v_row;
        unsigned long *lengths;
        lengths = mysql_fetch_lengths(result);
        for(unsigned i = 0; i < num_fields; i++)
        {
            std::string ele(row[i] ? row[i] : "NULL");
            ele.resize(MAXBYTES_EVERY_ELEMENT); // Bytes every element.
            v_row.push_back(ele);
            printf("[%.*s] ", (int) lengths[i],row[i] ? row[i] : "NULL");
        }
        v_table.push_back(v_row);
        printf("\n");
    }
    return v_table;
}

int MyGetResults(MYSQL & mysql,T_TABLES & v_tables)
{
    int rt =0;
    int status =0;
    do {
        MYSQL_RES * result = mysql_store_result(&mysql);
        if (result)
        {
            T_TABLE v_table =MyGetResult(mysql,result);
            v_tables.push_back(v_table);
            mysql_free_result(result);
        }
        else          /* no result set or error */
        {
            if (mysql_field_count(&mysql) == 0)
            {
                printf("%lld rows affected\n",mysql_affected_rows(&mysql));
            }
            else  /* some error occurred */
            {
                rt =-1;
                printf("Could not retrieve result set\n");
                break;
            }
        }
        /* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
        if ((status = mysql_next_result(&mysql)) > 0)
        {
            rt =-1;
            printf("Could not execute statement\n");
        }
    } while (status == 0);
    return rt;
}

void MyClose(MYSQL & mysql)
{
    mysql_close(&mysql);    
}
