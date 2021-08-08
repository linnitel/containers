#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include "VectorIterators.hpp"
# include "../utils/utils.hpp"

#define CAPACITY_COEFFICIENT 2

namespace ft {

	template <class T>
	void swap(T& x, T& y) {
		T temp = x;
		x = y;
		y = temp;
	}

	template <class T, class Alloc = std::allocator<T> >
	class vector {
	public:
			// Typedefs -----
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef std::size_t size_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef VectorIterator<value_type> iterator;
			typedef ConstVectorIterator<const value_type> const_iterator;
			typedef reverseIterator<iterator> reverse_iterator;
			typedef ft::reverseIterator<const_iterator> const_reverse_iterator;
			typedef iterator_traits<Iterator<RandomAccessIteratorTag, value_type> > difference_type;

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

			size_type _countPosition(iterator position) {
				for (size_type i = 0; i < _size; i++) {
					if (_vector[i] == *position) {
						return i;
					}
				}
				// throw exception??
				return -1;
			};
	public:
            // Constructors -----
        		// default
        // Constructs an empty container, with no elements.
        explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(0), _alloc(alloc) {
			_vector = _alloc.allocate(_capacity);
        };

				// fill
		// Constructs a container with n elements. Each element is a copy of val.
        explicit vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _alloc(alloc) {
			_vector = _alloc.allocate(n);
			_constructNSize(n, val);
        };

				// range
		// Constructs a container with as many elements as the range [first,last),
		// with each element constructed from its corresponding element in that range,
		// in the same order.
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type()): _alloc(alloc) {
			_size = _countIterRangeSize(first, last);
			_capacity = _size;
			_vector = _alloc.allocate(_capacity);
			_allocIterRange(first, last);
        };

				// copy
		// Constructs a container with a copy of each of the elements in x, in the same order.
        vector (const vector& x): _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
			*this = x;
        };

            // Destructor -----
			~vector() {
			    for (size_type i = 0; i < _size; ++i) {
			        _alloc.destroy(&_vector[i]);
			    }
			    _alloc.deallocate(_vector, _capacity);
			};

            // Operators reload -----
			vector &operator= (const vector &x) {
				if (!empty()) {
					clear();
				}
				if (_capacity != 0) {
					_alloc.deallocate(_vector, _capacity);
				}
				_vector = x._vector;
				_size = x._size;
				_capacity = x._capacity;
				_alloc = x._alloc;
				return *this;
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
				return iterator(_vector + _size);
            };
            const_iterator end() const {
				return const_iterator(_vector + _size);
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
				return _alloc.max_size();
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
					throw std::out_of_range("vector");
            	}
				return _vector[n];
            };
            const_reference at(size_type n) const {
				if (n > _size) {
                    throw std::out_of_range("vector");
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

            // range
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
            };

            // fill
            void assign(size_type n, const value_type& val) {
            	clear();
            	if (n > _capacity) {
					_alloc.deallocate(_vector, _capacity);
					_size = n;
					_capacity = _size;
					_vector = _alloc.allocate(_capacity);
            	}
            	_constructNSize(n, val);
            };

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

            // single element
            iterator insert(iterator position, const value_type& val) {
                insert(position, 1, val);
                return position;
            };

            // fill
            void insert(iterator position, size_type n, const value_type& val) {
				size_type positionIndex = _countPosition(position);
				if (_size + n > _capacity) {
					size_type i = 0;
					pointer temp = _alloc.allocate(_size + n);
					for (; i < positionIndex + n; i++) {
						if (i < positionIndex) {
							_alloc.construct(&temp[i], _vector[i]);
						}
						else {
							_alloc.construct(&temp[i], val);
						}
					}
					for (size_type j = positionIndex; j < _size; i++, j++) {
						_alloc.construct(&temp[i], _vector[j]);
					}
					for (iterator it = begin(); it != end(); ++it) {
						_alloc.destroy(&(*it));
					}
					_alloc.deallocate(_vector, _capacity);
					_vector = temp;
					_capacity = _size + n;
				}
				else {
					for (size_type j = _size + n; j > positionIndex; j--) {
						if (j > positionIndex + n) {
							_alloc.construct(&_vector[j], _vector[j - 1]);
						}
						else {
							_alloc.construct(&_vector[j], val);
						}
						if (j < _size) {
							_alloc.destroy(&_vector[j - 1]);
						}
					}
				}
                _size += n;
            };

            // range
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last) {
				size_type n = _countIterRangeSize(first, last);
				size_type positionIndex = _countPosition(position);
				if (_size + n > _capacity) {
					size_type i = 0;
					pointer temp = _alloc.allocate(_size + n);
					for (; i < positionIndex; i++) {
							_alloc.construct(&temp[i], _vector[i]);
					}
					for (; i < positionIndex + n; i++, first++) {
							_alloc.construct(&temp[i], first);
					}
					for (size_type j = positionIndex; j < _size; i++, j++) {
						_alloc.construct(&temp[i], _vector[j]);
					}
					for (iterator it = begin(); it != end(); ++it) {
						_alloc.destroy(&(*it));
					}
					_alloc.deallocate(_vector, _capacity);
					_vector = temp;
					_capacity = _size + n;
				}
				else {
					for (size_type j = _size + n; j > positionIndex; j--) {
						if (j > positionIndex + n) {
							_alloc.construct(&_vector[j], _vector[j - 1]);
						}
						else {
							_alloc.construct(&_vector[j], last);
							last--;
						}
						if (j < _size) {
							_alloc.destroy(&_vector[j - 1]);
						}
					}
				}
				_size += n;
            };

            iterator erase(iterator position) {
            	size_type positionIndex;
            	if (position + 1 != end()) {
					positionIndex = _countPosition(position);
					for(size_type i = positionIndex; i < _size - 1; i++) {
						_alloc.destroy(&_vector[i]);
						_alloc.construct(&_vector[i], _vector[i + 1]);
					}
            	}
				_alloc.destroy(&_vector[_size]);
            	_size -= 1;
				return position;
            };

            iterator erase(iterator first, iterator last) {
				size_type positionIndex;
				size_type n = _countIterRangeSize(first, last);
				if (first + 1 != end()) {
					positionIndex = _countPosition(first);
					for(size_type i = positionIndex; i < n; i++) {
						_alloc.destroy(&_vector[i]);
					}
					for(size_type i = positionIndex; i < _size - n; i++) {
						_alloc.construct(&_vector[i], _vector[i + n]);
						_alloc.destroy(&_vector[i + n]);
					}
				}
				_alloc.destroy(&_vector[_size]);
				_size -= n;
				return _vector[positionIndex];
            };

            void swap(vector& x) {
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
            allocator_type get_allocator() const {
				return _alloc;
            };
	};

    template <class Alloc> // bool specialization
    class vector<bool, Alloc> {
    };

    template <class T, class Alloc>
    bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs._size == rhs._size && equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class T, class Alloc>
    bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs._vector == rhs._vector);
    }
    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>
    bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
    }
}

#endif
