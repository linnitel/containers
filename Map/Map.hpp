#ifndef MAP_HPP
# define MAP_HPP

#include "../RedBlackTree/RedBlackTree.hpp"
#include "../Iterators/Iterator.hpp"
#include "../Iterators/iterator_traits.hpp"
#include "../utils/utils.hpp"

namespace ft {
	template <class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> > >    // map::allocator_type
	class Map: public RedBlackTree<pair<const Key, T>, Alloc, Compare> {
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
        typedef BidirectionalIterator<value_type> iterator;
        typedef BidirectionalIterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename iterator_traits<Iterator<RandomAccessIteratorTag, value_type> >::difference_type difference_type; //difference_type
		typedef size_t size_type;
		typedef RedBlackTree<value_type, Alloc, Compare> tree;

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
	private:
		// Variables -----
		allocator_type _alloc;

	public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit Map(const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()): tree(comp), _alloc(alloc) {
//			value_type _data = pair<key_type, mapped_type>();
//			value_type _data = _alloc.construct(1);
//			_alloc.construct(&_data[1], _data);
		};

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
	   					const allocator_type& alloc = allocator_type()): tree() {

	   					};

			// copy
		// Constructs a container with a copy of each of the elements in x.
		Map(const Map& x);

		// Destructor -----
		~Map();

		// Operators reload -----
		Map &operator=(const Map &x);

		// Functions -----
			// Iterators -----
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

			// Capacity -----
		size_type size() const {
			return this->_size;
		};

		size_type max_size() const {
			return _alloc.max_size();
		};

		bool empty() const {
			return size() == 0;
		}
			// Access elements -----
		mapped_type &operator[](const key_type &k) {
			mapped_type any;
			value_type value = findNode(pair<key_type, mapped_type>(k, any))->getData();
			return value.second;
		};

			// Modifiers -----
				// Insert -----
			// single element
		pair<iterator,bool> insert(const value_type &val);
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
