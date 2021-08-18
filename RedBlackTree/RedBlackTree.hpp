#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include <memory>
#include "Node.hpp"
#include "utils/utils.hpp"
#include "TreeIterator.hpp"

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
		typedef TreeIterator<value_type> iterator;
		typedef TreeIterator<const value_type> const_iterator;
		typedef reverseIterator<iterator> reverse_iterator;
		typedef reverseIterator<const_iterator> const_reverse_iterator;
		typedef typename iterator_traits<Iterator<RandomAccessIteratorTag, value_type> >::difference_type difference_type;

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

		void _rotateLeft(node *rotateNode) {
			node *rightRotateNode = rotateNode->_right;
            rotateNode->_right = rightRotateNode->_left;
			if (rightRotateNode->_left != _null) {
                rightRotateNode->_left->_parent = rotateNode;
			}
            rightRotateNode->_parent = rotateNode->_parent;
			if (rotateNode->_parent == _null) {
				_tree = rightRotateNode;
			}
			else if (rotateNode == rotateNode->_parent->_left) {
                rotateNode->_parent->_left = rightRotateNode;
			}
			else {
                rotateNode->_parent->_right = rightRotateNode;
			}
            rightRotateNode->_left = rotateNode;
            rotateNode->_parent = rightRotateNode;
		};

		void _rotateRight(node *rotateNode) {
			node *leftRotateNode = rotateNode->_left;
            rotateNode->_left = leftRotateNode->_right;
			if (leftRotateNode->_right != _null) {
                leftRotateNode->_right->_parent = rotateNode;
			}
            leftRotateNode->_parent = rotateNode->_parent;
			if (rotateNode->_parent == _null) {
				_tree = leftRotateNode;
			}
			else if (rotateNode == rotateNode->_parent->_right) {
                rotateNode->_parent->_right = leftRotateNode;
			}
			else {
                rotateNode->_parent->_left = leftRotateNode;
			}
            leftRotateNode->_right = rotateNode;
            rotateNode->_parent = leftRotateNode;
		};

		void _transplant(node *nodeToSubstitute, node *nodeToPaste) {
			if (nodeToSubstitute->_parent == _null) {
				_tree = nodeToPaste;
			}
			else if (nodeToSubstitute == nodeToSubstitute->_parent->_left) {
                nodeToSubstitute->_parent->_left = nodeToPaste;
			}
			else {
                nodeToSubstitute->_parent->_right = nodeToPaste;
			}
            nodeToPaste->_parent = nodeToSubstitute->_parent;
		};

		void _fixDelete(node *deletedChild) {
		    // TODO fix if uncle is _null
			node *uncle;
			while (deletedChild != _tree && deletedChild->_color == black) {
				if (deletedChild == deletedChild->_parent->_left) {
                    uncle = deletedChild->_parent->_right;
					if (uncle->_color == red) {
                        uncle->_color = black;
                        deletedChild->_parent->_color = red;
						_rotateLeft(deletedChild->_parent);
                        uncle = deletedChild->_parent->_right;
					}
					if (uncle->_left->_color == black && uncle->_right->_color == black) {
                        uncle->_color = red;
                        deletedChild = deletedChild->_parent;
					}
					else {
						if (uncle->_right->_color == black) {
                            uncle->_left->_color = black;
                            uncle->_color = red;
							_rotateRight(uncle);
                            uncle = deletedChild->_parent->_right;
						}
                        uncle->_color = deletedChild->_parent->_color;
                        deletedChild->_parent->_color = black;
                        uncle->_right->_color = black;
						_rotateLeft(deletedChild->_parent);
                        deletedChild = _tree;
					}
				}
				else {
                    uncle = deletedChild->_parent->_left;
					if (uncle->_color == red) {
                        uncle->_color = black;
                        deletedChild->_parent->_color = red;
						_rotateRight(deletedChild->_parent);
                        uncle = deletedChild->_parent->_left;
					}
					if (uncle->_right->_color == black && uncle->_left->_color == black) {
                        uncle->_color = red;
                        deletedChild = deletedChild->_parent;
					}
					else {
						if (uncle->_left->_color == black) {
                            uncle->_right->_color = black;
                            uncle->_color = red;
							_rotateLeft(uncle);
                            uncle = deletedChild->_parent->_left;
						}
                        uncle->_color = deletedChild->_parent->_color;
                        deletedChild->_parent->_color = black;
                        uncle->_left->_color = black;
						_rotateRight(deletedChild->_parent);
                        deletedChild = _tree;
					}
				}
                deletedChild->_color = black;
			}
		};
		node *_initNullNode() {
			node *temp = _nodeAlloc.allocate(1);
			temp->_color = black;
			temp->_parent = NULL;
			temp->_right = NULL;
			temp->_left = NULL;
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
		};

		node *_initNode(value_type const&data, node *parent) {
		    node *temp = _nodeAlloc.allocate(1);
		    temp->_color = red;
		    _alloc.construct(&temp->_data, data);
		    temp->_parent = parent;
			temp->_right = _null;
			temp->_left = _null;
            return temp;
		};

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

		RedBlackTree(RedBlackTree const &Tree): _compare(Tree._compare), _alloc(Tree._alloc),
												_nodeAlloc(Tree._nodeAlloc) {
			_null = _initNullNode();
			_tree = _null;
			_size = 0;
			node *temp = Tree.treeMin();
			while (temp != Tree.treeMax()) {
				_tree = addNode(temp);
				temp = temp->nextNode(Tree._null);
			}
			_tree = addNode(temp);
		};

		//Operator overloads -----
		RedBlackTree &operator=(const RedBlackTree &Tree) {
			if (this != &Tree) {
				if (!empty()) {
                    clear();
					_nodeAlloc.deallocate(_null, 1);
				}
				_alloc = Tree._alloc;
				_nodeAlloc = Tree._nodeAlloc;
				_compare = Tree._compare;
			}
			_null = _initNullNode();
			_tree = _null;
			_size = 0;
			node *temp = Tree.treeMin();
			while (temp != Tree.treeMax()) {
				_tree = addNode(temp);
				temp = temp->nextNode(Tree._null);
			}
			_tree = addNode(temp);
            return *this;
		};

		// Destructor -----
		~RedBlackTree() {
		    clear();
		    _nodeAlloc.deallocate(_null, 1);
		};

		// Getters -----
		node *getTree() const {
			return _tree;
		}

		// Protected member functions -----

		node *addNode(node *newNode) {
			node *temp = _tree;
			if (temp == _null) {
				newNode->_parent = temp;
				_size += 1;
				_tree = newNode;
				_tree->_color = black;
				return _tree;
			}
			while (temp != _null) {
				if (_compare(newNode->_data.first, temp->_data.first)) {
					if (temp->_left != _null) {
						temp = temp->_left;
					} else {
						newNode->_parent = temp;
						if (newNode->_parent == _null->_left) {
							_null->_left = newNode;
						}
						temp->_left = newNode;
						break ;
					}
				}
				else if (newNode->_data.first == temp->_data.first) { //compare by key if keys are equal assign data
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
						newNode->_parent = temp;
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

		node *addNode(value_type data) {
			node *newNode = _initNode(data);
			return addNode(newNode);
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

		node *treeMax() const {
            return treeMax(_tree);
		};

		node *treeMax(node *head) const {
			node *temp = head;
			if (temp != _null) {
				while (temp->_right != _null) {
					temp = temp->_right;
				}
			}
			return temp;
		};

		node *treeMin() const {
            return treeMin(_tree);
		};

		node *treeMin(node *head) const {
			node *temp = head;
			if (temp != _null) {
				while (temp->_left != _null) {
					temp = temp->_left;
				}
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

		size_type size() const {
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
                del = tmp->nextNode(_null);
		    }
			deleteNode(del);
		};

		allocator_type getAlloc() const {
			return _alloc;
		};

		node *getNull() const {
			return _null;
		};


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


		friend bool operator==(RedBlackTree<Key, T,Alloc>& lhs, RedBlackTree<Key, T,Alloc>& rhs) {
			return (lhs._size == rhs._size && ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		friend bool operator!=(RedBlackTree<Key, T,Alloc>& lhs, RedBlackTree<Key, T,Alloc>& rhs) {
			return !(lhs == rhs);
		}
    };
}


#endif //REDBLACKTREE_HPP
