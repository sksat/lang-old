TARGET	= lang.exe
OBJS	= main.o

SRC	= test.src

%.o:%.c
	gcc -c $< $(CFLAGS)

all:
	make -C liblang
	make $(TARGET)

$(TARGET):$(OBJS)
	gcc -o $@ $^ $(LDFLAGS)

run:$(TARGET)
	./$< $(SRC)

clean:
	rm *.exe *.o	
