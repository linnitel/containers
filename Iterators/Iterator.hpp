#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>
#include "iterator_traits.hpp"

namespace ft {
	template<class Category,            // Iterator::iterator_category
			class T,                     // Iterator::value_type
			class Distance = std::ptrdiff_t,  // Iterator::difference_type
			class Pointer = T *,          // Iterator::pointer
			class Reference = T &>
	class Iterator {
	public:
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <class Iterator>
    class reverseIterator {
	public:
    	typedef Iterator iterator_type;
		typedef iterator_traits<Iterator> traits;
		typedef typename traits::value_type value_type;
		typedef typename traits::difference_type difference_type;
		typedef typename traits::pointer pointer;
		typedef typename traits::reference reference;
		typedef typename traits::iterator_category iterator_category;
	private:
    	iterator_type _it;

	public:
		reverseIterator() {};

		explicit reverseIterator (iterator_type it): _it(it) {};

		reverseIterator (const reverseIterator<Iterator>& rev_it): _it(rev_it._it) {};

		iterator_type base() const {
			return _it;
		};

		reference operator*() const {
			iterator_type temp = _it;
			temp--;
			return (*temp);
		};

		reverseIterator operator+ (difference_type n) const {
			reverseIterator<iterator_type> temp(_it - n);
			return temp;
		};

		reverseIterator& operator++() {
			_it--;
			return *this;
		};

		reverseIterator  operator++(int) {
			reverseIterator temp = *this;
			--(*this);
			return temp;
		};

		reverseIterator& operator+=(difference_type n) {
			_it -= n;
			return *this;
		};

		reverseIterator operator-(difference_type n) const {
			reverseIterator<iterator_type> temp(_it + n);
			return temp;
		};

		reverseIterator& operator--() {
			_it++;
			return *this;
		};
		reverseIterator  operator--(int) {
			reverseIterator temp = *this;
			++(*this);
			return temp;
		};

		reverseIterator& operator-= (difference_type n) {
			_it += n;
			return *this;
		};

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return _it[- n - 1];
		};

		friend bool operator==(const reverseIterator<Iterator>& lhs,
						 const reverseIterator<Iterator>& rhs) {
			return lhs._it == rhs._it;
		};
		friend bool operator!=(const reverseIterator<Iterator>& lhs,
						 const reverseIterator<Iterator>& rhs) {
			return !(lhs._it == rhs._it);
		};
		friend bool operator<(const reverseIterator<Iterator>& lhs,
						 const reverseIterator<Iterator>& rhs) {
			return lhs._it < rhs._it;
		};
		friend bool operator<=(const reverseIterator<Iterator>& lhs,
						 const reverseIterator<Iterator>& rhs) {
			return !(rhs < lhs);
		};
		friend bool operator>(const reverseIterator<Iterator>& lhs,
						 const reverseIterator<Iterator>& rhs) {
			return rhs < lhs;
		};
		friend bool operator>=(const reverseIterator<Iterator>& lhs,
						 const reverseIterator<Iterator>& rhs) {
			return !(lhs < rhs);
		};

		friend reverseIterator<Iterator> operator+ (
				typename reverseIterator<Iterator>::difference_type n,
				const reverseIterator<Iterator>& rev_it) {
			return rev_it + n;
		};

		friend typename reverseIterator<Iterator>::difference_type operator- (
				const reverseIterator<Iterator>& lhs,
				const reverseIterator<Iterator>& rhs) {
			return lhs._it - rhs._it;
		};
    };
}
#endif
