// --------------------------------------------
//              DynArray class
// --------------------------------------------

#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <assert.h>
#define NULL 0 // for not carrying the entire library

#define DYN_ARRAY_PRED_SIZE 22

template<class DITTO>
class DynArray
{
private:

	DITTO*			queue; // pointer for array's memory
	unsigned int	num_elements; // number of elements
	unsigned int	capacity; // allocated memory


public:

	// Constructors -----------------------------------------
	DynArray() : capacity(0), num_elements(0), queue(NULL)
	{
		alloc(DYN_ARRAY_PRED_SIZE);
	}


	DynArray(unsigned int new_capacity) : capacity(0), num_elements(0), queue(NULL)
	{
		alloc(new_capacity);
	}


	// Destructor ------------------------------------------
	~DynArray()
	{
		delete[] queue;
	}


	// Some operators --------------------------------------
	DITTO& operator[](unsigned int index)
	{
		assert(index < num_elements);
		return queue[index];
	}


	const DITTO& operator[](unsigned int index) const
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
			alloc(num_elements);
		}

		return wasted;
	}


	// add item to the end of array
	void pushBack(const DITTO& value)
	{
		if (num_elements >= capacity)
			alloc(capacity + DYN_ARRAY_PRED_SIZE);

		queue[num_elements++] = value;
	}


	// delete the last array item
	bool pop(DITTO& value)
	{
		if (num_elements > 0)
		{
			value = queue[--num_elements];
			return true;
		}
		return false;
	}


	// delete array item
	bool del(DITTO position)
	{
		if (position >= num_elements)
			return false;

		if (num_elements == 1) // if array has only one element, we delete it
			clear();

		else
		{
			for (unsigned int i = position; i < num_elements - 1; i++)
				queue[i] = queue[i + 1];

			num_elements--;
		}
	}	


	bool insert(const DITTO& value, unsigned int position)
	{
		if (position > num_elements)
			return false;

		if (position == num_elements)
		{
			pushBack(value);
			return true;
		}

		if (num_elements + 1 > capacity)
			alloca(capacity + DYN_ARRAY_PRED_SIZE);

		for (unsigned int i = num_elements; i > position; --i)
			queue[i] = queue[i - 1];

		queue[position] = value;
		++num_elements;

		return true;
	}


	void flip()
	{
		DITTO* start = &queue[0];
		DITTO* end = &queue[num_elements - 1];

		while (start < end)
			swap(*start++, *end--);
	}


	// Set in order ----------------------------------------
	// 1) Comparar el primer amb tots.
	// 2) No comparar més a partir del últim swap.
	int bubbleSort()
	{
		int counter = 0;
		bool done = false;

		if (queue != NULL){

			while (done != true)
			{
				int iterations = 0;

				for (unsigned int i = 0; i < num_elements - 1; i++)
				{
					counter++;
					if (queue[i] > queue[i + 1])
					{
						swap(queue[i], queue[i + 1]);
						iterations++;
					}
				}

				if (iterations == 0)
					done = true;
			}
		}
		return counter;
	}


	int bubbleSortOptimized()
	{
		int counter = 0;
		bool done = false;
		unsigned int d = num_elements;

		if (queue != NULL){

			while (done != true)
			{
				int iterations = 0;

				for (unsigned int i = 0; i < d - 1; i++)
				{
					counter++;
					if (queue[i] > queue[i + 1])
					{
						swap(queue[i], queue[i + 1]);
						iterations++;
					}
				}
				d--;

				if (iterations == 0)
					done = true;
			}
		}
		return counter;
	}


	int combsort()
	{
		int counter = 0;
		bool swapped = true;
		int gap = num_elements;
		float interval = 1.3f;

		if (queue != NULL){

			while (swapped && gap >= 1)
			{
				swapped = false;

				if (gap > 1)
					gap = (gap / interval);

				else
					gap = 1;

				for (unsigned int i = 0; i + gap < num_elements - 1; i++)
				{
					counter++;
					if (queue[i] > queue[i + gap])
					{
						swap(queue[i], queue[i + gap]);
						swapped = true;
					}
				}
			}
		}
		return counter;
	}


	// Utilities -------------------------------------------
	void clear()
	{
		num_elements = 0;
	}


	unsigned int getCapacity() const
	{
		return capacity;
	}


	unsigned int count() const
	{
		return num_elements;
	}


	void swap(DITTO& a, DITTO& b)
	{
		DITTO tmp = a;
		a = b;
		b = tmp;
	}


	DITTO* at(unsigned int index)
	{
		DITTO* result = NULL;

		if (index < num_elements)
			return result = &queue[index];

		return result;
	}


	const DITTO* At(unsigned int index) const
	{
		DITTO* result = NULL;

		if (index < num_elements)
			return result = &queue[index];

		return result;
	}


private:

	void alloc(unsigned int new_capacity)
	{
		DITTO* new_queue = queue;
		capacity = new_memory;
		queue = new DITTO[capacity];

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


#endif  //__DYNARRAY_H__