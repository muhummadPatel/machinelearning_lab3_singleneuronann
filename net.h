#include <vector>

#include "neuron.h"

#ifndef NET_H
#define NET_H

class Net{
	public:
		Neuron output_neuron;

		Net(bool use_threshold);
		void train();
		float output(std::vector<float> x);
};

#endif
