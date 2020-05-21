TARGET = lab.exe
CC = gcc

.PHONY: edit run clean install uninstall valgrind

edit: $(TARGET)		 
	
Source.o: Source.c
				$(CC) -c Source.c
list.o: list.c list.h
				$(CC) -c list.c
a.out: Source.c list.c list.h
	gcc -g Source.c list.c

$(TARGET): Source.o list.o
				$(CC) -o $(TARGET) Source.o list.o
valgrind: a.out
	valgrind -q ./a.out	
	
splint:
	splint *.c
clean:
			@rm -rf $(TARGET) *.o *.i *.s *.gch *.out *.exe
install: $(TARGET) 
			install $(TARGET) /
run:
			$(TARGET)
uninstall:
			@rm -rf /$(TARGET)