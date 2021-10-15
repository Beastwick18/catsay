bin/catsay: src/catsay.cpp bin/catfetch
	g++ -o bin/catsay src/catsay.cpp

bin/catfetch: src/catfetch.cpp
	g++ -o bin/catfetch src/catfetch.cpp