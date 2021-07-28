#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/Vector.hpp"

namespace ft {

	template <class T, class Container = Vector<T> >
	class Stack {
	public:
		// Typedefs -----
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
	private:
		// Variables -----
		container_type _stack;

	public:
		// Constructors -----
		explicit Stack (const container_type &ctnr = container_type()): _stack(ctnr) {};

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
	};

	template <class T, class Container>
	bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
		return lhs._stack == rhs._stack;
	};
	template <class T, class Container>
	bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
		return (!lhs._stack == rhs._stack);
	};
	template <class T, class Container>
	bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
		return lhs._stack < rhs._stack;
	};
	template <class T, class Container>
	bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
		return lhs._stack <= rhs._stack;
	};
	template <class T, class Container>
	bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
		return lhs._stack > rhs._stack;
	};
	template <class T, class Container>
	bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
		return lhs._stack >= rhs._stack;
	};
}

#endif
