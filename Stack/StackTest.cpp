//
// Created by Tothmure Isabel on 7/28/21.
//

#include "StackTest.hpp"

void testStack() {
	printColourText("----- THIS IS STACK CONTAINER TEST -----", YELLOW, true);
	std::deque<int> deque = std::deque<int>(3, 1);
	std::stack<int> std_stack = std::stack<int>(deque);
	ft::stack<int, std::deque<int> > ft_stack = ft::stack<int, std::deque<int> >(deque);
	std::cout << ft_stack.size() << std::endl;
	std::cout << std_stack.size() << std::endl;
	std::cout << ft_stack.top() << std::endl;
	std::cout << std_stack.top() << std::endl;
	for (int i = 0; i < 12; i++) {
		ft_stack.push(i);
		std_stack.push(i);
	}
	std::cout << ft_stack.size() << std::endl;
	std::cout << std_stack.size() << std::endl;
	std::cout << ft_stack.top() << std::endl;
	std::cout << std_stack.top() << std::endl;
	for (int i = 0; i < 7; i++) {
		ft_stack.pop();
		std_stack.pop();
	}
	std::cout << ft_stack.size() << std::endl;
	std::cout << std_stack.size() << std::endl;
	std::cout << ft_stack.top() << std::endl;
	std::cout << std_stack.top() << std::endl;
	std::cout << ft_stack.empty() << std::endl;
	std::cout << std_stack.empty() << std::endl;
}
