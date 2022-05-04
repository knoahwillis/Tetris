PNAME := Tetris

PCXXSRC := $(wildcard src/*.cpp)
PCXXSRC += $(wildcard src/BoardPieces/*.cpp)

PCXXOBJS := $(PCXXSRC:src/%.cpp=build/%.o)

CC := g++

CXXFLAGS += -std=c++17 -O2 -g
LDLIBS += -lSDL2
LDFLAGS +=

.PHONY: all make_build_dirs clean

all: make_build_dirs $(PCXXOBJS)
	$(CC) $(LDFLAGS) $(PCXXOBJS) -o $(PNAME) $(LDLIBS)

$(PCXXOBJS): build/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

make_build_dirs:
	mkdir -p build/
	mkdir -p build/BoardPieces

clean:
	$(RM) -r build/
	$(RM) $(PNAME)