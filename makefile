default:
	gcc -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c netflix.c functions.c
debug:
	gcc -g -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c netflix.c functions.c
clean:
	rm -f prog