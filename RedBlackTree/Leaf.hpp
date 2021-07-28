#ifndef LEAF_HPP
# define LEAF_HPP

#define TREE_RED true
#define TREE_BLACK false

namespace ft {
	template<class T>
	class Leaf {
	public:
		typedef T value_type;
		typedef T *pointer;
	private:
		// Variables -----
		bool _color;
		pointer _data;
		Leaf *left;
		Leaf *right;
		Leaf *parent;
	public:
		Leaf() {};

		Leaf(pointer data) : _color(TREE_BLACK), _data(data) {};

		~Leaf() {};

		pointer getData() const {
			return _data;
		};
		bool getColor() const {

		}
	};
}

#endif //LEAF_HPP
