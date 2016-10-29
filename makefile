
FLAGS=-O2 -flto -I.

CFLAGS=${FLAGS}
CXXFLAGS=${FLAGS}

VPATH=Vector:Matrix:BasicOperation

ALL=test
RUN=./test

all:${ALL}
clean:
	rm -rf *.o ${ALL}
run:all
	${RUN}

test:Vector.h Matrix.h BasicOperation.h
Vector.h:Vector.hpp
Matrix.h:Matrix.hpp
BasicOperation.h:BasicOperation.hpp
