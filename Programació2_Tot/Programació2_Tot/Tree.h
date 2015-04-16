//Arbres

/*
Permet fer búsquedes molt ràpides si està ben ordenat
Root node (inicial)
SubTree (nodes mitjos. Poden ser utilitzats com a root node, ja que tenen altres nodes que penjen d'ells)
Leaf node (nodes finals, no tenen cap que penji d'ells)
Binary tree
QuadTree
OctTree
Poden revisar-se en		preOrder (primer els pares i despres els fills)
postOrder (primer els fills i despres els pares)
inOrder (la meitat dels fills, el pare, l'altra meitat dels fills)
*/

#include <stdlib.h>
#include "DLinkedList.h"

template <class TYPE>
class TreeNode
{

public:
	TreeNode(){ data = NULL; };
	TreeNode(TYPE _data){ data = _data; }

	TreeNode<TYPE>* parent;
	DLinkedList<TreeNode<TYPE>*> branches;
	TYPE data;

	void VisitPostOrder_Rec(DLinkedList <TYPE>* list) const
	{
		int node = branches.Count();
		for (int n = 0; n < node; n++)
		{
			branches.Get(n)->value->VisitPostOrder_Rec(list);
		}
		list->Add(data);
	}

	void VisitPreOrder_Rec(DLinkedList <TYPE>* list) const
	{
		list->Add(data);
		int node = branches.Count();
		for (int n = 0; n < node; n++)
		{
			branches.Get(n)->value->VisitPreOrder_Rec(list);
		}
	}

	void VisitInOrder_Rec(DLinkedList <TYPE>* list) const
	{
		int node = branches.Count();
		int n = 0;

		for (; n < node / 2; n++)
		{
			branches.Get(n)->value->VisitInOrder_Rec(list);
		}

		list->Add(data);

		for (; n < node; n++)
		{
			branches.Get(n)->value->VisitInOrder_Rec(list);
		}
	}

};

template <class TYPE>
class cTree
{

	TreeNode<TYPE>* rootNode;

public:

	//Constructor
	cTree() { rootNode = NULL; }


	//Destructor
	~cTree() { Clear(); }


	//Getters
	const TreeNode<TYPE>* GetRoot() const { return rootNode; }


	//Visit
	void VisitPreOrder_Rec(DLinkedList <TYPE>* list) const { rootNode->VisitPreOrder_Rec(list); }
	void VisitPostOrder_Rec(DLinkedList <TYPE>* list) const { rootNode->VisitPostOrder_Rec(list); }
	void VisitInOrder_Rec(DLinkedList <TYPE>* list) const { rootNode->VisitInOrder_Rec(list); }

	//Add
	TreeNode<TYPE>* Add(const TYPE& data, TreeNode<TYPE>* parent = NULL)
	{
		if (parent == NULL && rootNode != NULL)
		{
			return NULL;
		}
		TreeNode<TYPE>* newNode = new TreeNode<TYPE>(data);
		if (rootNode == NULL)
		{
			newNode->parent = NULL;
			rootNode = newNode;
		}
		else if (parent != NULL)
		{
			parent->branches.Add(newNode);
			newNode->parent = parent;
		}
		return newNode;
	}


	//Clear
	void Clear(TreeNode<TYPE>* nodeToErase = NULL)
	{
		if (nodeToErase == NULL)
		{
			nodeToErase = rootNode;
		}
		int node = nodeToErase->branches.Count();
		for (int n = 0; n < node; n++)
		{
			Clear(nodeToErase->branches.GetFirst()->value);
		}
		if (nodeToErase != rootNode)
		{
			TreeNode<TYPE>* myParent = nodeToErase->parent;
			myParent->branches.Del(myParent->branches.GetFirst());
		}
		delete nodeToErase;
	}

};