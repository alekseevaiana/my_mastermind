CC = gcc
CC_OPT = -g3 -fsanitize=address -Wall -Wextra -Werror

OUTPUT = my_mastermind

all: ${OUTPUT}

${OUTPUT}: *.o
	${CC} ${CC_OPT} *.o -o ${OUTPUT}

*.o: *.c
	${CC} ${CC_OPT} -c *.c

clean:
	rm *.o ${OUTPUT}