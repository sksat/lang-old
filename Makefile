TARGET	= test
OBJS	= main.o

%.o:%.c
	gcc -c $< $(CFLAGS)

$(TARGET):$(OBJS)
	gcc -o $@ $^ $(LDFLAGS)

run:$(TARGET)
	./$<
	
