TARGET	= test.exe
OBJS	= main.o

SRC	= test.src

%.o:%.c
	gcc -c $< $(CFLAGS)

$(TARGET):$(OBJS)
	gcc -o $@ $^ $(LDFLAGS)

run:$(TARGET)
	./$< $(SRC)
	
