#pragma once
#include "NeuronBase.hpp"

class TestNeuronBase: public NeuronBase
{
public:
    ~TestNeuronBase() 
    {
    }
protected:
    bool ActivationFunction(signal_t& result)
    {
        return result > 0;
    }
};