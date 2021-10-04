CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
LIB			= ar -rcs

NAME	 	= libgnl.a

INCLUDE		= get_next_line.h

SRC			= get_next_line.c get_next_line_utils.c
OBJ			= $(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
			$(LIB) $(NAME) $(OBJ)

bonus:		$(BONUS_O)
			$(LIB) $(NAME) $(BONUS_O)

.c.o:		$(INCLUDE)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re bonus rebonus run fsan

run:
			$(RM) a.out
			$(CC) $(CFLAGS) *.c && ./a.out

fsan:
			$(RM) a.out
			$(CC) $(CFLAGS) -fsanitize=address *.c && ./a.out

valg:
			$(RM) a.out
			$(CC) $(CFLAGS) -g *.c && --leak-check=full ./a.out
