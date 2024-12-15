CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Program 1 (megaphone)
NAME0 = megaphone
SRC0 = ex00/megaphone.cpp
OBJ0 = $(SRC0:.cpp=.o)

# Program 2 (PhoneBook)
NAME1 = PhoneBook
SRC1 = ex01/main.cpp ex01/PhoneBook.cpp
OBJ1 = $(SRC1:.cpp=.o)

# Targets
all: $(NAME0) $(NAME1)

# Compile program 1
$(NAME0): $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

# Compile program 2
$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

# Object files for program 1
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executables
clean:
	rm -f $(OBJ0) $(OBJ1)

fclean: clean
	rm -f $(NAME0) $(NAME1)

re: fclean all

# Custom rules for specific programs
0: $(NAME0)

1: $(NAME1)
