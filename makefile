
PROJ_NAME=complexo

C_SOURCE=$(wildcard *.c)

H_SOURCE=$(wildcard *.h)

OBJ=$(C_SOURCE:.c=.o)

CC=gcc

CC_FLAGS=-c


all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H.SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o *~ complexo