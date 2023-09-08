lists_c: lists_c.o linked_list.o
	gcc -ansi -Wall -g lists_c.o linked_list.o -o lists_c
lists_c.o: lists_c.c lists_c.h linked_list.h
	gcc -c -ansi -Wall lists_c.c -o lists_c.o
linked_list.o: linked_list.c lists_c.h linked_list.h
	gcc -c -ansi -Wall linked_list.c -o linked_list.o
