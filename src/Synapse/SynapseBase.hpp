#pragma once
#include "Common.hpp"

class NeuronBase;

class SynapseBase
{
public:
    SynapseBase(NeuronBase* output_neuron, signal_t initial_weight = 1.0);
    virtual ~SynapseBase();

    void SetWeight(signal_t weight);
    void ProcessSignal(signal_t signal);
    virtual void PostSynapticCallback(signal_t signal);
    virtual void PreSynapticCallback(signal_t signal);

private:
    NeuronBase* m_output_neuron;
    signal_t m_weight;
};