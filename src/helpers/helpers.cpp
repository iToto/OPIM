#include "helpers.h"
#include <iostream>

template<typename T>
size_t helpers::arraySize( T array )
{
	return sizeof( array ) / sizeof( T );
}

string helpers::longToString( const long& number )
{
	stringstream ss;

	ss << number;

	return ss.str();
}

bool helpers::isNumeric( string str )
{
	bool foundDecimal = false;

	for ( string::const_iterator it = str.begin() ; it != str.end() ; ++it )
	{
		if ( *it == '.' )
		{
			if ( it == str.begin() || foundDecimal )
				return false;
			else
				foundDecimal = true;
		}
		else if ( *it == '-' )
		{
			if ( it != str.begin() )
				return false;
		}
		else if ( *it < '0' || *it > '9' )
			return false;
	}

	return true;
}

string helpers::safeQuote( string str )
{
    char searchStrings[] = { '\\', '\'', '\"' };
    string newStr = "";
    string::size_type pos;
    size_t count = sizeof( searchStrings );

    for ( size_t i = 0 ; i != count ; ++i )
    {
    	for ( pos = 0 ; pos != str.size() ; ++pos )
    	{
    		if ( str[pos] == searchStrings[i] )
    		{
    			str = str.substr( 0, pos ) + '\\' + str.substr( pos );
    			++pos;
    		}
    	}
    }

    return "'" + str + "'";
}

string helpers::makeSql( string sql, ... )
{
	string::size_type start = 0;
	string::size_type end = 0;
	string newSql = "";
	string curVal;
	va_list values;

	va_start( values, sql );

	while ( ( end = sql.find( "?", start ) ) != string::npos )
	{
		curVal = va_arg( values, char* );

		if ( !isNumeric( curVal ) )
			curVal = safeQuote( curVal );

		newSql += sql.substr( start, end - start ) + curVal;
		start = end + 1;
	}

	newSql += sql.substr( start );

	return newSql.c_str();
}
