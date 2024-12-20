.PHONY:all
all:myexec mycpp

myexec:myexec.c
	gcc -o $@ $^

mycpp:mycpp.cpp
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -f myexec mycpp
