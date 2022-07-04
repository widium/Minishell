# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2022/07/04 16:58:08 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS		= 	main.c \
				utils/init.c \
				env/prompt.c \
				env/signal.c \
				exit_free/exit.c \
				exit_free/free.c \
				history/file.c \
				parsing/detect.c \



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 		= -Wall -Werror -Wextra
FLAGS			= -g3 -lreadline
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak

%.o : %.c
			$(CC) -c $< -o $@
	
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
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) -g3 libft/libft.a  -o $(NAME)
				gdb $(NAME)
				
sanitize :		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)

leak :			$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(LEAKS) libft/libft.a  -o $(NAME)


re : fclean all
.PHONY			: all clean fclean re leak sanitize