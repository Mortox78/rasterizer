MAKEFLAGS+=--no-builtin-rules --no-builtin-variables

CXXFLAGS=-O3 -Wall -MMD -Wno-unused-function -fopenmp -no-pie -pg
CXXFLAGS+=-Iinclude -Iinclude/inlVec
CXX=g++

LSDLIBS=-lSDL2 -lSDL2_image
LDLIBS=-Llib -lm $(LSDLIBS) -fopenmp -no-pie -pg
SRCXXS=$(wildcard src/*.cpp) 
OBJS=$(SRCXXS:.cpp=.o)
DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: rasterizer

-include $(DEPS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

rasterizer: $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^ $(LDLIBS)

clean:
	rm -f $(OBJS) $(DEPS) rasterizer

cmpl:
	make clean && make -j

perf:
	gprof ./rasterizer gmon.out > perf.txt

run:
	./rasterizer

