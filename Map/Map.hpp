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
	class Map {
	public:
		// Typedefs -----
		typedef const Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef Node<value_type> node;
		typedef typename Alloc::template rebind<node>::other node_allocator;
        typedef MapIterator<value_type> iterator;
        typedef MapIterator<const value_type> const_iterator;
		typedef reverseIterator<iterator> reverse_iterator;
		typedef ft::reverseIterator<const_iterator> const_reverse_iterator;
		typedef typename iterator_traits<Iterator<RandomAccessIteratorTag, value_type> >::difference_type difference_type; //difference_type
		typedef size_t size_type;

        class value_compare: public binary_function<value_type, value_type, bool> {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class Map;
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

        typedef RedBlackTree<value_type, node_allocator, value_compare> tree;
	private:
		// Variables -----
        tree _tree;

	public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit Map(const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()): _tree(comp, node_allocator(alloc)) {
		};

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
	   					const allocator_type& alloc = allocator_type()): _tree(comp, alloc) {
	   					    for (iterator it = first; it != last; it++) {
	   					        _tree.addNode(*it);
	   					    }
	   					};
			// copy
		// Constructs a container with a copy of each of the elements in x.
		Map(const Map& x): _tree(x._tree) {};

		// Destructor -----
		~Map() {};

		// Operators reload -----
		Map &operator=(const Map &x) {
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
		    return _tree.treeMax();
		};

		const_iterator end() const {
		    return _tree.treeMax();
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
			return this->_size;
		};

		size_type max_size() const {
			return _tree.max_size();
		};

		bool empty() const {
			return size() == 0;
		}
			// Access elements -----
		mapped_type &operator[](const key_type &k) {
			mapped_type any;
			value_type value = _tree.findNode(pair<key_type, mapped_type>(k, any))->getData();
			return value.second;
		};

			// Modifiers -----
				// Insert -----
			// single element
		pair<iterator,bool> insert(const value_type &val) {
		    pair<iterator,bool> ret;
		    if (_tree.findNode(val) != _tree.getNull())
		};
			// with hint
		iterator insert(iterator position, const value_type &val);
			// range
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);

				// Erase -----
			// by iterator
		void erase (iterator position);
			// by key
		size_type erase (const key_type& k) {
			mapped_type any;
			deleteNode(pair<key_type, mapped_type>(k, any));
		};
			// range
		void erase (iterator first, iterator last);

				// Other -----
		void swap (Map &x);
		void clear();

			// Observers -----
		key_compare key_comp() const;
		value_compare value_comp() const;

			// Operations -----
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;

		size_type count (const key_type& k) const;

		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;

		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;

		pair<iterator,iterator>             equal_range (const key_type& k);
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

			// Allocator -----
		allocator_type get_allocator() const {
				return _alloc;
		};
	};
}

#endif
