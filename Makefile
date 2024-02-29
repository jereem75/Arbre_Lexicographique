CC = gcc
CFLAGS = -Wall -std=c17
TOUT = dessine.o ABR.o filtrage.o
FICHIERS = en_commun.dot en_commun.pdf filtrage.dot filtrage.pdf texte.dot texte.pdf filtre.dot filtre.pdf

filtre: $(TOUT)
	$(CC) $(CFLAGS) -o filtre $(TOUT) $(LDLIBS)

dessine.o: dessine.c dessine.h
	$(CC) $(CFLAGS) -c -o $@ $<

ABR.o: ABR.c ABR.h
	$(CC) $(CFLAGS) -c -o $@ $<

filtrage.o: filtrage.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm -rf $(TOUT) filtre $(FICHIERS)
