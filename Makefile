CC = g++
PROJECT = "Face Detector"
SRC = main.cpp FaceDetector.cpp FaceBorders.cpp

# Use pkg-config to get the correct compiler and linker flags
CFLAGS = $(shell pkg-config --cflags opencv4) -I/usr/include/opencv4
LIBS = $(shell pkg-config --libs opencv4)

# Target rule to build the project
$(PROJECT) : $(SRC)
	$(CC) -o $(PROJECT) $(SRC) $(CFLAGS) $(LIBS)

# Clean rule to remove build artifacts
clean:
	rm -f $(PROJECT)
