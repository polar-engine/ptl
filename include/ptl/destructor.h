#pragma once

#include <functional>

namespace ptl {
	class destructor {
	  private:
		std::function<void()> fn;

	  public:
		destructor() = default;
		destructor(std::function<void()> fn) : fn(fn) {}
		~destructor() { fn(); }

		void set(std::function<void()> f) { fn = f; }
	};
} // namespace ptl
