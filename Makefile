
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
EXEC = programme

SOURCES = main.c carre.c cercle.c ligne.c forme.c saisie.c affichage.c svg.c creation.c modification.c suppression.c visualisation.c

OBJETS = $(SOURCES:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJETS)
	$(CC) $(CFLAGS) $(OBJETS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJETS) $(EXEC)

.PHONY: all clean
