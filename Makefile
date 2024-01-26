output: main.o System.o  
	g++ main.o System.o -o FRS.exe
	./FRS.exe

main.o: main.cc
	g++ -c main.cc

System.o: ./src/System.cc
	g++ -c ./src/System.cc

# Flight.o: ./src/Flight.cc
# 	g++ -c ./src/Flight.cc
#
# Passenger.o: ./src/Passenger.cc
# 	g++ -c ./src/Passenger.cc

clean : 
	rm -rf FRS.exe ./*.o


