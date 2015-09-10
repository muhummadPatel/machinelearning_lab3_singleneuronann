//Implements a single neuron to be used to build up the ANN.

#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "neuron.h"

using namespace std;

//constructor initialises all weights to 0
Neuron::Neuron(int num, bool use_t){
	num_weights = num;
	for(int i = 0; i < num_weights + 1; i++){
		w.push_back(0.0f);
	}

	use_threshold = use_t;
}

//Computes and returns the output of this Neuron using the linear activation function.
float Neuron::output(vector<float> x){
	float sum = w[0] * 1.0f;
	for(int i = 0; i < x.size(); i++){
		sum += w[i+1] * x[i];
	}

	//thresholding
	if(use_threshold){
		if(sum > 0.5){
			return 1;
		}else{
			return -1;
		}
	}else{
		return sum;
	}
}

//trains the Neuron using the given trainingData.
void Neuron::train(int max_iterations, double eta, vector<vector<float>> trainingData, vector<float> targets){
 	using namespace std;

	string filename = (use_threshold)? "threshold_training_log.txt": "linear_training_log.txt";
	fstream outfile;
	outfile.open(filename, fstream::out);

	float error = 0;
	int c = 0;

	outfile << filename << endl << "start training" << endl;
	outfile << "====================" << endl;

	do{
		outfile << "___iteration " << (c+1) << "___" << endl;

		error = 0;
		for(int i = 0; i < trainingData.size(); i++){ //for each training example
			outfile << "training example " << (i+1) << endl;

			vector<float> x = trainingData[i];
			vector<float> x_copy = x;
			float o = this->output(x);
			x.insert(x.begin(), 1.0f);
			float t = targets[i];

			outfile << "weights:" << endl;
			for(int j = 0; j < w.size(); j++){ //for each weight, adjust the weight according to the rule
				if(j>0){
					//dont output the bias
					outfile << "\t" << w[j];
				}

				float deltaW = eta * (t - o) * x[j];
				w[j] += deltaW;
			}
			outfile << endl;
			outfile << "output: " << o << endl;


			float adjusted_out = this->output(x_copy);
			error += ((t - adjusted_out) * (t - adjusted_out));
		}

		error = 0.5f * error;
		c++;

		outfile << "Error for this iteration: " << error << endl << endl;

	}while(error > 0.0000000001 && c < max_iterations);

	string activation_func = (use_threshold)? "threshold activation function": "linear activation function";
	cout << "Neuron (" << activation_func << ") trained in " << c << " iterations. (error = 0)" << endl;
}
