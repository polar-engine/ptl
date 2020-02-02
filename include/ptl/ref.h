#pragma once

#include <boost/container_hash/hash.hpp>
#include <ptl/destructor.h>
#include <ptl/id.h>

namespace ptl {
	class ref {
	  public:
		using dtor_type = std::shared_ptr<destructor>;

	  private:
		static mtl::id global_id;

		mtl::id _id;
		dtor_type _dtor;

	  public:
		ref() = default;
		ref(std::function<void()> fn) : ref(std::make_shared<destructor>(fn)) {}
		ref(dtor_type dtor) : _id(global_id++), _dtor(dtor) {}

		auto dtor() const { return _dtor; }

		auto id() const { return _id; }

		operator mtl::id() const { return id(); }

		friend inline bool operator==(const ref &lhs, const ref &rhs) { return lhs.id() == rhs.id(); }

		friend inline bool operator<(const ref &lhs, const ref &rhs) { return lhs.id() < rhs.id(); }
	};

	using weak_ref = mtl::id;
} // namespace ptl

namespace std {
	template<> struct hash<ref> {
		inline size_t operator()(const ref &r) const { return std::hash<mtl::id>()(r.id()); }
	};
} // namespace std
