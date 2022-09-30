NAME = ethbro

CC = gcc
LD = gcc
CCFLAGS = -c -m64 -std=gnu99 -O2 -Wall -Werror
LDFLAGS =
INCS =
LIBS =

TARGET = $(NAME)

OBJECTS = $(NAME).o hex.o

build: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

.c.o:
	$(CC) $(CCFLAGS) -o $@ $< $(INCS)

$(NAME).o: $(NAME).h eth.h hex.h
hex.o: hex.h
