# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2022/07/20 19:10:22 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS		= 	main.c \
				utils/init.c \
				utils/string_utils.c \
				env/prompt.c \
				env/signal.c \
				exit_free/exit.c \
				exit_free/free.c \
				history/file.c \
				parsing/detect.c \
				parsing/detect2.c \
				parsing/detect3.c \
				parsing/detect4.c \
				parsing/detect5.c \
				parsing/detect_cmd.c \
				parsing/is.c \
				parsing/is_redirection.c \
				parsing/is_quote.c \
				parsing/parsing.c \
				parsing/casting.c \
				verbose/verbose.c \
				tokenization/init_token.c \
				tokenization/tokenizer.c \
				tokenization/chained.c \
				tokenization/create.c \
				tokenization/is_token.c \
				redirection/redirect.c \
				boolean/boolean.c \
				boolean/is_boolean.c \
				
				 



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 		= -Wall -Werror -Wextra
FLAGS			= -g3 -lreadline
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak

%.o : %.c
			$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(OBJS) $(FLAGS) libft/libft.a -o $(NAME)		

all : 			$(NAME)

clean :
				make clean -C libft
				/bin/rm -rf $(OBJS)

fclean : clean
				make fclean -C libft
				/bin/rm -rf $(NAME)

debug : 		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)
				gdb $(NAME)
				
sanitize :		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)

leak :			$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(LEAKS) libft/libft.a  -o $(NAME)


re : fclean all
.PHONY			: all clean fclean re leak sanitize