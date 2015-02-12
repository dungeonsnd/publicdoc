#ifndef _HEADER_FILE_COMPRESS_HPP_
#define _HEADER_FILE_COMPRESS_HPP_

#include "zlib.h"
#include <string>


/*
src [in]
srcLen [in]
dest [out]
destLen [out]
compressLevel [in]

compressLevel Copy from zlib.h
#define Z_NO_COMPRESSION 0
#define Z_BEST_SPEED 1
#define Z_BEST_COMPRESSION 9
#define Z_DEFAULT_COMPRESSION (-1)
*/
int Compress(const char * src, unsigned long int srcLen, 
			std::string & dest, unsigned long int & destLen,
			int compressLevel =Z_DEFAULT_COMPRESSION)
{
	destLen =compressBound(srcLen);
	dest.resize(destLen);
	return compress2((Bytef*)(&dest[0]),(uLongf*)(&destLen),
					   (Bytef*)src,(uLong)srcLen, compressLevel);	
}


/*
src [in]
srcLen [in]
dest [out]
destLen [in,out]
compressLevel [in]
*/
int Uncompress(const void * src, unsigned long int srcLen, void * dest, unsigned long int & destLen)
{
	return uncompress((Bytef*)dest,(uLongf*)(&destLen),
					   (Bytef*)src,(uLong)srcLen);
}


#endif  // _HEADER_FILE_COMPRESS_HPP_
