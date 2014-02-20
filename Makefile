CC		= g++

TARGET	= game

$(TARGET):	Main.o Init.o Camera.o Input.o DrawShip.o 
	$(CC) -o $(TARGET) Main.o Init.o Camera.o Input.o DrawShip.o `sdl-config --libs` -lGL -lGLU -lm

Main.o:		Main.cpp main.h
	$(CC) -c Main.cpp `sdl-config --cflags`

Init.o:		Init.cpp main.h
	$(CC) -c Init.cpp `sdl-config --cflags`

Camera.o:	Camera.cpp camera.h main.h
	$(CC) -c Camera.cpp `sdl-config --cflags`

Input.o:	Input.cpp main.h
	$(CC) -c Input.cpp `sdl-config --cflags`

DrawShip.o:	DrawShip.cpp main.h
	$(CC) -c DrawShip.cpp `sdl-config --cflags`

clean:
	rm -f $(TARGET) Main.o Init.o Camera.o Input.o DrawShip.o core
