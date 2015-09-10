CPP=g++
CPPFLAGS=-std=c++11
EXE_NAME=lab3

$(EXE_NAME): main.cpp neuron.h neuron.cpp net.h net.cpp
	$(CPP) -o $(EXE_NAME) main.cpp neuron.cpp net.cpp $(CPPFLAGS)

run_threshold:
	@./$(EXE_NAME) -t

run_linear:
	@./$(EXE_NAME) -l

clean:
	rm -f *.o $(EXE_NAME)
