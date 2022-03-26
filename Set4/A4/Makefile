TARGET = A4
SRC_FILES = main.cpp array_functions.cpp obj_functions.cpp

CXX = g++
CFLAGS = -Wall -g

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

#DEPENDENCIES
obj_functions.o: obj_functions.h obj_functions.cpp
array_functions.o: array_functions.h array_functions.cpp
main.o: array_functions.h obj_functions.h main.cpp