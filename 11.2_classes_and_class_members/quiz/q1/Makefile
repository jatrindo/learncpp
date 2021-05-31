CFILES = $(wildcard *.cpp)
OBJFILES = $(CFILES:.cpp=.o)
OUT = program
CC = g++
CPPFLAGS = -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++17 -g

$(OUT): $(OBJFILES)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJFILES) $(OUT)

