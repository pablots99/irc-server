NAME = ircserver

SRCS = 	src/server/bbdd.cpp \
		src/server/server.cpp \
		src/main.cpp \
		src/commands/cmd.cpp \
		src/commands/userCmd.cpp \
		src/commands/nickCmd.cpp \
		src/commands/pongCmd.cpp \
		src/utils/splitString.cpp \
		src/utils/generatePingRandomString.cpp \
		src/client/reply.cpp \
		src/client/user.cpp \
		
		

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