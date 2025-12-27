CFLAGS := -g -std=c23 -Wall -O3
exec = $(patsubst %.c,%,$(c))
run: $(exec)
	./$(exec)

debug: $(exec)
	gdb ./$(exec)

%: %.c
	${CC} ${CFLAGS} $< -o $@

