frecpal : main.o list.o ordered_list.o
	gcc -o frecpal main.o list.o ordered_list.o

main.o : main.c list.h ordered_list.h
	gcc -c -ansi -Wpedantic main.c

list.o : list.c list.h
	gcc -c -ansi -Wpedantic list.c 

ordered_list.o : ordered_list.c ordered_list.h
	gcc -c -ansi -Wpedantic ordered_list.c

clean :
	rm -f *.o frecpal