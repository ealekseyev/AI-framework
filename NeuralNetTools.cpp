#pragma once
#include <ctime>
#define E_CONST 2.781828

// returns a value between +/- 6.0
static inline double sigmoid_random() {
  return (double)(((rand() % 120) - 60) / 10.0);
}

static inline int max(int x, int y, int z) {
  return (x > y ? x : y) > z ? (x > y ? x : y) : z;
}
static inline int max(int x, int y) {
  return x > y ? x : y;
}

// basically a weighted connection + pointer to a couple perceptrons
// the perceptrons must be void pointers because we have not yet
// defined what a perceptron is
struct SSynapseVector {
  void* startpoint;
  void* endpoint;
  double weight;
};
typedef struct SSynapseVector SynapseVector;


class Perceptron {
private:
  double value;
  double threshold;
public:
  static double sigmoid(double input) {
    return (double) 1.0 / (1.0 + pow(E_CONST, input*(-1)));
  }

  double getValue() {
    return this->value;
  }

  void setValue(double value) {
    this->value = value;
  }

  double getThreshold() {
    return this->threshold;
  }

  void setThreshold(double threshold) {
    this->threshold = threshold;
  }

  double calculateValue(SynapseVector* inputs, int inputcount) {
    double result = 0.0;
    for(int i = 0; i < inputcount; i++) {
      result += ((Perceptron*)inputs[i].startpoint)->getValue() * inputs[i].weight;
    } // sums the weights multipled by the perceptron inputs
    return Perceptron::sigmoid(result - threshold); // return the sigmoid; as the network learns this will be closer to 0
  }
};

// blueprint of a highly structured neural network
template<int inputcount, int hiddencount, int outputcount>
class Structured3LNeuralNetwork {
protected:
  Perceptron input_neurons[inputcount];
  Perceptron hidden_neurons[hiddencount];
  Perceptron output_neurons[outputcount];

  SynapseVector input_to_hidden[inputcount][hiddencount];
  SynapseVector hidden_to_output[hiddencount][outputcount];

  void initSynapsesAndPerceptrons() {
    srand(time(NULL)); // init the random seed
    /// connect the synapses
    // selects the input perceptron
    for(int inputid = 0; inputid< inputcount; inputid++) {
      // connects the selected input perceptron to each hidden perceptron
      for(int hiddenid = 0; hiddenid < hiddencount; hiddenid++) {
        input_to_hidden[inputid][hiddenid].weight = sigmoid_random() / 6.0; // +/- 1.0
        input_to_hidden[inputid][hiddenid].startpoint = (void*) &(input_neurons[inputid]);
        input_to_hidden[inputid][hiddenid].endpoint = (void*) &(hidden_neurons[hiddenid]);
      }
    }
    // selects the hidden perceptron
    for(int hiddenid = 0; hiddenid < hiddencount; hiddenid++) {
      // connects the selected hidden perceptron to each output perceptron
      for(int outputid = 0; outputid < outputcount; outputid++) {
        hidden_to_output[hiddenid][outputid].weight = sigmoid_random() / 6.0; // +/- 1.0
        hidden_to_output[hiddenid][outputid].startpoint = (void*) &(hidden_neurons[hiddenid]);
        hidden_to_output[hiddenid][outputid].endpoint = (void*) &(output_neurons[outputid]);
      }
    }

    /// init the perceptrons
    // more time efficient than three separate fors
    for(int i = 0; i < max(hiddencount, outputcount); i++) {
      // don't init the thresholds; they are already 0
      // also don't init the input values; we set them later
      //if(i < inputcount)
      //  input_neurons[i].setValue(sigmoid_random())
      if(i < hiddencount)
        hidden_neurons[i].setValue(sigmoid_random());
      if(i < outputcount)
        output_neurons[i].setValue(sigmoid_random());
    }
  }

public:
  virtual bool backpropogate() {
    return false;
  }

  virtual bool feedforward() {
    return false;
  }
  void setInputs(double* inputVals) {
    for(int i = 0; i < inputcount; i++)
      input_neurons[i].value = inputVals[i];
  }

  void init() {
    initSynapsesAndPerceptrons();
  }
};
