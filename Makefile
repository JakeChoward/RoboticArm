RoboticArm: RoboticArm.o WiimoteBtns.o main.o 
	g++ RoboticArm.o WiimoteBtns.o main.o -o RoboticArm

RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -c RoboticArm.cpp -o RoboticArm.o
 
WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
	g++ -c WiimoteBtns.cpp -o WiimoteBtns.o

  
main.o: main.cpp RoboticArm.h WiimoteBtns.h
	g++ -c  main.cpp -o main.o
 
clear:
	rm RoboticArm RoboticArm.o main.o 