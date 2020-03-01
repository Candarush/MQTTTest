output: main.o 
	g++ -Wdeprecated-declarations  -o output main.o -L"C:\Program Files\mosquitto\devel" -lmosquittopp
main.o:
	g++ -I"C:\Program Files\mosquitto\devel" -c main.cpp
