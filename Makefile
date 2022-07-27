# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2022/07/27 17:35:20 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS		= 	main.c \
				utils/init.c \
				utils/string_utils.c \
				env/prompt.c \
				env/signal.c \
				env/env.c \
				exit_free/exit.c \
				exit_free/free.c \
				exit_free/remove_arg.c \
				exit_free/remove_token.c \
				exit_free/remove.c \
				history/file.c \
				parsing/detect.c \
				parsing/detect2.c \
				parsing/detect3.c \
				parsing/detect4.c \
				parsing/detect5.c \
				parsing/detect_cmd.c \
				detection/extraction.c \
				detection/quote_extraction.c \
				detection/classification.c \
				is/is.c \
				is/is_redirection.c \
				is/is_quote.c \
				is/is_file.c \
				parsing/parsing.c \
				parsing/casting.c \
				verbose/verbose.c \
				tokenization/init_token.c \
				tokenization/tokenizer.c \
				tokenization/chained.c \
				tokenization/create.c \
				tokenization/is_token.c \
				tokenization/is_arg.c \
				tokenization/token.c \
				tokenization/get.c \
				tokenization/tokenization.c \
				redirection/redirect.c \
				boolean/boolean.c \
				boolean/is_boolean.c \
				concatenate/concatenate.c \
				
				 



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 		= -Wall -Werror -Wextra
FLAGS			= -g3 -lreadline
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak
DEBUGGER		= lldb

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
				$(DEBUGGER) $(NAME)
				
sanitize :		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)

leak :			$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(LEAKS) libft/libft.a  -o $(NAME)


re : fclean all
.PHONY			: all clean fclean re leak sanitize