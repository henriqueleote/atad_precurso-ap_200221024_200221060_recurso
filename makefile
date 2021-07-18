default:
	gcc -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c netflix.c stringWrap.c mapElem.c mapArrayList.c search.c import.c agregation.c auxiliarFuncs.c
debug:
	gcc -g -o prog main.c date.c input.c stringutils.c listArrayList.c listElem.c netflix.c stringWrap.c mapElem.c mapArrayList.c search.c import.c agregation.c auxiliarFuncs.c
clean:
	rm -f prog