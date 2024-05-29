NAME        := minishell
CC        := clang
CFLAGS    := -Wall -Wextra -Werror -g3
LIBS = -lreadline
SRCS        :=   libft/ft_lst.c \
					libft/ft_substr.c \
					libft/ft_str.c \
					libft/ft_utils.c \
					libft/ft_strcmp.c \
					libft/ft_split.c \
					libft/ft_putstr_fd.c \
					libft/ft_memcpy.c \
					libft/ft_itoa.c \
					srcs/parsing/tokenization/tokens.c \
					srcs/parsing/parse/parse.c \
					srcs/parsing/parse/parser.c \
					srcs/parsing/tokenization/pipes_spaces.c \
					srcs/parsing/tokenization/quotes.c \
					srcs/parsing/tokenization/tokenizer.c \
					srcs/exec/simple_command_exec.c \
					srcs/exec/get_env_path.c \
					utils/perror.c \
					utils/ft_free.c \
					utils/convert_to_execve_args.c \
					utils/count_args.c \
					srcs/builtins/ft_echo.c \
					srcs/builtins/ft_pwd.c \
					srcs/parsing/environment/environment.c \
					srcs/parsing/environment/free.c \
					srcs/exec/env_utils.c \
					# parsing/tokenization/operators.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} $(LIBS)
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
