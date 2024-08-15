# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 12:39:28 by souaouri          #+#    #+#              #
#    Updated: 2024/08/15 11:00:17 by souaouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				=	cc
CC				+=	-Wall -Wextra -Werror #-fsanitize=thread
NAME 			=	philo
HEADER 			=	philo.h
DIR				=	.object_files

MANDATORY_FILES		=	philo_main.c	philo_utils.c	philo_print_errors.c \
						philo_parsing.c	

MANDATORY_SRC			=	$(addprefix mandatory/,$(MANDATORY_FILES))

MANDATORY_OBJ			=	$(addprefix $(DIR)/,$(MANDATORY_SRC:.c=.o))

OBJ_FILES		=	$(MANDATORY_OBJ)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	@$(CC) -lreadline -o $@ $^
	@echo "✅ \033[1;32mCompilation Completed Successfully!\033[0;m"

$(DIR)/mandatory/%.o : mandatory/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@
	@echo "\033[1;30mObject files generated Successfully! $@ \033[0;m"

clean :
	@rm -rf $(DIR)
	@echo "\033[31mObject files has been removed Successfully! ✅\033[0;m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[31mExecutable file has been removed Successfully! ✅\033[0;m"

re : fclean all