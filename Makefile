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

.PHONY: 	all clean fclean re bonus rebonus m fsan

m:
			$(RM) a.out
			$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c main.c && ./a.out
bonus:
			$(RM) a.out
			$(CC) $(CFLAGS) get_next_line_bonus.c get_next_line_utils_bonus.c main.c && ./a.out
fsan:
			$(RM) a.out
			$(CC) $(CFLAGS) -g -fsanitize=address *.c && ./a.out

valg:
			$(RM) a.out
			$(CC) $(CFLAGS) -g *.c && valgrind --leak-check=full \
			--track-origins=yes ./a.out
