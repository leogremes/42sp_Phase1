SRC			=	ft_atoi.c			ft_bzero.c			ft_calloc.c			\
                ft_isalnum.c		ft_isalpha.c		ft_isascii.c		\
				ft_isdigit.c		ft_isprint.c		ft_itoa.c			\
				ft_memchr.c			ft_memcmp.c			ft_memcpy.c			\
				ft_memmove.c		ft_memset.c			ft_putchar_fd.c		\
				ft_putendl_fd.c		ft_putnbr_fd.c		ft_putstr_fd.c		\
				ft_split.c			ft_strchr.c			ft_strdup.c			\
				ft_striteri.c		ft_strjoin.c		ft_strmapi.c		\
				ft_strlcat.c		ft_strlcpy.c		ft_strlen.c			\
				ft_strnstr.c		ft_strrchr.c		ft_strtrim.c		\
				ft_substr.c			ft_tolower.c		ft_toupper.c		\
				ft_strncmp.c

SRC_B 		=	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c		\
                ft_lstdelone.c		ft_lstiter.c		ft_lstlast.c		\
				ft_lstmap.c			ft_lstnew.c			ft_lstsize.c

OBJ_FOLDER	=	obj/

OBJ			= 	$(addprefix $(OBJ_FOLDER), $(SRC:.c=.o))

OBJ_B		=	$(addprefix $(OBJ_FOLDER), $(SRC_B:.c=.o))

NAME		=	libft.a

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

all: $(NAME)

bonus: $(OBJ) $(OBJ_B)
	@ar -rcs $(NAME) $^
	@echo "libft bonus done"

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $^
	@echo "libft mandatory done"

$(OBJ_FOLDER)%.o: %.c libft.h
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$@ added"

clean:
	@rm -rf $(OBJ_FOLDER)
	@echo "Removing objects"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removing binary"

re:  fclean all

.PHONY: all clean fclean re bonus