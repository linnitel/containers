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

	template <class T>
	void swap(T& x, T& y) {
		T temp = x;
		x = y;
		y = temp;
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
			pointer _last;

			// Private functions -----
			void _setCapacity(size_type size) {
			    _capacity = size + (1.5 * size);
			};

            void _reallocContainerMemmory(size_type new_capacity) {
				pointer temp = _alloc.allocate(new_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(&temp[i], _vector[i]);
				}
				for (iterator it = begin(); it != end(); ++it) {
					_alloc.destroy(&(*it));
				}
				_alloc.deallocate(_vector, _capacity);
				_capacity = new_capacity;
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
            iterator begin() {
				return iterator(_begin);
            };
            const_iterator begin() const {
				return const_iterator(_begin);
            };

            iterator end() {
				return iterator(_last);
            };
            const_iterator end() const {
				return const_iterator(_last);
            };

            reverse_iterator rbegin() {
				return reverse_iterator(_last - 1);
            };
            const_reverse_iterator rbegin() const {
				return const_reverse_iterator(_last - 1);
            };

            reverse_iterator rend() {
				return reverse_iterator(_begin - 1);
            };
            const_reverse_iterator rend() const {
				return const_reverse_iterator(_begin - 1);
            };

                // Capacity -----
            size_type size() const {
					return _size;
            };
            size_type max_size() const {
				return ((size_type)-1);
            };
            void resize(size_type n, value_type val = value_type()) {
            	while (_size > n) {
            		pop_back();
            	}
            	reserve(n);
				while (_size < n) {
					push_back(val);
				}
            };
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
				if (_capacity < n) {
					_reallocContainerMemmory(n);
				}
            };
                // Access elements -----
            reference operator[](size_type n) {
            	return _vector[n];
            };
            const_reference operator[](size_type n) const {
				return _vector[n];
            };

            reference at(size_type n) {
            	if (n > _size) {
//					throw Vector::out_of_bound // TODO write an exception
            	}
				return _vector[n];
            };
            const_reference at(size_type n) const {
				if (n > _size) {
//					throw Vector::out_of_bound // TODO write an exception
				}
				return _vector[n];
            };

            reference front() {
				return _vector;
            };
            const_reference front() const {
				return _vector;
            };

            reference back() {
				return _last - 1;
            };
            const_reference back() const {
				return _last - 1;
            };
                // Modifiers -----

            template <class InputIterator>
            void assign(InputIterator first, InputIterator last); // range
            void assign(size_type n, const value_type& val); // fill

            void push_back(const value_type& val);
            void pop_back() {
				if (_size)
					_alloc.destroy(&_vector[_size - 1]);
				_size -= 1;
            };

            iterator insert(iterator position, const value_type& val); // single element
            void insert(iterator position, size_type n, const value_type& val); // fill
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last); // range

            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);

            void swap(Vector& x) {
            	ft::swap(this->_vector, x._vector);
				ft::swap(this->_size, x._size);
				ft::swap(this->_capacity, x._capacity);
				ft::swap(this->_alloc, x._alloc);
            };
            void clear() {
				if (_size) {
					for (size_type i = 0; i < _size; ++i) {
						_alloc.destroy(&_vector[i]);
					}
					_size = 0;
				}
            };

                // Allocator -----
            allocator_type get_allocator() const;
            // Nonmember functions -----
        friend bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
        friend bool operator>=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
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
}

#endif
