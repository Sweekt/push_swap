SRCS	:=	main.c				\
			push_swap.c

SRCS_D	:=	srcs/

OBJS_D	:=	objs/

OBJS	:=	$(SRCS:%.c=$(OBJS_D)%.o)

HEAD_D	:=	.

CFLAGS	:=	-Wall -Wextra -Werror

AR	:=	ar rcs

NAME	:=	push_swap

all	:	$(NAME)

$(NAME)	:	$(OBJS_D) $(OBJS) Makefile
			$(CC) $(OBJS) -g3 -o $(NAME)

$(OBJS)	:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD)
			$(CC) $(CFLAGS) -I/usr/include -c $< -o $@

$(OBJS_D)	:
			@mkdir -p $(OBJS_D)

clean	:
			$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY: all bonus clean fclean re