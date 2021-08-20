//
// Created by Yuliya Martsenko on 18.08.2021.
//

#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "../Iterators/Iterator.hpp"
#include "../Iterators/iterator_traits.hpp"

namespace ft {

	template <class P>
	class TreeIterator {
	public:
		typedef TreeIterator<P> iterator;
		typedef Node<P> node;
		typedef iterator_traits<Iterator<BidirectionalIteratorTag, node> > traits;
		typedef typename traits::value_type value_type;
		typedef typename traits::difference_type difference_type;
		typedef typename traits::pointer pointer;
		typedef typename traits::reference reference;
		typedef typename traits::iterator_category iterator_category;
	protected:
		pointer _tree;
		pointer _null;

	public:
		TreeIterator(): _tree(), _null() {};
		TreeIterator(pointer ptr, const pointer null): _tree(ptr), _null(null) {};

		TreeIterator(TreeIterator const &Iter): _tree(Iter._tree), _null(Iter._null) {};

		TreeIterator(ConstTreeIterator<P> const &Iter): _tree(Iter._tree), _null(Iter._null) {};

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
			_tree = _tree->prevNode(_null);
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
	class ConstTreeIterator {
	public:
		typedef const ConstTreeIterator<const P> iterator;
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
		ConstTreeIterator(): _tree(), _null() {};
		ConstTreeIterator(pointer ptr, const pointer null): _tree(ptr), _null(null) {};

		ConstTreeIterator(ConstTreeIterator const &Iter): _tree(Iter._tree), _null(Iter._null) {};

		ConstTreeIterator(TreeIterator<P> const &Iter): _tree(Iter._tree), _null(Iter._null) {};

		ConstTreeIterator &operator=(ConstTreeIterator const &Iter) {
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
	};
}

#endif //TREEITERATOR_HPP
