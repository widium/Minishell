# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2022/10/05 14:50:28 by ebennace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# === File && Header === #
SRCS		= 	source/main.c \
				source/env/create_env_var.c \
				source/env/prompt.c \
				source/env/signal.c \
				source/env/env_var_value.c \
				source/env/variable.c \
				source/env/line.c \
				source/env/read_line.c \
				source/env/chained.c \
				source/init/init_token.c \
				source/init/init_env.c \
				source/init/init_redirect.c\
				source/exit_free/free.c \
				source/exit_free/remove_arg.c \
				source/exit_free/remove_token.c \
				source/exit_free/remove.c \
				source/exit_free/disconect.c \
				source/exit_free/remove_token_type.c \
				source/detection/extraction.c \
				source/detection/argument_extraction.c \
				source/detection/classification.c \
				source/detection/variable_detection.c \
				source/is/is.c \
				source/is/is_redirection.c \
				source/is/is_basic_redirection.c \
				source/is/is_separator.c \
				source/is/is_blank.c \
				source/is/is_token_cmd.c \
				source/is/is_variable.c \
				source/is/is_cmd.c \
				source/is/is_fd.c \
				source/is/is_quote.c \
				source/is/is_file.c \
				source/is/is_finish.c \
				source/is/is_line.c \
				source/is/is_cmd_arg.c \
				source/is/is_arg.c \
				source/is/have.c \
				source/is/is_same.c \
				source/is/is_built_in.c \
				source/is/is_token.c \
				source/is/is_token_redirection.c \
				source/is/cmd_have.c \
				source/parsing/parsing.c \
				source/parsing/casting.c \
				source/parsing/quote_detection.c \
				source/parsing/word_detection.c \
				source/parsing/redirection_detection.c \
				source/verbose/verbose.c \
				source/verbose/verbose_token.c \
				source/verbose/verbose_class.c \
				source/verbose/verbose_env.c \
				source/verbose/verbose_cmd.c \
				source/verbose/verbose_redirect.c \
				source/verbose/verbose_env_var.c \
				source/verbose/verbose_env_var_fd.c \
				source/verbose/verbose_basic_redirect.c \
				source/tokenization/tokenizer.c \
				source/tokenization/create_token.c \
				source/tokenization/tokenization.c \
				source/tokenization/quote_tokenizer.c \
				source/tokenization/cmd_tokenizer.c \
				source/tokenization/connect.c \
				source/redirection/redirect.c \
				source/redirection/manage_redirection.c\
				source/redirection/heredoc.c \
				source/redirection/close.c \
				source/concatenate/concatenate.c \
				source/concatenate/list_to_array.c \
				source/execution/execution.c \
				source/execution/access.c \
				source/execution/bin_exe.c \
				source/execution/status.c \
				source/built_in/built_in_exe.c \
				source/built_in/built_in.c \
				source/built_in/export.c \
				source/error/error.c \
				source/error/error_cmd.c \
				source/error/error_built_in.c \
				source/error/error_env.c \
				source/error/error_redirect.c \
				source/processing/variable_value.c \
				source/processing/processing_cmd.c \
				source/processing/processing_built.c \
				source/processing/processing_redirection.c \
				source/processing/bin_processing.c \
				source/get/get.c \
				source/get/get_env.c \
				source/get/get_token.c \
				source/get/get_next.c \
				source/get/get_arg.c \
				source/get/get_cmd.c \
				source/get/get_redirection.c \
				source/get/get_path.c \

HEADER 			= header/class.h \
				  header/execution.h \
				  header/free.h \
				  header/get.h \
				  header/is.h \
				  header/token.h \
				  header/verbose.h \

# ==== Template ==== #
TEMPLATE = source/header/header.txt

# ==== Execute ==== #
EXE = @./$(NAME)
LIBFT = source/libft/libft.a
# ==== Debug && Leak ==== #
SANITIZE 		= -fsanitize=address
LEAKS 			= -fsanitize=leak
DEBUGGER		= lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# ==== Objet && compiling ==== #
OBJS			= $(SRCS:.c=.o)
CC				?= gcc
FLAGS			= -g3
FLAGS 			+= -Wall -Werror -Wextra
FLAGS 			+= $(SANITIZE)
READLINE		= -lreadline
MAKE			= make -s

# Cross fLags
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	
else
	NPROC := $(shell sysctl -n hw.ncpu)
	FLAGS += -I$(HOME)/.brew/opt/readline/include
    READLINE += -L$(HOME)/.brew/opt/readline/lib
	
endif

# === Convert all .c to .o with flags and header === # 
%.o : %.c
			@$(CC) $(FLAGS) -c $< -o $@
	
$(NAME) : 	    $(OBJS)
				@echo "==== Create all .o ===="
				@echo "==== Compiling all .c ===="
				@echo "==== Compiling libft ===="
				@$(MAKE) -C source/libft
				@echo "==== Compiling Minishell ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"		

all : 	 $(NAME)

clean :
				@echo "==== Remove all Libft .o ===="
				@$(MAKE) clean -C source/libft
				@echo "==== Remove all Minishell .o ===="
				@$(RM_FILE) $(OBJS)

fclean : clean
				@$(MAKE) fclean -C source/libft
				@$(RM_FILE) $(NAME)

debug : 		$(OBJS)
				@echo "==== Mode Debug Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
				$(DEBUGGER) $(NAME)
				@cat "$(TEMPLATE)"
				
sanitize :		$(OBJS)
				@echo "==== Mode Sanitize Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"

leak :			$(OBJS)
				@echo "==== Mode Leak Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(LEAKS) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"


re : fclean all
.PHONY			: all clean fclean re leak sanitize