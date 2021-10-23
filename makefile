bin/catsay: src/catsay.cpp
	g++ -o bin/catsay src/catsay.cpp

bin/catfetch: src/catfetch.cpp
	g++ -o bin/catfetch src/catfetch.cpp

.PHONY: install
clean:
	rm -f bin/catsay
	rm -f bin/catfetch

install: bin/catsay bin/catfetch
	sudo cp ./bin/catsay /usr/bin/
	sudo cp ./bin/catfetch /usr/bin/
