CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = megaphone

SOURCES = megaphone.cpp
BIN_DIR = bin
OBJECTS = $(SOURCES:.cpp=.o)
BIN_OBJECTS = $(addprefix $(BIN_DIR)/, $(OBJECTS))

all: $(BIN_DIR) $(NAME)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: %.cpp | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN_OBJECTS)
	$(CC) $(BIN_OBJECTS) -o $(NAME)

clean:
	rm -f $(BIN_OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(BIN_DIR)

re: fclean all



