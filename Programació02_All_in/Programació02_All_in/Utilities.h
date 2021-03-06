#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdio.h>

//  NULL just in case ----------------------

#ifdef NULL
#undef NULL
#endif
#define NULL  0

// Deletes a buffer
#define RELEASE( x ) \
	    {                        \
    if( x != NULL )        \
		    {                      \
      delete x;            \
	  x = NULL;              \
		    }                      \
	    }

// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	    {                              \
    if( x != NULL )              \
		    {                            \
      delete[] x;                \
	  x = NULL;                    \
		    }                            \
                              \
	    }

#define IN_RANGE( value, min, max ) ( ((value) >= (min) && (value) <= (max)) ? 1 : 0 )
#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define TO_BOOL( a )  ( (a != 0) ? true : false )

typedef unsigned int uint;

template <class DITTO> 
void swap(DITTO& a, DITTO& b)
{
	DITTO tmp = a;
	a = b;
	b = tmp;
}

// Standard string size
#define SHORT_STR	32
#define MID_STR		255
#define HUGE_STR	8192

// Joins a path and file
inline const char* const PATH(const char* folder, const char* file)
{
	static char path[MID_STR];
	sprintf_s(path, MID_STR, "%s/%s", folder, file);
	return path;
}

#endif