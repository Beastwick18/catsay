bin/catsay: src/catsay.cpp
	g++ -o bin/catsay src/catsay.cpp

bin/catfetch: src/catfetch.cpp
	g++ -o bin/catfetch src/catfetch.cpp

<<<<<<< HEAD
.PHONY: install
=======
.PHONY install
>>>>>>> 3397010dff56122e65c889a9b58a53ea31d9eec2
install: bin/catsay bin/catfetch
	sudo cp ./bin/catsay /usr/bin/
	sudo cp ./bin/catfetch /usr/bin/
