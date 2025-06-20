all: clean build

build:
	qmake -o Makefile.qmake Project.pro
	make -f Makefile.qmake

clean:
	rm -rf mqtt-explorer *.o ui_* moc_* qrc_*.cpp Makefile.qmake .qmake.stash

run: all
	./mqtt-explorer
