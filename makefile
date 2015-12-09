PrimeThreads:  LabAssignment2.o PrimesMath.o
	g++ LabAssignment2.o PrimesMath.o -pthread -o PrimeThreads

LabAssignment2.o: cPrimesMath LabAssignment2.cpp
	g++ -c LabAssignment2.cpp -fpermissive

PrimesMath.o: cPrimesMath PrimesMath.cpp
	g++ -c PrimesMath.cpp -fpermissive

clean:
	rm *.o PrimeThreads
