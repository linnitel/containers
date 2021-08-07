#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include <memory>
#include "Node.hpp"
#include "../utils/utils.hpp"

namespace ft {
    template <class Key,
            	class T,
				class Alloc = std::allocator<pair<const Key,T> >,
				class Compare = less<Key>,
				class ValueCompare = less<pair<const Key,T> > >
    class RedBlackTree {
	public:
    	typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
    	typedef Node<value_type> node;
    	typedef RedBlackTree<Key, T, Alloc, Compare> tree;
		typedef Alloc allocator_type;
		typedef typename Alloc::template rebind<node>::other node_allocator;
		typedef Compare key_compare;
		typedef ValueCompare value_compare;
		typedef size_t size_type;

	protected:
		// Variables -----
		node *_null; // left node of the null node points to the min node of the tree
					 // and right node to the max value of the tree. // Not implemented
        node *_tree;
        size_type _size;
        value_compare _compare;
        node_allocator _alloc;
	private:
		// Private member functions -----
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
		node *_initNullNode() {
			node *temp = _alloc.allocate(1);
			temp->setColour(black);
			temp->setData(NULL);
			temp->setParent(NULL);
			temp->setRight(NULL);
			temp->setLeft(NULL);
			return temp;
		};

		node *_initNode(value_type const&data) {
		    node *temp = _alloc.allocate(1);
			temp->setColor(red);
			_alloc.construct(&temp, data);
			temp->setParent(_null);
			temp->setRight(_null);
			temp->setLeft(_null);
			return temp;
		}

		node *_initNode(value_type const&data, node *parent) {
		    node *temp = _alloc.allocate(1);
		    temp->setColor(red);
		    _alloc.construct(&temp, data);
		    temp->setParent(parent);
		    temp->setRight(_null);
		    temp->setLeft(_null);
            return temp;
		}

	public:
		// Constructors -----
		RedBlackTree(): _size(0), _compare(), _alloc() {
			_null = _initNullNode();
			_tree = _null;
		};

		RedBlackTree(const key_compare& comp = key_compare(),
			   const allocator_type& alloc = allocator_type()): _size(0),
			   								_compare(value_compare(comp)), _alloc(alloc) {
			_null = _initNullNode();
			_tree = _null;
		};

		RedBlackTree(RedBlackTree const &Tree): _null(Tree._null), _tree(Tree._tree), _size(Tree._size),
												_compare(Tree._compare), _alloc(Tree._alloc) {};

		//Operator overloads -----
		RedBlackTree &operator=(const RedBlackTree &Tree) {
			if (this != &Tree) {
				if (!empty()) {
                    clear();
					_alloc.deallocate(_null);
				}
				_tree = Tree._tree;
				_null = Tree._null;
				_alloc = Tree._alloc;
				_compare = Tree._compare;
				_size = Tree._size;
			}
            return *this;
		};

		// Destructor -----
		~RedBlackTree() {
		    clear();
		    _alloc.deallocate(_null);
		};

		// Protected member functions -----

		node *addNode(value_type data) {
			node *temp = _tree;
			node *newNode;
			while (temp != _null) {
				if (_compare(data, temp->getData())) {
					if (temp->getLeft() != _null) {
						temp = temp->getLeft();
					} else {
						newNode = _initNode(data, temp);
						if (newNode->getParent() == _null->getLeft()) {
						    _null->setLeft(newNode);
						}
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
						newNode = _initNode(data, temp);
						if (newNode->getParent() == _null->getLeft()) {
						    _null->setRight(newNode);
						}
						temp->setRight(newNode);
						break ;
					}
				}
			}
			_size += 1;
			_fixInsert(newNode);
			return newNode;
		};

		node *findNode(value_type const &data) {
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

		node *findNode(node *nodeToSearch) {
			return findNode(nodeToSearch->getData());
		};

		node *treeMax() {
//			node *temp = _tree;
//			while (temp->getRight() != _null) {
//				temp = temp->getRight();
//			}
//			return temp;
            return _null->getRight();
		};

		node *treeMin() {
//			node *temp = _tree;
//			while (temp->getLeft() != _null) {
//				temp = temp->getLeft();
//			}
//			return temp;
            return _null->getLeft();
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
					successorNode = treeMin(delitingNode->getRight());
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
				_alloc.destroy(&delitingNode);
				_alloc.deallocate(delitingNode, 1);
				_size -= 1;
			}
		};

		size_type size() {
			return _size;
		};

		size_type max_size() {
            return _alloc.max_size();
		};

		bool empty() {
            return (_tree == _null);
		};

		void clear() {
		    node *tmp = _tree;
		    while (_tree != _null) {
		        deleteNode(tmp);
		    }
		};

		allocator_type getAlloc() const {
			return _alloc;
		};

		/*
		// Iterators -----
		iterator begin() {
			return treeMin();
		};
		const_iterator begin() const {
			return treeMin();
		};

		iterator end() {
			return _null;
		};

		const_iterator end() const {
			return _null;
		};

		reverse_iterator rbegin() {
			return treeMax();
		};

		const_reverse_iterator rbegin() const {
			return treeMax();
		};

		reverse_iterator rend() {
			return treeMin();
		};
		const_reverse_iterator rend() const {
			return treeMin();
		};
		 */
    };
}


#endif //REDBLACKTREE_HPP
