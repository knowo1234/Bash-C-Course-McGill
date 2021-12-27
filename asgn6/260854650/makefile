CC = gcc
CFLAGS = -Wall 
OBJFILES = utils.o polyapp.o poly.o
TARGET = polyapp

all: $(TARGET)

$(TARGET):$(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
