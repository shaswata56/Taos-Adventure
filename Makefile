LIBS=-lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system

all:
	@echo "** Building the game"
	g++ -c "Source/Taos-Adventure.cpp" -o Taos-Adventure.o
	g++ -o Taos-Adventure Taos-Adventure.o $(LIBS)
	rm Taos-Adventure.o
clean:
	@echo "** Removing object files and executable..."
	rm -f Taos-Adventure

install:
	@echo '** Installing...'
	sudo cp Taos-Adventure /usr/bin
	sudo cp -r Resource /usr/bin
uninstall:
	@echo '** Uninstalling...'
	sudo rm /usr/bin/Taos-Adventure
	sudo rm -rf /usr/bin/Resource
