
headers = $(wildcard *.h)
sources = $(wildcard *.c)
objs = $(patsubst %.c, %.o, $(sources))

target = libnode1.a

.PHONY: ALL ${target} ${objs} install uninstall clean

ALL: $(target)

$(target): $(objs)
	$(AR) $(target) $(objs)

$(objs): $(sources)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(objs) $(target)

install:
	$(MK) $(BUILD_DIR)/lib
	$(MK) $(BUILD_DIR)/include
	$(CP) $(target) $(BUILD_DIR)/lib
	$(CP) $(headers) $(BUILD_DIR)/include

uninstall:
	$(RM) $(BUILD_DIR)/lib/$(target)
	@for header in $(headers); do \
		$(RM) $(BUILD_DIR)/include/$$header; \
	done
