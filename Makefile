CC = g++
CFLAGS = -Wall -g -std=c++17 
DEPFLAGS = -MMD
LDFLAGS = 
TARGET = rabin_karp_app

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(patsubst %.cpp,%.d,$(SRCS))

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	del /Q $(OBJS) $(TARGET) $(DEPS)