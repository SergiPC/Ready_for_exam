// --------------------------------------------
//             DLinkedList class
// --------------------------------------------

#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#include <assert.h>
#include "Utilities.h"

#define NULL 0 // for not carrying the entire library



// node from a Double Linked List ----------------------
template<class DITTO>
struct DListNode
{
	DITTO				data;
	DListNode<DITTO>*	next;
	DListNode<DITTO>*	prev;

	// Constructor -----------------------------------------
	inline DListNode(const DITTO& new_data)
	{
		data = new_data;
		next = prev = NULL;
	}

	// Destructor ------------------------------------------
	~DListNode()
	{}
};



// Manages a double linked list ------------------------
template<class DITTO>
class DLinkedList
{
public:

	DListNode<DITTO>*	head;
	DListNode<DITTO>*	bottom;

private:

	unsigned int		size; // number of nodes

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






	// EXAMEN FINAL PROGRAMACIÓ 2 (9 JUNY 2015)
	// DLinkedList :: Mètode a la classe de llista enllaçada que insereixi una altre llista enllaçada després
	// de un index donat.Si la llista està buida ha de afegir tots els elements : ----------------------------
	//insertAfter(0, mylist2)

	void insertAfter(unsigned int index, const DLinkedList<DITTO>& other_list)
	{
		DListNode<DITTO>*	tmp_my_list = at(index);
		DListNode<DITTO>*	tmp_other_list = other_list.head;

		while (tmp_other_list != NULL)
		{
			DListNode<DITTO>* new_item = new DListNode<DITTO>(tmp_other_list->data);

			//new_item->next = (tmp_my_list) ? tmp_my_list->next : NULL;	
			if (tmp_my_list != NULL)
				new_item->next = tmp_my_list->next;

			if (new_item->next != NULL)
				new_item->next->prev = new_item;

			else
				bottom = new_item;

			new_item->prev = tmp_my_list;

			if (new_item->prev != NULL)
				new_item->prev->next = new_item;

			else
				head = new_item;

			tmp_my_list = new_item;
			tmp_other_list = tmp_other_list->next;
		}
	}

	// FINAL EXAMEN PARCIAL PROGRAMACIÓ 2 (9 JUNY 2015)





	


	// Some operators --------------------------------------
	const DITTO& operator[](unsigned int index) const
	{
		long				pos;
		DListNode<DITTO>*	tmp;

		pos = 0;
		tmp = head;

		while (tmp != NULL)
		{
			if (pos == index)
				break;

			++pos;
			tmp = tmp->next;
		}

		assert(tmp);

		return(tmp->data);
	}

	DITTO& operator[](unsigned int index)
	{
		long				pos;
		DListNode<DITTO>*	tmp;

		pos = 0;
		tmp = head;

		while (tmp != NULL)
		{
			if (pos == index)
				break;

			++pos;
			tmp = tmp->next;
		}

		assert(tmp);

		return tmp->data;
	}


	const DLinkedList<DITTO>& operator +=(const  DLinkedList<DITTO>& other_list)
	{
		DListNode<DITTO>*   tmp = other_list.head;

		while (tmp != NULL)
		{
			addNode(tmp->data);
			tmp = tmp->next;
		}

		return(*this);
	}


	// Data management -------------------------------------
	// Add new node at bottom
	unsigned int addNode(const DITTO& new_data)
	{
		DListNode<DITTO>*	new_node;
		new_node = new DListNode<DITTO>(new_data);

		if (head == NULL)
			head = bottom = new_node;

		else
		{
			new_node->prev = bottom;
			bottom->next = new_node;
			bottom = new_node;
		}

		return(++size); // ++size increments size and returns the incremented number
	}


	bool delNode(const DListNode<DITTO>* node)
	{
		if (node == NULL)
			return false;

		if (node->prev != NULL)
		{
			node->prev->next = node->next;

			if (node->next != NULL)
				node->next->prev = node->prev;

			else
				bottom = node->prev;
		}

		else
		{
			if (node->next) // only get in if node->next != NULL
			{
				node->next->prev = NULL;
				head = node->next;
			}

			else
				head = bottom = NULL;
		}

		delete node;
		--size;
		return true;
	}


	// Delete some nodes
	unsigned int delNodes(int position, int num_nodes)
	{
		DListNode<DITTO>*	tmp_node = head;
		DListNode<DITTO>*	tmp_next;

		unsigned int deletedNodes = 0;
		unsigned int needed_size = num_nodes + position;

		if (position > size || num_nodes == 0) // if position isn't a valid number, or nummber of nodes deleted == 0 
			return deletedNodes;

		for (int i = 0; i < position; i++) // searching node
			tmp_node = tmp_node->next;

		if (tmp_node == NULL)
			return deletedNodes;

		if (needed_size > size)
			num_nodes = size - position;

		for (int p = 0; p < num_nodes; p++)
		{
			if (tmp_node->prev != NULL)
			{
				tmp_node->prev->next = tmp_node->next;

				if (tmp_node->next != NULL)
					tmp_node->next->prev = tmp_node->prev;

				else
					bottom = tmp_node->prev;
			}

			else
			{
				if (tmp_node->next) // only get in if tmp_node->next != NULL
				{
					tmp_node->next->prev = NULL;
					head = tmp_node->next;
				}

				else
					head = bottom = NULL;
			}

			tmp_next = tmp_node->next;
			delete tmp_node;
			tmp_node = tmp_next;
			--size;
		}

		return deletedNodes;
	}


	// Destroy and free for all!
	void delAll()
	{
		DListNode<DITTO>*	tmp_data;
		DListNode<DITTO>*	tmp_next;

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


	// Set in order ----------------------------------------
	int bubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			DListNode<DITTO>*	tmp = head;

			while (tmp != NULL && tmp->next != NULL)
			{
				++ret;

				if (tmp->data > tmp->next->data)
				{
					swap(tmp->data, tmp->next->data); // Swap Nodes -----
					swapped = true;
				}

				tmp = tmp->next;
			}
		}
		return ret;
	}


	// Utilities -------------------------------------------
	unsigned int count()
	{
		return(size);
	}


	// returns the first apperance of data as count (-1 if not found)
	int find(const DITTO& old_data)
	{
		DListNode<DITTO>* tmp = head;
		int count = 0;

		while (tmp != NULL)
		{
			if (tmp->data == old_data)
			{
				return(count);
			}
			++count;
			tmp = tmp->next;
		}
		return (-1);
	}


	const DListNode<DITTO>* at(unsigned int index) const
	{
		long					pos = 0;
		DListNode<DITTO>*		tmp = head;

		while (tmp != NULL)
		{
			if (pos == index)
				break;

			++pos;
			tmp = tmp->next;

			/*
			if (pos++ == index)
			break;

			tmp = tmp->next;
			*/
		}

		return tmp;
	}

	
	// access to a node in a position in the list
	DListNode<DITTO>* at(unsigned int index)
	{
		long					pos = 0;
		DListNode<DITTO>*		tmp = head;

		while (tmp != NULL)
		{
			if (pos == index)
				break;

			++pos;
			tmp = tmp->next;

			/*
			if (pos++ == index)
				break;

			tmp = tmp->next;
			*/
		}

		return tmp;
	}

};



#endif // __DLINKEDLIST_H__