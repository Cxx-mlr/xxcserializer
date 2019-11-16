#ifndef XXCSER_ARITHMETIC
#define XXCSER_ARITHMETIC

#include <iostream>

#include <fstream>
#include <string_view>

#include <type_traits>
#include <algorithm>

namespace io {
	thread_local std::filebuf file;

	template <class t>
	void discard(std::size_t count) {
		t value;

		while (count--) {
			io::read(value);
		}
	}

	template <class t>
	auto write_object(std::string_view path, const t& obj) -> decltype(io::write(obj)) {
		file.open(path.data(), std::ios::binary | std::ios::out);

		io::write(obj);

		file.close();
	}

	template <class t, std::enable_if_t <std::is_arithmetic_v <t>, int> = 0>
	void write(const t& arithmetic) {
		file.sputn(reinterpret_cast <const char*>(&arithmetic), sizeof(t));

		std::cout << "saved " << arithmetic << '\n';
	}

	template <class t>
	auto read_object(std::string_view path, t& obj) -> decltype(io::read(obj)) {
		file.open(path.data(), std::ios::binary | std::ios::in);

		io::read(obj);

		file.close();
	}

	template <class t, std::enable_if_t <std::is_arithmetic_v <t>, int> = 0>
	void read(t& arithmetic) {
		char *buffer;
		file.sgetn(buffer, sizeof(t));
		
		arithmetic = *(t*)buffer;

		std::cout << "extracted " << arithmetic << '\n';
	}
}

#endif // XXCSER_ARITHMETIC