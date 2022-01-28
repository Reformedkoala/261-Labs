TARGET = A1
SRC_FILES = main.cpp
CXX = g++
CFLAGS = -Wall
OBJECTS = $(SRC_FILES:.cpp=.o)


$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -g -o $@ -c $<
