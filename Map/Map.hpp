#ifndef MAP_HPP
# define MAP_HPP

namespace ft {

	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>,                     // map::key_compare
			class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
	> class Map {
	public:
		// Typedefs -----
		typedef const Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename fd::random_access_iterator<iterator> iterator;
		typedef typename fd::random_access_iterator<const_iterator> const_iterator;
		typedef typename fd::reverse_iterator<iterator> reverse_iterator;
		typedef typename fd::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename fd::iterator_traits<iterator>::difference_type difference_type //difference_type
		typedef typename size_t size_type;
	private:
		// Variables -----

	public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit Map(const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type());

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		// in the same order.
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
	   					const allocator_type& alloc = allocator_type());

			// copy
		// Constructs a container with a copy of each of the elements in x, in the same order.
		Map(const map& x);

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
		size_type size() const;
		size_type max_size() const;
		bool empty() const {
			if (_size == 0) {
				return true;
			}
			return false;
		}
			// Access elements -----
		mapped_type &operator[](const key_type &k);

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
		size_type erase (const key_type& k);
			// range
		void erase (iterator first, iterator last);

				// Other -----
		void swap (map& x);
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
		allocator_type get_allocator() const;
	};
}

#endif
