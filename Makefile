NAME = ircserver

SRCS = src/server/Server.cpp src/main.cpp

OBJ = $(SRCS:.cpp=.o)
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror --std=c++98

all: $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all