#include <vector>

#ifndef NEURON_H
#define NEURON_H

class Neuron{
	public:
		int num_weights = 2;
		bool use_threshold; //true - use threshold act func; false - use linear act func
		std::vector<float> w; //weights 

		Neuron(int num, bool use_threshold);
		float output(std::vector<float> x);
		void train(int max_iterations, double eta, std::vector<std::vector<float>> trainingData, std::vector<float> targets);
};

#endif
