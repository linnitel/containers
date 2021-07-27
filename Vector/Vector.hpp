#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "Iterator.hpp"
# include "iterator_traits.hpp"
# include <cstddef>

#define CAPACITY_COEFFICIENT 2

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
			typedef iterator_traits<Iterator<RandomAccessIteratorTag, value_type>> difference_type;

	private:
			// Variables -----
			pointer _vector;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;

			// Private functions -----

            void _reallocContainerMemmory(size_type new_capacity) {
				pointer temp = _alloc.allocate(new_capacity);
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(&temp[i], _vector[i]);
				}
				for (iterator it = begin(); it != end(); ++it) {
					_alloc.destroy(&(*it));
				}
				_alloc.deallocate(_vector, _capacity);
				_vector = temp;
				_capacity = new_capacity;
            };

            void _constructNSize(size_type n, const value_type& val) {
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(&_vector[i], val); // allocate object?
				}
            };

			template <class InputIterator>
			size_type _countIterRangeSize(InputIterator first, InputIterator last) {
				InputIterator it(first);
				size_type size = 0;
				for (;it != last; ++it) {
					++size;
				}
				return size;
            };

			template <class InputIterator>
			void _allocIterRange(InputIterator first, InputIterator last) {
				for (size_type i = 0; first != last; ++first, ++i) {
					_alloc.construct(&_vector[i], first);
				}
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
			_vector = _alloc.allocate(n);
			_constructNSize(n, val);
        };

				// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		// in the same order.
        template <class InputIterator>
        Vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type()): _alloc(alloc) {
			_size = _countIterRangeSize(first, last);
			_capacity = _size;
			_vector = _alloc.allocate(_capacity);
			_allocIterRange(first, last);
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
				return iterator(_vector);
            };
            const_iterator begin() const {
				return const_iterator(_vector);
            };

            iterator end() {
				return iterator(_vector - 1 + _size);
            };
            const_iterator end() const {
				return const_iterator(_vector - 1 + _size);
            };

            reverse_iterator rbegin() {
				return reverse_iterator(_vector - 1 + _size);
            };
            const_reverse_iterator rbegin() const {
				return const_reverse_iterator(_vector - 1 + _size);
            };

            reverse_iterator rend() {
				return reverse_iterator(_vector - 1);
            };
            const_reverse_iterator rend() const {
				return const_reverse_iterator(_vector - 1);
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
				return _vector - 1 + _size;
            };
            const_reference back() const {
				return _vector - 1 + _size;
            };
                // Modifiers -----

            template <class InputIterator>
            void assign(InputIterator first, InputIterator last) {
				clear();
				_size = _countIterRangeSize(first, last);
				if (_size > _capacity) {
					_alloc.deallocate(_vector, _capacity);
					_capacity = _size;
					_vector = _alloc.allocate(_capacity);
				}
				_allocIterRange(first, last);
            }; // range

            void assign(size_type n, const value_type& val) {
            	clear();
            	if (n > _capacity) {
					_alloc.deallocate(_vector, _capacity);
					_size = n;
					_capacity = _size;
					_vector = _alloc.allocate(_capacity);
            	}
            	_constructNSize(n, val);
            }; // fill

            void push_back(const value_type& val) {
            	if (_size + 1 > _capacity) {
            		_reallocContainerMemmory(_capacity * CAPACITY_COEFFICIENT);
            	}
				_alloc.construct(&(_vector[_size]), val);
            	_size += 1;
            };
            void pop_back() {
				if (_size)
					_alloc.destroy(&_vector[_size - 1]);
				_size -= 1;
            };

            iterator insert(iterator position, const value_type& val) {
				position--;
				pointer temp = _vector;
            	if (_size + 1 > _capacity) {
					_reallocContainerMemmory(_capacity * CAPACITY_COEFFICIENT);
            	}
            	if (position + 1 != end()) {
					_moveRight(position);
            	}
				_alloc.construct(&(*position), val);
            	_size = _size + 1;
				return position;
            }; // single element

            void insert(iterator position, size_type n, const value_type& val) {
				pointer temp;
				size_type i = 0;
				iterator it;
				position--;
				if (_size + n > _capacity) {
					temp = _alloc.allocate((_size + n) * CAPACITY_COEFFICIENT);
					it = begin();
					for (; it != position; it++) {
						_alloc.construct(&temp[i], *it);
						i++;
					}
					int j = i;
					for (; j < n; j++) {
						_alloc.construct(&temp[i + j], val);
					}
					i += j;
					for (iterator copy = it; copy != end(); copy++) {
						_alloc.construct(&temp[i], *copy);
						i++;
					}
					for (iterator destroy = begin(); destroy != end(); ++destroy) {
						_alloc.destroy(&(*destroy));
					}
					_alloc.deallocate(_vector, _capacity);
					_vector = temp;
					_capacity = _capacity * CAPACITY_COEFFICIENT;
				}
				else {
					it = end() + n;
					reverse_iterator copy = rbegin();
					for (; copy != rbegin() && copy != position; copy++, it--) {
						_alloc.construct(&(*it), *copy);
					}
					if (copy == rbegin()) {
						for (; copy != position; copy++, it--) {
							_alloc.construct(&(*it), *copy);
						}
					}

					for (int j = 0; j < n; j++) {
						*it = val;
						it--;
					}
				}
				_size = _size + n;
            }; // fill
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last) {
				pointer temp;
				size_type i = 0;
				iterator it;
				position--;
				size_type newSize = _countIterRangeSize(first, last);
				if (_size + newSize > _capacity) {
					temp = _alloc.allocate((_size + newSize) * CAPACITY_COEFFICIENT);
					it = begin();
					for (; it != position; it++) {
						_alloc.construct(&temp[i], *it);
						i++;
					}
					for (; first != last; first++) {
						_alloc.construct(&temp[i], first);
						i++;
					}
					for (iterator copy = it; copy != end(); copy++) {
						_alloc.construct(&temp[i], *copy);
						i++;
					}
					for (iterator destroy = begin(); destroy != end(); ++destroy) {
						_alloc.destroy(&(*destroy));
					}
					_alloc.deallocate(_vector, _capacity);
					_vector = temp;
					_capacity = _capacity * CAPACITY_COEFFICIENT;
				}
				else {
					it = end() + newSize;
					reverse_iterator copy = rbegin();
					for (; copy != position; copy++, it--) {
						*it = *copy;
					}
					for (; first != last; first++) {
						*it = *first;
						it--;
					}
				}
				_size += newSize;
            }; // range

            iterator erase(iterator position) {

            };

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
