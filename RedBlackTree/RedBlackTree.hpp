#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include "Node.hpp"

namespace ft {
    template <class T, class Alloc = std::allocator<T>>
    class RedBlackTree {
	public:
    	typedef Node<T, Alloc> node;
    	typedef RedBlackTree<T, Alloc> tree;
		typedef T value_type;
		typedef T* pointer;
		typedef Alloc allocator_type;

    private:
		node *_null;
        node *_tree;

    public:
		// Constructors -----
		RedBlackTree(): _null(), _tree() {};

		RedBlackTree(RedBlackTree const &Tree): _null(Tree._null), _tree(Tree._tree) {};

		// Destructor -----
		~RedBlackTree();

		// Public member functions -----

		void addNode(value_type data) {};

		void rotateLeft();
		void rotateRight();

    };
}


#endif //REDBLACKTREE_HPP
