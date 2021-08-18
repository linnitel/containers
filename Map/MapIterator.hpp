
#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

#include "../Iterators/Iterator.hpp"
#include "../Iterators/iterator_traits.hpp"

namespace ft {
    template <class P>
    class MapIterator {
    public:
        typedef MapIterator<P> iterator;
        typedef Node<P> node;
        typedef iterator_traits<Iterator<BidirectionalIteratorTag, node> > traits;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;
        typedef typename traits::iterator_category iterator_category;
    protected:
        pointer _tree;
        const pointer _null;

    public:
        MapIterator(): _tree(), _null() {};
        explicit MapIterator(pointer ptr, const pointer null): _tree(ptr), _null(null) {};

        MapIterator(MapIterator const &Iter): _tree(Iter._tree), _null(Iter._null) {};

        iterator &operator=(iterator const &Iter) {
            if (&Iter != this) {
                _tree = Iter._tree;
                _null = Iter._null;
            }
            return *this;
        };

        reference operator*() const {
            return *_tree;
        };

        pointer operator->() {
            return &(*_tree);
        };

        iterator &operator++() {
            _tree = _tree->nextNode(_null);
            return *this;
        };

        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        };

        iterator &operator--() {
            _tree = _tree.prevNode(_tree, _null);
            return *this;
        };

        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        };

        friend bool operator==(const iterator& a, const iterator& b) {
            return a._tree == b._tree && a._null == b._null;
        };
        friend bool operator!=(const iterator& a, const iterator& b) {
            return !(a._tree == b._tree);
        };
    };

	template <class P>
	class ConstMapIterator {
	public:
		typedef const ConstMapIterator<const P> iterator;
		typedef const Node<const P> node;
		typedef iterator_traits<Iterator<BidirectionalIteratorTag, node> > traits;
		typedef typename traits::value_type value_type;
		typedef typename traits::difference_type difference_type;
		typedef typename traits::pointer pointer;
		typedef typename traits::reference reference;
		typedef typename traits::iterator_category iterator_category;
	protected:
		pointer _tree;
		const pointer _null;

	public:
		ConstMapIterator(): _tree(), _null() {};
		explicit ConstMapIterator(pointer ptr, const pointer null): _tree(ptr), _null(null) {};

		ConstMapIterator(ConstMapIterator const &Iter): _tree(Iter._tree), _null(Iter._null) {};

		ConstMapIterator &operator=(ConstMapIterator const &Iter) {
			if (&Iter != this) {
				_tree = Iter._tree;
				_null = Iter._null;
			}
			return *this;
		};

		reference operator*() const {
			return *_tree;
		};

		pointer operator->() {
			return &(*this);
		};

		iterator &operator++() {
			_tree = _tree.nextNode(_null);
			return *this;
		};

		iterator operator++(int) {
			iterator tmp = *this;
			++(*this);
			return tmp;
		};

		iterator &operator--() {
			_tree = _tree.prevNode(_null);
			return *this;
		};

		iterator operator--(int) {
			iterator tmp = *this;
			--(*this);
			return tmp;
		};

		friend bool operator==(const iterator& a, const iterator& b) {
			return a._tree == b._tree && a._null == b._null;
		};
		friend bool operator!=(const iterator& a, const iterator& b) {
			return !(a._tree == b._tree);
		};

		pointer getNode() const {
            return _tree;
		}

		pointer getNull() const {
		    return _null;
		}
	};
}

#endif //MAPITERATOR_HPP
