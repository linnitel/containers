#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# define MAX_SIZE (size_t)-1

namespace ft {

	template <class T, class Alloc = std::allocator<T>>
	class Vector {
	public:
			// Typedefs -----
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename RandomAccessIterator<iterator> iterator;
			typedef typename RandomAccessIterator<const_iterator> const_iterator;
			typedef typename ReverseIterator<iterator> reverse_iterator;
			typedef typename ReverseIterator<const_iterator> const_reverse_iterator;
			typedef typename IteratorTraits<iterator>::difference_type difference_type
			typedef typename size_t size_type;
	private:
			// Variables -----
			pointer _vector;
            size_type _size;
			size_type _capacity;
			allocator_type _alloc;

			// Private functions -----
			void _setCapacity() {
			    _capacity = _size + _size / 10;
			};

            void _setCapacity(long capacity) {
                _capacity = capacity;
            };
	public:
            // Constructors -----
        		// default
        // Constructs an empty container, with no elements.
        explicit Vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0) {
            	_vector = _alloc.allocate(_capacity);
        };

				// fill
		// Constructs a container with n elements. Each element is a copy of val.
        explicit Vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n) {
        	_vector = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++) {
				_vector[i] = val; // allocate object?
			}
        };

				// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		// in the same order.
        template <class InputIterator>
        Vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type()): _alloc(alloc) {
        	InputIterator it(first);
        	_vector = _alloc.allocate(0);
        };

				// copy
		// Constructs a container with a copy of each of the elements in x, in the same order.
        Vector (const vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
			*this = x;
        };

            // Destructor -----
			~Vector();

            // Operators reload -----
			Vector &operator= (const Vector &x);

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
            size_type size() const; // size_type ?? what is it?
            size_type max_size() const;
            void resize(size_type n, value_type val = value_type());
            size_type capacity() const;
            bool empty() const {
                if (_size == 0) {
                    return true;
                }
                return false;
            }
            void reserve (size_type n);
                // Access elements -----
            reference operator[](size_type n);
            const_reference operator[](size_type n) const;

            reference at(size_type n);
            const_reference at(size_type n) const;

            reference front();
            const_reference front() const;

            reference back();
            const_reference back() const;
                // Modifiers -----

            template <class InputIterator>
            void assign(InputIterator first, InputIterator last); // range
            void assign(size_type n, const value_type& val); // fill

            void push_back(const value_type& val);
            void pop_back();

            iterator insert(iterator position, const value_type& val); // single element
            void insert(iterator position, size_type n, const value_type& val); // fill
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last); // range

            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);

            void swap(vector& x);
            void clear();

                // Allocator -----
            allocator_type get_allocator() const;
            // Nonmember functions -----
        friend bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        friend bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        friend bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        friend bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        friend bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        friend bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
        friend void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
	};

    template <class Alloc> // bool specialization
    class Vector<bool,Alloc> {
    };

    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
