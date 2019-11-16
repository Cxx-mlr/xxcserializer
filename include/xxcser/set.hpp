#ifndef XXCSER_SET
#define XXCSER_SET

#include <xxcser/arithmetic.hpp>
#include <set>

namespace io {
	template <class t>
	auto write(const std::set <t>& set) -> decltype(io::write(*set.begin())) {
		io::write(set.size());

		for (auto it : set) {
			io::write(it);
		}
	}

	template <class t>
	auto read(std::set <t>& set) -> decltype(io::read(*set.begin())) {
	}
}

#endif // XXSER_SET