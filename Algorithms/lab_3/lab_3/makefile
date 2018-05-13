CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic
OBJS :=

ifeq ($(mode), DEBUG)
	CFLAGS += -g3 -ggdb
endif

ifeq ($(mode), RELEASE)
	CFLAGS += -g0
endif

all : app.exe

app.exe : $(OBJS) main.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c %.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) *.o *.exe
