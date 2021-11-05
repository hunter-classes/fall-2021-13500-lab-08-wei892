main: main.o imageio.o invert.o
	g++ -o main main.o imageio.o invert.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

invert.o: invert.cpp invert.h


clean:
	rm -f main.o sample.o imageio.o invert.o
