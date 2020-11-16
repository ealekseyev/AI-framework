#include <iostream>
#include <chrono>
#include "./NeuralNetTools.cpp"

using std::vector;
using std::cout;
using std::endl;
//using namespace std::chrono;


// implementation of 3 layer structured neural network
template<int inputcount, int hiddencount, int outputcount>
class CustomStructured3LNeuralNetwork: public Structured3LNeuralNetwork<inputcount, hiddencount, outputcount> {
public:
  bool backpropogate() {// override {
      cout << "running backpropogate" << endl;
      return true;
  }
  bool feedforward() {// override {
    cout << "running feedforward" << endl;
    return true;
  }
};
// 784 inputs, one hidden layer of 100 nodes, and 26 outputs
CustomStructured3LNeuralNetwork<7840, 10000, 2060> network;

int main(int argc, char** argv) {
  cout << "Size of neural network object: " << sizeof network << "" << endl;
  unsigned long start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  network.init();
  unsigned long stop = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
  cout << "Took a total of " << (stop - start)/1000.0 << " seconds to run one round of feedforward in the neural network of size " << sizeof network << "B."<< endl;
}
