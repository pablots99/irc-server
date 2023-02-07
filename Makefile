NAME = ircserver

SRCS = 	src/server/server.cpp \
		src/main.cpp \
		src/commands/cmd.cpp \
		src/utils/splitString.cpp \
		src/client/reply.cpp \
		src/client/user.cpp \
		src/commands/userCmd.cpp

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