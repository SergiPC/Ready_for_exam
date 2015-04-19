// --------------------------------------------
//                 Queue Class
// --------------------------------------------

#ifndef __QUEUE_H__
#define __QUEUE_H_
#include <stdio.h>

template<struct TYPE>
struct Queue_item
{
	TYPE				value;
	Queue_item<TYPE>*	next;
};

template<class TYPE>
class Queue
{
private:
	unsigned int	size;

public:
	Queue_item<TYPE>*	head;

	// Constructor -----------------------------------------
	Queue() : start(NULL)
	{}

	// Destructor ------------------------------------------
	~Queue()
	{
		Clear();
	}

	// Utilities -------------------------------------------
	unsigned int count() const
	{
		unsigned int result = 0;
		Queue_item<TYPE>* tmp;

		for (tmp = head; tmp != NULL; tmp = tmp->next)
			++result;

		return result;
	}

	Queue_item<TYPE>* getLast()
	{
		Queue_item<TYPE>* tmp = head;

		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;

		return tmp;
	}

	// Data management -------------------------------------
	void push(const TYPE& new_data)
	{
		Queue_item<TYPE>*	new_node;
		new_node = new Queue_item<TYPE>(new_data);
		Queue_item<TYPE>* last = getLast();

		if (last == NULL)
		{
			head = new_node;
		}
		else
		{
			last->next = new_node;
		}
		++size; // ++size increments size and returns the incremented number
	}

	bool pop(TYPE& item)
	{
		Queue_item<TYPE>* last = getLast();

		if (last != NULL)
		{
			Queue_item<TYPE>* tmp = head;

			while (tmp->next != last)
			{
				tmp = tmp->next;
			}
			item = tmp->next->value;
			delete tmp->next;
			return true;
			return(--size); // ++size increments size and returns the incremented number
		}
		return false;
	}

	const TYPE& peek(unsigned int index) const
	{
		unsigned int i = 0;
		Queue_item<TYPE>* tmp;

		for (tmp = head; tmp != NULL && i < index; tmp = tmp->next)
		{
			++i;
		}
		if (tmp != NULL)
		{
			return &(tmp->value);
		}
		return NULL;
	}

	void clear()
	{
		Queue_item<TYPE>*	p_value;
		Queue_item<TYPE>*	p_next;
		p_value = head;

		while (p_value != NULL)
		{
			p_next = p_value->next;
			delete p_value;
			p_value = p_next;
		}

		head = NULL;
	}
};
#endif