SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_S = mandatory/server.c mandatory/utils.c
SRC_C = mandatory/client.c mandatory/utils.c

BONUS_S = bonus/server_bonus.c bonus/utils_bonus.c
BONUS_C = bonus/client_bonus.c bonus/utils_bonus.c

FLAG = -Wall -Werror -Wextra

OBJ_S = $(SRC_S:%.c=%.o)
OBJ_C = $(SRC_C:%.c=%.o)

BONUS_S_O = $(BONUS_S:%.c=%.o)
BONUS_C_O = $(BONUS_C:%.c=%.o)

%.o : %.c
	cc $(FLAG) -c $< -o $@

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S)
	cc $(FLAG) $(OBJ_S) -o $(SERVER)

$(CLIENT) : $(OBJ_C)
	cc $(FLAG) $(OBJ_C) -o $(CLIENT)

$(SERVER_BONUS) : $(BONUS_S_O)
	cc $(FLAG) $(BONUS_S_O) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(BONUS_C_O)
	cc $(FLAG) $(BONUS_C_O) -o $(CLIENT_BONUS)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	rm -f $(OBJ_S) $(OBJ_C) $(BONUS_S_O) $(BONUS_C_O)

fclean : clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
