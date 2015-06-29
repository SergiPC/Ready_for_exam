// --------------------------------------------
//              CString class
// --------------------------------------------

#ifndef __CSTRING_H__
#define __CSTRING_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#define TMP_STRING_SIZE 2204

class CString
{
private:
	
	unsigned int	size;
	char*			str;

public:


	// Constructors -----------------------------------------
	CString()
	{
		alloc(1);
		clear();
	}


	CString(unsigned int new_size)
	{
		if (new_size > 0)
			alloc(new_size);

		else
			alloc(1);

		clear();
	}


	CString(const CString& other_string)
	{
		alloc(other_string.size);
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
				alloc(res + 1);
				strcpy_s(str, size, tmp);
			}
		}

		if (size == 0)
		{
			alloc(1);
			clear();
		}
	}







	// EXAMEN FINAL PROGRAMACIÓ 2 (9 JUNY 2015)
	// String :: Mètode per tallar una cadena rebent la posició inicial i final: -----------------------------
	bool cut(unsigned int initial_num, unsigned int final_num)
	{
		unsigned int len = length();

		if (final_num >= len || final_num == 0)
			final_num = len - 1;

		if (initial_num > len || final_num <= initial_num)
			return false;

		unsigned int n_numbers = final_num - initial_num + 1;

		for (unsigned int i = initial_num; i < size - n_numbers; i++)
			str[i] = str[i + n_numbers];

		return true;
	}
	// FINAL EXAMEN PARCIAL PROGRAMACIÓ 2 (9 JUNY 2015)











	// Destructor -------------------------------------------
	virtual ~CString()
	{
		if (str != NULL)
			delete[] str;
	}


	// Operators --------------------------------------------
	bool operator==(const char* other_char) const
	{
		if (other_char != NULL)
			return(strcmp(other_char, str) == 0);

		else
			return false;
	}


	bool operator==(const CString& other_string) const
	{
		return(strcmp(other_string.str, str) == 0);
	}


	bool operator!=(const char* other_char) const
	{
		if (other_char != NULL)
			return(strcmp(other_char, str) != 0);

		else
			return true;
	}


	bool operator!=(const CString& other_string) const
	{
		return(strcmp(other_string.str, str) != 0);
	}


	const CString& operator=(const char* other_char)
	{
		if (other_char != NULL)
		{
			if (strlen(other_char) + 1 > size)
			{
				delete[] str;
				alloc(strlen(other_char) + 1);
			}

			else
				clear();

			strcpy_s(str, size, other_char);
		}

		else
			clear();

		return(*this);
	}


	const CString& operator=(const CString& other_string)
	{
		if (other_string.length() + 1 > size)
		{
			delete[] str;
			alloc(other_string.length() + 1);
		}

		else
			clear();

		strcpy_s(str, size, other_string.str);
		return(*this);
	}


	const CString& operator+=(const char* other_char)
	{
		if (other_char != NULL)
		{
			if (strlen(other_char) + length() + 1 > size)
			{
				char* tmp = str;
				alloc(strlen(other_char) + length() + 1);
				strcpy_s(str, size, tmp);
				delete[] tmp;
			}

			strcat_s(str, size, other_char);
		}

		return(*this);
	}


	const CString& operator+=(const CString& other_string)
	{
		if (other_string.length() + length() + 1 > size)
		{
			char* tmp = str;
			alloc(other_string.length() + length() + 1);
			strcpy_s(str, size, tmp);
			delete[] tmp;
		}

		strcat_s(str, size, other_string.str);
		return(*this);
	}


	// Especials --------------------------------------------
	void trim()
	{
		// cut right
		char* end = str + size;
		while (*--end == ' ') *end = '\0';

		// cut left
		char* start = str;
		while (*++start == ' ');

		unsigned int s = strlen(start);

		for (unsigned int i = 0; i < s + 1; ++i)
			str[i] = start[i];
	}


	const CString& prefix(char* other_char)
	{
		if (other_char != NULL)
		{
			unsigned int needed_size = strlen(other_char) + length() + 1;
			char* tmp = str;

			alloc(needed_size);
			strcpy_s(str, size, other_char);

			strcat_s(str, size, tmp);
			delete[] tmp;
		}

		return(*this);
	}


	const CString& prefix(const CString& other_string)
	{
		if (other_string.length() == 0)
		{
			return(*this);
		}

		if (length() == 0)
		{
			return operator=(other_string);
		}

		unsigned int needed_size = other_string.length() + length() + 1;

		char* tmp = str;
		alloc(needed_size);

		strcpy_s(str, size, other_string.str);
		strcat_s(str, size, tmp);

		delete[] tmp;
		return(*this);
	}


	unsigned int substitute(const char* src, const char *dst)
	{
		assert(src);
		assert(dst);

		unsigned int instances = find(src);

		if (instances > 0)
		{
			unsigned int src_len = strlen(src);
			unsigned int dst_len = strlen(dst);
			unsigned int diff = dst_len - src_len;
			unsigned int needed_size = 1 + strlen(str) + (diff * instances);

			if (size < needed_size)
			{
				char* tmp = str;
				alloc(needed_size);
				strcpy_s(str, size, tmp);
				delete tmp;
			}

			for (unsigned int i = 0; i < size - src_len; ++i)
			{
				if (strncmp(src, &str[i], src_len) == 0)
				{
					// make room
					for (unsigned int j = strlen(str) + diff; j > i + diff; --j)
					{
						str[j] = str[j - diff];
					}

					// copy
					for (unsigned int j = 0; j < dst_len; ++j)
					{
						str[i++] = dst[j];
					}
				}
			}
		}

		return instances;
	}


	unsigned int find(const char* string) const
	{
		unsigned int ret = 0;

		if (string != NULL)
		{
			unsigned int len = strlen(string);

			for (unsigned int i = 0; i < size - len; ++i)
			{
				if (strncmp(string, &str[i], len) == 0)
				{
					i += len;
					++ret;
				}
			}
		}

		return ret;
	}


	// Utilities --------------------------------------------
	void clear()
	{
		str[0] = '\0';
	}


	unsigned int length() const
	{
		return(strlen(str));
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

	void alloc(unsigned int new_size)
	{
		size = new_size;
		str = new char[size];
	}
};

#endif //__CSTRING_H__