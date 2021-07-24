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
			this->_it = InpIter._it;
			this->_n = InpIter._n;
			return *this;
		}
		friend bool operator== (const InputIterator& a, const InputIterator& b);
		friend bool operator!= (const InputIterator& a, const InputIterator& b);

		pointer operator->() { return (*this)._it; };
		InputIterator operator++(int) {
			InputIterator tmp = *this;
			++(*this);
			return tmp;
		};
	};

	template <class T, class Pointer = T*, class Reference = T&>
	bool operator== (const InputIterator<T, Pointer, Reference>& a, const InputIterator<T, Pointer, Reference>& b) { return a._it == b._it; }
	template <class T, class Pointer = T*, class Reference = T&>
	bool operator!= (const InputIterator<T, Pointer, Reference>& a, const InputIterator<T, Pointer, Reference>& b) { return !(a._it == b._it); }

	template<class Category,            // Iterator::iterator_category
			class T,                     // Iterator::value_type
			class Distance = std::ptrdiff_t,  // Iterator::difference_type
			class Pointer = T *,          // Iterator::pointer
			class Reference = T &>        // Iterator::reference
	class ForwardIterator: public InputIterator<Category, T, Distance, Pointer, Reference> {
		typedef InputIterator<Category, T, Distance, Pointer, Reference> input_iterator;
		typedef typename input_iterator::value_type value_type;
		typedef typename input_iterator::difference_type difference_type;
		typedef typename input_iterator::pointer pointer; //if the iterator category allows output_iterator, should be value_type pointer and if no, const value type pointer
		typedef typename input_iterator::reference reference;
		typedef typename input_iterator::iterator_category iterator_category;
		ForwardIterator(pointer ptr): input_iterator(ptr) {};
		ForwardIterator(ForwardIterator const &FwdIter): input_iterator(FwdIter._it) {};
		ForwardIterator &operator=(ForwardIterator const &FwdIter) {
			this->_it = FwdIter._it;
			this->_n = FwdIter._n;
			return *this;
		}

	};
}
#endif
