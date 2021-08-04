#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include "Node.hpp"
#include "../utils/utils.hpp"

namespace ft {
    template <class T, class Alloc = std::allocator<T>, class Compare = less<T> >
    class RedBlackTree {
	public:
    	typedef Node<T> node;
    	typedef RedBlackTree<T, Alloc> tree;
		typedef T value_type;
		typedef T* pointer;
		typedef Alloc allocator_type;
		typedef Compare data_compare;
		typedef size_t size_type;

	protected:
		// Variables -----
		node *_null; // left node of the null node points to the min node of the tree
					 // and right node to the max value of the tree.
        node *_tree;
        size_type _size;
        data_compare _compare;
        allocator_type _alloc;
	private:
		// Public member functions -----
		void _fixInsert(node *fixingNode) {
			while (fixingNode != _tree && fixingNode->getParent()->getColor() == red) {
				if (fixingNode->getParent() == fixingNode->getParent()->getParent()->getLeft()) {
					node *y = fixingNode->getParent()->getParent()->getRight();
					if (y->getColor() == red) {
						fixingNode->getParent()->setColor(black);
						y->setColor(black);
						fixingNode->getParent()->getParent()->setColor(red);
						fixingNode = fixingNode->getParent()->getParent();
					}
					else {
						if (fixingNode == fixingNode->getParent()->getRight()) {
							fixingNode = fixingNode->getParent();
							_rotateLeft(fixingNode);
						}
						fixingNode->getParent()->setColor(black);
						fixingNode->getParent()->getParent()->setColor(red);
						_rotateRight(fixingNode->getParent()->getParent());
					}
				}
				else {
					node *y = fixingNode->getParent()->getParent()->getLeft();
					if (y->getColor() == red) {
						fixingNode->getParent()->setColor(black);
						y->setColor(black);
						fixingNode->getParent()->getParent()->setColor(red);
						fixingNode = fixingNode->getParent()->getParent();
					}
					else {
						if (fixingNode == fixingNode->getParent()->getLeft()) {
							fixingNode = fixingNode->getParent();
							_rotateRight(fixingNode);
						}
						fixingNode->getParent()->setColor(black);
						fixingNode->getParent()->getParent()->setColor(red);
						_rotateLeft(fixingNode->getParent()->getParent());
					}
				}
			}
			_tree->setColor(black);
		};

		void _rotateLeft(node *x) {
			node *y = x->getRight();
			x->setRight(y->getLeft());
			if (y->getLeft() != _null) {
				y->getLeft()->setParent(x);
			}
			y->setParent(x->getParent());
			if (x->getParent() == _null) {
				_tree->setParent(y);
			}
			else if (x == x->getParent()->getLeft()) {
				x->getParent()->setLeft(y);
			}
			else {
				x->getParent()->setRight(y);
			}
			y->setLeft(x);
			x->setParent(y);
		};

		void _rotateRight(node *y) {
			node *x = y->getLeft();
			y->setLeft(x->getRight());
			if (x->getRight() != _null) {
				x->getRight()->setParent(y);
			}
			x->setParent(y->getParent());
			if (y->getParent() == _null) {
				_tree->setParent(x);
			}
			else if (y == y->getParent()->getRight()) {
				y->getParent()->setRight(x);
			}
			else {
				y->getParent()->setLeft(x);
			}
			x->setRight(y);
			y->setParent(x);
		};

		void _transplant(node *u, node *v) {
			if (u->getParent() == _null) {
				_tree = v;
			}
			else if (u == u->getParent()->getLeft()) {
				u->getParent()->setLeft(v);
			}
			else {
				u->getParent()->setRight(v);
			}
			v->setParent(u->getParent());
		};

		void _fixDelete(node *x) {
			node *w;
			while (x != _tree && x->getColor() == black) {
				if (x == x->getParent()->getLeft()) {
					w = x->getParent()->getRight();
					if (w->getColor() == red) {
						w->setColor(black);
						x->getParent()->setColor(red);
						_rotateLeft(x->getParent());
						w = x->getParent()->getRight();
					}
					if (w->getLeft()->getColor() == black && w->getRight()->getColor() == black) {
						w->setColor(red);
						x = x->getParent();
					}
					else {
						if (w->getRight()->getColor() == black) {
							w->getLeft()->setColor(black);
							w->setColor(red);
							_rotateRight(w);
							w = x->getParent()->getRight();
						}
						w->setColor(x->getParent()->getColor());
						x->getParent()->setColor(black);
						w->getRight()->setColor(black);
						_rotateLeft(x->getParent());
						x = _tree;
					}
				}
				else {
					w = x->getParent()->getLeft();
					if (w->getColor() == red) {
						w->setColor(black);
						x->getParent()->setColor(red);
						_rotateRight(x->getParent());
						w = x->getParent()->getLeft();
					}
					if (w->getRight()->getColor() == black && w->getLeft()->getColor() == black) {
						w->setColor(red);
						x = x->getParent();
					}
					else {
						if (w->getLeft()->getColor() == black) {
							w->getRight()->setColor(black);
							w->setColor(red);
							_rotateLeft(w);
							w = x->getParent()->getLeft();
						}
						w->setColor(x->getParent()->getColor());
						x->getParent()->setColor(black);
						w->getLeft()->setColor(black);
						_rotateRight(x->getParent());
						x = _tree;
					}
				}
				x->setColor(black);
			}
		}

	protected:
		// Constructors -----
		RedBlackTree(): _null(), _tree(), _size(0), _compare() {};
		RedBlackTree(const data_compare& comp = data_compare()): _null(), _tree(), _size(0), _compare(comp) {};

		RedBlackTree(RedBlackTree const &Tree): _null(Tree._null), _tree(Tree._tree), _size(Tree._size) {};

		// Destructor -----
		~RedBlackTree() {};

		// Protected member functions -----

		node *addNode(value_type data) {
			node *temp = _tree;
			node *newNode;
			while (temp != _null) {
				if (_compare(data, temp->getData())) {
					if (temp->getLeft() != _null) {
						temp = temp->getLeft();
					} else {
						newNode = new node(data, _null, _null, temp, red);
						temp->setLeft(newNode);
						break ;
					}
				}
				else if (data == temp->getData()) { //compare by key if keys are equal assign data
													// to the item, as there can't be equal nodes in map
					temp->setData(data);
					_size += 1;
					return temp;
				}
				else {
					if (temp->getRight() != _null) {
						temp = temp->getRight();
					} else {
						newNode = new node(data, _null, _null, temp, red);
						temp->setRight(newNode);
						break ;
					}
				}
			}
			_size += 1;
			_fixInsert(newNode);
			return newNode;
		};

		node *findNode(value_type data) {
			node *temp = _tree;
			while (temp != _null) {
				if (_compare(data, temp->getData())) {
					temp = temp->getLeft();
				}
				else if (data == temp->getData()) {
					break;
				}
				else {
					temp = temp->getRight();
				}
			}
			return temp;
		};

		value_type const &maxData() {
			return _null->getRight();
		};

		value_type const &minData() {
			_null->getLeft();
		};

		node *deleteNode(value_type data) {
			node *delitingNode = findNode(data);
			if (delitingNode != _null) {
				node *successorNode = delitingNode;
				node *successorChild;
				Color yOriginalColour = successorNode->getColor();
				if (delitingNode->getLeft() == _null) {
					successorChild = delitingNode->getRight();
					_transplant(delitingNode, delitingNode->getRight());
				}
				else if (delitingNode->getRight() == _null) {
					successorChild = delitingNode->getLeft();
					_transplant(delitingNode, delitingNode->getLeft());
				}
				else {
					successorNode = _treeMin(delitingNode->getRight()); // TODO Implement function
					yOriginalColour = successorNode->getColor();
					successorChild = successorNode->getRight();
					if (successorNode->getParent() == delitingNode) {
						successorChild->setParent(successorNode);
					}
					else {
						_transplant(successorNode, successorNode->getRight());
						successorNode->setRight(delitingNode->getRight());
						successorNode->getRight()->setParent(successorNode);
					}
					_transplant(delitingNode, successorNode);
					successorNode->setLeft(delitingNode->getLeft());
					successorNode->getLeft()->setParent(successorNode);
					successorNode->setColor(delitingNode->getColor());
				}
				if (yOriginalColour == black) {
					_fixDelete(successorChild);
				}
				_size -= 1;
			}
		};

		size_type size() {
			return _size;
		};

		node *nextNode(node *current) {
			node next;

			if (next.getRight() == _null) {
				// node has no right child
				next = current;
				while (next.parent != _null && next == next.parent.right) {
					next = next.parent;
				}
				next = next.parent;
			} else {
				// Find the leftmost node in the right subtree
				next = current->getRight();
				while (next.left != _null) {
					next = next.left;
				}
			}
			return next;
		};

		node *prevNode(node *current) {
			node prev;

			if (prev.getLeft() == _null) {
				// node has no right child
				prev = current;
				while (prev.getParent() != _null && prev == prev.getParent()->getLeft()) {
					prev = prev.getParent();
				}
				prev = prev.getParent();
			} else {
				// Find the leftmost node in the right subtree
				prev = _tree->getLeft();
				while (prev.getRight() != _null) {
					prev = prev.getRight();
				}
			}
			return prev;
		};
    };
}


#endif //REDBLACKTREE_HPP
