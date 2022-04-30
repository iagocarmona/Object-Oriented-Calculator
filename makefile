all:
	g++ -g -c IagoCalculator/Calculator/IagoCalculator.cpp
	g++ -g -c IagoCalculator/CPU/IagoCpu.cpp
	g++ -g -c IagoCalculator/Display/IagoDisplay.cpp
	g++ -g -c IagoCalculator/Keyboard/IagoKeyboard.cpp
	g++ -g -c interface.cpp
	g++ -g -c main.cpp
	g++ -o main *.o

clean:
	rm ./*.o
	rm main