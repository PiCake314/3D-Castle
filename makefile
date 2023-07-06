EXE=final

# Main target
all: $(EXE)

#  Msys/MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall -DUSEGLEW
LIBS=-lfreeglut -lglew32 -lglu32 -lopengl32 -lm
CLEAN=rm -f *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
RES=$(shell uname -r|sed -E 's/(.).*/\1/'|tr 12 21)
CFLG=-O3 -Wall -Wno-deprecated-declarations -DRES=$(RES) -std=c++20
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a
endif

# Dependencies
final.o: final.cpp CSCIx229.h input-handler.hpp shapes.hpp
fatal.o: fatal.cpp CSCIx229.h
errcheck.o: errcheck.cpp CSCIx229.h
print.o: print.cpp CSCIx229.h
loadtexbmp.o: loadtexbmp.cpp CSCIx229.h
loadobj.o: loadobj.cpp CSCIx229.h
projection.o: projection.cpp CSCIx229.h

#  Create archive
CSCIx229.a:fatal.o errcheck.o print.o loadtexbmp.o loadobj.o projection.o
	ar -rcs $@ $^

# Compile rules
.c.o:
	gcc -c $(CFLG)  $<
.cpp.o:
	g++ -c $(CFLG)  $<

#  Link
final:final.o   CSCIx229.a
	g++ $(CFLG) -o $@ $^  $(LIBS)


run:
	make; ./final

#  Clean
clean:
	$(CLEAN)
