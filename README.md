##Machine Learning: Lab 3 - Artificial Neural Networks

**Author** : Muhummad Yunus Patel  
**Student#** : PTLMUH006  
**Date**  : 11-September-2015

###Answer to Q1:
Using a linear activation, it takes 1980 iterations of the perceptron learning
rule to acieve an error of 0.

###Answer to Q2:
Using a threshold activation function, it takes only 5 iterations for an error
of 0 to be achieved. The threshold activation function, has only 2 discrete outputs whereas the linear activation function has a range of possible outputs.
The threshold functions learns quicker because there is more room for slack(e.g all sums between 0.0 and 0.5 will give a 1). The linear activation function will have to learn to sum up to exactly 1 whereas, for the same target output, the threshold function only needs to learn to sum up to between [0, 0.5].

 ###Usage:
 Please compile and then run as described below. All required source files including a makefile have been included.
 To compile: make
 To run with linear activation function: make run_linear
 To run with threshold activation function: make run_threshold