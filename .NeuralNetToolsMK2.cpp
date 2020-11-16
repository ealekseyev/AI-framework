#pragma once
#include <vector>

/// Basic perceptron
/*
class BasePerceptron {
private:
  friend class Perceptron;
public:
  double value;

  BasePerceptron() {

  }
  ~BasePerceptron() {

  }

};

/// Smart perceptron w/ input synapses

template<int startpointc>
class Perceptron: public BasePerceptron {
private:
  // these are the synapses
  BasePerceptron startpoints[startpointc];

public:

  Perceptron(BasePerceptron* startpoints) {
    this->startpoints = startpoints;
  }
  ~Perceptron() {

  }
};

template<int pcount>
class NeuralLayer {
private:
  BasePerceptron perceptrons[pcount];
  // add the pcount dynamic variable
public:
  NeuralLayer(BasePerceptron* perceptrons) {
    this->perceptrons = perceptrons;
  }
};

template<int hiddenLayerc>
class NeuralNetwork {
protected:
  NeuralLayer* inputLayer;                // smart pointer; efficiency
  NeuralLayer hiddenLayers[hiddenLayerc];
  NeuralLayer* outputLayer;
public:
  NeuralNetwork() {

  }
  ~NeuralLayer() {

  }

  virtual void setInputs();
  virtual void layerFeedForward();
  virtual void backPropogate();
};*/
