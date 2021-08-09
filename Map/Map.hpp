#ifndef MAP_HPP
# define MAP_HPP

#include "../RedBlackTree/Node.hpp"
#include "../RedBlackTree/RedBlackTree.hpp"
#include "MapIterator.hpp"
#include "../utils/utils.hpp"

namespace ft {

	template <class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> > >    // map::allocator_type
	class map {
	public:
		// Typedefs -----
		typedef const Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
        typedef MapIterator<value_type> iterator;
        typedef MapIterator<const value_type> const_iterator;
		typedef reverseIterator<iterator> reverse_iterator;
		typedef reverseIterator<const_iterator> const_reverse_iterator;
		typedef typename iterator_traits<Iterator<RandomAccessIteratorTag, value_type> >::difference_type difference_type;
		typedef size_t size_type;
		typedef RedBlackTree<key_type, mapped_type, allocator_type, key_compare> tree;

		class value_compare: public binary_function<value_type, value_type, bool> {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
		protected:
			Compare comp;
			explicit value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};

	private:
		// Variables -----
        tree _tree;

	public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit map(const key_compare& comp = key_compare(),
					 const allocator_type& alloc = allocator_type()): _tree(comp, alloc) {};

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(comp, alloc) {
            for (iterator it = first; it != last; it++) {
                _tree.addNode(*it);
            }
        };
			// copy
		// Constructs a container with a copy of each of the elements in x.
		map(const map& x): _tree(x._tree) {};

		// Destructor -----
		~map() {};

		// Operators reload -----
		map &operator=(const map &x) {
		    if (_tree != x._tree) {
		        if (!_tree.empty()) {
		            _tree.clean();
		        }
		        _tree = x._tree;
		    }
            return *this;
		};

		// Functions -----
			// Iterators -----
		iterator begin() {
            return _tree.treeMin();
		};
		const_iterator begin() const {
		    return _tree.treeMin();
		};

		iterator end() {
		    return _tree.getNull();
		};

		const_iterator end() const {
		    return _tree.getNull();
		};

		reverse_iterator rbegin() {
		    return _tree.treeMax();
		};

		const_reverse_iterator rbegin() const {
		    return _tree.treeMax();
		};

		reverse_iterator rend() {
		    return _tree.treeMin();
		};
		const_reverse_iterator rend() const {
		    return _tree.treeMin();
		};

			// Capacity -----
		size_type size() const {
			return _tree.size();
		};

		size_type max_size() const {
			return _tree.max_size();
		};

		bool empty() const {
			return size() == 0;
		}
			// Access elements -----
		mapped_type &operator[](const key_type &k) {
			return _tree.addNode(value_type(k, mapped_type()))->_data.second;
		};

			// Modifiers -----
				// Insert -----
			// single element
		pair<iterator,bool> insert(const value_type &val) {
		    if (_tree.findNode(val) != _tree.getNull()) {
				return pair<iterator,bool>(iterator(_tree.addNode(val), _tree.getNull()), true);
		    }
			return pair<iterator,bool>(iterator(_tree.getNull(), _tree.getNull()), false);
		};
			// with hint
		iterator insert(iterator position, const value_type &val) {
			if (*position._tree->_data == val) {
				return position;
			}
			return iterator(_tree.addNode(val), _tree.getNull());
		};
			// range
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			while (first != last) {
				_tree.addNode(*first);
				first++;
			}
		};

				// Erase -----
			// by iterator
		void erase (iterator position) {
			_tree.deleteNode(*position);
		};
			// by key
		size_type erase (const key_type& k) {
			_tree.deleteNode(pair<key_type, mapped_type>(k, NULL));
		};
			// range
		void erase (iterator first, iterator last) {
			while (first != last) {
				_tree.deleteNode(*first);
				first++;
			}
		};

				// Other -----
		void swap (map &x) {
			tree *temp = this->tree;
			this->tree = x.tree;
			x.tree = temp;
		};

		void clear() {
			_tree.clear();
		};

			// Observers -----
		key_compare key_comp() const {
			key_compare _compare;
			return _compare;
		};
		value_compare value_comp() const {
			return value_compare();
		};

			// Operations -----
		iterator find(const key_type& k) {
			return iterator(_tree.findNode(pair<key_type, mapped_type>(k, NULL)), _tree.getNull());
		};

		const_iterator find(const key_type& k) const {
			return const_iterator(_tree.findNode(pair<key_type, mapped_type>(k, NULL)), _tree.getNull());
		};

		size_type count(const key_type& k) const {
		    if (_tree.findNode(pair<key_type, mapped_type>(k, NULL)) != _tree.getNull()) {
                return 1;
		    }
            return 0;
		};

		iterator lower_bound(const key_type& k) {
			return iterator(_tree.lower_bound(pair<key_type, mapped_type>(k, NULL)), _tree.getNull()); // TODO add lower_bound to tree
		};
		const_iterator lower_bound(const key_type& k) const {
			return const_iterator(_tree.lower_bound(pair<key_type, mapped_type>(k, NULL)), _tree.getNull());
		};

		iterator upper_bound(const key_type& k) {
			return iterator(_tree.upper_bound(pair<key_type, mapped_type>(k, NULL)), _tree.getNull()); // TODO add upper_bound to tree
		};

		const_iterator upper_bound(const key_type& k) const {
			return const_iterator(_tree.upper_bound(pair<key_type, mapped_type>(k, NULL)), _tree.getNull());
		};

		pair<iterator,iterator>             equal_range(const key_type& k) {
			return pair<iterator,iterator>(lower_bound(k), upper_bound(k));
		};
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const {
			return pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
		};

			// Allocator -----
		allocator_type get_allocator() const {
				return _tree.getAlloc();
		};
	};
}

#endif
