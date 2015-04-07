// --------------------------------------------
//              Stack cLass
// --------------------------------------------

#ifndef __Stack_H__
#define __Stack_H__

#include <assert.h>

#define DYN_ARRAY_PRED_SIZE 22

template<class KIND>
class Stack
{
private:

	KIND*			queue; // pointer for array's memory
	unsigned int	num_elements; // number of elements
	unsigned int	capacity; // allocated memory

public:

	// Constructor -----------------------------------------
	Stack() : capacity(0), num_elements(0), queue(NULL)
	{
		allocation(DYN_ARRAY_PRED_SIZE);
	}


	Stack(unsigned int new_capacity) : capacity(0), num_elements(0), queue(NULL)
	{
		allocation(new_capacity);
	}

	// Destructor ------------------------------------------
	~Stack()
	{
		delete[] queue;
	}

	// Some operators --------------------------------------
	const KIND& pick(unsigned int index) const
	{
		assert(index < num_elements);
		return queue[index];
	}

	// Data management -------------------------------------
	// remove memory
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

#endif // __Stack_H__