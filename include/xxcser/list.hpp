#ifndef XXCSER_LIST
#define XXCSER_LIST

#include <xxcser/arithmetic.hpp>
#include <list>

namespace io {
	template <class t>
	auto write(const std::list <t>& list) -> decltype(io::write(list.front())) {
		io::write(list.size());

		for (auto& it : list) {
			io::write(it);
		}
	}

	template <class t>
	auto read(std::list <t>& list) -> decltype(io::read(list.front())) {
		std::size_t size = 0;
		io::read(size);

		if (list.size() < size) {
			list.resize(size);
		}

		std::for_each_n(list.begin(), size, [](t& it) { io::read(it); });
	}
}

#endif // XXCSER_LIST