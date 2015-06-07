#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programació02_All_in/Point2D.h"
#include "../Programació02_All_in/CString.h"
#include "../Programació02_All_in/GenericTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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

		TEST_METHOD(Tree_inOrderIterative)
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
			tree.inOrderIterative(&list);

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

	};
}