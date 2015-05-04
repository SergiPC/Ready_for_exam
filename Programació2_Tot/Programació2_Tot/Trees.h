// --------------------------------------------
//               Generic Tree
// --------------------------------------------

#ifndef __Tree_H__
#define __Tree_H__

#include "DLinkedList.h"
#include "Stack.h"

// Tree node -------------------------------------------
template<class KIND>
class TreeNode
{
public:
	KIND					data;
	TreeNode*				parent;
	DLinkedList<TreeNode>*	childs;

public:
	TreeNode(const KIND& new_data)
	{
		data = new_data;
		parent = NULL;
	}

	void addChild(TreeNode* new_node)
	{
		//ASSERT(node);

		childs.add(new_node);
		new_node->parent = this;
	}

	bool removeChild(TreeNode* old_node)
	{
		//ASSERT(node);

		bool ret = false;

		node<TreeNode*>* tmp = childs.head;
		for (; tmp != NULL; tmp = tmp->next)
		{
			TreeNode* child = tmp->data;

			if (old_node == child)
			{
				childs.del(tmp);
				old_node->parent = NULL;
				ret = true;
				break;
			}
		}
		return ret;
	}

	void preOrderRecursive(DLinkedList<TreeNode<KIND>*>* list)
	{
		list->addNode(this);

		node<TreeNode*>* item = childs.head;

		for (; item != NULL; item = item->next)
		{
			item->data->preOrderRecursive(list);
		}
	}

	void inOrderRecursive(DLinkedList<TreeNode<KIND>*>* list)
	{
		node<TreeNode*>* item = childs.head;
		unsigned int mid = childs.count() / 2;

		for (unsigned int i = 0; i < mid; ++i, item = item->next)
		{
			item->data->inOrderRecursive(list);
		}

		list->add(this);

		for (; item != NULL; item = item->next)
		{
			item->data->inOrderRecursive(list);
		}
	}

	void postOrderRecursive(DLinkedList<TreeNode<KIND>*>* list)
	{
		node<TreeNode*>* item = childs.head;

		for (; item != NULL; item = item->next)
		{
			item->data->postOrderRecursive(list);
		}

		list->add(this);
	}

	TreeNode<KIND>* findRecursive(const KIND& new_node)
	{
		if (new_node == data)
		{
			return this;
		}

		TreeNode<KIND>* result = NULL;
		DLinkedList<TreeNode*>* item = childs.head;
		for (; item != NULL; item = item->next)
		{
			TreeNode* child = item->data;
			result = child->findRecursive(node);

			if (result != NULL)
			{
				break;
			}
		}
		return result;
	}

	void gatherAll(DLinkedList<TreeNode*>* list)
	{
		//ASSERT(list);
		list->add(this);

		DLinkedList<TreeNode*>* item = childs.head;

		for (; item != NULL; item = item->next)
		{
			TreeNode* child = item->data;
			child->gatherAll(list);
		}
	}

	void gatherAllData(DLinkedList<KIND>* list)
	{
		//ASSERT(list);
		list->add(data);

		DLinkedList<TreeNode*>* item = childs.start;

		for (; item != NULL; item = item->next)
		{
			TreeNode* child = item->data;
			child->gatherAllData(list);
		}
	}

};

// Tree class -------------------------------------------------------
template<class KIND>
class Tree
{
public:

	TreeNode<KIND>	trunk;

public:

	// Constructor
	Tree(const KIND& new_data) : trunk(new_data)
	{}

	// Destructor
	virtual ~Tree()
	{}

	void preOrderRecursive(DLinkedList<TreeNode<KIND>*>* list)
	{
		trunk.preOrderRecursive(list);
	}

	void postOrderRecursive(DLinkedList<TreeNode<KIND>*>* list)
	{
		trunk.postOrderRecursive(list);
	}

	void inOrderRecursive(DLinkedList<TreeNode<KIND>*>* list)
	{
		trunk.inOrderRecursive(list);
	}

	void preOrderIterative(DLinkedList<TreeNode<KIND>*>* list)
	{
		Stack<TreeNode<KIND>*> stack;
		TreeNode<KIND>* new_node = &trunk;

		while (new_node != NULL || stack.pop(node))
		{
			list->add(new_node);

			node<TreeNode<KIND>*>* tmp = new_node->childs.bottom;
			for (; tmp != new_node->childs.head; tmp = tmp->prev)
			{
				stack.push(tmp->data)
			}

			new_node = (tmp != NULL) ? tmp->data : NULL; // IMPORTANT!!!
		}
	}

	void postOrderIterative(DLinkedList<TreeNode<KIND>*>* list)
	{
		Stack<TreeNode<KIND>*> stack;
		TreeNode<KIND>* new_node = &trunk;

		while (new_node != NULL || stack.pop(new_node))
		{
			node<TreeNode<KIND>*>* item = new_node->childs.bottom;

			if (item != NULL && list->find(item->data) == -1)
			{
				stack.push(node);
				for (; item != new_node->childs.head; item = item->prev)
					stack.push(item->data);

				new_node = item->data;
			}
			else
			{
				list->add(new_node);
				new_node = NULL;
			}
		}
	}

	void inOrderIterative(DLinkedList<TreeNode<KIND>*>* list)
	{
		Stack<TreeNode<KIND>*> stack;
		TreeNode<KIND>* new_node = &trunk;

		while (new_node != NULL || stack.pop(new_node))
		{
			list->add(new_node);

			node<TreeNode<KIND>*>* item = new_node->childs.bottom;
			for (; item != new_node->childs.head; item = item->prev)
				stack.push(item->data);

			new_node = (item != NULL) ? item->data : NULL;
		}
	}

	void add(const KIND& data, const KIND& parent)
	{
		TreeNode<KIND>* p = trunk.findRecursive(parent);
		TreeNode<KIND>* new_node = new TreeNode<KIND>(data);
		p->addChild(new_node);
	}

	void add(const KIND& data)
	{
		TreeNode<KIND>* new_node = new TreeNode<KIND>(data);
		trunk.addChild(new_node);
	}

	bool relocate(const KIND& data, const KIND& parent)
	{
		bool ret = false;

		TreeNode<KIND>* dad = trunk.findRecursive(parent);
		TreeNode<KIND>* child = trunk.findRecursive(data);

		if (dad && child && child->parent != dad)
		{
			child->parent->removeChild(child);
			dad->addChild(child);
			ret = true;
		}

		return ret;
	}

	bool delRecursive(const KIND& data)
	{
		bool ret = false;

		TreeNode<KIND>* new_node = trunk.findRecursive(data);

		if (new_node != NULL)
		{
			DLinkedList<TreeNode<KIND>*> results;
			new_node->gatherAll(&results);

			node<TreeNode<KIND>*>* item = results.head;

			for (; item != NULL; item = item->next)
			{
				TreeNode<KIND>* child = item->data;

				if (child->parent)
					child->parent->removeChild(child);
			}

			ret = true;
		}

		return ret;
	}

	void clear()
	{
		DLinkedList<TreeNode<KIND>*> results;
		trunk.gatherAll(&results);

		node<TreeNode<KIND>*>* item = results.head;
		for (; item != NULL; item = item->next)
		{
			TreeNode<KIND>* child = item->data;
			if (child->parent)
				child->parent->RrmoveChild(child);
		}
	}
};




#endif // __Tree_H__