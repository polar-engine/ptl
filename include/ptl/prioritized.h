#pragma once

#include <stdint.h>

namespace ptl {
	template<typename T> struct prioritized {
		using priority_type = int_fast32_t;

		T value;
		priority_type priority;

		prioritized(T value, priority_type priority = 0) : value(value), priority(priority) {}

		friend inline bool operator==(const prioritized &lhs, const prioritized &rhs) { return lhs.value == rhs.value; }

		friend inline bool operator<(const prioritized &lhs, const prioritized &rhs) {
			return lhs.priority < rhs.priority;
		}
	};

	template<typename T> inline size_t hash_value(const prioritized<T> &p) {
		boost::hash<T> hasher;
		return hasher(p.value);
	}

	template<typename T> struct priority_comp {
		inline bool operator()(prioritized<T> lhs, prioritized<T> rhs) const { return lhs.priority < rhs.priority; }
	};
} // namespace ptl

namespace std {
	template<typename T> struct hash<ptl::prioritized<T>> {
		inline size_t operator()(const ptl::prioritized<T> &p) const { return std::hash<T>()(p.value); }
	};
} // namespace std
