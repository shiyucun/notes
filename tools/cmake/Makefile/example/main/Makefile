
sources = $(wildcard *.c)
objs = $(patsubst %.c, %.o, $(sources))

target := main
libs   := -lnode1 -lnode2

.PHONY: ALL $(target) $(objs) install uninstall clean

ALL: $(target)

$(target): $(objs)
  # 链接库要放在最后面
	$(CC) $(LDFLAGS) $(objs) -o $(target) $(libs)

$(objs): $(sources)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(objs) $(target)

install:
	$(MK) $(BUILD_DIR)/bin
	$(CP) $(target) $(BUILD_DIR)/bin

uninstall:
	$(RM) $(BUILD_DIR)/bin/$(target)
