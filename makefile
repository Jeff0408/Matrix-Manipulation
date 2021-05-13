all: matrix.out

#declare variables
CC = g++
INSTDIR = /usr/local/bin
INCLUDE = .
CFLAGS = -g -Wall -ansi
LIBS += -framework CoreFoundation


matrix.out: matrix.o main.o
	$(CC) -o matrix.out matrix.o main.o
matrix.o: matrix.cpp matrix.hpp
	$(CC) -c matrix.cpp
main.o: main.cpp matrix.hpp
	$(CC) -c main.cpp

clean:
	rm -f matrix.o main.o matrix.out 

install: matrix
	@if[   -d $(INSTDIR)   ]; \
	then   \
		cp matrix.out $(INSTDIR);\
		chmod a+x $$(INSTDIR)/matrix.out; \
		chmod og-w $(INSTDIR)/matrix.out; \
		echo "Installed in $(INSTDIR)"; \
	else \
		echo "Sorry, $(INSTDIR) dose not exist";\
	fi