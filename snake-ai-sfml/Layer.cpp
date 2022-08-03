#include "Layer.h"

Layer::Layer(int nInputs, int nNeurons)
{
	weights = new Matrix(nNeurons, nInputs);
	biases = new Matrix(nNeurons, 1);


}