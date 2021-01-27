all: Data.o Horario.o Agenda.o TestaAgenda.o 
	g++ -g -o a Data.o Horario.o Agenda.o main.o 

Horario.o: Horario.h Horario.cpp 
	g++ -g -c Horario.h Horario.cpp

Data.o: Data.h Data.cpp 
	g++ -g -c Data.h Data.cpp

Agenda.o: Agenda.h Agenda.cpp 
	g++ -g -c Agenda.h Agenda.cpp 

main.o: main.cpp
	g++ -g -c main.cpp 