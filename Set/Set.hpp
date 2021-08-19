
#ifndef SET_HPP
# define SET_HPP

#include "../RedBlackTree/Node.hpp"
#include "../RedBlackTree/RedBlackTree.hpp"
#include "Iterators/iterator_traits.hpp"
#include "Iterators/Iterator.hpp"
#include "utils/utils.hpp"

namespace ft {

	template <class T,                        // set::key_type/value_type
			class Compare = less<T>,        // set::key_compare/value_compare
			class Alloc = std::allocator<T>>      // set::allocator_type
	class set {
        public:
            // Typedefs -----
            typedef T value_type;
            typedef T key_type;
            typedef Compare key_compare;
            typedef Compare value_compare;
            typedef Alloc allocator_type;
			typedef typename allocator_type::template rebind<pair<const T,T> >::other pair_allocator;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef TreeIterator<pair<const T,T> > iterator;
            typedef ConstTreeIterator<const pair<const T,T> > const_iterator;
            typedef reverseIterator<iterator> reverse_iterator;
            typedef reverseIterator<const_iterator> const_reverse_iterator;
            typedef typename iterator_traits<Iterator<RandomAccessIteratorTag, value_type> >::difference_type difference_type;
            typedef size_t size_type;
            typedef RedBlackTree<key_type, value_type, pair_allocator, key_compare> tree;

        private:
            // Variables -----
            tree _tree;

        public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit set(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()): _tree(comp, pair_allocator(alloc)) {};

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range.
		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type(), typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0): _tree(comp, pair_allocator(alloc)) {
                for (InputIterator it = first; it != last; it++) {
                    _tree.addNode(&(*it));
                }
            };

			// copy
		// Constructs a container with a copy of each of the elements in x.
		set(const set& x): _tree(x._tree) {};

		// Operators ----
		set &operator=(const set& x) {
			if (_tree.getTree() != x._tree.getTree()) {
				if (!_tree.empty()) {
					_tree.clear();
				}
				_tree = x._tree;
			}
		    return *this;
		};

		// Destructor -----
		~set() {};

		// Functions -----
			// Iterators -----
		iterator begin() {
		    return iterator(_tree.treeMin(), _tree.getNull());
		};
		const_iterator begin() const {
		    return const_iterator(_tree.treeMin(), _tree.getNull());
		};

		iterator end() {
		    return iterator(_tree.getNull(), _tree.getNull());
		};
		const_iterator end() const {
		    return const_iterator(_tree.getNull(), _tree.getNull());
		};

		reverse_iterator rbegin() {
		    return reverse_iterator(iterator(_tree.treeMax(), _tree.getNull()));
		};
		const_reverse_iterator rbegin() const {
		    return reverse_iterator(const_iterator(_tree.treeMax(), _tree.getNull()));
		};

		reverse_iterator rend() {
		    return reverse_iterator(iterator(_tree.getNull(), _tree.getNull()));
		};
		const_reverse_iterator rend() const {
		    reverse_iterator(const_iterator(_tree.getNull(), _tree.getNull()));
		};

			// Capacity -----
		size_type size() const {
		    return _tree.size();
		};
		size_type max_size() const {
		    return _tree.max_size();
		};
		bool empty() const {
		    return _tree.size() == 0;
		}

			// Modifiers -----
				// Insert -----
			// single element
		pair<iterator, bool> insert (const value_type &val) {
		    if (_tree.findNode(pair<value_type, value_type>(val, val)) != _tree.getNull()) {
		        return pair<iterator,bool>(iterator(_tree.addNode(pair<value_type, value_type> (val, val)), _tree.getNull()), true);
		    }
		    return pair<iterator,bool>(iterator(_tree.getNull(), _tree.getNull()), false);
		};
			// with hint
		iterator insert (iterator position, const value_type &val) {
		    if (position->getData().first == val) {
		        return position;
		    }
		    return iterator(_tree.addNode(pair<value_type, value_type>(val, val)), _tree.getNull());
		};
			// range
		template <class InputIterator>
		        void insert(InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0) {
		    while (first != last) {
		        _tree.addNode(first->getData());
		        first++;
		    }
		};

				// Erase -----
			// by iterator
		void erase (iterator position) {
		    _tree.deleteNode(&(*position));
		};
			// by val
		size_type erase (const value_type &val) {
			size_type saveSize = size();
		    _tree.deleteNode(pair<value_type, value_type>(val, value_type()));
			return saveSize == size() ? 0 : 1;
		};
			// range
		void erase (iterator first, iterator last) {
		    while (first != last) {
		        _tree.deleteNode(&(*first));
		        first++;
		    }
		};

		// Other -----
		void swap (set &x) {
		    tree *temp = &_tree;
		    _tree = x._tree;
		    x._tree = *temp;
		};
		void clear() {
		    _tree.clear();
		};

		// Observers -----
		key_compare key_comp() const {
		    return key_compare();
		};

		value_compare value_comp() const {
		    return value_compare();
		};

		// Operations -----
		iterator find (const value_type &val) const {
		    return iterator(_tree.findNode(pair<key_type, value_type>(val, value_type())), _tree.getNull());
		};

		size_type count (const value_type& val) const {
		    if (_tree.findNode(pair<key_type, value_type>(val, val)) != _tree.getNull()) {
		        return 1;
		    }
		    return 0;
		};

		iterator lower_bound(const value_type& val) const {
		    return _tree.lower_bound(ft::pair<key_type, value_type>(val, val));
		};

		iterator upper_bound (const value_type& val) const;
		pair<iterator, iterator> equal_range (const value_type& val) const {
		    return pair<iterator,iterator>(lower_bound(val), _tree.upper_bound(ft::pair<key_type, value_type>(val, val)));
		};

		// Allocator -----
		allocator_type get_allocator() const {
		    return _tree.getAlloc();
		};
	};
}

#endif
