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

    template <class P>
    class RandomAccessIterator {
    public:
		typedef RandomAccessIterator<P> iterator;
        typedef iterator_traits<Iterator<RandomAccessIteratorTag, P> > traits;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;
		pointer _it;
    public:
        RandomAccessIterator(): _it()   {};
        RandomAccessIterator(pointer ptr): _it(ptr)  {};

        RandomAccessIterator(RandomAccessIterator const &Iter): _it(Iter._it) {};

        RandomAccessIterator &operator=(RandomAccessIterator const &Iter) {
			if (Iter._it != this->_it) {
				_it = Iter._it;
			}
            return *this;
        };

		reference operator*() const {
			return *_it;
		};

		pointer operator->() {
			return _it;
		};

		reference operator[](difference_type n) const {
			return (_it[n]);
		};

		iterator operator++(int) {
			iterator  tmp = *this;
			++(*this);
			return tmp;
		};

		iterator &operator++() {
			_it++;
			return *this;
		};

		iterator operator--(int) {
			iterator  tmp = *this;
			--(*this);
			return tmp;
		};

		iterator &operator--() {
			_it--;
			return *this;
		};

		iterator operator+(difference_type n) const {
			iterator it(*this);
			it._it += n;
			return (it);
		}

		iterator operator-(difference_type n) const {
			iterator it(*this);
			it._it -= n;
			return (it);
		}

		iterator &operator+=(difference_type n) {
			_it += n;
			return (*this);
		};

		iterator &operator-=(difference_type n) {
			_it -= n;
			return (*this);
		};

		friend bool operator==(const iterator& a, const iterator& b) {
			return a._it == b._it;
		};
		friend bool operator!=(const iterator& a, const iterator& b) {
			return !(a._it == b._it);
		};

		friend iterator operator+(difference_type n, const iterator& it) {
			return (it + n);
		};

		friend iterator operator-(difference_type n, const iterator& it) {
			return (it - n);
		};

		friend difference_type operator-(const iterator& a, const iterator& b) {
			return (a._it - b._it);
		};

		friend difference_type operator+(const iterator& a, const iterator& b) {
			return (a._it + b._it);
		};

		friend bool operator<(const iterator& a, const iterator& b) {
			return (a._it < b._it);
		};
		friend bool operator>(const iterator& a, const iterator& b) {
			return (a._it > b._it);
		};
		friend bool operator<=(const iterator& a, const iterator& b) {
			return (a._it <= b._it);
		};
		friend bool operator>=(const iterator& a, const iterator& b) {
			return (a._it >= b._it);
		};
    };

	template <class Iterator>
    class reverse_iterator {
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
		reverse_iterator() {};

		explicit reverse_iterator (iterator_type it): _it(it) {};

		reverse_iterator (const reverse_iterator<Iterator>& rev_it): _it(rev_it._it) {};

		iterator_type base() const {
			return _it;
		};

		reference operator*() const {
			iterator_type temp = _it;
			temp--;
			return (*temp);
		};

		reverse_iterator operator+ (difference_type n) const {
			reverse_iterator<iterator_type> temp(_it - n);
			return temp;
		};

		//(1)
		reverse_iterator& operator++() {
			_it--;
			return *this;
		};
		//(2)
		reverse_iterator  operator++(int) {
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		};

		reverse_iterator& operator+=(difference_type n) {
			_it -= n;
			return *this;
		};

		reverse_iterator operator-(difference_type n) const {
			reverse_iterator<iterator_type> temp(_it + n);
			return temp;
		};

		reverse_iterator& operator--() {
			_it++;
			return *this;
		};
		reverse_iterator  operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		};

		reverse_iterator& operator-= (difference_type n) {
			_it += n;
			return *this;
		};

		pointer operator->() const {
			return &(operator*());
		}

		reference operator[] (difference_type n) const {
			return _it[- n - 1];
		};

		friend bool operator==(const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs) {
			return lhs._it == rhs._it;
		};
		friend bool operator!=(const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs) {
			return !(lhs._it == rhs._it);
		};
		friend bool operator<(const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs) {
			return lhs._it < rhs._it;
		};
		friend bool operator<=(const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs) {
			return !(rhs < lhs);
		};
		friend bool operator>(const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs) {
			return rhs < lhs;
		};
		friend bool operator>=(const reverse_iterator<Iterator>& lhs,
						 const reverse_iterator<Iterator>& rhs) {
			return !(lhs < rhs);
		};

		friend reverse_iterator<Iterator> operator+ (
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it) {
			return rev_it + n;
		};

		friend typename reverse_iterator<Iterator>::difference_type operator- (
				const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs) {
			return lhs._it - rhs._it;
		};
    };
}
#endif
