# Declaratiile de variabile
CC = gcc
CFLAGS = -g -Wall -lm
 


# Regula de compilare
build:
	$(CC) -o fsminishell fsminishell.c mycd.c myrmdir.c mycreate.c mydelete.c myfind.c myls.c mymkdir.c mypwd.c myrm.c mytouch.c mytree.c interpreter.c $(CFLAGS)

run:
	./fsminishell

# Regulile de "curatenie" (se folosesc pentru stergerea fisierelor intermediare si/sau rezultate)

.PHONY: 
	clean
clean:
	rm -f fsminishell
	rm -f *.out
