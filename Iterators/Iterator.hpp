#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft {
	template<class Category,            // Iterator::iterator_category
			class T,                     // Iterator::value_type
			class Distance = std::ptrdiff_t,  // Iterator::difference_type
			class Pointer = T *,          // Iterator::pointer
			class Reference = T &>        // Iterator::reference
	class Iterator {
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	protected:
		pointer _it;
		difference_type _n;
	public:
		explicit Iterator(pointer ptr) : _it(ptr) {};

		Iterator(Iterator const &Iter) : _it(Iter._it) {};

		Iterator &operator=(Iterator const &Iter) {
			_it = Iter._it;
			return *this;
		};

		reference operator*() const { return *_it; };

		Iterator &operator++() {
			_it += _n;
			return *this;
		};
	};

	template<class Category,            // Iterator::iterator_category
			class T,                     // Iterator::value_type
			class Distance = std::ptrdiff_t,  // Iterator::difference_type
			class Pointer = T *,          // Iterator::pointer
			class Reference = T &>        // Iterator::reference
	class InputIterator: public Iterator<Category, T, Distance, Pointer, Reference> {
	public:
		typedef Iterator<Category, T, Distance, Pointer, Reference> iterator;
		typedef typename iterator::value_type value_type;
		typedef typename iterator::difference_type difference_type;
		typedef typename iterator::pointer pointer;
		typedef typename iterator::reference reference;
		typedef typename iterator::iterator_category iterator_category;

		InputIterator(pointer ptr): iterator(ptr) {};
		InputIterator(InputIterator const &InpIter): iterator(InpIter._it) {};
		InputIterator &operator=(InputIterator const &InpIter) {
			iterator::_it = InpIter._it;
			iterator::_n = InpIter._n;
			return *this;
		}
	};
}
#endif
