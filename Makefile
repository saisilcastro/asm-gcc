ifeq ($(OS), Windows_NT)
	CC = gcc
	CREATE = mkdir -p $(1)
	REMOVE = rm -rf $(1)
else
	CREATE = mkdir -p $(1)
	REMOVE = rm -rf $(1)
endif
NAME = libasm.a
INCLUDE = -I$(CURDIR)
SRC = assembly.c
OBJ = obj
SRCOBJ = $(SRC:%.c=${OBJ}/%.o)

all: $(NAME)
$(NAME): $(SRCOBJ)
	ar src $(NAME) $^
${OBJ}/%.o : %.c
	$(call CREATE,${OBJ})
	$(CC) -c $< -o $@ $(INCLUDE)
clean:
	$(call REMOVE,${OBJ})
fclean: clean
	$(call REMOVE,${NAME})
re: fclean all