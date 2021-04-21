CFILES = $(wildcard *.cpp)
OBJFILES = $(CFILES:.cpp=.o)
OUT = add_subt
CC = g++
CPPFLAGS = -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++17

$(OUT): $(OBJFILES)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJFILES) $(OUT)

