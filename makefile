default:
	gcc -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c netflix.c functions.c StringWrap.c mapElem.c mapArrayList.c
debug:
	gcc -g -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c netflix.c functions.c StringWrap.c mapElem.c mapArrayList.c
clean:
	rm -f prog