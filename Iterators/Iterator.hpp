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
    class BidirectionalIterator {
    public:
    	typedef BidirectionalIterator<P> iterator;
        typedef iterator_traits<Iterator<BidirectionalIteratorTag, P> > traits;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;
    protected:
        pointer _it;
        difference_type _n;
    public:
        BidirectionalIterator(): _it(), _n() {};
        explicit BidirectionalIterator(pointer ptr): _it(ptr), _n() {};

        BidirectionalIterator(BidirectionalIterator const &Iter) : _it(Iter._it), _n() {};

        BidirectionalIterator &operator=(BidirectionalIterator const &Iter) {
            _it = Iter._it;
            _n = Iter._n;
            return *this;
        };

        reference operator*() const {
            return *_it;
        };

        pointer operator->() {
            return (*this)._it;
        };

		reference operator[](difference_type n) const {
			return (_it[n]);
		};

        BidirectionalIterator operator++(int) {
            BidirectionalIterator tmp = *this;
            ++(*this);
            return tmp;
        };

        BidirectionalIterator &operator++() {
            _it += _n;
            return *this;
        };

		BidirectionalIterator operator--(int) {
			BidirectionalIterator tmp = *this;
			--(*this);
			return tmp;
		};

		BidirectionalIterator &operator--() {
			_it -= _n;
			return *this;
		};

		virtual BidirectionalIterator operator+(difference_type n) const {
			iterator it(*this);
			it._it += n;
			return (it);
		};

		virtual BidirectionalIterator operator-(difference_type n) const {
			iterator it(*this);
			it._it -= n;
			return (it);
		};

		BidirectionalIterator& operator+=(difference_type n) {
			_it += n; return (*this);
		}

		BidirectionalIterator& operator-=(difference_type n) {
			_it -= n; return (*this);
		}

        friend bool operator==(const iterator& a, const iterator& b) {
			return a._it == b._it;
		};
        friend bool operator!=(const iterator& a, const iterator& b) {
			return !(a._it == b._it);
        };

		friend BidirectionalIterator operator+(difference_type n, const iterator& it) {
			return (it + n);
		};

		friend BidirectionalIterator operator-(difference_type n, const iterator& it) {
			return (it - n);
		};

		friend difference_type operator-(const iterator& a, const iterator& b) {
			return (a._it - b._it);
		};

		friend difference_type operator+(const iterator& a, const iterator& b) {
			return (a._it + b._it);
		};
    };

    template <class P>
    class RandomAccessIterator: public BidirectionalIterator<P> {
    public:
		typedef RandomAccessIterator<P> iterator;
        typedef iterator_traits<Iterator<RandomAccessIteratorTag, P> > traits;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;

    public:
        RandomAccessIterator(): BidirectionalIterator<P>() {};
//        explicit RandomAccessIterator(pointer ptr): iterator(pointer ptr) {};

        RandomAccessIterator(RandomAccessIterator const &Iter): BidirectionalIterator<P>(Iter) {};

        RandomAccessIterator &operator=(RandomAccessIterator const &Iter) {
            this->_it = Iter._it;
			this->_n = Iter._n;
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
    };

	template <class P>
    class ReverseIterator {
    };
}
#endif
