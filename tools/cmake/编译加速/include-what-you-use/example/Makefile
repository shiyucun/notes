CXX=/usr/bin/g++

TARGET = example
OBJS = example.o

$(TARGET) : $(OBJS)
	@rm -rf $(TARGET)
	@$(CXX) $(OBJS) -o $@ 

clean:
	@rm -rf $(TARGET) $(OBJS)

.PHONY: clean