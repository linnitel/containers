
#ifndef SET_HPP
# define SET_HPP

#include "../RedBlackTree/Node.hpp"
#include "../RedBlackTree/RedBlackTree.hpp"
#include "Iterators/iterator_traits.hpp"
#include "Iterators/Iterator.hpp"
#include "utils/utils.hpp"

namespace ft {

    template <class P>
            class SetIterator {
            public:
                typedef SetIterator<P> iterator;
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
                SetIterator(): _tree(), _null() {};
                explicit SetIterator(pointer ptr, const pointer null): _tree(ptr), _null(null) {};

                SetIterator(SetIterator const &Iter): _tree(Iter._tree), _null(Iter._null) {};

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
                    _tree = _tree.nextNode(_tree, _null);
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
            class ConstSetIterator {
            public:
                typedef const ConstSetIterator<const P> iterator;
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
                ConstSetIterator(): _tree(), _null() {};
                explicit ConstSetIterator(pointer ptr, const pointer null): _tree(ptr), _null(null) {};

                ConstSetIterator(ConstSetIterator const &Iter): _tree(Iter._tree), _null(Iter._null) {};

                ConstSetIterator &operator=(ConstSetIterator const &Iter) {
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
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef SetIterator<value_type> iterator;
            typedef SetIterator<const value_type> const_iterator;
            typedef reverseIterator<iterator> reverse_iterator;
            typedef reverseIterator<const_iterator> const_reverse_iterator;
            typedef typename iterator_traits<Iterator<RandomAccessIteratorTag, value_type> >::difference_type difference_type;
            typedef size_t size_type;
            typedef RedBlackTree<key_type, value_type, allocator_type, key_compare> tree;

        private:
            // Variables -----
            tree _tree;

        public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit set(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()): _tree(comp, alloc) {};

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range.
		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type(), typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0): _tree(comp, alloc) {
                for (iterator it = first; it != last; it++) {
                    _tree.addNode(*it);
                }
            };

			// copy
		// Constructs a container with a copy of each of the elements in x.
		set(const set& x): _tree(x._tree) {};

		// Operators ----
		set &operator=(const set& x) {
		    if (_tree != x._tree) {
		        if (!_tree.empty()) {
		            _tree.clean();
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
		    if (_tree.findNode(val) != _tree.getNull()) {
		        return pair<iterator,bool>(iterator(_tree.addNode(val), _tree.getNull()), true);
		    }
		    return pair<iterator,bool>(iterator(_tree.getNull(), _tree.getNull()), false);
		};
			// with hint
		iterator insert (iterator position, const value_type &val) {
		    if (*position._tree->_data.first == val) {
		        return position;
		    }
		    return iterator(_tree.addNode(val), _tree.getNull());
		};
			// range
		template <class InputIterator>
		        void insert(InputIterator first, InputIterator last, typename enable_if<!std::numeric_limits<InputIterator>::is_specialized>::type * = 0) {
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
		size_type erase (const value_type &val) {
		    _tree.deleteNode(pair<value_type, value_type>(val, value_type()));
		};
			// range
		void erase (iterator first, iterator last) {
		    while (first != last) {
		        _tree.deleteNode(*first);
		        first++;
		    }
		};

		// Other -----
		void swap (set &x) {
		    tree *temp = this->tree;
		    this->tree = x.tree;
		    x.tree = temp;
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

		iterator lower_bound (const value_type& val) const {
		    return iterator(_tree.lower_bound(pair<key_type, value_type>(val, val)), _tree.getNull());
		};

		iterator upper_bound (const value_type& val) const;
		pair<iterator, iterator> equal_range (const value_type& val) const {
		    return pair<iterator,iterator>(lower_bound(val), iterator(_tree.upper_bound(pair<key_type, value_type>(val, val)), _tree.getNull()));
		};

		// Allocator -----
		allocator_type get_allocator() const {
		    return _tree.getAlloc();
		};
	};
}

#endif
