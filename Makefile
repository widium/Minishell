# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2022/09/29 14:03:09 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# === File && Header === #
SRCS		= 	main.c \
				env/create_env_var.c \
				env/prompt.c \
				env/signal.c \
				env/env_var_value.c \
				env/variable.c \
				env/line.c \
				env/read_line.c \
				env/chained.c \
				init/init_token.c \
				init/init_env.c \
				init/init_redirect.c\
				exit_free/free.c \
				exit_free/remove_arg.c \
				exit_free/remove_token.c \
				exit_free/remove.c \
				exit_free/disconect.c \
				exit_free/remove_token_type.c \
				detection/extraction.c \
				detection/argument_extraction.c \
				detection/classification.c \
				is/is.c \
				is/is_redirection.c \
				is/is_basic_redirection.c \
				is/is_separator.c \
				is/is_blank.c \
				is/is_token_cmd.c \
				is/is_variable.c \
				is/is_cmd.c \
				is/is_fd.c \
				is/is_quote.c \
				is/is_file.c \
				is/is_finish.c \
				is/is_line.c \
				is/is_cmd_arg.c \
				is/is_arg.c \
				is/have.c \
				is/is_same.c \
				is/is_built_in.c \
				is/is_token.c \
				is/is_token_redirection.c \
				is/cmd_have.c \
				parsing/parsing.c \
				parsing/casting.c \
				parsing/quote_detection.c \
				parsing/word_detection.c \
				parsing/redirection_detection.c \
				verbose/verbose.c \
				verbose/verbose_token.c \
				verbose/verbose_class.c \
				verbose/verbose_env.c \
				verbose/verbose_cmd.c \
				verbose/verbose_redirect.c \
				verbose/verbose_env_var.c \
				verbose/verbose_basic_redirect.c \
				tokenization/tokenizer.c \
				tokenization/create_token.c \
				tokenization/tokenization.c \
				tokenization/quote_tokenizer.c \
				tokenization/cmd_tokenizer.c \
				tokenization/connect.c \
				redirection/redirect.c \
				redirection/manage_redirection.c\
				redirection/heredoc.c \
				redirection/close.c \
				concatenate/concatenate.c \
				concatenate/list_to_array.c \
				execution/execution.c \
				execution/access.c \
				execution/bin_exe.c \
				execution/status.c \
				built_in/built_in_exe.c \
				built_in/built_in.c \
				built_in/export.c \
				error/error.c \
				error/error_cmd.c \
				error/error_built_in.c \
				error/error_env.c \
				error/error_redirect.c \
				processing/variable_value.c \
				processing/processing_cmd.c \
				processing/processing_built.c \
				processing/processing_redirection.c \
				processing/bin_processing.c \
				get/get.c \
				get/get_env.c \
				get/get_token.c \
				get/get_next.c \
				get/get_arg.c \
				get/get_cmd.c \
				get/get_redirection.c \
				get/get_path.c \
				
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