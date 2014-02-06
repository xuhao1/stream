stream:stream.o vector2f.o vector3f.o
	g++ -o stream stream.o vector3f.o vector2f.o
stream.o:stream.cpp stream.h
	g++ -c stream.cpp -g
vector2f.o:vector2f.cpp vector2f.h
	g++ -c vector2f.cpp -g
vector3f.o:vector3f.cpp vector3f.h
	g++ -c vector3f.cpp -g
.PHONY:run clean
clean:
	rm *.o
	rm stream
	rm data.txt
run:stream
	./stream
