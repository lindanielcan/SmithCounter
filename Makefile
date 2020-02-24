smith: smith.o smithcounter.o branchtracker.o
	g++ -o smith smith.o smithcounter.o branchtracker.o

smithcounter.o: smithcounter.cc smithcounter.h
	g++  -c smithcounter.cc -o smithcounter.o

branchtracker.o: branchtracker.cc branchtracker.h
	g++ -c branchtracker.cc -o branchtracker.o

smith.o: smith.cc smithcounter.h branchtracker.h
	g++ -c smith.cc -o smith.o


clean:
	rm -f smith smith.o smithcounter.o branchtracker.o
