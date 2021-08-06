#ifndef NODE_HPP
# define NODE_HPP



namespace ft {
	enum Color
	{
		red,
		black
	};
	template<class T>
	class Node {
	public:
		typedef T value_type;
		typedef Node<T> node;
	private:
		// Variables -----
		Color _color;
		value_type _data;
		node *_left;
		node *_right;
		node *_parent;

		// Private functions ----
		Node(): _color(black), _data(NULL), _left(NULL), _right(NULL), _parent(NULL) {};
	public:
		// Constructors ----
		Node(value_type data, node *left, node *right, node *parent, Color color): _color(color),
											_data(data), _left(left), _right(right),
											_parent(parent) {};

		explicit Node(value_type data, node *null): _color(black), _data(data),
											_parent(null), _right(null), _left(null) {};

		// Destructor ----
		~Node() {};

		// Getters ----

		value_type getData() const {
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

		// Operators reload -----
		value_type operator*() const {
			return _data;
		};

		node *nextNode(node *current, node *nullNode) {
			node next;

			if (next.getRight() == nullNode) {
				// node has no right child
				next = current;
				while (next.parent != nullNode && next == next.parent.right) {
					next = next.parent;
				}
				next = next.parent;
			}
			else {
				// Find the leftmost node in the right subtree
				next = current->getRight();
				while (next.left != nullNode) {
					next = next.left;
				}
			}
			return next;
		};

		node *prevNode(node *current, node *nullNode) {
			node prev;

			if (prev.getLeft() == nullNode) {
				// node has no right child
				prev = current;
				while (prev.getParent() != nullNode && prev == prev.getParent()->getLeft()) {
					prev = prev.getParent();
				}
				prev = prev.getParent();
			} else {
				// Find the leftmost node in the right subtree
				prev = current->getLeft();
				while (prev.getRight() != nullNode) {
					prev = prev.getRight();
				}
			}
			return prev;
		};
	};
}

#endif //NODE_HPP
