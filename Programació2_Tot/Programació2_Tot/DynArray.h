// --------------------------------------------
//              DynArray cLass
// --------------------------------------------

#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <assert.h>
#define NULL 0 // for not carrying the entire library

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


	// Flip ------------------------------------------------
	void flip()
	{
		KIND* start = &queue[0];
		KIND* end = &queue[num_elements - 1];

		while (start < end)
			swap(*start++, *end--);
	}


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

	int combsort(){
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

	/*
	function combsort11(array input)
    gap:= input.size //inicializar tamaño de espacio
    
    loop until gap = 1 and swaps = 0
        //actualizar el valor del espacio para el siguiente rastreo
        if gap > 1
            gap:= gap / 1.3
            if gap = 10 or gap = 9
                gap:= 11
            end if
        end if
        
        i:= 0
        swaps:= 0 //véase ordenamiento de burbuja para una explicación
        //un único "rastreo" sobre la lista de entrada
        loop until i + gap >= array.size
            if array[i] > array[i+gap]
                swap (array[i], array[i+gap])
                swaps:= swaps + 1
            end if
            i:= i + 1
        end loop
    end loop
end function
	*/

	void swap(KIND& a, KIND& b)
	{
		KIND tmp = a;
		a = b;
		b = tmp;
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