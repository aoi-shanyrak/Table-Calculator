CXX := g++
CXX_STD := c++20

BASE_CXXFLAGS := -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wconversion \
            -Wnull-dereference -Wold-style-cast -Wduplicated-cond -Wduplicated-branches \
            -Wlogical-op -Wuseless-cast -Wdouble-promotion -Wno-unused-parameter \
            -Wno-unused-variable -Wno-unused-but-set-variable -Wno-sign-conversion

SANITIZERS := -fsanitize=address -fsanitize=undefined -fsanitize=leak
DEBUG := -g3 -O0

DEBUG_CXXFLAGS := -std=$(CXX_STD) $(BASE_CXXFLAGS) $(DEBUG) $(SANITIZERS)

RELEASE_FLAGS := -std=$(CXX_STD) -Wall -Wextra -Wpedantic -O3 -march=native -flto 

TARGET := calculator

SOURCES = $(wildcard ./*.cpp)

all: debug

debug: CXXFLAGS = $(DEBUG_CXXFLAGS)
debug: $(TARGET)

release: CXXFLAGS = $(RELEASE_FLAGS)
release: $(TARGET)

$(TARGET): 
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(TARGET)

rebuild: clean all

format:
	find . -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i

check-style:
	cppcheck --enable=all --suppress=missingIncludeSystem \
						--std=$(CXX_STD) $(shell find . -name "*.cpp")

.PHONY: all clean rebuild debug check-style $(PROJECTS)
