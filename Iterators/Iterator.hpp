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
        typedef iterator_traits<Iterator<BidirectionalIteratorTag, P>> traits;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;
    protected:
        pointer _it;
        difference_type _n;
    public:
        BidirectionalIterator(): _it(new pointer), _n() {};
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

        BidirectionalIterator operator++(int) {
            BidirectionalIterator tmp = *this;
            ++(*this);
            return tmp;
        };

        BidirectionalIterator &operator++() {
            _it += _n;
            return *this;
        };

        friend bool operator== (const BidirectionalIterator& a, const BidirectionalIterator& b);
        friend bool operator!= (const BidirectionalIterator& a, const BidirectionalIterator& b);
    };

    template <class T, class Pointer = T*, class Reference = T&>
    bool operator== (const BidirectionalIterator<T>& a, const BidirectionalIterator<T>& b) {
        return a._it == b._it;
    }
    template <class T, class Pointer = T*, class Reference = T&>
    bool operator!= (const BidirectionalIterator<T>& a, const BidirectionalIterator<T>& b) {
        return !(a._it == b._it);
    }

    template <class P>
    class RandomAccessIterator: public BidirectionalIterator<P> {
    public:
        typedef iterator_traits<Iterator<RandomAccessIteratorTag, P>> traits;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;
    protected:
        pointer _it;
        difference_type _n;
    public:
        RandomAccessIterator(): _it(new pointer), _n() {};
        explicit RandomAccessIterator(pointer ptr): _it(ptr), _n() {};

        RandomAccessIterator(RandomAccessIterator const &Iter) : _it(Iter._it), _n() {};

        RandomAccessIterator &operator=(RandomAccessIterator const &Iter) {
            _it = Iter._it;
            _n = Iter._n;
            return *this;
        };
    };
}
#endif
