#pragma once

namespace tll // two linked list
{
	template<typename t>
	struct elem
	{
		t info;
		elem* next;
		elem* prev;
	};

	template<typename t>
	elem<t>* create(t info, elem<t>* next = NULL, elem<t>* prev = NULL)
	{
		elem<t>* base = reinterpret_cast<elem<t>*>(malloc(sizeof(elem<t>)));

		base->info = info;
		base->next = next;
		base->prev = prev;
		
		return base;
	}

	template<typename t>
	void remove(elem<t>* base)
	{
		if (base->next != NULL && base->prev != NULL)
		{
			base->next->prev = base->prev;
			base->prev->next = base->next;
		}

		free(base);
	}

	template<typename t>
	elem<t>* end(elem<t>* base)
	{
		elem<t>* ptr = base;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		return ptr;
	}

	template<typename t>
	void push_back(elem<t>* base, elem<t>* e)
	{
		elem<t>* end = tll::end(base);

		e->prev = base;
		end->next = e;
	}

	// or push_front
	template<typename t>
	elem<t>* emplace(elem<t>* base, elem<t>* e)
	{
		e->next = base;
		base->prev = e;

		return e;
	}

	template<typename t>
	void replace(elem<t>* e1, elem<t>* e2)
	{
		t tmp = e1->info;
		e1->info = e2->info;
		e2->info = tmp;
	}

	template<typename t>
	void insert(elem<t>* prev, elem<t>* next, elem<t>* e)
	{
		e->prev = prev;
		e->next = next;
		prev->next = e;
		next->prev = e;
	}

	template<typename t>
	void show(elem<t>* base)
	{
		std::cout << "-----------------SHOW-START-----------------" << std::endl;

		elem<t>* ptr = base;
		while (ptr != NULL)
		{
			std::cout << ptr->info << std::endl;

			ptr = ptr->next;
		}

		std::cout << "------------------SHOW-END------------------" << std::endl;
	}

	// to_str - how info would look in text format
	template<typename t>
	void show(elem<t>* base, char*(*to_str)(t))
	{
		std::cout << "-----------------SHOW-START-----------------" << std::endl;

		elem<t>* ptr = base;
		while (ptr != NULL)
		{
			std::cout << to_str(ptr->info) << std::endl;

			ptr = ptr->next;
		}

		std::cout << "------------------SHOW-END------------------" << std::endl;
	}

	template<typename t>
	elem<t>* find(elem<t>* base, t info)
	{
		elem<t>* ptr = base;
		while (ptr != NULL)
		{
			if (ptr->info == info)
				return ptr;

			ptr = ptr->next;
		}

		return NULL;
	}

	// comp - comparison for searching info
	template<typename t>
	elem<t>* find(elem<t>* base, bool(*comp)(t))
	{
		elem<t>* ptr = base;
		while (ptr != NULL)
		{
			if (comp(ptr->info))
				return ptr;

			ptr = ptr->next;
		}

		return NULL;
	}

	// comp - comparison a > b
	template<typename t>
	void sort(elem<t>* base, bool(*comp)(t, t), bool reverse = false)
	{
		auto p1 = base;
		while (p1 != NULL)
		{
			auto p2 = base;
			while (p2 != NULL)
			{
				if ((reverse && comp(p1->info, p2->info)) || (!reverse && !comp(p1->info, p2->info)))
				{
					replace(p1, p2);
				}

				p2 = p2->next;
			}

			p1 = p1->next;
		}
	}
}