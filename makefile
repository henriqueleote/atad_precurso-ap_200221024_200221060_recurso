default:
	gcc -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c
debug:
	gcc -g -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c
clean:
	rm -f prog