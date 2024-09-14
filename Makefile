
NAME = rubik
DEBUG = debug
RANDOM = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
# CXXFLAGS += -std=c++98
# CXXFLAGS += -g -fsanitize=address
DEBUGFLAG = -g -fsanitize=address


FILES = Cp Co Eo E_Com Ep Ep_Ud Ep_E PruningTable Search
SRC = $(FILES:=.cpp)
HEADER = $(FILES:=.hpp)
SRC += main.cpp
HEADER += rubic.hpp

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

$(RANDOM):
	$(CXX) random.cpp

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(DEBUG) $(RANDOM)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test1:
	@./$(NAME) "L D2 R U2 L F2 U2 L F2 R2 B2 R U' R' U2 F2 R' D B' F2"

test: $(NAME) $(RANDOM)
	@sh run.sh

leak: $(NAME)
	$(LEAK) ./$(NAME)

.PHONY: all clean fclean re leak bonus test