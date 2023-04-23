NAME = ircserver

SRCS = 	src/server/bbdd.cpp \
		src/server/Server.cpp \
		src/main.cpp \
		src/commands/cmd.cpp \
		src/commands/userCmd.cpp \
		src/commands/pongCmd.cpp \
		src/utils/splitString.cpp \
		src/utils/toUpperCase.cpp \
		src/utils/nicknameCheck.cpp \
		src/utils/generatePingRandomString.cpp \
		src/client/reply.cpp \
		src/client/user.cpp
		
		

OBJ = $(SRCS:.cpp=.o)
CPP = c++
CPP_FLAGS = -g3 -Wall -Wextra -Werror 

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