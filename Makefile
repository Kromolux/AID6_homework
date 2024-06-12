NAME		:=	AID6

OBJ_FOLDER	:=	obj
SRC_FOLDER	:=	src

CC			:=	g++

SRCS		:=	main.cpp \
				Dice.cpp \
				utils.cpp \
				Character.cpp \
				AMateria.cpp \
				Icebolt.cpp \
				Meditate.cpp \
				Cure.cpp \
				Game.cpp \
				TerminalManager.cpp


OBJS		:=	$(SRCS:%.cpp=$(OBJ_FOLDER)/%.o)

CFLAGS		=	-Wall -Werror -Wextra -Wfatal-errors -Wconversion -std=c++98
DFLAG		:=	-g -D DEBUG=1

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

debug:	CFLAGS += $(DFLAG)
debug:	all
		./$(NAME)


clean:
	rm -fr $(OBJ_FOLDER)

fclean: clean
	rm -fr $(NAME) $(NAME).dSYM docu

re: fclean all


val:
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME)


.PHONY: clean fclean re val $(NAME)
