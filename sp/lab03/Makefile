TARGET=shell

$(TARGET): fig3_5.o error.o
	$(CC) -o $@ $^ 

fig13_5.o: fig3_5.c
error.o: error.c

clean:
	rm -f fig3_5.o error.o $(TARGET)
