NAME_C = client
NAME_S = server

NAME_CBONUS = client_bonus
NAME_SBONUS = server_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_S = server.c
OBJ_S = $(SRC_S:.c=.o)
SRC_C = client.c
OBJ_C = $(SRC_C:.c=.o)

SRC_CBONUS = client_bonus.c
OBJ_CBONUS = $(SRC_CBONUS:.c=.o)
SRC_SBONUS = server_bonus.c
OBJ_SBONUS = $(SRC_SBONUS:.c=.o)

LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = FT_PRINTF
PRINTF = $(PRINTF_DIR)/libprintf.a

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

bonus:  all client_bonus server_bonus

client_bonus: $(LIBFT) $(PRINTF) $(OBJ_CBONUS)
	@ $(CC) $(FLAGS) -o $(NAME_CBONUS) $(OBJ_CBONUS) $(LIBFT) $(PRINTF)

server_bonus: $(LIBFT) $(PRINTF) $(OBJ_SBONUS)
	@ $(CC) $(FLAGS) -o $(NAME_SBONUS) $(OBJ_SBONUS) $(LIBFT) $(PRINTF)

all: client server

server: $(LIBFT) $(PRINTF) $(OBJ_S)
	@ $(CC) $(FLAGS) -o $(NAME_S) $(OBJ_S) $(LIBFT) $(PRINTF)

client: $(LIBFT) $(PRINTF) $(OBJ_C)
	@ $(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) $(LIBFT) $(PRINTF)

$(LIBFT):
	@ make -C $(LIBFT_DIR)

$(PRINTF):
	@ make -C $(PRINTF_DIR)

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C) $(OBJ_SBONUS) $(OBJ_CBONUS)
	@ make -C $(LIBFT_DIR) clean
	@ make -C $(PRINTF_DIR) clean

fclean: clean
	@ $(RM) $(NAME_S) $(NAME_C) $(NAME_SBONUS) $(NAME_CBONUS)
	@ make -C $(LIBFT_DIR) fclean
	@ make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all $(LIBFT) $(PRINTF) clean fclean bonus re client_bonus server_bonus client server
