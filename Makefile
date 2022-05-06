CC = gcc
CC_OPT = -g3 -fsanitize=address -Wall -Wextra -Werror

OUTPUT = my_mastermind

all: ${OUTPUT}

${OUTPUT}: my_mastermind.o get_opt.o helper.o
	${CC} ${CC_OPT} my_mastermind.o get_opt.o helper.o -o ${OUTPUT}

my_mastermind.o: my_mastermind.c
	${CC} ${CC_OPT} -c my_mastermind.c

get_opt.o: get_opt.c
	${CC} ${CC_OPT} -c get_opt.c

helper.o: helper.c
	${CC} ${CC_OPT} -c helper.c

clean:
	rm *.o ${OUTPUT}