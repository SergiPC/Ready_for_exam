// --------------------------------------------
//             DLinkedList cLass
// --------------------------------------------

#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#include <assert.h>
#define NULL 0 // for not carrying the entire library


// node from a Double Linked List ----------------------
template<class kdata>
struct node
{
	kdata			data;
	node<kdata>*	next;
	node<kdata>*	prev;

	// Constructor -----------------------------------------
	inline node(const kdata& new_data)
	{
		data = new_data;
		next = prev = NULL;
	}

	// Destructor ------------------------------------------
	~node()
	{}
};


// Manages a double linked list ------------------------
template<class kdata>
class DLinkedList
{
public:
	
	node<kdata>*	head;
	node<kdata>*	bottom;

private:

	unsigned int	size;

public:

	// Constructor -----------------------------------------
	DLinkedList()
	{
		head = bottom = NULL;
		size = 0;
	}

	// Destructor ------------------------------------------
	~DLinkedList()
	{
		delAll();
	}

	// Get size counter ------------------------------------
	unsigned int count()
	{
		return(size);
	}

	// Operator[] ------------------------------------------
	const kdata& operator[](unsigned int index) const
	{
		long			pos;
		node<kdata>*	tmp;

		pos = 0;
		tmp = head;

		while (tmp != NULL)
		{
			if (pos == index)
			{
				break;
			}

			++pos;
			tmp = tmp->next;
		}

		assert(tmp);
	}

	kdata& operator[](unsigned int index)
	{
		long			pos;
		node<kdata>*	tmp;

		pos = 0;
		tmp = head;

		while (tmp != NULL)
		{
			if (pos == index)
			{
				break;
			}

			++pos;
			tmp = tmp->next;
		}

		//assert(tmp);
		return tmp->data;
	}

	
	// BubbleSort ------------------------------------------
	int bubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			node<kdata>*	tmp = head;
		
			while (tmp != NULL && tmp->next != NULL)
			{
				++ret;

				if (tmp->data > tmp->next->data)
				{
					swap(tmp, tmp->next); // Swap Nodes -----
					swapped = true;
				}

				tmp = tmp->next;
			}
		}
		return ret;
	}

	void swap(node<kdata>*& a, node<kdata>*& b){
		node<kdata>* tmp = a;
		
		a->next->prev = b;
		a->prev->next = b;
		a->next = b->next;
		a->prev = b->prev;

		b->next->prev = a;
		b->prev->next = a;
		b->next = tmp->next;
		b->prev = tmp->prev;
	}
	

	// Add new node at bottom ------------------------------
	unsigned int addNode(const kdata& new_data)
	{
		node<kdata>*	new_node;
		new_node = new node<kdata>(new_data);
		if (head == NULL)
		{
			head = bottom = new_node;
		}
		else
		{
			new_node->prev = bottom;
			bottom->next = new_node;
			bottom = new_node;
		}
		return(++size); // ++size increments size and returns the incremented number
	}

	// Deletes an item -------------------------------------
	bool delNode(const node<kdata>* node)
	{
		if (node == NULL)
		{
			return false;
		}
		
		if (node->prev != NULL)
		{
			node->prev->next = node->next;
			if (node->next != NULL)
			{
				node->next->prev = node->prev;
			}
			else
			{
				bottom = node->prev;
			}
		}
		else
		{
			if (node->next) // only get in if node->next != NULL
			{
				node->next->prev = NULL;
				head = node->next;
			}
			else
			{
				head = bottom = NULL;
			}
		}
		delete node;
		--size;
		return true;
	}


	// Delete some nodes -----------------------------------
	unsigned int delNodes(int posicio, int num_nodes)
	{
		unsigned int deletedNodes = 0;
		node<kdata>*	tmp_node;
		node<kdata>*	tmp_next;
		tmp_node = head;
		unsigned int needed_size = num_nodes + posicio;

		if (posicio > size || num_nodes == 0) // if posicio isn't a valid number, or nummber of nodes deleted == 0 
		{
			return deletedNodes;
		}

		for (int i = 0; i < posicio; i++) // searching node
		{
			tmp_node = tmp_node->next;
		}

		if (tmp_node == NULL)
		{
			return deletedNodes;
		}

		if (needed_size > size)
		{
			num_nodes = size - posicio;
		}

		for (int p = 0; p < num_nodes; p++)
		{
			if (tmp_node->prev != NULL)
			{
				tmp_node->prev->next = tmp_node->next;
				if (tmp_node->next != NULL)
				{
					tmp_node->next->prev = tmp_node->prev;
				}
				else
				{
					bottom = tmp_node->prev;
				}
			}
			else
			{
				if (tmp_node->next) // only get in if tmp_node->next != NULL
				{
					tmp_node->next->prev = NULL;
					head = tmp_node->next;
				}
				else
				{
					head = bottom = NULL;
				}
			}
			tmp_next = tmp_node->next;
			delete tmp_node;
			tmp_node = tmp_next;
			--size;
		}
		return deletedNodes;
	}





	// Destroy and free for all! ---------------------------
	void delAll()
	{
		node<kdata>*	tmp_data;
		node<kdata>*	tmp_next;
		tmp_data = head;

		while (tmp_data != NULL)
		{
			tmp_next = tmp_data->next;
			delete tmp_data;
			tmp_data = tmp_next;
		}
		head = bottom = NULL;
		size = 0;
	}
};

#endif // __DLINKEDLIST_H__