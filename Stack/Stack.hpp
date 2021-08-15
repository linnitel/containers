#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/Vector.hpp"

namespace ft {

	template <class T, class Container = vector<T> >
	class stack {
	public:
		// Typedefs -----
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
    protected:
		// Variables -----
		container_type _stack;

	public:
		// Constructors -----
		explicit stack (const container_type &ctnr = container_type()): _stack(ctnr) {};

		// Member functions -----
		bool empty() const {
			return _stack.empty();
		};
		size_type size() const {
			return _stack.size();
		};

		value_type& top() {
			return _stack.back();
		};
		const value_type& top() const {
			return _stack.back();
		};

		void push (const value_type& val) {
			_stack.push_back(val);
		};
		void pop() {
			_stack.pop_back();
		};

		friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._stack == rhs._stack;
		}
		friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return !(lhs._stack == rhs._stack);
		}
		friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._stack < rhs._stack;
		}
		friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._stack <= rhs._stack;
		}
		friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._stack > rhs._stack;
		}
		friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return lhs._stack >= rhs._stack;
		}
	};
}

#endif
