TARGET = lab.exe
CC = gcc

.PHONY: edit run clean install uninstall valgrind

edit: $(TARGET)		 
	
Source.o: Source.c
				$(CC) -c Source.c
BinTree.o: BinTree.c BinTree.h
				$(CC) -c BinTree.c
Stack.o: Stack.c Stack.h
				$(CC) -c Stack.c
a.out: Source.c BinTree.c Header.h BinTree.h
	gcc -g Source.c BinTree.c

$(TARGET): Source.o BinTree.o Stack.o
				$(CC) -o $(TARGET) Source.o BinTree.o Stack.o
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