#ifndef XXCSER_VECTOR
#define XXCSER_VECTOR

#include <xxcser/arithmetic.hpp>
#include <vector>

namespace io {
	template <class t>
	auto write(const std::vector <t>& vector) -> decltype(io::write(vector.front())) {
		io::write(vector.size());

		for (auto &it : vector) {
			io::write(it);
		}
	}

	template <class t>
	auto read(std::vector <t>& vector) -> decltype(io::read(vector.front())) {
		std::size_t size = 0;
		io::read(size);

		if (vector.size() < size) {
			vector.resize(size);
		}

		for (std::size_t index = 0; index < size; ++index) {
			io::read(vector[index]);
		}
	}
}

#endif // XXCSER_VECTOR