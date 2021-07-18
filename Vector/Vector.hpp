#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "Iterator.hpp"
# include "iterator_traits.hpp"
# include <cstddef>

namespace ft {

	template <class P>
	class RandomAccessIterator {
	public:
		iterator_traits<P*> traits;
	};

	template <class RI>
	class ReverseIterator {

	};

	template <class T, class Alloc = std::allocator<T>>
	class Vector {
	public:
			// Typedefs -----
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef std::size_t size_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef RandomAccessIterator<value_type> iterator;
			typedef RandomAccessIterator<const value_type> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef typename std::ptrdiff_t difference_type;



	private:
			// Variables -----
			pointer _vector;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;
			pointer _begin;
			pointer _end;

			// Private functions -----
			void _setCapacity() {
			    _capacity = _size + (1.5 * _size);
			};

            void _setCapacity(size_type capacity) {
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
                _alloc.construct(&_vector[i], val); // allocate object?
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
        	for (;it != last; ++it) {
                ++_size;
                ++_capacity;
        	}
        	_vector = _alloc.allocate(_capacity);
        	for (size_type i = 0; first != last; ++it, ++i) {
                _alloc.construct(&_vector[i], first);
        	}
        };

				// copy
		// Constructs a container with a copy of each of the elements in x, in the same order.
        Vector (const Vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
			*this = x;
        };

            // Destructor -----
			~Vector() {
			    for (size_type i = 0; i < _size; ++i) {
			        _alloc.destroy(&_vector[i]);
			    }
			    _alloc.deallocate(_vector, _capacity);
			};

            // Operators reload -----
			Vector &operator= (const Vector &x) {

			};

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
					return _size;
            };
            size_type max_size() const {
				return ((size_type)-1);
            };
            void resize(size_type n, value_type val = value_type());
            size_type capacity() const {
				return _capacity;
            };
            bool empty() const {
                if (_size == 0) {
                    return true;
                }
                return false;
            }
            void reserve (size_type n) {

            };
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

            void swap(Vector& x);
            void clear();

                // Allocator -----
            allocator_type get_allocator() const;
            // Nonmember functions -----
        friend bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend void swap(Vector<T,Alloc>& x, Vector<T,Alloc>& y);
	};

    template <class Alloc> // bool specialization
    class Vector<bool,Alloc> {
    };

    template <class T, class Alloc>
    bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
    template <class T, class Alloc>
    bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);

    template <class T, class Alloc>
    void swap(Vector<T,Alloc>& x, Vector<T,Alloc>& y);
}

#endif
