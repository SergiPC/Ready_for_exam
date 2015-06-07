#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Programació2_Tot/Point2D.h"
#include "../Programació2_Tot/CString.h"
#include "../Programació2_Tot/DLinkedList.h"
#include "../Programació2_Tot/DynArray.h"
#include "../Programació2_Tot/Projectile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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

		TEST_METHOD(DynArray_resize)
		{
		DynArray<int> new_array;

		for(int i = 0; i < 999; ++i)
		{
			new_array.pushBack(i);
		}

		Assert::AreEqual(*(new_array.at(900)), 900);
		Assert::IsNull(new_array.at(1000));
		Assert::AreEqual((int)new_array.getCapacity(), 1008);
		Assert::AreEqual((int)new_array.count(), 999);
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

			new_array.pushBack(3);
			new_array.pushBack(10);
			new_array.pushBack(1);
			new_array.pushBack(6);
			new_array.pushBack(7);

			new_array.bubbleSort();

			Assert::AreEqual((int)new_array.count(), 5);
			Assert::AreEqual((int)new_array[3], 7);
		}
	};
}