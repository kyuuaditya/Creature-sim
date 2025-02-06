all: compile link run

compile:
	g++ -I"C:\SFML-2.6.2\include" -I"C:\SFML-2.6.2\include" -c main.cpp -o main.o
	g++ -I"C:\SFML-2.6.2\include" -I"C:\SFML-2.6.2\include" -c textures.cpp -o textures.o

link: 
	g++ -I"C:\SFML-2.6.2\include" .\main.o .\textures.o -o main.exe -L"C:\SFML-2.6.2\lib" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main 

run:
	./main.exe