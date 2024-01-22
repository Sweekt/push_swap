# $@ : NAME de la regle
# $^ : tous les OBJS
# $< : premiere dependance

GREY		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
ORANGE		= \033[33m
BLUE		= \033[34m
PURPLE		= \033[35m
LIGHTBLUE	= \033[36m
WHITE		= \033[37m
IRED		= \033[41m
IWHITE		= \033[47m
IBLUE		= \033[44m
IPURPLE		= \033[45m
END			= \033[0m

NAME		= push_swap

DISPLAY		= display

FLAGS		= -Wall -Wextra -Werror -I includes/ -I libs/libft -g3 -fsanitize=address

SRCS		=	main.c

OBJS	:=	$(SRCS:%.c=$(OBJS_D)%.o)

SRCS_D	:=	srcs/

OBJS_D	:=	objs/

HEADER		= includes/push_swap.h

all:	libs ${NAME}

${NAME}:	$(OBJS_D) $(OBJS) Makefile
			@ cc ${FLAGS} -o $@ ${OBJS} super_libft/libft.a && echo "${GREEN}\n* ${NAME} compilation completed !!!\n${END}"

libs:
	${MAKE} -C super_libft

%.o: %.c ${HEADER}
	@ cc ${FLAGS} ${HEAD} -c $< -o $@ && echo "  $@"

clean:
	@ ${RM} ${OBJS} $(OBJS_D) && echo "${RED} * object cleared...${END}"

fclean: clean
	@ ${RM} ${NAME} && echo "${RED} * everything is cleared...${END}"
	$(MAKE) fclean -C super_libft

re:	fclean
	${MAKE} all

sus:
	@echo "${BLUE}           ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀        ${END}"
	@echo "${BLUE}        ⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀     ${END}"
	@echo "${BLUE}        ⣼⣿⠋       ${WHITE}⢀⣀⣀${BLUE}⠈⢻⣿⣿⡄    ${END}"
	@echo "${BLUE}       ⣸⣿⡏   ${WHITE}⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄   ${END}"
	@echo "${BLUE}       ⣿⣿⠁  ${WHITE}⢰⣿⣿⣯⠁       ⠈⠙⢿⣷⡄ ${END}"
	@echo "${BLUE}  ⣀⣤⣴⣶⣶⣿⡟   ${WHITE}⢸⣿⣿⣿⣆          ⣿⣷ ${END}"
	@echo "${BLUE} ⢰⣿⡟⠋⠉⣹⣿⡇   ${WHITE}⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿ ${END}"
	@echo "${BLUE} ⢸⣿⡇  ⣿⣿⡇    ${WHITE}⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃ ${END}"
	@echo "${BLUE} ⣸⣿⡇  ⣿⣿⡇     ${WHITE}⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛${BLUE}⢻⣿⡇  ${END}"
	@echo "${BLUE} ⠸⣿⣧⡀ ⣿⣿⡇                ⣿⣿⠃  ${END}"
	@echo "${BLUE}  ⠛⢿⣿⣿⣿⣿⣇     ⣰⣿⣿⣷⣶⣶⣶⣶⠶ ⢠⣿⣿   ${END}"
	@echo "${BLUE}       ⣿⣿     ⣿⣿⡇ ⣽⣿⡏⠁  ⢸⣿⡇   ${END}"
	@echo "${BLUE}       ⣿⣿     ⣿⣿⡇ ⢹⣿⡆   ⣸⣿⠇   ${END}"
	@echo "${BLUE}       ⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁ ⠈⠻⣿⣿⣿⣿⡿⠏    ${END}"
	@echo "${BLUE}       ⠈⠛⠻⠿⠿⠿⠿⠋⠁              ${END}"
	@echo "$(IBLUE)         ░█▀▀░█░█░█▀▀         ${END}"
	@echo "$(IBLUE)         ░▀▀█░█░█░▀▀█         ${END}"
	@echo "$(IBLUE)         ░▀▀▀░▀▀▀░▀▀▀         ${END}"

.PHONY: all libs clean fclean re