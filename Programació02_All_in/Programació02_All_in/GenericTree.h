// --------------------------------------------
//               Generic Tree
// --------------------------------------------
// http://www.rsbauer.com/class/dsa2/slides/General%20Trees.pdf


#ifndef __Tree_H__
#define __Tree_H__

#include "DLinkedList.h"
#include "Stack.h"

// Tree node -------------------------------------------
template<class DITTO>
class TreeNode
{
public:
	DITTO					data;
	TreeNode*				parent; // pointer for parent node
	DLinkedList<TreeNode*>	childs; // pointer for childs node

public:
	TreeNode(const DITTO& new_data)
	{
		data = new_data;
		parent = NULL;
	}

	void addChild(TreeNode* new_node)
	{
		childs.addNode(new_node);
		new_node->parent = this;
	}

	bool removeChild(TreeNode* old_node)
	{
		bool exit = false;
		DListNode<TreeNode*>* tmp = childs.head; // create a tmp to point to the first node

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;

			if (old_node == child)
			{
				childs.delNode(tmp);
				old_node->parent = NULL;
				exit = true;
				break;
			}
		}
		return exit;
	}

	// Pre order recursive ---------------------------------
	// 1) process root
	// 2) recursively process children from "left to right"
	void preOrderRecursive(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		new_list->addNode(this);
		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->preOrderRecursive(new_list);
	}

	// Post order recursive --------------------------------
	// 1) no node is processed until all of its children have been processed
	// 2) process root
	void postOrderRecursive(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->postOrderRecursive(new_list);

		new_list->addNode(this);
	}

	// In order recursive ----------------------------------
	// half of the children, the root and the other half of the children
	void inOrderRecursive(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		DListNode<TreeNode*>* tmp = childs.head;
		unsigned int middle = childs.count() / 2;

		for (unsigned int i = 0; i < middle; ++i, tmp = tmp->next)
			tmp->data->inOrderRecursive(new_list);

		new_list->addNode(this);

		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->inOrderRecursive(new_list);
	}

	TreeNode<DITTO>* findRecursive(const DITTO& new_node)
	{
		if (new_node == data)
			return this;

		TreeNode<DITTO>* result = NULL;
		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;
			result = child->findRecursive(new_node);

			if (result != NULL)
				break;
		}

		return result;
	}

	void gatherAll(DLinkedList<TreeNode*>* new_list)
	{
		new_list->addNode(this);

		DListNode<TreeNode*>* tmp = childs.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;
			child->gatherAll(new_list);
		}
	}
};

// Tree class ------------------------------------------
template<class DITTO>
class Tree
{
public:

	TreeNode<DITTO>	root;

public:

	// Constructor -----------------------------------------
	Tree(const DITTO& new_data) : root(new_data)
	{}

	// Destructor ------------------------------------------
	virtual ~Tree()
	{}

	void preOrderRecursive(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		root.preOrderRecursive(new_list);
	}

	void postOrderRecursive(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		root.postOrderRecursive(new_list);
	}

	void inOrderRecursive(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		root.inOrderRecursive(new_list);
	}


	// Pre order iterative ---------------------------------
	// 1) process root
	// 2) recursively process children from "left to right"
	void preOrderIterative(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		Stack<TreeNode<DITTO>*>	new_stack;
		TreeNode<DITTO>*		new_node = &root;

		while (new_node != NULL || new_stack.pop(new_node))
		{
			new_list->addNode(new_node);
			DListNode<TreeNode<DITTO>*>* tmp = new_node->childs.bottom;

			for (; tmp != new_node->childs.head; tmp = tmp->prev)
				new_stack.pushBack(tmp->data);

			if (tmp != NULL)
				new_node = tmp->data;

			else
				new_node = NULL;
		}
	}
	

	// Post order iterative --------------------------------
	// 1) no node is processed until all of its children have been processed
	// 2) process root
	void postOrderIterative(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		Stack<TreeNode<DITTO>*>	new_stack;
		TreeNode<DITTO>*		new_node = &root;

		while (new_node != NULL || new_stack.pop(new_node))
		{
			DListNode<TreeNode<DITTO>*>* tmp = new_node->childs.bottom;

			if (tmp != NULL && new_list->find(tmp->data) == -1)
			{
				new_stack.pushBack(new_node);

				for (; tmp != new_node->childs.head; tmp = tmp->prev)
					new_stack.pushBack(tmp->data);

				new_node = tmp->data;
			}

			else
			{
				new_list->addNode(new_node);
				new_node = NULL;
			}
		}
	}
	

	// In order iterative ----------------------------------
	void inOrderIterative(DLinkedList<TreeNode<DITTO>*>* new_list)
	{
		Stack<TreeNode<DITTO>*>	new_stack;
		TreeNode<DITTO>*		new_node = &root;

		unsigned int middle = 0;
		new_stack.pushBack(new_node);

		while (new_node != NULL)
		{
			DListNode<TreeNode<DITTO>*>* tmp = new_node->childs.head;
			unsigned int middle = new_node->childs.count() / 2;

			if (tmp != NULL)
			{
				for (unsigned int i = 0; i < middle; ++i, tmp = tmp->next)
					new_stack.pushBack(tmp->data);

				new_node = new_node->childs.head->data;
			}

			else
			{
				new_list->addNode(new_node);
				new_stack.pop(new_node);
				new_node = NULL;

				//new_list->addNode(new_node);
				//new_stack.pop(new_node);
				//new_node = tmp->next->data;				
			}
		}
	}

	void add(const DITTO& new_data, const DITTO& new_parent)
	{
		TreeNode<DITTO>* p = root.findRecursive(new_parent);
		TreeNode<DITTO>* new_node = new TreeNode<DITTO>(new_data);
		p->addChild(new_node);
	}

	void add(const DITTO& new_data)
	{
		TreeNode<DITTO>* new_node = new TreeNode<DITTO>(new_data);
		root.addChild(new_node);
	}

	void clear()
	{
		DLinkedList<TreeNode<DITTO>*> results;
		root.gatherAll(&results);
		DListNode<TreeNode<DITTO>*>* tmp = results.head;

		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode<DITTO>* child = tmp->data;

			if (child->parent)
				child->parent->removeChild(child);
		}
	}
};

#endif // __Tree_H__