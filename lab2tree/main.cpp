#include <iostream>

#include "inc/Tree.h"
#include <cassert>
#include <vector>
#include "concepts"

int main()
{
	{
		Tree<int> tree;
		assert(tree.IsRootEmpty() == true);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		int arr[] = {1, -1, 2, 3};
		int i = 0;
		for (auto it = tree.begin(); it != tree.end(); ++it, ++i)
			assert(*it == arr[i]);

		assert(i == 4);
	}

	{
		Tree<int> tree = {1, 2, 1, -1, 1, 1};
		int arr[] = {1, -1, 2};
		int i = 0;

		for (auto elem : tree)
		{
			assert(elem == arr[i]);
			i++;
		}

		assert(i == 3);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		Tree<int> tree_2(tree);
		int arr[] = {1, -1, 2, 3};
		int i = 0;

		for (auto it = tree_2.begin(); it != tree_2.end(); ++it, ++i)
			assert(*it == arr[i]);

		assert(i == 4);
	}


	{
		Tree<int> tree = {1, 2, 3, -1};
		Tree<int> tree_2;
		tree_2 = tree;
		int arr[] = {1, -1, 2, 3};
		int i = 0;

		for (auto it = tree_2.begin(); it != tree_2.end(); ++it, ++i)
			assert(*it == arr[i]);

		assert(i == 4);
	}

	{
		Tree<int> tree_2;
		tree_2 = {1, 2, 3, -1};
		int arr[] = {1, -1, 2, 3};
		int i = 0;
		for (auto it = tree_2.begin(); it != tree_2.end(); ++it, ++i)
			assert(*it == arr[i]);

		assert(i == 4);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		Tree<int> tree_2;
		tree_2 = tree;

		bool res = tree_2.isEqual(tree);

		assert(res == true);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		Tree<int> tree_2;
		tree_2 = tree;

		bool res = tree_2 == tree;

		assert(res == true);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		Tree<int> tree_2 = {1, 2, 3, -1, -2};

		bool res = tree_2.isNotEqual(tree);

		assert(res == true);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		Tree<int> tree_2 = {1, 2, 3, -2};

		bool res = tree_2 != tree;

		assert(res == true);
	}

	{
		Tree<int> tree = {1, 2, 3, 4};
		Tree<int> tree_2 = {5, 6, 7};
		Tree<int> tree_3 = {1, 2, 3, 4, 5, 6, 7};

		Tree<int> tree_4 = tree.Add(tree_2);

		int i;

		for (auto it = tree_4.begin(), i = tree_3.begin(); it != tree_4.end(); ++it, ++i)
			assert(*it == *i);
	}

	{
		Tree<int> tree = {1, 2, 3, 4};
		Tree<int> tree_2 = {5, 6, 7};
		Tree<int> tree_3 = {1, 2, 3, 4, 5, 6, 7};

		Tree<int> tree_4 = tree + tree_2;

		int i;

		for (auto it = tree_4.begin(), i = tree_3.begin(); it != tree_4.end(); ++it, ++i)
			assert(*it == *i);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		bool res = tree.Find(0);

		assert(res == false);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		int rootData = tree[0];

		assert(rootData == 1);
	}

	{
		Tree<int> tree = {1, 2, 3, -1};
		int rootData = tree[1];

		assert(rootData == -1);
	}

	{
		Tree<int> tree = {};
		Tree<int> tree_1 = {5};

		tree.Insert(5);
		for (auto it = tree.begin(), i = tree_1.begin(); it != tree.end(); ++it, ++i)
			assert(*it == *i);

	}

	{
		Tree<int> tree = {4, 3, 5, -2, 7};
		Tree<int> tree_1 = {1, 3, 5};
		Tree<int> tree_2 = {4, -2, 7};
		Tree<int> tree_3(tree);
		tree_3 -= tree_1;

		for (auto it = tree_2.begin(), i = tree_3.begin(); it != tree_2.end(); ++it, ++i)
			assert(*it == *i);
	}

	{
		Tree<int> tree = {4, 9, 0, 3, 5, -2, 7};
		Tree<int> tree_1 = {1, 3, 5, -7, 9};
		Tree<int> tree_2 = {5, 3, 9};

		tree.Intersection(tree_1);

		for (auto it = tree.begin(), i = tree_2.begin(); it != tree.end(); ++it, ++i) {
			assert(*it == *i);
		}
	}

	{
		Tree<int> tree = {4, 9, 0, 3, 5, -2, 7};
		Tree<int> tree_1 = {1, 3, 5, -7, 9};
		Tree<int> tree_2 = {5, 3, 9};

		tree &= tree_1;

		for (auto it = tree.begin(), i = tree_2.begin(); it != tree.end(); ++it, ++i) {
			assert(*it == *i);
		}
	}

	{
		Tree<int> tree = {1, 3, 4, 5};
		double insert_data = 2.5;
		Tree<int> res_tree = {1, 3, 2, 4, 5};

		bool res = tree.Insert(insert_data);

		assert(res == true);

		for (auto it = tree.begin(), i = res_tree.begin(); it != tree.end(); ++it, ++i) {
			assert(*it == *i);
		}
	}

	{
		Tree<int> tree = {4, 3, 5, -2, 7};

		auto iter = tree.begin();

		assert(tree[2] == iter[2]);

	}

	{
		Tree<int> tree = {4, 3, 6, 1};
		int test_node_data = *tree.begin();

		tree = {};

		test_node_data += 1;

		assert(test_node_data == 5);
	}

	{
		class A {
		public:
			A() = default;
			A(int r) {field = r;}
			size_t size() const { return field; }
			A &get() {return *this;}
			void set(int h) {field = h;}
			bool operator==(const A &bob) const {return (size() == bob.size());}
			bool operator!=(const A &bob) const {return (size() != bob.size());}

			bool operator>(const A &bob) const {return (size() > bob.size());}
			bool operator>=(const A &bob) const {return (size() >= bob.size());}

			bool operator<(const A &bob) const {return (size() < bob.size());}
			bool operator<=(const A &bob) const {return (size() <= bob.size());}
		private:
			size_t field;
		};

		A popter(4);
		Tree<A> tree = {popter, A(3), A(6), A(1)};
		A test_node_data = tree.begin()->get();

		tree = {};

		// test_node_data.set(9);

		assert(test_node_data.size() == 4);
	}

	{
		std::stack<int> stack_1;
		stack_1.push(1);
		std::stack<int> stack_2;
		stack_2.push(2);
		Tree<std::stack<int>> tree = {stack_1, stack_2};

		auto field = tree.begin()->top();
		field++;
		assert(field == 2);

		assert(tree[0].top() == 1);
	}
	{
		Tree<int> tree = {4, 3, 5, -2, 7};
		Tree<double> tree_2 = {5, 3, 9};
		
		auto tree_3 = tree.CopyAdd(2.5);

	}
	{
		Tree<int> tree = {-1, 1, 2, 3, 4, 5, 6, 7, 8};

		std::vector<double> test = {-1000, -10000.1, -0.1, 0};
		auto range = test | std::ranges::views::reverse;

		auto tree2 = tree.CopyAdd(range); //double
	}
	{
		Tree<int> tree  =  {4,  3,  5,  -2,  7};
		static_assert(std::ranges::range<Tree<int>>);
		std::ranges::for_each(tree, [](const auto& elem) {std::cout << elem << std::endl;});
	}

	return 0;
}
