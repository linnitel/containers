#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {

	template <class T, class Allocator = std::allocator<T>>
	class Vector {
		private:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename fd::random_access_iterator<iterator> iterator;
			typedef typename fd::random_access_iterator<const_iterator> const_iterator;
			typedef typename fd::reverse_iterator<iterator> reverse_iterator;
			typedef typename fd::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename fd::iterator_traits<iterator>::difference_type difference_type
			//difference_type
			typedef typename size_t size_type;
			T *_vector;
			long _capacity;
			long _size;

		public:
			Vector();
			~Vector();

			Vector<T> &operator=(Vector<T> &vector);
			T &operator[](Vector<T> &vector);

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
	};
}

#endif
