NAME = containers_tester

CC = clang++

SRCS = main.cpp Vector/VectorTest.cpp \
						Stack/StackTest.cpp \
						Map/MapTest.cpp \

OBJS = $(SRCS:.cpp=.o)

HEADERS = Vector/Vector.hpp Stack/Stack.cpp \
						Map/Map.cpp \
						Iterators/Iterators.hpp iterator_traits.hpp \
						RedBlackTree/Leaf.hpp RedBlackTree/RedBlackTree.hpp \

SRCS_BONUS = main_bonus.cpp Set/SetTest.cpp \

OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)

HEADERS_BONUS =

FLAGS = -Wall -Wextra -std=c++98

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@echo "compile"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "cleaning .o files"
	/bin/rm -rf $(OBJS)

fclean: clean
	@echo "cleaning executable"
	@/bin/rm -f $(NAME)

re: fclean all
	@echo "recompile"
