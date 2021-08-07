#ifndef NODE_HPP
# define NODE_HPP



namespace ft {
	enum Color
	{
		red,
		black
	};
	template<class T>
	struct Node {
	public:
		typedef T value_type;
		typedef Node<T> node;

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

		// Operators reload -----
		value_type operator*() const {
			return _data;
		};

		node *nextNode(node *current, node *nullNode) {
			node next;

			if (next._right == nullNode) {
				// node has no right child
				next = current;
				while (next._parent != nullNode && next == next._parent->_right) {
					next = next._parent;
				}
				next = next._parent;
			}
			else {
				// Find the leftmost node in the right subtree
				next = current->_right;
				while (next._left != nullNode) {
					next = next._left;
				}
			}
			return next;
		};

		node *prevNode(node *current, node *nullNode) {
			node prev;

			if (prev._left == nullNode) {
				// node has no right child
				prev = current;
				while (prev._parent != nullNode && prev == prev._parent->_left) {
					prev = prev._parent;
				}
				prev = prev._parent;
			} else {
				// Find the leftmost node in the right subtree
				prev = current->_left;
				while (prev._right != nullNode) {
					prev = prev._right;
				}
			}
			return prev;
		};
	};
}

#endif //NODE_HPP
