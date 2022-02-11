########################################################################
####################### My Makefile ##############################
########################################################################

# Compiler settings
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
 

# Makefile settings
NAME = minitalk
CLIENTSRC = client.c utils.c
SERVERSRC = server.c utils.c
HEADER = minitalk.h
EXT1 = .c
EXT2 = .o

############## The referencing #############

CLIENTOBJ = $(CLIENTSRC:$(EXT1)=$(EXT2))
SERVEROBJ = $(SERVERSRC:$(EXT1)=$(EXT2))


# UNIX-based OS variables & settings

RM = rm -rf

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(NAME)

$(NAME) : client	server

# Builds the app

client : $(CLIENTOBJ) $(HEADER)
			$(CC) $(CFLAGS) -o $@ $(CLIENTOBJ)
			echo "the client app..."

server : $(SERVEROBJ) $(HEADER)
			$(CC) $(CFLAGS) -o $@ $(SERVEROBJ)
			echo "build the server app..."

# Building rule for .o files and its .c

%.o:%.c 
		$(CC) $(CFLAGS) -c $<

################### Cleaning rules for Unix-based OS ###################

clean:
			$(RM) $(SERVEROBJ) $(CLIENTOBJ)

fclean:		clean
			$(RM) client server

re:			fclean all

.PHONY:		all clean fclean re 
