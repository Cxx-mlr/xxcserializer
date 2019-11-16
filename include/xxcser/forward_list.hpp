#ifndef XXCSER_FORWARD_LIST
#define XXCSER_FORWARD_LIST

#include <xxcser/arithmetic.hpp>
#include <forward_list>

namespace io {
	template <class t>
	auto write(const std::forward_list <t>& forward_list) -> decltype(io::write(*forward_list.begin())) {
	}

	template <class t>
	auto read(std::forward_list <t>& forward_list) -> decltype(io::read(*forward_list.begin())) {
	}
}

#endif // XXCSER_FORWARD_LIST
