#include <iostream>
#include <vector>
#include <string>

#include "neuron.h"
#include "net.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Please specify linear (-l) or threshold (-t) activation function to be used." << endl;
		return -1;
	}

	bool use_threshold;
	if(string(argv[1]) == "-t"){
		use_threshold = true;
	}else if (string(argv[1]) == "-l"){
		use_threshold = false;
	}else{
		cout << "invalid argument." << endl;
		return -1;
	}
	Net net(use_threshold);

	cout << "Test the artificial neural network by inputting the float values when prompted." << endl;
	cout << "___Press ctrl-c to quit.___" << endl;

	while(true){		
		vector<float> inputs;
		
		for(int i = 0; i < 4; i++){
			cout << "Enter value" << i << " (e.g. 1.1):" << endl;
			string temp;
			getline(cin, temp);
			inputs.push_back(stof(temp));
		}

		float result = net.output(inputs);
		cout << "output=" << result << endl;
		cout << "====================" << endl << endl;

	}

	return 0;
}
