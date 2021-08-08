#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include <memory>
#include "Node.hpp"
#include "../utils/utils.hpp"

namespace ft {
    template <class Key,
            	class T,
				class Alloc = std::allocator<pair<const Key,T> >,
				class Compare = less<Key> >
    class RedBlackTree {
	public:
    	typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
    	typedef Node<value_type> node;
		typedef Alloc allocator_type;
		typedef typename allocator_type::template rebind<Node<pair<const Key,T> > >::other node_allocator;
		typedef Compare key_compare;
		typedef size_t size_type;

	protected:
		// Variables -----
		node *_null; // left node of the null node points to the min node of the tree
					 // and right node to the max value of the tree. // Not implemented
        node *_tree;
        size_type _size;
        key_compare _compare;
		allocator_type _alloc;
		node_allocator _nodeAlloc;
	private:
		// Private member functions -----
		void _fixInsert(node *fixingNode) {
			while (fixingNode != _tree && fixingNode->_parent->_color == red) {
				if (fixingNode->_parent == fixingNode->_parent->_parent->_left) {
					node *y = fixingNode->_parent->_parent->_right;
					if (y->_color == red) {
						fixingNode->_parent->_color = black;
						y->_color = black;
						fixingNode->_parent->_parent->_color = red;
						fixingNode = fixingNode->_parent->_parent;
					}
					else {
						if (fixingNode == fixingNode->_parent->_right) {
							fixingNode = fixingNode->_parent;
							_rotateLeft(fixingNode);
						}
						fixingNode->_parent->_color = black;
						fixingNode->_parent->_parent->_color = red;
						_rotateRight(fixingNode->_parent->_parent);
					}
				}
				else {
					node *y = fixingNode->_parent->_parent->_left;
					if (y->_color == red) {
						fixingNode->_parent->_color = black;
						y->_color = black;
						fixingNode->_parent->_parent->_color = red;
						fixingNode = fixingNode->_parent->_parent;
					}
					else {
						if (fixingNode == fixingNode->_parent->_left) {
							fixingNode = fixingNode->_parent;
							_rotateRight(fixingNode);
						}
						fixingNode->_parent->_color = black;
						fixingNode->_parent->_parent->_color = red;
						_rotateLeft(fixingNode->_parent->_parent);
					}
				}
			}
			_tree->_color = black;
		};

		void _rotateLeft(node *x) {
			node *y = x->_right;
			x->_right = y->_left;
			if (y->_left != _null) {
				y->_left->_parent = x;
			}
			y->_parent = x->_parent;
			if (x->_parent == _null) {
				_tree = y;
			}
			else if (x == x->_parent->_left) {
				x->_parent->_left = y;
			}
			else {
				x->_parent->_right = y;
			}
			y->_left = x;
			x->_parent = y;
		};

		void _rotateRight(node *y) {
			node *x = y->_left;
			y->_left = x->_right;
			if (x->_right != _null) {
				x->_right->_parent = y;
			}
			x->_parent = y->_parent;
			if (y->_parent == _null) {
				_tree = x;
			}
			else if (y == y->_parent->_right) {
				y->_parent->_right = x;
			}
			else {
				y->_parent->_left = x;
			}
			x->_right = y;
			y->_parent = x;
		};

		void _transplant(node *u, node *v) {
			if (u->_parent == _null) {
				_tree = v;
			}
			else if (u == u->_parent->_left) {
				u->_parent->_left = v;
			}
			else {
				u->_parent->_right = v;
			}
			v->_parent = u->_parent;
		};

		void _fixDelete(node *x) {
			node *w;
			while (x != _tree && x->_color == black) {
				if (x == x->_parent->_left) {
					w = x->_parent->_right;
					if (w->_color == red) {
						w->_color = black;
						x->_parent->_color = red;
						_rotateLeft(x->_parent);
						w = x->_parent->_right;
					}
					if (w->_left->_color == black&& w->_right->_color == black) {
						w->_color = red;
						x = x->_parent;
					}
					else {
						if (w->_right->_color == black) {
							w->_left->_color = black;
							w->_color = red;
							_rotateRight(w);
							w = x->_parent->_right;
						}
						w->_color = x->_parent->_color;
						x->_parent->_color = black;
						w->_right->_color = black;
						_rotateLeft(x->_parent);
						x = _tree;
					}
				}
				else {
					w = x->_parent->_left;
					if (w->_color == red) {
						w->_color = black;
						x->_parent->_color = red;
						_rotateRight(x->_parent);
						w = x->_parent->_left;
					}
					if (w->_right->_color == black&& w->_left->_color == black) {
						w->_color = red;
						x = x->_parent;
					}
					else {
						if (w->_left->_color == black) {
							w->_right->_color = black;
							w->_color = red;
							_rotateLeft(w);
							w = x->_parent->_left;
						}
						w->_color = x->_parent->_color;
						x->_parent->_color = black;
						w->_left->_color = black;
						_rotateRight(x->_parent);
						x = _tree;
					}
				}
				x->_color = black;
			}
		}
		node *_initNullNode() {
			node *temp = _nodeAlloc.allocate(1);
			temp->_color = black;
			return temp;
		};

		node *_initNode(value_type const&data) {
		    node *temp = _nodeAlloc.allocate(1);
			temp->_color = red;
			_alloc.construct(&temp->_data, data);
			temp->_parent = _null;
			temp->_right = _null;
			temp->_left = _null;
			return temp;
		}

		node *_initNode(value_type const&data, node *parent) {
		    node *temp = _nodeAlloc.allocate(1);
		    temp->_color = red;
		    _alloc.construct(&temp->_data, data);
		    temp->_parent = parent;
			temp->_right = _null;
			temp->_left = _null;
            return temp;
		}

	public:
		// Constructors -----
		RedBlackTree(): _size(0), _compare(), _alloc(), _nodeAlloc() {
			_null = _initNullNode();
			_tree = _null;
		};

		RedBlackTree(const key_compare& comp = key_compare(),
			   const allocator_type& alloc = allocator_type()): _size(0),
			   								_compare(comp),
			   								_alloc(alloc), _nodeAlloc(node_allocator(alloc)) {
			_null = _initNullNode();
			_tree = _null;
		};

		RedBlackTree(RedBlackTree const &Tree): _null(Tree._null), _tree(Tree._tree), _size(Tree._size),
												_compare(Tree._compare), _alloc(Tree._alloc),
												_nodeAlloc(Tree._nodeAlloc) {};

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
				_nodeAlloc = Tree._nodeAlloc;
				_compare = Tree._compare;
				_size = Tree._size;
			}
            return *this;
		};

		// Destructor -----
		~RedBlackTree() {
		    clear();
		    _nodeAlloc.deallocate(_null, 1);
		};

		// Protected member functions -----

		node *addNode(value_type data) {
			node *temp = _tree;
			node *newNode;
			if (temp == _null) {
				newNode = _initNode(data, temp);
				_size += 1;
				_tree = newNode;
				_tree->_color = black;
				return _tree;
			}
			while (temp != _null) {
				if (_compare(data.first, temp->_data.first)) {
					if (temp->_left != _null) {
						temp = temp->_left;
					} else {
						newNode = _initNode(data, temp);
						if (newNode->_parent == _null->_left) {
						    _null->_left = newNode;
						}
						temp->_left = newNode;
						break ;
					}
				}
				else if (data.first == temp->_data.first) { //compare by key if keys are equal assign data
													// to the item, as there can't be equal nodes in map
//					if (temp->_data != data) {
//						_alloc.destroy(&temp->_data);
//						_alloc.construct(&temp->_data, data);
//					}
					return temp;
				}
				else {
					if (temp->_right != _null) {
						temp = temp->_right;
					} else {
						newNode = _initNode(data, temp);
						if (newNode->_parent == _null->_right) {
						    _null->_right = newNode;
						}
						temp->_right = newNode;
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
				if (_compare(data.first, temp->_data.first)) {
					temp = temp->_left;
				}
				else if (data.first == temp->_data.first) {
					break;
				}
				else {
					temp = temp->_right;
				}
			}
			return temp;
		};

		node *findNode(node *nodeToSearch) {
			return findNode(nodeToSearch->_data);
		};

		node *treeMax() {
//			node *temp = _tree;
//			while (temp->_right != _null) {
//				temp = temp->_right;
//			}
//			return temp;
            return _null->_right;
		};

		node *treeMax(node *head) {
			node *temp = head;
			while (temp->_right != _null) {
				temp = temp->_right;
			}
			return temp;
		};

		node *treeMin() {
//			node *temp = _tree;
//			while (temp->_left != _null) {
//				temp = temp->_left;
//			}
//			return temp;
            return _null->_left;
		};

		node *treeMin(node *head) {
			node *temp = head;
			while (temp->_left != _null) {
				temp = temp->_left;
			}
			return temp;
		};

		node *deleteNode(node *nodeToDel) {
			node *successorNode = nodeToDel;
			node *successorChild;
			if (nodeToDel != _null) {
				Color yOriginalColour = successorNode->_color;
				if (nodeToDel->_left == _null) {
					successorChild = nodeToDel->_right;
					_transplant(nodeToDel, nodeToDel->_right);
				}
				else if (nodeToDel->_right == _null) {
					successorChild = nodeToDel->_left;
					_transplant(nodeToDel, nodeToDel->_left);
				}
				else {
					successorNode = treeMin(nodeToDel->_right);
					yOriginalColour = successorNode->_color;
					successorChild = successorNode->_right;
					if (successorNode->_parent == nodeToDel) {
						successorChild->_parent = successorNode;
					}
					else {
						_transplant(successorNode, successorNode->_right);
						successorNode->_right = nodeToDel->_right;
						successorNode->_right->_parent = successorNode;
					}
					_transplant(nodeToDel, successorNode);
					successorNode->_left = nodeToDel->_left;
					successorNode->_left->_parent = successorNode;
					successorNode->_color = nodeToDel->_color;
				}
				if (yOriginalColour == black) {
					_fixDelete(successorChild);
				}
				_alloc.destroy(&nodeToDel->_data);
				_nodeAlloc.deallocate(nodeToDel, 1);
				_size -= 1;
			}
			return successorNode;
		};

		node *deleteNode(value_type data) {
			node *nodeToDel = findNode(data);
			return deleteNode(nodeToDel);
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
		    node *del = treeMin();
		    while (del != treeMax()) {
		        node *tmp = del;
                deleteNode(del);
                del = tmp->nextNode(nullptr);
		    }
		};

		allocator_type getAlloc() const {
			return _alloc;
		};

		node *getNull() const {
			return _null;
		}

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
