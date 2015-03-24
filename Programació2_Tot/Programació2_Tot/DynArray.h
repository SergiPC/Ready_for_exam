// --------------------------------------------
//              DynArray cLass
// --------------------------------------------

#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <assert.h>

#define DYN_ARRAY_PRED_SIZE 22

template<class KIND>
class DynArray
{
private:

	KIND*			queue; // pointer for array's memory
	unsigned int	num_elements; // number of elements
	unsigned int	capacity; // allocated memory

public:

	// Constructor -----------------------------------------
	DynArray() : capacity(0), num_elements(0), queue(NULL)
	{
		allocation(DYN_ARRAY_PRED_SIZE);
	}


	DynArray(unsigned int new_capacity) : capacity(0), num_elements(0), queue(NULL)
	{
		allocation(new_capacity);
	}

	// Destructor ------------------------------------------
	~DynArray()
	{
		delete[] queue;
	}

	// Some operators --------------------------------------
	KIND& operator[](unsigned int index)
	{
		assert(index < num_elements);
		return queue[index];
	}
	

	const KIND& operator[](unsigned int index) const
	{
		assert(index < num_elements);
		return queue[index];
	}

	// Data management -------------------------------------


	const unsigned int removeWastedMemory()
	{
		unsigned int wasted = 0;
		if (num_elements < capacity)
		{
			wasted = capacity - num_elements;
			allocation(num_elements);
		}
		return wasted;
	}



	// add item to the end of array
	void pushBack(const KIND& value)
	{
		if (num_elements >= capacity)
		{
			allocation(capacity + DYN_ARRAY_PRED_SIZE);
		}
		queue[num_elements++] = value;
	}
	
	// delete the last array item
	bool pop(KIND& value)
	{
		if (num_elements > 0)
		{
			value = queue[--num_elements];
			return true;
		}
		return false;
	}

	// delete array item
	bool del(KIND position) 
	{
		if (position >= num_elements)
		{
			return false;
		}
		if (num_elements == 1) // if array has only one element, we delete it
		{
			clear();
		}
		else
		{
			for (unsigned int i = position; i < num_elements - 1; i++)
			{
				queue[i] = queue[i + 1];
			}
			num_elements--;
		}
	}


	void clear()
	{
		num_elements = 0;
	}


	bool insert(const KIND& value, unsigned int position)
	{
		if (position > num_elements)
		{
			return false;
		}
		if (position == num_elements)
		{
			pushBack(value);
			return true;
		}
		if (num_elements + 1 > capacity)
		{
			allocation(capacity + DYN_ARRAY_PRED_SIZE);
		}
		for (unsigned int i = num_elements; i > position; --i)
		{
			queue[i] = queue[i - 1];
		}
		queue[position] = value;
		++num_elements;
		return true;
	}

	/*
	KIND* At(unsigned int index)
	{
		KIND* result = NULL;

		if (index < num_elements)
			return result = &queue[index];

		return result;
	}


	const KIND* At(unsigned int index) const
	{
		KIND* result = NULL;

		if (index < num_elements)
			return result = &queue[index];

		return result;
	}
	*/


	// Utilities -------------------------------------------
	unsigned int getCapacity() const
	{
		return capacity;
	}


	unsigned int count() const
	{
		return num_elements;
	}

private:

	// Requires going private ------------------------------
	void allocation(unsigned int new_memory)
	{
		KIND* new_queue = queue;
		capacity = new_memory;
		queue = new KIND[capacity];
		if (num_elements > capacity)
		{
			num_elements = capacity;
		}
		if (new_queue != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i)
			{
				queue[i] = new_queue[i];
			}
			delete[] new_queue;
		}
	}
};

#endif // __DYNARRAY_H__