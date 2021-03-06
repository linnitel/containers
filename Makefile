NAME = containers_tester

NAME_BONUS = container_bonus_tester

CC = clang++

SRCS = main.cpp Vector/VectorTest.cpp \
						Stack/StackTest.cpp \
						map/MapTest.cpp \
						Set/SetTest.cpp \
						utils/utils.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Vector/Vector.hpp Vector/VectorIterators.hpp VectorTest.hpp\
						Stack/Stack.hpp StackTest.hpp\
						Map/Map.hpp MapTest.hpp\
						Set/Set.hpp Set/SetTest.hpp \
						Iterators/Iterators.hpp Iterators/iterator_traits.hpp \
						RedBlackTree/Node.hpp RedBlackTree/RedBlackTree.hpp \
						utils/utils.hpp

SRCS_BONUS = main_bonus.cpp Set/SetTest.cpp

OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)

HEADERS_BONUS = Set/Set.hpp Set/SetTest.hpp

FLAGS = -Wall -Wextra -std=c++98

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@echo "compile"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

%.o: %.cpp $(HEADERS_BONUS)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "compile"
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	@echo "cleaning .o files"
	/bin/rm -rf $(OBJS)

clean_bonus:
	@echo "cleaning bonus .o files"
	/bin/rm -rf $(OBJS_BONUS)

fclean: clean
	@echo "cleaning executable"
	@rm ft_vector std_vector ft_map std_map ft_stack std_stack
	@/bin/rm -f $(NAME)

fclean_bonus: clean_bonus
	@echo "cleaning bonus executable"
	@rm  ft_set std_set
	@/bin/rm -f $(NAME_BONUS)

re: fclean all
	@echo "recompile"

re_bonus: fclean bonus
	@echo "recompile bonus"

test:
#    @rm ft_vector std_vector ft_map std_map ft_stack std_stack
	./$(NAME)

test_bonus:
#    @rm  ft_set std_set
	./$(NAME_BONUS)

.PHONY: all bonus clean clean_bonus fclean fclean_bonus re re_bonus test test_bonus
