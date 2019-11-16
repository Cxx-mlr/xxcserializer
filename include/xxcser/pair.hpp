#ifndef XXCSER_PAIR
#define XXCSER_PAIR

#include <xxcser/all.hpp>
#include <utility>

namespace io {
	template <class tfirst, class tsecond>
	auto write(const std::pair <tfirst, tsecond>& pair) -> decltype(io::write(pair.first), io::write(pair.second)) {
		io::write(pair.first);
		io::write(pair.second);
	}

	template <class tfirst, class tsecond>
	auto read(std::pair <tfirst, tsecond>& pair) -> decltype(io::read(pair.first), io::read(pair.second)) {
		io::read(pair.first);
		io::read(pair.second);
	}
}

#endif // XXCSER_PAIR