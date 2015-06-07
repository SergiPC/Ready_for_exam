// --------------------------------------------
//                 Queue class
// --------------------------------------------

#ifndef __QUEUE_H__
#define __QUEUE_H_

#include <stdio.h>

template<struct DITTO>
struct Queue_item
{
	DITTO				value;
	Queue_item<DITTO>*	next;
};


template<class DITTO>
class Queue
{
public:
	Queue_item<DITTO>*	head;

	// Constructor -----------------------------------------
	Queue() : start(NULL)
	{}


	// Destructor ------------------------------------------
	~Queue()
	{
		Clear();
	}


	// Data management -------------------------------------
	void push(const DITTO& new_data)
	{
		Queue_item<DITTO>*	new_node;
		new_node = new Queue_item<DITTO>(new_data);

		Queue_item<DITTO>* last = getLast();

		if (last == NULL)
			head = new_node;

		else
			last->next = new_node;

		++size; // ++size increments size and returns the incremented number
	}


	bool pop(DITTO& item)
	{
		Queue_item<DITTO>* last = getLast();

		if (last != NULL)
		{
			Queue_item<DITTO>* tmp = head;

			while (tmp->next != last)
				tmp = tmp->next;

			item = tmp->next->value;
			delete tmp->next;

			return true;
			return(--size); // ++size increments size and returns the incremented number
		}

		return false;
	}


	const DITTO& peek(unsigned int index) const
	{
		unsigned int i = 0;
		Queue_item<DITTO>* tmp;

		for (tmp = head; tmp != NULL && i < index; tmp = tmp->next)
			++i;

		if (tmp != NULL)
			return &(tmp->value);

		return NULL;
	}


	void clear()
	{
		Queue_item<DITTO>*	p_value;
		Queue_item<DITTO>*	p_next;
		p_value = head;

		while (p_value != NULL)
		{
			p_next = p_value->next;
			delete p_value;
			p_value = p_next;
		}

		head = NULL;
	}


	// Utilities -------------------------------------------
	unsigned int count() const
	{
		unsigned int result = 0;
		Queue_item<DITTO>* tmp;

		for (tmp = head; tmp != NULL; tmp = tmp->next)
			++result;

		return result;
	}


	Queue_item<DITTO>* getLast()
	{
		Queue_item<DITTO>* tmp = head;

		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;

		return tmp;
	}
};

#endif // __QUEUE_H__