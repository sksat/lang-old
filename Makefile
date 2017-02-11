TARGET	= lang.exe
OBJS	= main.o strtols.o

#SRC	= test.src

%.o:%.c
	gcc -c $< $(CFLAGS)

all:
	make $(TARGET)

$(TARGET):$(OBJS)
	gcc -o $@ $^ $(LDFLAGS)

run:$(TARGET)
	./$< $(SRC)

clean:
	rm *.exe *.o	
