
#ifndef SET_HPP
# define SET_HPP

#include "../utils/utils.hpp"

namespace ft {

	template <class T,                        // set::key_type/value_type
			class Compare = less<T>,        // set::key_compare/value_compare
			class Alloc = allocator<T>>      // set::allocator_type
	class Set: public RedBlackTree {
        public:
            // Typedefs -----
            typedef T value_type;
            typedef T key_type;
            typedef Compare key_compare;
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

        class value_compare: public binary_function<value_type, value_type, bool> {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class Set;
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
        }

        private:
            // Variables -----

        public:
		// Constructors -----
			// default
		// Constructs an empty container, with no elements.
		explicit Set(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type());

			// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range.
		template <class InputIterator>
		Set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
	   					const allocator_type& alloc = allocator_type());

			// copy
		// Constructs a container with a copy of each of the elements in x.
		Set(const Set& x);

		// Destructor -----
		~Set();

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

			// Modifiers -----
				// Insert -----
			// single element
		pair<iterator,bool> insert (const value_type &val);
			// with hint
		iterator insert (iterator position, const value_type &val);
			// range
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);

				// Erase -----
			// by iterator
		void erase (iterator position);
			// by key
		size_type erase (const value_type &val);
			// range
		void erase (iterator first, iterator last);

		// Other -----
		void swap (Set &x);
		void clear();

		// Observers -----
		key_compare key_comp() const;
		value_compare value_comp() const;

		// Operations -----
		iterator find (const value_type &val) const;
		size_type count (const value_type& val) const;
		iterator lower_bound (const value_type& val) const;
		iterator upper_bound (const value_type& val) const;
		pair<iterator,iterator> equal_range (const value_type& val) const;

		// Allocator -----
		allocator_type get_allocator() const;
	};
}

#endif
