NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ./sources/main.c ./sources/ft_atoi.c ./sources/init_table.c\
	./sources/simulation.c ./sources/thinking.c ./sources/forks.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: fclean all