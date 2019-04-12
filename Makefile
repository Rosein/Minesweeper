battleship: app/main.cpp
	g++ -std=c++17 -Wall app/main.cpp src/ManagerAssets.cpp src/Game.cpp src/StateGame.cpp src/ManagerInput.cpp src/MachineOfStates.cpp src/Board.cpp src/Timer.cpp -lsfml-graphics -lsfml-window -lsfml-system
