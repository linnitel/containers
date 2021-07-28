
#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {

	class InputIteratorTag {
        std::string getTag() {
            return "InputIteratorTag";
        };
	};

	class OutputIteratorTag {
        std::string getTag() {
            return "OutputIteratorTag";
        };
	};

	class ForwardIteratorTag: public InputIteratorTag {
        std::string getTag() {
            return "ForwardIteratorTag";
        };
	};

	class BidirectionalIteratorTag: public ForwardIteratorTag {
        std::string getTag() {
            return "BidirectionalIteratorTag";
        };
	};

	class RandomAccessIteratorTag: public BidirectionalIteratorTag {
        std::string getTag() {
            return "RandomAccessIteratorTag";
        };
	};

	template<class Iter>
	struct iterator_traits {
	public:
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef RandomAccessIteratorTag iterator_category;

	};

	template<class T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef RandomAccessIteratorTag iterator_category;
	};
}

#endif //ITERATOR_TRAITS_HPP
