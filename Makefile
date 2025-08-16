CC = g++
CFLAGS = -Wall -g -std=c++17 
DEPFLAGS = -MMD
LDFLAGS = 
TARGET = eGrep

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))

.PHONY: all clean re
re:clean all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(TARGET) $(DEPS)