battleship: app/main.cpp
	g++ -std=c++17 -Wall app/main.cpp src/Board.cpp src/BoardGui.cpp -lsfml-graphics -lsfml-window -lsfml-system
