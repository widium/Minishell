# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2022/09/21 17:33:27 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# === File && Header === #
SRCS		= 	main.c \
				utils/init.c \
				utils/string_utils.c \
				env/chained_var.c \
				env/prompt.c \
				env/signal.c \
				env/env.c \
				env/variable.c \
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
				detection/quote_detection.c \
				detection/classification.c \
				is/is.c \
				is/is_redirection.c \
				is/is_quote.c \
				is/is_file.c \
				parsing/parsing.c \
				parsing/casting.c \
				verbose/verbose.c \
				verbose/verbose_token.c \
				verbose/verbose_class.c \
				verbose/verbose_env.c \
				verbose/verbose_cmd.c \
				verbose/verbose_redirect.c \
				tokenization/init_token.c \
				tokenization/tokenizer.c \
				tokenization/chained.c \
				tokenization/create.c \
				tokenization/is_token.c \
				tokenization/is_arg.c \
				tokenization/token.c \
				tokenization/get.c \
				tokenization/tokenization.c \
				tokenization/argument.c \
				redirection/redirect.c \
				redirection/redirection.c \
				redirection/manage_redirection.c\
				redirection/heredoc.c \
				redirection/close.c \
				boolean/boolean.c \
				boolean/is_boolean.c \
				concatenate/concatenate.c \
				execution/execution.c \
				execution/access.c \
				execution/bin.c \
				execution/bin_processing.c \
				execution/bin_exe.c \
				execution/built_in_exe.c \
				execution/built_in.c \
				error/error.c \
				error/error_cmd.c \
				error/error_built_in.c \
				processing/processing_cmd.c \
				processing/processing_built.c \
				
HEADER 			= header/class.h \
				  header/execution.h \
				  header/free.h \
				  header/get.h \
				  header/is.h \
				  header/token.h \
				  header/verbose.h \

# ==== Template ==== #
TEMPLATE = header/header.txt

# ==== Execute ==== #
EXE = @./$(NAME)

# ==== Debug && Leak ==== #
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak
DEBUGGER		= lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# ==== Objet && compiling ==== #
OBJS			= $(SRCS:.c=.o)
CC				= gcc
# FLAGS 		= -Wall -Werror -Wextra
FLAGS			= -g3
FLAGS 			+= $(SANITIZE)
READLINE		= -lreadline
MAKE			= make -s


# === Convert all .c to .o with flags and header === # 
%.o : %.c $(HEADER)
			@$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : 	    $(OBJS)
				@echo "==== Compiling all .c ===="
				@echo "==== Compiling libft ===="
				@$(MAKE) -C libft
				@echo "==== Compiling Minishell ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) libft/libft.a -o $(NAME)
				@cat "$(TEMPLATE)"		

all : 	 $(NAME)

clean :
				@echo "==== Remove all Libft .o ===="
				@$(MAKE) clean -C libft
				@echo "==== Remove all Minishell .o ===="
				@$(RM_FILE) $(OBJS)

fclean : clean
				@$(MAKE) fclean -C libft
				@$(RM_FILE) $(NAME)

debug : 		$(OBJS)
				@echo "==== Mode Debug Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) libft/libft.a  -o $(NAME)
				$(DEBUGGER) $(NAME)
				@cat "$(TEMPLATE)"
				
sanitize :		$(OBJS)
				@echo "==== Mode Sanitize Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) libft/libft.a  -o $(NAME)
				@cat "$(TEMPLATE)"

leak :			$(OBJS)
				@echo "==== Mode Leak Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(LEAKS) libft/libft.a  -o $(NAME)
				@cat "$(TEMPLATE)"


re : fclean all
.PHONY			: all clean fclean re leak sanitize