//Implementation of the artificial neural network described in the lab spec.
//The network consists of a single neuron with a linear activation function.
//This class also contains the training data given. This training data is used to 
//train the neuron to produce the correct output. Output is correct to within ~0.0001
//This slight "inaccuracy" is due to the floating point inaccuracy.

#include <vector>

#include "neuron.h"
#include "net.h"

using namespace std;

//training data to be used to train the ANN
vector<vector<float>> training_data = {
		{1, -1, 1, -1},
		{1, 1, 1, 1},
		{1, 1, 1, -1},
		{1, -1, -1, 1}
};
vector<float> targets = {1, 1, -1, -1};

//constructor trains the net appropriately
Net::Net(bool use_threshold): output_neuron(4, use_threshold) {
	output_neuron.train(100000, 0.01, training_data, targets);
}

//gets the result of passing the inputs in x through the network
float Net::output(vector<float> x){
	float out = output_neuron.output(x);
	return out;
}
