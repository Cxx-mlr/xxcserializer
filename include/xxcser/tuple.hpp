#ifndef XXCSER_TUPLE
#define XXCSER_TUPLE

#include <xxcser/arithmetic.hpp>
#include <tuple>

namespace io {
	template <class... targs>
	auto write(const std::tuple <targs...> &tuple) -> decltype(io::write(std::get <0>(tuple))) {
		std::apply([](auto... args) { (io::write(args), ...); }, tuple);
	}

	template <class... targs>
	auto read(std::tuple <targs...>& tuple) -> decltype(io::read(std::get <0>(tuple))) {
		std::apply([](auto... args) { (io::write(args), ...); }, tuple);
	}
}

#endif // XXCSER_TUPLE