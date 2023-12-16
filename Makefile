CC = gcc
TARGET = calculator

OBJS = main.o read_numbers.o print_numbers.o operations.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c print_numbers.h read_numbers.h operations.h
	$(CC) $(CFLAGS) -c main.c

print_numbers.o: print_numbers.h
	$(CC) $(CFLAGS) -c print_numbers.c

read_numbers.o: read_numbers.h
	$(CC) $(CFLAGS) -c read_numbers.c

operations.o: operations.h
	$(CC) $(CFLAGS) -c operations.c

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)
