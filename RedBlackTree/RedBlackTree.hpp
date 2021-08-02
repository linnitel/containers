#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include "Node.hpp"
#include "../utils/utils.hpp"

namespace ft {
    template <class T, class Alloc = std::allocator<T>, class Compare = less<T> >
    class RedBlackTree {
	public:
    	typedef Node<T, Alloc> node;
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
	private:
		// Public member functions -----
		void _balanceTree();
		void _rotateLeft();
		void _rotateRight();
		void _swapColours();
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
			while (temp != _null) {
				if (_compare(data, temp->data)) {
					if (temp->getLeft() != _null) {
						temp = temp->getLeft();
					} else {
						node *newNode = new node(data, _null, _null, temp, red);
						temp->setLeft(newNode);
						_size += 1;
						return newNode;
					}
				} else {
					if (temp->getRight() != _null) {
						temp = temp->getRight();
					} else {
						node *newNode = new node(data, _null, _null, temp, red);
						temp->setRight(newNode);
						_size += 1;
						return newNode;
					}
				}
			}

		};

		node *findNode(value_type data) {};
		value_type const &maxData() {
			return _null->getRight();
		};

		value_type const &minData() {
			_null->getLeft();
		};

		void deleteNode(value_type data) {
			_size -= 1;
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
