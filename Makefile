obj:=$(patsubst %.c,%.o,$(wildcard *.c))
final.exe:$(obj)
	gcc -o $@ $^
clean:
	rm *.exe *.o
