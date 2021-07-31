#ifndef NODE_HPP
# define NODE_HPP



namespace ft {
	enum Color
	{
		red,
		black
	};
	template<class T, class Alloc = std::allocator<T>>
	class Node {
	public:
		typedef T value_type;
		typedef T* pointer;
		typedef Alloc allocator_type;
		typedef Node<T, Alloc> node;
	private:
		// Variables -----
		Color _color;
		allocator_type _alloc;
		value_type _data;
		node *_left;
		node *_right;
		node *_parent;

		// Private functions ----
		Node(): _color(black), _alloc(), _data(), _left(), _right(), _parent() {};
	public:
		// Constructors ----
		Node(value_type data, node *left, node *right, node *parent, Color color): _color(color),
											_alloc(), _data(data), _left(left), _right(right),
											_parent(parent) {};

		explicit Node(value_type data, node *null): _color(black), _alloc(), _data(data),
											_parent(null), _right(null), _left(null) {};

		// Destructor ----
		~Node() {};

		// Getters ----

		pointer getData() const {
			return _data;
		};

		Color getColor() const {
			return _color;
		};

		node *getLeft() const {
			return _left;
		};

		node *getRight() const {
			return _right;
		};

		node *getParent() const {
			return _parent;
		};

		// Setters ----

		void setColor(Color color) {
			_color = color;
		};

		void setData(const value_type data) {
			_data = data;
		};

		void setLeft(node *left) {
			_left = left;
		};

		void setRight(node *right) {
			_right = right;
		};

		void setParent(node *parent) {
			_parent = parent;
		};
	};
}

#endif //NODE_HPP
