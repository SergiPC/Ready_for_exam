#ifndef __QUEUE_H__
#define __QUEUE_H_
#include <stdio.h>

template<struct TYPE>
struct node
{
	TYPE value;
	node<TYPE>* next;
};

template<class TYPE>
class Queue
{
private:
	unsigned int	size;

public:
	node<TYPE>*	head;
	node<TYPE>*	bottom;

	void push(const TYPE& new_data)
	{
		node<TYPE>*	new_node;
		new_node = new node<TYPE>(new_data);
		if (head == NULL)
		{
			head = bottom = new_node;
		}
		else
		{
			new_node->next = bottom;
			bottom->next = new_node;
			bottom = new_node;
		}
		return(++size); // ++size increments size and returns the incremented number
	}

	// ha de tornar el valor que eliminem!!
	bool pop(TYPE& value)
	{
		value = head->next; // fer una copia del valor, per poder agafar-lo més tard

		if (head != NULL)
		{
			head = head->next;
			return true;
			return(--size); // ++size increments size and returns the incremented number
		}
		return false;
	}

	const TYPE& pick(unsigned int index) const
	{
		assert(index < num_elements);
		return queue[index];
	}

	unsigned int count() const
	{
		unsigned int counter = 0;
		node<TYPE>* tmp = start;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}

	void delAll()
	{

		if (start != NULL)
		{
			node<TYPE>* tmp = start;
			while (tmp->next != NULL)
			{
				node<TYPE>* tmp2 = tmp;
				tmp = tmp->next;
				delete tmp2;
			}
			delete tmp;
			start = NULL;
		}
	}
};
#endif