
NAME = rubic
DEBUG = debug

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUGFLAG = -g -fsanitize=address

FILES = Status
SRC = $(FILES:=.cpp)
HEADER = $(FILES:=.hpp)
SRC += main.cpp move.cpp
HEADER += rubic.hpp

TEMPLATEFILEW = 
TEMPLATE = $(TEMPLATEFILEW:=.tpp)
HEADER += $(TEMPLATEFILEW:=.hpp)
TEMPLATE +=

OBJDIR = objs
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

RM = rm -rf
LEAK = valgrind --tool=memcheck

$(NAME): $(OBJ) $(HEADER) $(TEMPLATE)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

all: $(NAME)

$(DEBUG): $(OBJ) $(HEADER) $(TEMPLATE)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAG) $(OBJ) -o $@

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(DEBUG)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test:
	@./$(NAME) "L D2 R U2 L F2 U2 L F2 R2 B2 R U' R' U2 F2 R' D B' F2"

leak: $(NAME)
	$(LEAK) ./$(NAME)

.PHONY: all clean fclean re leak bonus