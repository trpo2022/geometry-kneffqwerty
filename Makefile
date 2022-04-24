CC=gcc 
O=-o
CFLAGS=-Wall -Werror -c
SOURCE=src/geometry/
LIBSOURCE=src/libgeo/
INCLUDEPATHHH=-I thirdparty
INCLUDEPATHH=-I obj
INCLUDEPATH=-I src
all: bin/geometry clean
bin/geometry: obj/src/geometry/main.o obj/src/libgeo/lib.a
	$(CC) -o bin/geometry obj/src/geometry/main.o obj/src/libgeo/lib.a  -lm
obj/src/libgeo/lib.a: obj/src/libgeo/per_krug.o obj/src/libgeo/per_treug.o obj/src/libgeo/plosh_krug.o obj/src/libgeo/plosh_treug.o obj/src/libgeo/check.o
	ar rcs obj/src/libgeo/lib.a obj/src/libgeo/per_krug.o obj/src/libgeo/per_treug.o obj/src/libgeo/plosh_krug.o obj/src/libgeo/plosh_treug.o obj/src/libgeo/check.o
obj/src/geometry/main.o: 
	$(CC) -o obj/src/geometry/main.o $(CFLAGS) $(INCLUDEPATH) $(SOURCE)main.c
obj/src/libgeo/per_krug.o: 
	$(CC) -o obj/src/libgeo/per_krug.o $(CFLAGS) $(INCLUDEPATH) -lm $(LIBSOURCE)per_krug.c
obj/src/libgeo/per_treug.o: 
	$(CC) -o obj/src/libgeo/per_treug.o $(CFLAGS) $(INCLUDEPATH) -lm $(LIBSOURCE)per_treug.c
obj/src/libgeo/plosh_krug.o: 
	$(CC) -o obj/src/libgeo/plosh_krug.o $(CFLAGS) $(INCLUDEPATH) -lm $(LIBSOURCE)plosh_krug.c
obj/src/libgeo/plosh_treug.o: 
	$(CC) -o obj/src/libgeo/plosh_treug.o $(CFLAGS) $(INCLUDEPATH) -lm $(LIBSOURCE)plosh_treug.c
obj/src/libgeo/check.o: 
	$(CC) -o obj/src/libgeo/check.o $(CFLAGS) $(INCLUDEPATH) -lm $(LIBSOURCE)check.c
clean:
	rm -rf