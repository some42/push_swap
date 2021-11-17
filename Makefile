# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 10:00:31 by tmatis            #+#    #+#              #
#    Updated: 2021/10/23 02:34:20 by agaliste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################


NAME	= push_swap
CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MMD -MF $(@:.o=.d)
AUTHOR	= agaliste
DATE	= 19/10/2021

NOVISU 	= 0 # 1 = no progress bar usefull when tty is not available

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

FILE_EXTENSION	= .c

SRCS_PATH		= ./

INCLUDE_PATH	= ./

SRCS			= 	libft/ft_isdigit.c \
					libft/ft_memset.c \
					libft/ft_isprint.c \
					libft/ft_strlcat.c \
					libft/ft_atoi.c \
					libft/ft_atoli.c \
					libft/ft_putchar_fd.c \
					libft/ft_putstr_fd.c \
					libft/ft_strlcpy.c \
					libft/ft_tolower.c \
					libft/ft_bzero.c \
					libft/ft_memccpy.c \
					libft/ft_strlen.c \
					libft/ft_toupper.c \
					libft/ft_calloc.c \
					libft/ft_memchr.c \
					libft/ft_isalnum.c \
					libft/ft_putendl_fd.c \
					libft/ft_memcmp.c \
					libft/ft_strncmp.c \
					libft/ft_isalpha.c \
					libft/ft_memcpy.c \
					libft/ft_strchr.c \
					libft/ft_strnstr.c \
					libft/ft_isascii.c \
					libft/ft_memmove.c \
					libft/ft_strdup.c \
					libft/ft_strrchr.c \
					libft/ft_putnbr_fd.c \
					libft/ft_substr.c \
					libft/ft_strjoin.c \
					libft/ft_strtrim.c \
					libft/ft_strmapi.c \
					libft/ft_itoa.c \
					libft/ft_split.c \
					libft/ft_lstnew.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstsize.c \
					libft/ft_lstlast.c \
					libft/ft_lstadd_back.c \
					libft/ft_lstdelone.c \
					libft/ft_lstclear.c \
					libft/ft_lstiter.c \
					libft/ft_lstmap.c \
					libft/ft_lstdel_last.c \
					functions/operations.c \
					helper/init.c \
					helper/tools.c \
					helper/checks.c \

MAIN			= push_swap.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SHELL := /bin/bash


OBJS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
DEPS				= $(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})
DEPS_MAIN			= $(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.d})

################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

COM_STRING   = "compiling"

HASH	= 

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin) 
	RUN_CMD = script -q $@.log $1 > /dev/null; \
				RESULT=$$?
else ifeq ($(detected_OS),Linux)
	RUN_CMD = script -q -e -c "$(1)" $@.log > /dev/null; \
				RESULT=$$?; \
				sed -i '1d' $@.log; \
				sed -i "$$(($$(wc -l < $@.log)-1)),\$$d" $@.log
else
	RUN_CMD = $(1) 2> $@.log; \
				RESULT=$$?
endif

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | head -n 1 | sed 's/\n/, /g')
	DATE	:= $(shell git log -1 --date=format:"%Y/%m/%d %T" --format="%ad")
	HASH	:= $(shell git rev-parse --short HEAD)
endif

define run_and_test
printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
$(RUN_CMD); \
if [[ $$RESULT -ne 0 ]]; then \
	printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
	rm -rf .files_changed; \
	if [[ $(NOVISU) -eq 0 ]]; then \
		echo; \
	fi; \
elif [[ -s $@.log ]]; then \
	printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)"; \
else  \
	printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

define save_files_changed
	FILE_CPP=`echo $(SRCS) $(MAIN)`; \
	FILE_OBJ=`find objs -type f -name '*.o' 2>/dev/null | sed 's/objs\///'`; \
	TO_COMPILE=`echo $$FILE_CPP | wc -w`; \
	for FILE in $$FILE_CPP; do \
		for OBJ in $$FILE_OBJ; do \
			if [[ $${FILE%$(FILE_EXTENSION)} = $${OBJ%.o} ]]; then \
				if [[ $(SRCS_PATH)/$$FILE -ot objs/$$OBJ ]]; then \
					FILE_DEP=`echo objs/$$OBJ | sed 's/\.o/\.d/'`; \
					HEAD_FILES=`< $$FILE_DEP xargs | grep -oh "\w*.h\w*"`; \
					RECOMPILE=0; \
					for HEAD in $$HEAD_FILES; do \
						if [[ $(SRCS_PATH)/$$HEAD -nt objs/$$OBJ ]]; then \
							RECOMPILE=1; \
							break; \
						fi; \
					done; \
					if [[ $$RECOMPILE -eq 0 ]]; then \
						((TO_COMPILE=$$TO_COMPILE-1)); \
					fi;\
				fi; \
			fi; \
		done; \
	done; \
	echo 0/$$TO_COMPILE > .files_changed
endef

define draw_bar
	FILE_TOTAL=`bash -c 'cat .files_changed | cut -d"/" -f2'`; \
	FILE_DONE=`bash -c 'cat .files_changed | cut -d"/" -f1'`; \
	if [[ $$FILE_TOTAL -eq 0 ]]; then \
		FILE_TOTAL=1; \
		FILE_DONE=1; \
	fi; \
	RES=`echo "scale=2; $$FILE_DONE/$$FILE_TOTAL*48" | bc`; \
	RES=`echo $${RES%%.*}`; \
	printf "$(OBJ_COLOR)[$(NO_COLOR)"; \
	i=0; \
	while [ $$i -lt 48 ]; do \
		if [[ $$i -lt $$RES ]]; then \
			printf "$(OK_COLOR)█$(NO_COLOR)"; \
		else \
			printf "$(COM_COLOR)▒$(NO_COLOR)"; \
		fi; \
		((i=$$i+1)); \
	done; \
	printf "$(OBJ_COLOR)]$(NO_COLOR)"; \
	printf " ($(COM_COLOR)$$FILE_DONE$(NO_COLOR)/$(COM_COLOR)$$FILE_TOTAL$(NO_COLOR))"; \
	printf " "; \
	((FILE_DONE=$$FILE_DONE+1)); \
	echo $$FILE_DONE/$$FILE_TOTAL > .files_changed;
endef

define display_progress_bar
	if [[ $(NOVISU) -eq 0 ]]; then \
		line=`bash -c 'oldstty=$$(stty -g); stty raw -echo min 0; tput u7 > /dev/tty; IFS=";" read -r -d R -a pos; stty $$oldstty; row=$$(($${pos[0]:2} - 1)); echo $$row'`; \
		max_line=`tput lines`; \
		((max_line=$$max_line-2));\
		new_line=0; \
		tput sc; \
		i=0; \
		while [ $$i -lt 60 ]; do \
			printf " "; \
			((i=$$i+1)); \
		done; \
		tput rc; \
		if [[ $$line -gt $$max_line ]]; then \
			new_line=1; \
			echo ; \
		else \
			((line=$$line+1));\
		fi; \
		tput sc; \
		tput cup $$line; \
		$(draw_bar) \
		if [[ $$new_line -eq 1 ]]; then \
			((line=$$line-1));\
			tput cup $$line; \
		else \
			tput rc; \
		fi; \
	fi
endef

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header setup $(NAME)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo
	@echo "░█████╗░░██████╗░░█████╗░██╗░░░░░██╗░██████╗████████╗███████╗"
	@echo "██╔══██╗██╔════╝░██╔══██╗██║░░░░░██║██╔════╝╚══██╔══╝██╔════╝"
	@echo "███████║██║░░██╗░███████║██║░░░░░██║╚█████╗░░░░██║░░░█████╗░░"
	@echo "██╔══██║██║░░╚██╗██╔══██║██║░░░░░██║░╚═══██╗░░░██║░░░██╔══╝░░"
	@echo "██║░░██║╚██████╔╝██║░░██║███████╗██║██████╔╝░░░██║░░░███████╗"
	@echo "╚═╝░░╚═╝░╚═════╝░╚═╝░░╚═╝╚══════╝╚═╝╚═════╝░░░░╚═╝░░░╚══════╝"
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
	@echo


-include $(DEPS) $(DEPS_MAIN)
$(NAME):	${OBJS} ${OBJ_MAIN}
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) $(DFLAGS) -I$(INCLUDE_PATH) -o $@ ${OBJS} ${OBJ_MAIN})

setup:
	@$(call save_files_changed)

objs/%.o: 	$(SRCS_PATH)/%$(FILE_EXTENSION)
			@mkdir -p $(dir $@)
			@$(call display_progress_bar)
			@$(call run_and_test,$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I$(INCLUDE_PATH))

clean:		header
			@rm -rf objs objs_tests
			@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

fclean:		header clean
			@rm -rf $(NAME)
			@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)[✓]$(NO_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re header
