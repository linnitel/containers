NAME = containers_tester

NAME_BONUS = container_bonus_tester

CC = clang++

SRCS = main.cpp Vector/VectorTest.cpp \
						Stack/StackTest.cpp \
						Map/MapTest.cpp \
						utils/utils.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Vector/Vector.hpp Stack/Stack.hpp \
						Map/Map.hpp \
						Iterators/Iterators.hpp iterator_traits.hpp \
						RedBlackTree/Node.hpp RedBlackTree/RedBlackTree.hpp \
						utils/utils.hpp

SRCS_BONUS = main_bonus.cpp Set/SetTest.cpp

OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)

HEADERS_BONUS = Set/Set.hpp

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
	@/bin/rm -f $(NAME)

fclean_bonus: clean_bonus
	@echo "cleaning bonus executable"
	@/bin/rm -f $(NAME_BONUS)

re: fclean all
	@echo "recompile"

re_bonus: fclean bonus
	@echo "recompile bonus"

test:
	./$(NAME)

test_bonus:
	./$(NAME_BONUS)

.PHONY: all bonus clean clean_bonus fclean fclean_bonus re re_bonus test test_bonus
