SRC_DIR		=	src/
SRC_FILES	=	ft_flags_handler.c		\
                ft_print_char.c			\
				ft_printf.c				\
				ft_print_string.c		\
				ft_print_integer.c		\
				ft_print_unsigned.c		\
				ft_print_hexadecimal.c	\
				ft_print_pointer.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_FILES_B	=	ft_flags_handler_bonus.c	\
                ft_print_char_bonus.c		\
				ft_printf_bonus.c			\
				ft_print_string_bonus.c		\
				ft_print_integer_bonus.c	\
				ft_print_unsigned_bonus.c	\
				ft_print_hexadecimal_bonus.c	\
				ft_print_pointer_bonus.c
SRC_B		=	$(addprefix $(SRC_DIR), $(SRC_FILES_B))

UTILS_DIR	=	utils/
UTILS_FILES	=	ft_char_check.c			\
				ft_putchar.c			\
				ft_putnbr.c				\
				ft_putstr.c				\
				ft_strlen.c
UTILS		=	$(addprefix $(UTILS_DIR), $(UTILS_FILES))
UTILS_FILES_B	=	ft_char_check_bonus.c	\
                    ft_putchar_bonus.c		\
					ft_putnbr_bonus.c		\
					ft_putstr_bonus.c		\
					ft_strlen_bonus.c
UTILS_B		=	$(addprefix $(UTILS_DIR), $(UTILS_FILES_B))

OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))	\
                $(addprefix $(OBJ_DIR), $(UTILS_FILES:.c=.o))
OBJ_B		=	$(addprefix $(OBJ_DIR), $(SRC_FILES_B:.c=.o))	\
                $(addprefix $(OBJ_DIR), $(UTILS_FILES_B:.c=.o))

HEADER_DIR	=	includes/
HEADER_FILE	=	ft_printf.h
HEADER_FILE_B	=	ft_printf_bonus.h
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_FILE))
HEADER_B	=	$(addprefix $(HEADER_DIR), $(HEADER_FILE_B))

NAME		=	libftprintf.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

bonus: $(OBJ_B)
	ar -rcs $(NAME) $^

$(NAME): $(OBJ)
	ar -rcs $@ $^

$(OBJ_DIR)%_bonus.o: $(SRC_DIR)%_bonus.c $(HEADER_B) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(HEADER_DIR)

$(OBJ_DIR)%_bonus.o: $(UTILS_DIR)%_bonus.c $(HEADER_B) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(HEADER_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(HEADER_DIR)

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c $(HEADER) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -o $@ -I$(HEADER_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re