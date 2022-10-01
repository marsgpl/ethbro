NAME = ethbro
NAME_VANITY = vanity

CC = gcc
LD = gcc
CCFLAGS = -c -m64 -std=gnu99 -O2 -Wall -Werror
LDFLAGS =
INCS =
LIBS = -lsecp256k1

TARGET = $(NAME)
TARGET_VANITY = $(NAME_VANITY)

OBJECTS = $(NAME).o hex.o keccak.o
OBJECTS_VANITY = $(NAME_VANITY).o hex.o keccak.o fill_random.o

build: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) vanity

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

$(TARGET_VANITY): $(OBJECTS_VANITY)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

.c.o:
	$(CC) $(CCFLAGS) -o $@ $< $(INCS)

$(NAME).o: $(NAME).h eth.h hex.h keccak.h
$(NAME_VANITY).o: $(NAME_VANITY).h eth.h hex.h keccak.h fill_random.h
hex.o: hex.h
keccak.o: keccak.h
fill_random.o: fill_random.h
