#ifndef MAP_HPP
# define MAP_HPP

#include "../RedBlackTree/Node.hpp"
#include "../RedBlackTree/RedBlackTree.hpp"
#include "utils/utils.hpp"

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
        typedef TreeIterator<value_type> iterator;
        typedef ConstTreeIterator<const value_type> const_iterator;
		typedef reverseIterator<iterator> reverse_iterator;
		typedef reverseIterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
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
            const allocator_type& alloc = allocator_type(), typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0): _tree(first, last, comp, alloc) {
        };
			// copy
		// Constructs a container with a copy of each of the elements in x.
		map(const map& x): _tree(x._tree) {};

		// Destructor -----
		~map() {};

		// Operators reload -----
		map &operator=(const map &x) {
		    if (_tree.getTree() != x._tree.getTree()) { // comparison should be of all items of the tree
		        if (!_tree.empty()) {
		            _tree.clear();
		        }
		        _tree = x._tree;
		    }
            return *this;
		};

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
		    return const_reverse_iterator(const_iterator(_tree.treeMax(), _tree.getNull()));
		};

		reverse_iterator rend() {
		    return reverse_iterator(iterator(_tree.getNull(), _tree.getNull()));
		};
		const_reverse_iterator rend() const {
		    return const_reverse_iterator(const_iterator(_tree.getNull(), _tree.getNull()));
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
		    if (_tree.findNode(val) == _tree.getNull()) {
				return pair<iterator,bool>(iterator(_tree.addNode(val), _tree.getNull()), true);
		    }
			return pair<iterator,bool>(iterator(_tree.getNull(), _tree.getNull()), false);
		};
			// with hint
		iterator insert(iterator position, const value_type &val) {
		    key_compare compare;
		    if (compare(position->getData().first, val.first)) {
			    position->getData().second = val.second;
				return position;
			}
			return iterator(_tree.addNode(val), _tree.getNull());
		};
			// range
		template <class InputIterator>
		        void insert(InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0) {
            _tree.insert(first, last);
		};

				// Erase -----
			// by iterator
			void erase (iterator position, typename enable_if<!std::numeric_limits<iterator>::is_specialized>::type * = 0) {
			_tree.deleteNode(&(*position));
		};
			// by key
		size_type erase (const key_type& k) {
		    size_type currentSize = size();
			_tree.deleteNode(pair<key_type, mapped_type>(k, mapped_type()));
            return currentSize == size() ? 0 : 1;
		};
			// range
		void erase (iterator first, iterator last) {
			while (first != last) {
			    _tree.deleteNode(&(*first));
				first++;
			}
		};

				// Other -----
		void swap (map &x) {
			tree *temp = &_tree;
			_tree = x._tree;
			x._tree = *temp;
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
			return iterator(_tree.findNode(pair<key_type, mapped_type>(k, mapped_type())), _tree.getNull());
		};

		const_iterator find(const key_type& k) const {
			return const_iterator(_tree.findNode(pair<key_type, mapped_type>(k, mapped_type())), _tree.getNull());
		};

		size_type count(const key_type& k) const {
		    if (_tree.findNode(pair<key_type, mapped_type>(k, mapped_type())) != _tree.getNull()) {
                return 1;
		    }
            return 0;
		};

		iterator lower_bound(const key_type& k) {
			return _tree.lower_bound(pair<key_type, mapped_type>(k, mapped_type()));
		};
		const_iterator lower_bound(const key_type& k) const {
			return const_iterator(_tree.lower_bound(pair<key_type, mapped_type>(k, mapped_type())));
		};

		iterator upper_bound(const key_type& k) {
			return _tree.upper_bound(pair<key_type, mapped_type>(k, mapped_type()));
		};

		const_iterator upper_bound(const key_type& k) const {
			return _tree.upper_bound(pair<key_type, mapped_type>(k, mapped_type()));
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
