// --------------------------------------------
//             DLinkedList cLass
// --------------------------------------------

#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

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