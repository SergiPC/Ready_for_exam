// --------------------------------------------
//              CString cLass
// --------------------------------------------

#ifndef __CSTRING_H__
#define __CSTRING_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TMP_STRING_SIZE 2204

class CString
{
private:

	unsigned int	size;
	char*			str;

public:

	// Constructors ----------------------------------------
	CString()
	{
		allocation(1);
		clear();
	}


	CString(unsigned int size)
	{
		if (size > 0)
		{
			allocation(size);
		}
		else
		{
			allocation(1);
		}
		clear();
	}


	CString(const CString& other_string)
	{
		allocation(other_string.size);
		strcpy_s(str, size, other_string.str);
	}


	CString(const char *format, ...)
	{
		size = 0;

		if (format != NULL)
		{
			static char tmp[TMP_STRING_SIZE];
			static va_list  ap;

			// Construct the string from variable arguments
			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);

			if (res > 0)
			{
				allocation(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{
			allocation(1);
			clear();
		}
	}

	// Destructor ------------------------------------------
	virtual ~CString()
	{
		if (str != NULL)
		{
			delete[] str;
		}
	}

	// Operators -------------------------------------------
	bool operator==(const CString& other_string) const
	{
		return(strcmp(other_string.str, str) == 0);
	}


	bool operator==(const char* other_char) const
	{
		if (other_char != NULL)
		{
			return(strcmp(other_char, str) == 0);
		}
		else
		{
			return false;
		}
	}


	bool operator!=(const CString& other_string) const
	{
		return(strcmp(other_string.str, str) != 0);
	}


	bool operator!=(const char* other_char) const
	{
		if (other_char != NULL)
		{
			return(strcmp(other_char, str) != 0);
		}
		else
		{
			return true;
		}
	}


	const CString& operator=(const CString& other_string)
	{
		if (other_string.length() + 1 > size)
		{
			delete[]str;
			allocation(other_string.length() + 1);
		}
		else
		{
			clear();
		}
		strcpy_s(str, size, other_string.str);
		return(*this);
	}


	const CString& operator=(const char* other_char)
	{
		if (other_char != NULL)
		{
			if (strlen(other_char) + 1 > size)
			{
				delete[] str;
				allocation(strlen(other_char) + 1);
			}
			else
			{
				clear();
			}
			strcpy_s(str, size, other_char);
		}
		else
		{
			clear();
		}

		return(*this);
	}


	const CString& operator+=(const CString& other_string)
	{
		unsigned int needed_size = other_string.length() + length() + 1;

		if (needed_size > size)
		{
			char* tmp = str;
			allocation(needed_size);
			strcpy_s(str, size, tmp);
			delete[] tmp;
		}

		strcat_s(str, size, other_string.str);

		return(*this);
	}


	const CString& operator+=(const char* other_char)
	{
		if (other_char != NULL)
		{
			unsigned int needed_size = strlen(other_char) + length() + 1;

			if (needed_size > size)
			{
				char* tmp = str;
				allocation(needed_size);
				strcpy_s(str, size, tmp);
				delete[] tmp;
			}

			strcat_s(str, size, other_char);
		}

		return(*this);
	}




	// Prefix ----------------------------------------------
	const CString& prefix(CString& other_string)
	{
		unsigned int needed_size = other_string.length() +length() + 1;
		
		if (needed_size > other_string.length())
		{
			char* tmp = str;
			allocation(needed_size);
			strcpy_s(str, size, other_string.str);
			strcat_s(other_string.str, size, tmp);
			delete[] tmp;
			return(*this);
		}
		else
		{
			strcat_s(other_string.str, size, str);
			return(*this);
		}
	}
	
	
	
	const CString& prefix(char* other_char)
	{
		if (other_char != NULL)
		{
			unsigned int needed_size = strlen(other_char) + length() + 1;
			char* tmp = str;

			allocation(needed_size);
			strcpy_s(str, size, other_char);			

			strcat_s(str, size, tmp);
			delete[] tmp;
		}

		return(*this);
	}




	// Utilities -------------------------------------------
	unsigned int length() const
	{
		return(strlen(str));
	}


	void clear()
	{
		str[0] = '\0';
	}


	const char* getString() const
	{
		return(str);
	}


	const unsigned int getCapacity() const
	{
		return(size);
	}


private:

	// Requires going private ------------------------------
	void allocation(unsigned int needed_memory)
	{
		size = needed_memory;
		str = new char[size];
	}
};
#endif // __CSTRING_H__ 