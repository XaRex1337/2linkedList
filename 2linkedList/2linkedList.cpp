#include <iostream>

#include "2linkedList.h"

struct foo
{
	int a, b, c;
};

int main()
{
	auto root = tll::create(0);

	for (int i = 0; i < 10; i++)
	{
		tll::push_back(root, tll::create(i + 1));
	}

	tll::show(root);

	tll::insert(tll::find(root, 3), tll::find(root, 4), tll::create(111));

	tll::show(root);

	tll::remove(tll::find(root, 111));

	tll::show(root);

	root = tll::emplace(root, tll::create(111));

	tll::show(root);

	tll::replace(tll::find(root, 4), tll::find(root, 10));

	tll::show(root);

	tll::sort<int>(root, [](int a, int b) { return a > b; });

	tll::show(root);

	//////////////////////////////////////////////////////////////////////////////

	auto root2 = tll::create<foo>({ 10, -11, 120 });
	tll::push_back(root2, tll::create<foo>({ 7, -8, 100 }));
	tll::push_back(root2, tll::create<foo>({ 1, -2, 150 }));
	tll::push_back(root2, tll::create<foo>({4, -5, 125}));

	// convert foo to str function
	const auto foo_to_str = [](foo info) -> char* 
	{ 
		char r[256]; 
		sprintf_s(r, "%i, %i, %i", info.a, info.b, info.c); 
		return r; 
	};
	
	tll::show<foo>(root2, foo_to_str);

	std::cout << 
		foo_to_str( // output info
		tll::find<foo>(root2, [](foo info) { return info.c == 120; }) // of elem with 120 in .c
		->info) 
		<< std::endl;

	tll::sort<foo>(root2, [](foo a, foo b) { return a.c > b.c; }); // sorting by .c variable

	tll::show<foo>(root2, foo_to_str);

	tll::sort<foo>(root2, [](foo a, foo b) { return a.b > b.b; }, true); // sorting by .b variable in reverse order

	tll::show<foo>(root2, foo_to_str);

	return 0;
}
