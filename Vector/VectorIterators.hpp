
#ifndef VECTORITERATORS_HPP
# define VECTORITERATORS_HPP

#include "../Iterators/Iterator.hpp"
#include "../Iterators/iterator_traits.hpp"

namespace ft {

    template <class P>
    class VectorIterator {
        public:
            typedef VectorIterator<P> iterator;
            typedef iterator_traits<Iterator<RandomAccessIteratorTag, P> > traits;
            typedef typename traits::value_type value_type;
//            typedef typename traits::difference_type difference_type;
			typedef ptrdiff_t difference_type;
            typedef typename traits::pointer pointer;
            typedef typename traits::reference reference;
            typedef typename traits::iterator_category iterator_category;
        private:
            pointer _it;
    public:
            VectorIterator(): _it() {};
            VectorIterator(pointer ptr): _it(ptr)  {};

            VectorIterator(VectorIterator const &Iter): _it(Iter._it) {};

            VectorIterator &operator=(VectorIterator const &Iter) {
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

        iterator &operator++() {
            _it++;
            return *this;
        };

        iterator operator++(int) {
            iterator  tmp = *this;
            ++(*this);
            return tmp;
        };

        iterator &operator--() {
            _it--;
            return *this;
        };

        iterator operator--(int) {
            iterator  tmp = *this;
            --(*this);
            return tmp;
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

        pointer getIt() const {
            return _it;
        }
    };

    template <class P>
    class ConstVectorIterator {
    public:
        typedef ConstVectorIterator<const P> iterator;
        typedef iterator_traits<Iterator<RandomAccessIteratorTag, const P> > traits;
        typedef typename traits::value_type value_type;
//        typedef typename traits::difference_type difference_type;
		typedef ptrdiff_t difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;
    private:
        pointer _it;
    public:
        ConstVectorIterator(): _it()   {};
        explicit ConstVectorIterator(pointer ptr): _it(ptr)  {};

        ConstVectorIterator(ConstVectorIterator const &Iter): _it(Iter._it) {};

        explicit ConstVectorIterator(VectorIterator<P> &Iter): _it(Iter.getIt()) {};

        ConstVectorIterator &operator=(ConstVectorIterator const &Iter) {
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

        iterator &operator++() {
            _it++;
            return *this;
        };

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        };

        iterator &operator--() {
            _it--;
            return *this;
        };

        iterator operator--(int) {
            iterator  tmp = *this;
            --(*this);
            return tmp;
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
            return a._it != b._it;
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
}

#endif //VECTORITERATORS_HPP
