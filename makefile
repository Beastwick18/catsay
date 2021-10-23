ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

bin/catsay: src/catsay.cpp bin/catfetch
	g++ -o bin/catsay src/catsay.cpp

bin/catfetch: src/catfetch.cpp
	g++ -o bin/catfetch src/catfetch.cpp

.PHONY: install clean
clean:
	rm -f bin/catsay
	rm -f bin/catfetch

install: bin/catsay bin/catfetch
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 ./bin/catsay $(DESTDIR)$(PREFIX)/bin/
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 ./bin/catfetch $(DESTDIR)$(PREFIX)/bin/

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/catsay
	rm -f $(DESTDIR)$(PREFIX)/bin/catfetch
