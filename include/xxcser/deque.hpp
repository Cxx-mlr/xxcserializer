#ifndef XXCSER_DEQUE
#define XXCSER_DEQUE

#include <xxcser/arithmetic.hpp>
#include <deque>

namespace io {
	template <class t>
	auto write(const std::deque <t>& deque) -> decltype(io::write(deque.front())) {
		io::write(deque.size());

		for (auto& it : deque) {
			io::write(it);
		}
	}

	template <class t>
	auto read(std::deque <t>& deque) -> decltype(io::read(deque.front())) {
		std::size_t size = 0;
		io::read(size);

		if (deque.size() < size) {
			deque.resize(size);
		}

		for (std::size_t index = 0; index < size; ++index) {
			io::read(deque[index]);
		}
	}
}

#endif // XXCSER_DEQUE