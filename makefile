

bin/tui : src/tui_test.cpp	
	g++ src/tui_test.cpp -o bin/tui -I include -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a 

run : bin/tui
	./bin/tui
