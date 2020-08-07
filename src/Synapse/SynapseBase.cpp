#include "SynapseBase.hpp"
#include "NeuronBase.hpp"

SynapseBase::SynapseBase(NeuronBase* output_neuron, signal_t initial_weight):
    m_output_neuron(output_neuron), m_weight(initial_weight)
{
}

SynapseBase::~SynapseBase()
{
}

void SynapseBase::SetWeight(signal_t weight)
{
    m_weight = weight;
}

void SynapseBase::ProcessSignal(signal_t signal)
{
    //signal_t output = signal * m_weight;
    //m_output_neuron->ComputeOutput(output, )
}

void SynapseBase::PostSynapticCallback(signal_t signal)
{
}

void SynapseBase::PreSynapticCallback(signal_t signal)
{
}
