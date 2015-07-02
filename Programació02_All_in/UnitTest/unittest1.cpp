#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programació02_All_in/Point2D.h"
#include "../Programació02_All_in/CString.h"
#include "../Programació02_All_in/GenericTree.h"
#include "../Programació02_All_in/DynArray.h"
#include "../Programació02_All_in/Projectile.h"
#include "../Programació02_All_in/DLinkedList.h"
#include "../Programació02_All_in/Cercle.h"
#include "../Programació02_All_in/Queue.h"
#include "../Programació02_All_in/Stack.h"
#include "../Programació02_All_in/Utilities.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// EXAMEN FINAL PROGRAMACIÓ 2 (9 JUNY 2015)
		
		// String :: Mètode per tallar una cadena rebent la posició inicial i final: -----------------------------
		TEST_METHOD(CString_cut)
		{
			CString s1("Hola mundo");

			s1.cut(2, 5);

			Assert::AreEqual((int)strcmp("Houndo", s1.getString()), 0);

			s1.cut(3, 0);

			Assert::AreEqual((int)strcmp("Hou", s1.getString()), 0);
		}


		// DynArray :: Operador += al DynArray que concatena dos arrays: -----------------------------------------
		TEST_METHOD(DynArray_Operator_concat)
		{
			DynArray<int> array(5);

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(4);
			array.pushBack(5);
			array.pushBack(8);

			DynArray<int> array2;

			array2.pushBack(991);
			array2.pushBack(992);
			array2.pushBack(993);

			array += array2;

			Assert::AreEqual((int)array.count(), 8);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 991);
			Assert::AreEqual((int)array[6], 992);
			Assert::AreEqual((int)array[7], 993);
		}

		
		// DLinkedList :: Mètode a la classe de llista enllaçada que insereixi una altre llista enllaçada després
		// de un index donat.Si la llista està buida ha d'afegir tots els elements : ----------------------------
		TEST_METHOD(ListInsert)
		{
			DLinkedList<int> mylist;

			DLinkedList<int> mylist2;

			mylist2.addNode(1);
			mylist2.addNode(2);
			mylist2.addNode(3);

			DLinkedList<int> mylist3;

			mylist3.addNode(4);
			mylist3.addNode(5);
			mylist3.addNode(6);

			mylist.insertAfter(0, mylist2);

			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 3);

			
			mylist.insertAfter(1, mylist3);

			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 2);
			Assert::AreEqual(mylist[2], 4);
			Assert::AreEqual(mylist[3], 5);
			Assert::AreEqual(mylist[4], 6);
			Assert::AreEqual(mylist[5], 3);
			
			mylist.insertAfter(0, mylist3);

			Assert::AreEqual(mylist[0], 1);
			Assert::AreEqual(mylist[1], 4);
			Assert::AreEqual(mylist[2], 5);
			Assert::AreEqual(mylist[3], 6);
			Assert::AreEqual(mylist[4], 2);
			Assert::AreEqual(mylist[5], 4);
			Assert::AreEqual(mylist[6], 5);
			Assert::AreEqual(mylist[7], 6);
			Assert::AreEqual(mylist[8], 3);

			Assert::IsTrue((DListNode<int>*) &mylist[0] == mylist.head);
			Assert::IsTrue((DListNode<int>*) &mylist[8] == mylist.bottom);
		}

		
		// GeneralTree :: Mètode recursiu i mètode iteratiu per sumar totes les dades de un arbre: ---------------
		TEST_METHOD(TreeCalcAddition)
		{
			Tree<int> tree(1);

			tree.add(2, 1);
			tree.add(3, 1);
			tree.add(4, 1);
			tree.add(5, 2);
			tree.add(6, 2);
			tree.add(7, 2);
			tree.add(8, 4);
			tree.add(9, 4);
			tree.add(10, 9);

			Assert::AreEqual((int)tree.calcAdditionRecursive(), 55);
			Assert::AreEqual((int)tree.calcAdditionIterative(), 55);
		}


		// FINAL EXAMEN PARCIAL PROGRAMACIÓ 2 (9 JUNY 2015)







		




		
		// EXAMEN PARCIAL PROGRAMACIÓ 2 (24 MARÇ 2015)
		// Projectile ----------------------------------------
		TEST_METHOD(Projectile_test)
		{
			Projectile p;

			p.point.x = 10.0f;
			p.point.y = 10.0f;

			p.speed.x = 2.0f;
			p.speed.y = 0.0f;

			Point2D<float> current = p.getCurrentPosition(3.0f);

			Assert::AreEqual((float)16.0f, current.x, 0.00001f);
			Assert::AreEqual((float)10.0f, current.y, 0.00001f);
		}


		// DynArray remove wasted memory ----------------------------------------
		TEST_METHOD(DynArray_optimizeMem)
		{
			DynArray<int> array(10);

			array.pushBack(1);
			array.pushBack(2);
			array.pushBack(3);

			Assert::AreEqual((unsigned int)10, array.getCapacity());

			unsigned int wasted = array.removeWastedMemory();

			Assert::AreEqual((unsigned int)3, array.getCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}


		// DLinkedList delete few nodes ----------------------------------------
		TEST_METHOD(DLinkedList_delNodes_mid)
		{
			DLinkedList<int> l;

			l.addNode(1);
			l.addNode(2);
			l.addNode(3);
			l.addNode(4);

			l.delNodes(1, 2);

			Assert::AreEqual((int)1, l.head->data);
			Assert::AreEqual((int)4, l.bottom->data);
			Assert::AreEqual((unsigned int)2, l.count());
		}

		// DLinkedList delete few nodes ----------------------------------------
		TEST_METHOD(DLinkedList_delNodes_begin)
		{
			DLinkedList<int> l;

			l.addNode(1);
			l.addNode(2);
			l.addNode(3);
			l.addNode(4);

			l.delNodes(0, 3);

			Assert::AreEqual((int)4, l.head->data);
			Assert::AreEqual((int)4, l.bottom->data);
			Assert::AreEqual((unsigned int)1, l.count());
		}

		// DLinkedList delete few nodes ----------------------------------------
		TEST_METHOD(DLinkedList_delNodes_end)
		{
			DLinkedList<int> l;

			l.addNode(1);
			l.addNode(2);
			l.addNode(3);
			l.addNode(4);

			l.delNodes(2, 100);

			Assert::AreEqual((int)1, l.head->data);
			Assert::AreEqual((int)2, l.bottom->data);
			Assert::AreEqual((unsigned int)2, l.count());
		}


		// CString prefix ----------------------------------------

		TEST_METHOD(String_prefix)
		{
			CString a("1234567890");
			CString b(50);
			b = "hola";

			a.prefix(b);
			b.prefix("1234567890");

			Assert::AreEqual(strcmp(a.getString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.getString(), "1234567890hola"), 0);
		}

		// FINAL EXAMEN PARCIAL PROGRAMACIÓ 2 (24 MARÇ 2015)











		// Point2D ---------------------------------------------
		TEST_METHOD(Point2D_operatoMinus)
		{
			Point2D<float> t, f, p;
			p.x = p.y = f.x = f.y = 3;
			t = p - f;

			Assert::IsTrue(t.x == 0 && t.y == 0);
		}

		TEST_METHOD(Point2D_operatoPlus)
		{
			Point2D<float> t, f, p;
			t = p + f;

			Assert::IsTrue(p.x + f.x == t.x && p.y + f.y == t.y);
		}

		TEST_METHOD(Point2D_operatorPlusEqual)
		{
			Point2D<float> f, p;
			f.x = 5.0f;
			f.y = 6.0f;
			p.x = 7.0f;
			p.y = 8.0f;

			f += p;

			Assert::AreEqual(f.x, 12.0f && p.y, 14.0f);
		}

		TEST_METHOD(Point2D_operatorMinusEqual)
		{
			Point2D<float> f, p;
			f.x = 8.0f;
			f.y = 7.0f;
			p.x = 6.0f;
			p.y = 5.0f;

			f -= p;

			Assert::AreEqual(f.x, 2.0f && p.y, 2.0f);
		}

		TEST_METHOD(Point2D_operatorEqualEqual)
		{
			Point2D<float> f, p;
			f.x = 5.0f;
			f.y = 6.0f;
			p.x = 5.0f;
			p.y = 6.0f;

			Assert::IsTrue(f == p);
		}

		TEST_METHOD(Point2D_operatorNotEqual)
		{
			Point2D<float> f, p;
			f.x = 5.0f;
			f.y = 6.0f;
			p.x = 7.0f;
			p.y = 8.0f;

			Assert::IsTrue(f != p);
		}

		TEST_METHOD(Point2D_isZero)
		{
			Point2D<float> p;
			p.x = p.y = 0.0f;

			Assert::IsTrue(p.isZero());
		}

		TEST_METHOD(Point2D_setZero)
		{
			Point2D<float> p;
			p.setZero();

			Assert::IsTrue(p.isZero());
		}

		TEST_METHOD(Point2D_distanceTo)
		{
			Point2D<float> f, p;
			f.x = 0;
			f.y = 0;
			p.x = 2;
			p.y = 0;

			Assert::IsTrue(f.distanceTo(p) == 2);
		}


		// CString ---------------------------------------------
		TEST_METHOD(CString_trim)
		{
			CString s("    Metal Gear   ");
			s.trim();

			Assert::AreEqual((int)s.length(), 10);
		}

		TEST_METHOD(CString_constructor)
		{
			CString s;

			Assert::AreEqual((int)s.length(), 0);
		}

		TEST_METHOD(CString_size_constructor)
		{
			CString s("Metal Gear");

			Assert::AreEqual((int)s.length(), 10);
		}

		TEST_METHOD(CString_string_constructor)
		{
			CString s("%s %s %d", "Metal", "Gear", 12);
			CString s2(s);

			Assert::AreEqual((int)s2.length(), 13);
		}

		TEST_METHOD(CString_format_constructor)
		{
			CString s("%s %s %d", "Metal", "Gear", 12);

			Assert::AreEqual((int)s.length(), 13);
		}

		TEST_METHOD(CString_operator_equal)
		{
			CString s1("Metal Gear");
			CString s2("Metal Gear");

			Assert::IsTrue(s1 == s2);
		}

		TEST_METHOD(CString_operator_notequal)
		{
			CString s1("Metal Gear Solid");
			CString s2("Metal Gear Rising");

			Assert::IsTrue(s1 != s2);
		}

		TEST_METHOD(CString_operator_equal_string)
		{
			CString s1("Metal Gear");

			Assert::IsTrue(s1 == "Metal Gear");
		}

		TEST_METHOD(CString_operator_notequal_char)
		{
			CString s1("Metal Gear Solid");

			Assert::IsTrue(s1 != "Metal Gear Rising");
		}

		TEST_METHOD(CString_operator_assign)
		{
			CString s1("Metal Gear");
			CString s2;

			s2 = s1;

			Assert::IsTrue(s2 == "Metal Gear");
		}

		TEST_METHOD(CString_operator_assign_char)
		{
			CString s1("Metal Gear Solid");

			s1 = "Metal Gear Rising";

			Assert::IsTrue(s1 == "Metal Gear Rising");
		}

		TEST_METHOD(CString_operator_plusequal)
		{
			CString s1("Metal Gear");
			CString s2(" Solid");

			s1 += s2;

			Assert::IsTrue(s1 == "Metal Gear Solid");
		}

		TEST_METHOD(CString_operator_plusequal_char)
		{
			CString s1("Metal Gear");

			s1 += " Solid";

			Assert::IsTrue(s1 == "Metal Gear Solid");
		}

		TEST_METHOD(CString_length)
		{
			CString s1("Metal Gear");

			Assert::AreEqual((int)s1.length(), 10);
		}

		TEST_METHOD(CString_getcapacity)
		{
			CString s1("Metal Gear");

			Assert::AreEqual((int)s1.getCapacity(), 11);
		}

		TEST_METHOD(CString_getstring)
		{
			CString s1("Metal Gear");

			Assert::AreEqual((int)strcmp("Metal Gear", s1.getString()), 0);
		}

		TEST_METHOD(CString_clear)
		{
			CString s1("Metal Gear");

			s1.clear();

			Assert::AreEqual((int)s1.length(), 0);
		}


		// DLinkedList -----------------------------------------
		TEST_METHOD(DLinkedList_add_node)
		{
			DLinkedList<int> new_list;
			Assert::AreEqual((int)new_list.addNode(22), 1);
		}

		TEST_METHOD(DLinkedList_del_node)
		{
			DLinkedList<int> new_list;
			new_list.addNode(22); new_list.addNode(5);
			new_list.delNode(new_list.head);
			Assert::AreEqual((int)new_list.addNode(4), 2);
		}

		TEST_METHOD(DLinkedList_del_all)
		{
			DLinkedList<int> new_list;
			new_list.addNode(22); new_list.addNode(5); new_list.addNode(21); new_list.addNode(4);
			new_list.delAll();
			Assert::AreEqual((int)new_list.count(), 0);
		}

		// I think this method isn't necessary because we checked it in the previous Assert, but i'm not sure
		TEST_METHOD(DLinkedList_counting)
		{
			DLinkedList<int> new_list;
			new_list.addNode(22); new_list.addNode(5); new_list.addNode(21); new_list.addNode(4);
			Assert::AreEqual((int)new_list.count(), 4);
		}

		TEST_METHOD(DLinkedList_operator)
		{
			DLinkedList<int> new_list;

			new_list.addNode(22);
			new_list.addNode(5);
			new_list.addNode(21);
			new_list.addNode(4);

			Assert::AreEqual((int)new_list[2], 21);
		}

		
		TEST_METHOD(DLinkedList_bubbleSort)
		{
			DLinkedList<int> new_list;

			new_list.addNode(22);
			new_list.addNode(5);
			new_list.addNode(21);
			new_list.addNode(4);

			new_list.bubbleSort();

			Assert::AreEqual((int)new_list[3], 22);
		}
		


		// DynArray --------------------------------------------
		TEST_METHOD(DynArray_creator)
		{
			DynArray<int> new_array;

			Assert::AreEqual((int)new_array.getCapacity(), DYN_ARRAY_PRED_SIZE);
		}

		TEST_METHOD(DynArray_creator_capacity)
		{
			DynArray<int> new_array(4);

			Assert::AreEqual((int)new_array.getCapacity(), 4);
		}

		TEST_METHOD(DynArray_operator)
		{
			DynArray<int> new_array;
			new_array.pushBack(1);
			new_array.pushBack(2);

			Assert::AreEqual(new_array[0], 1);
			Assert::AreEqual(new_array[1], 2);
		}

		TEST_METHOD(DynArray_push_back)
		{
			DynArray<int> new_array;
			new_array.pushBack(1);
			new_array.pushBack(2);

			Assert::AreEqual((int)new_array.getCapacity(), DYN_ARRAY_PRED_SIZE);
			Assert::AreEqual((int)new_array.count(), 2);
		}

		TEST_METHOD(DynArray_pop)
		{
			DynArray<int> new_array;
			int d;
			new_array.pushBack(1);
			new_array.pushBack(2);
			new_array.pop(d);

			Assert::AreEqual((int)new_array.count(), 1);
		}

		TEST_METHOD(DynArray_clear)
		{
			DynArray<int> new_array;
			new_array.pushBack(1);
			new_array.pushBack(2);
			new_array.clear();

			Assert::AreEqual((int)new_array.getCapacity(), DYN_ARRAY_PRED_SIZE);
			Assert::AreEqual((int)new_array.count(), 0);
		}


		TEST_METHOD(DynArray_at)
		{
			DynArray<int> new_array;
			new_array.pushBack(1);
			new_array.pushBack(2);

			Assert::AreEqual(*(new_array.at(0)), 1);
			Assert::AreEqual(*(new_array.at(1)), 2);
			Assert::IsNull(new_array.at(2));
		}

		
		TEST_METHOD(DynArray_insert)
		{
			DynArray<int> new_array;

			for (int i = 0; i < DYN_ARRAY_PRED_SIZE; ++i)
			{
				new_array.pushBack(i);
			}

			new_array.insert(22, 4);
			new_array.insert(4, 30);
			Assert::IsFalse(new_array.insert(4, 30));
			Assert::AreEqual((int)new_array.count(), 23);
			Assert::AreEqual((int)new_array[4], 22);
		}
		

		TEST_METHOD(DynArray_bubblesort)
		{
			DynArray<int> new_array;

			new_array.pushBack(5);
			new_array.pushBack(4);
			new_array.pushBack(1);
			new_array.pushBack(2);
			new_array.pushBack(8);

			new_array.bubbleSort();

			Assert::AreEqual((int)new_array[0], 1);
			Assert::AreEqual((int)new_array[1], 2);
			Assert::AreEqual((int)new_array[2], 4);
			Assert::AreEqual((int)new_array[3], 5);
			Assert::AreEqual((int)new_array[4], 8);
		}


		// Tree ------------------------------------------------
		TEST_METHOD(Tree_add)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);

			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);

			tree.add(210, 200);
			tree.add(220, 200);

			tree.add(221, 220);

			// Just do not test that we run forever because of the recursion
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Tree_preOrderIterative)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('X', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.preOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(Tree_postOrderIterative)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.postOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}


		TEST_METHOD(Tree_preOrder)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('X', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.preOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(Tree_postOrder)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.postOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(Tree_inOrder)
		{
			Tree<char> tree('F');

			tree.add('B', 'F');
			tree.add('G', 'F');
			tree.add('A', 'B');
			tree.add('D', 'B');
			tree.add('C', 'D');
			tree.add('E', 'D');
			tree.add('I', 'G');
			tree.add('H', 'I');

			DLinkedList<TreeNode<char>*> list;
			tree.inOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Tree_gather)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);
			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);
			tree.add(210, 200);
			tree.add(220, 200);
			tree.add(221, 220);

			DLinkedList<TreeNode<int>*> list;
			tree.root.gatherAll(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((int)list[0]->data, 0);
			Assert::AreEqual((int)list[1]->data, 100);
			Assert::AreEqual((int)list[2]->data, 101);
			Assert::AreEqual((int)list[3]->data, 102);
			Assert::AreEqual((int)list[4]->data, 103);
			Assert::AreEqual((int)list[5]->data, 200);
			Assert::AreEqual((int)list[6]->data, 210);
			Assert::AreEqual((int)list[7]->data, 220);
			Assert::AreEqual((int)list[8]->data, 221);
			Assert::AreEqual((int)list[9]->data, 300);

		}

		TEST_METHOD(Tree_clear)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);
			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);
			tree.add(210, 200);
			tree.add(220, 200);
			tree.add(221, 220);

			tree.clear();

			DLinkedList<TreeNode<int>*> list;
			tree.root.gatherAll(&list);

			Assert::AreEqual((int)list.count(), 1);
		}

		TEST_METHOD(Tree_find)
		{
			Tree<int> tree(0);

			tree.add(100, 0);
			tree.add(200, 0);
			tree.add(300, 0);
			tree.add(101, 100);
			tree.add(102, 100);
			tree.add(103, 100);
			tree.add(210, 200);
			tree.add(220, 200);
			tree.add(221, 220);

			TreeNode<int>* p = tree.root.findRecursive(210);
			TreeNode<int>* p2 = tree.root.findRecursive(999);

			Assert::AreEqual((int)p->data, 210);
			Assert::IsNull(p2);
		}

		/*
		// QEUE ----------------------------------------------
		TEST_METHOD(Qeue_test)
		{
			p2Qeue<int> fifo;


			fifo.Push(11);
			fifo.Push(22);
			fifo.Push(33);

			Assert::AreEqual((int)fifo.Count(), 3);
			Assert::AreEqual((int)*(fifo.Peek(1)), 22);


			int result;
			bool r = fifo.Pop(result);
		}

		TEST_METHOD(Qeue2_test)
		{
			p2Qeue2<int> fifo;


			fifo.Push(11);
			fifo.Push(22);
			fifo.Push(33);

			Assert::AreEqual((int)fifo.Count(), 3);
			Assert::AreEqual((int)*(fifo.Peek(1)), 22);


			int result;
			bool r = fifo.Pop(result);
		}

		// STACK ---------------------------------------------
		TEST_METHOD(Stack_test)
		{
			p2Stack<int> lifo;

			lifo.Push(10);
			lifo.Push(20);
			lifo.Push(30);
			lifo.Push(40);

			Assert::AreEqual((int)lifo.Count(), 4);
			Assert::AreEqual((int)*(lifo.Peek(1)), 20);

			int result;
			bool r = lifo.Pop(result);

			Assert::AreEqual((int)result, 40);
			Assert::AreEqual((int)lifo.Count(), 3);
		}

		TEST_METHOD(Stack2_test)
		{
			p2Stack2<int> lifo;

			lifo.Push(10);
			lifo.Push(20);
			lifo.Push(30);
			lifo.Push(40);

			Assert::AreEqual((int)lifo.Count(), 4);
			Assert::AreEqual((int)*(lifo.Peek(1)), 20);

			int result;
			bool r = lifo.Pop(result);

			Assert::AreEqual((int)result, 40);
			Assert::AreEqual((int)lifo.Count(), 3);
		}
		*/
	};
}