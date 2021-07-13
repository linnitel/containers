#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template <class Category,            // Iterator::iterator_category
        class T,                     // Iterator::value_type
        class Distance = ptrdiff_t,  // Iterator::difference_type
        class Pointer = T*,          // Iterator::pointer
        class Reference = T&         // Iterator::reference
> class Iterator {
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

};

#endif
