CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Program 1 (megaphone)
NAME0 = megaphone
SRC0 = ex00/megaphone.cpp
OBJ_DIR0 = ex00/bin
OBJ0 = $(OBJ_DIR0)/megaphone.o

# Program 2 (PhoneBook)
NAME1 = PhoneBook
SRC1 = ex01/main.cpp ex01/PhoneBook.cpp
OBJ_DIR1 = ex01/bin
OBJ1 = $(SRC1:ex01/%.cpp=$(OBJ_DIR1)/%.o)

all: $(NAME0) $(NAME1)

# Compile program 1
$(NAME0): $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

# Compile program 2
$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

# Rule to compile .cpp to .o for Program 1
$(OBJ_DIR0)/%.o: ex00/%.cpp
	@mkdir -p $(OBJ_DIR0)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile .cpp to .o for Program 2
$(OBJ_DIR1)/%.o: ex01/%.cpp
	@mkdir -p $(OBJ_DIR1)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR0) $(OBJ_DIR1)

fclean: clean
	rm -f $(NAME0) $(NAME1)

re: fclean all

0: $(NAME0)

1: $(NAME1)
