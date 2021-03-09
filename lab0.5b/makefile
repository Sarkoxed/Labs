OPT = -O3

CFLAGS = -Wall
#CFLGAS += -Wfloat-equal
CFLAGS += -Wextra
CFLAGS += -pedantic

DEBUGFLAGS = -g

.PHONY: default
default: string_maker

lib.o: lib.h lib.c
	clang -c -Wall -fpic lib.c

libmain.so: lib.o lib.h
	clang -shared -o libmain.so lib.o

string_maker: main.c libmain.so lib.h
	clang -L. -Wl,-rpath=. $(CFLAGS) $(DEBUGFLAGS) $(OPT) -o string_maker.out main.c -lmain


.PHONY: sanitize
sanitize: *.c *.h
	@echo Running ASAN
	@$(CC) -fsanitize=address $(CFLAGS) *.c -o asan.out $(LIBS)
	@ASAN_OPTIONS=detect_leaks=1 ../../run_tests.sh asan.out
	@echo "ASAN passed"
	@echo Running MSAN
	@$(CC) -fsanitize=memory $(CFLAGS) src/*.c -o msan.out $(LIBS)
	@../../run_tests.sh msan.out
	@echo "MSAN passed"
	@$(CC) -fsanitize=undefined $(CFLAGS) src/*.c -o ubsan.out $(LIBS)
	@../../run_tests.sh ubsan.out
	@echo "UBSAN passed"


.PHONY: afl-build
afl-build:
	afl-gcc $(CFLAGS) *.c -o fuzz.out $(LIBS)


.PHONY: afl-start
afl-start: fuzz.out
	afl-fuzz -i fuzzing/in -o fuzzing/sync -M fuzz1 -- ./fuzz.out

.PHONY: clean
clean:
	-rm *.out
	-rm *.o
	-rm *.so

