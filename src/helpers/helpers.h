#ifndef __HELPERS__
#define __HELPERS__

#include <string>
#include <sqlite3.h>
#include <libsqlitewrapped.h>
#include <sstream>

using namespace std;

namespace helpers
{
	template<typename T>
	size_t arraySize( T );
	string longToString( const long& );
	bool isNumeric( string );
	string safeQuote( string );
	string makeSql( string, ... );
}

#endif
