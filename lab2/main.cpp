#include <iostream>

#include "Headers/Class/List.h"
#include <vector>


int main()
{

	//Constructors
	{
		List<int> list;
	}
	{
		List<int> list = {1,2,3,4,5,6};
		std::cout << "Init list constructor: " << list << std::endl;

		List<int> copylist = List(list);
		std::cout << "Copy constructor: " << copylist << std::endl;

		List<int> newlist = List(std::move(copylist));
		std::cout << "move constructor: " << newlist << std::endl;

		List<double> doublelist = {1.1f, 2.2f, 3.3f};
		std::cout << "Move convertable constructor: " << doublelist << std::endl;

		List<int> intlist = List<int>(doublelist);
		std::cout << "Copy convertable constructor: " << intlist << std::endl;
		std::cout << "Test: " << doublelist << std::endl;
	}
	{
		std::vector<int> vec1 = { 1, 2, 3 };
		std::vector<double> vec2 = { 1.1, 2.2, 3.3 };

		List<int> list = List<int>(vec1);
		std::cout << "Container constructor from vector: " << list << std::endl;

		List<double> list2 = vec1;
		std::cout << "Container constructor from convertible vector: " << list2 << std::endl;

		List<int> list3 = List<int>(vec2.begin(), vec2.end());
		std::cout << "Iterator constructor convertible: " << list3 << std::endl;
	}

	//Итераторы
	{
		List<int> list1 = {1,2,3,4,5};
		std::cout << "List auto iterator: " << std::endl;
		for (auto& i : list1)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	{
		const List<int> list = {1,2,3,4,5};
		std::cout << "const List auto iterator: " << std::endl;
		for (auto& i : list)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	{
		List<int> list = {1,2,3,4,5};

		ListIterator<int> beg = list.begin();
		ListIterator<int> end = list.end();

		std::cout << "List beg end iterator: " << std::endl;
		for (; beg != end; ++beg)
		{
			std::cout << *beg << " ";
		}
		std::cout << std::endl;
	}
	{
		const List<int> list = {1,2,3,4,5};

		ConstListIterator<int> beg = list.begin();
		ConstListIterator<int> end = list.end();

		std::cout << "const List beg end iterator: " << std::endl;
		for (; beg != end; ++beg)
		{
			std::cout << *beg << " ";
		}
		std::cout << std::endl;
	}
	{
		List<int> list = {1,2,3,4,5};

		ConstListIterator<int> beg = list.cbegin();
		ConstListIterator<int> end = list.cend();

		std::cout << "List cbeg cend iterator: " << std::endl;
		for (; beg != end; ++beg)
		{
			std::cout << *beg << " ";
		}
		std::cout << std::endl;
	}

	//Push
	{
		List<int> list1;

		for (int i = 0; i < 10; i++)
		{
			list1.PushFront(i);
		}
		std::cout << "List pushfront: " << list1 << std::endl;

		List<int> list2;
		for (int i = 0; i < 10; i++)
		{
			list2.PushBack(i);
		}
		std::cout << "List pushback: " << list2 << std::endl;
	}
	{
		List<int> list1;

		for (int i = 0; i < 10; i++)
		{
			list1.PushFront(double(i));
		}
		std::cout << "List pushfront convertible: " << list1 << std::endl;

		List<int> list2;
		for (int i = 0; i < 10; i++)
		{
			list2.PushBack(double(i));
		}
		std::cout << "List pushback convertible: " << list2 << std::endl;
	}

	//Remove test
//	{
//		List<int> list = {1,2,3,4,5};
//		list.Remove(1);
//		std::cout << "Removed 1st index: " << list << std::endl;
//
//		list.Remove(1,4);
//		std::cout << "Removed 1-4 indexes further: " << list << std::endl;
//	}
	{
		List<int> list = {1,2,3,4,5};
		ListIterator<int> beg = list.begin();
		ListIterator<int> end = list.begin();

		++beg;

		++end;
		++end;
		++end;

		list.Remove(beg, end);
		std::cout << "Remove iterators: " << list << std::endl;
	}

	//Merge
	{
		List<int> list1 = {1,2};
		List<int> list2 = {3,4};

		list1.Merge(list2);

		std::cout << "Merged list: " << list1 << std::endl;
	}
	{
		List<int> list1 = {1,2};
		List<double> list2 = {3,4};

		list1.Merge(list2);

		std::cout << "Merged list (int.merge(double)): " << list1 << std::endl;
	}
	{
		List<int> list = {1,2,3};

		std::vector<int> vec = {1,2,3};
		list.Merge(vec);

		std::cout << "Merged list + vec: " << list << std::endl;

		list.Merge(vec.begin(), vec.end());

		std::cout << "Merged list + iterators on vec" << list << std::endl;
	}

	//Insert
	{
		List<int> list = {1,2,3,4,5};
		list.Insert(6, 3);

		std::cout << "Inserted 3th index: " << list << std::endl;

		list.Insert(7.56f, 2);

		std::cout << "Inserted double at 2nd index: " << list << std::endl;
	}
	{
		List<int> list = {1,2,3};
		List<int> list2 = {4,5,6};

		list.Insert(list2, 2);

		std::cout << "Inserted list2 at 2nd index: " << list << std::endl;
	}
	{
		List<int> list = {1,2,3};
		List<double> list2 = {4.56f,5.12f,6.0001f};

		list.Insert(list2, 2);

		std::cout << "Inserted convertable list2 at 2nd index: " << list << std::endl;
	}
	{
		List<int> list = {1,2,3};
		std::vector<int> vec = {4,5,6};

		list.Insert(vec, 2);

		std::cout << "Inserted vec at 2nd index: " << list << std::endl;
	}
	{
		List<int> list = {1,2,3};
		std::vector<double> vec = {4.56f,5.12f,6.0001f};

		list.Insert(vec, 2);

		std::cout << "Inserted convertable vec at 2nd index: " << list << std::endl;
	}
	{
		List<int> list = {1,2,3};
		std::vector<int> vec = {4,5,6};

		list.Insert(vec.begin(), vec.end(), 2);

		std::cout << "Inserted vec iterators at 2nd index: " << list << std::endl;
	}
	{
		List<int> list = {1,2,3};
		std::vector<double> vec = {4.56f,5.12f,6.0001f};

		list.Insert(vec.begin(), vec.end(), 2);

		std::cout << "Inserted convertable vec iterators at 2nd index: " << list << std::endl;
	}

	//Тесты на сравнение
	{
		List<int> list1 = {1,2,3};
		List<int> list2 = {3,2,1};

		if (list1 < list2)
		{
			std::cout << "list1 < list2" << std::endl;
		}
		else if (list1 > list2)
		{
			std::cout << "list1 > list2" << std::endl;
		}
		else
		{
			std::cout << "list1 == list2" << std::endl;
		}
	}
	{
		List<int> list1 = {1,2,3};
		List<int> list2 = {3,2,1,0};

		if (list1 < list2)
		{
			std::cout << "list1 < list2" << std::endl;
		}
		else if (list1 > list2)
		{
			std::cout << "list1 > list2" << std::endl;
		}
		else
		{
			std::cout << "list1 == list2" << std::endl;
		}
	}
	{
		List<int> list1 = {1,2,3,0,-1};
		List<int> list2 = {3,2,1,0};

		if (list1 < list2)
		{
			std::cout << "list1 < list2" << std::endl;
		}
		else if (list1 > list2)
		{
			std::cout << "list1 > list2" << std::endl;
		}
		else
		{
			std::cout << "list1 == list2" << std::endl;
		}
	}

	//Iterator conversion tests
	{
		List<int> list = {1,2,3,4,5};
		ConstListIterator<int> iter = list.cbegin();
		ListIterator<int> iter2 = ListIterator<int>(iter);
		ListIterator<int> iter3 = list.end();

		std::cout << "Converted iterators" << std::endl;
		for (; iter2 != iter3; ++iter2)
		{
			std::cout << *iter2 << " ";
		}
		std::cout << std::endl;
	}
	{
		List<int> list = {1,2,3,4,5};
		ListIterator<int> iter = list.begin();
		ConstListIterator<int> iter2 = ConstListIterator<int>(iter);
		ConstListIterator<int> iter3 = list.end();

		std::cout << "Converted (nonconst -> const) iterators" << std::endl;
		for (; iter2 != iter3; ++iter2)
		{
			std::cout << *iter2 << " ";
		}
		std::cout << std::endl;
	}

//	List<List<int>> list;

    return 0;
}
