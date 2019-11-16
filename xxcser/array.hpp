#ifndef XXCSER_ARRAY
#define XXCSER_ARRAY

#include <xxcser/arithmetic.hpp>
#include <array>

#include <algorithm>

namespace io {
	template <class t, std::size_t n>
	auto write(const std::array <t, n>& array) -> decltype(io::write(array.front())) {
		io::write(n);

		for (auto& it : array) {
			io::write(it);
		}
	}

	template <class t, std::size_t n>
	auto read(std::array <t, n>& array) -> decltype(io::read(array.front()))  {
		std::size_t size = 0;
		io::read(size);

		auto minmax = std::minmax(size, n);

		for (std::size_t index = 0; index < minmax.first; ++index) {
			io::read(array[index]);
		}

		io::discard <t>(minmax.second - minmax.first);
	}
}

#endif // XXCSER_ARRAY