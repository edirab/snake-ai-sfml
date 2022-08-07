#include "NeuralNet.h"

NeuralNet::NeuralNet(int nHiddenLayers, int nNeurons, int nInputs, int nOutputs)
	: hidden1(nInputs, nNeurons), hidden2(nNeurons, nNeurons), out(nNeurons, 4)
{
	hidden1.randomize();
	hidden2.randomize();
	out.randomize();

	//hidden1.print();
	//hidden2.print();
	//out.print();
}

NeuralNet::NeuralNet(const Layer& hidden1, const Layer& hidden2, const Layer& out ) 
	: hidden1(hidden1), hidden2(hidden1), out(out)
{

}

NeuralNet::NeuralNet(const NeuralNet &net)
	: hidden1(net.hidden1), hidden2(net.hidden1), out(net.out)
{

}

vector<double> NeuralNet::pass(vector<int>& inputs)
{
	//cout << "\tNet forward: \n";
	Matrix m_inputs(inputs);
	//m_inputs.print();

	//cout << "output of hidden 1:\n";
	Matrix out_1 = hidden1.process( *m_inputs.get_mat() );
	//out_1.print();

	//cout << "output of hidden 2:\n";
	Matrix out_2 = hidden2.process( *out_1.get_mat() );
	//out_2.print();

	//cout << "output of net itself:\n";
	Matrix output = out.process( *out_2.get_mat() );
	//output.print();

	return output.to_vector();
}

NeuralNet& NeuralNet::crossover(const NeuralNet& parent)
{
	Matrix w1_new = this->hidden1.get_weights().crossover( parent.hidden1.get_weights() );
	Matrix b1_new = this->hidden1.get_biases().crossover( parent.hidden1.get_biases() );
	w1_new.mutate(mutation_rate);
	b1_new.mutate(mutation_rate);

	Layer hidden_1_new(w1_new, b1_new);

	Matrix w2_new = this->hidden2.get_weights().crossover( parent.hidden2.get_weights() );
	Matrix b2_new = this->hidden2.get_biases().crossover( parent.hidden2.get_biases() );
	w2_new.mutate(mutation_rate);
	b2_new.mutate(mutation_rate);
	Layer hidden_2_new(w2_new, b2_new);

	Matrix w3_new = this->out.get_weights().crossover( parent.out.get_weights() );
	Matrix b3_new = this->out.get_biases().crossover( parent.out.get_biases() );
	w3_new.mutate(mutation_rate);
	b3_new.mutate(mutation_rate);
	Layer out_new(w3_new, b3_new);

	NeuralNet n(hidden_1_new, hidden_2_new, out_new);
	return n;
}
