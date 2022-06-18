CC=gcc
CFLAGS=-std=c89 -pedantic -Wall -Werror -g `pkg-config libxml-2.0 --cflags`

LDFLAGS=`pkg-config libxml-2.0 --libs-only-L`
LDLIBS=`pkg-config libxml-2.0 --libs-only-l`
RM=rm -fv
all: smm.out
mission.o: mission.c mission.h
	$(CC) $(CFLAGS) -c -o mission.o mission.c
soldier.o: soldier.c soldier.h
	$(CC) $(CFLAGS) -c -o soldier.o soldier.c
smm.out: smm.c mission.o soldier.o
	$(CC) $(CFLAGS) -o smm.out smm.c mission.o soldier.o $(LDFLAGS) $(LDLIBS)
clean:
	$(RM) *.o *.out
