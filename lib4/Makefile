CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -std=c99
TARGET  = sorting_bench
OBJS    = main.o bubble_sort.o insert_sort.o merge_sort.o array_utils.o
HEADERS = sorts.h

all: $(TARGET)

$(TARGET): $(OBJS)
 $(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
 $(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
 ./$(TARGET)

clean:
 rm -f $(OBJS) $(TARGET)

rebuild: clean all