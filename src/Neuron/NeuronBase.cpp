#include "NeuronBase.hpp"

using namespace std;

NeuronBase::NeuronBase() : 
    m_kill_neuron(false)
{
    m_clean_up_thread = thread(&NeuronBase::CleanUpThread, this);
}

NeuronBase::~NeuronBase()
{
    m_kill_neuron = true;
    m_clean_up_thread.join();
}

void NeuronBase::AddInputSynapse(SynapseBase* synapse)
{
#if USE_POST_SYNAPTIC_CB
    // Add synapse to list of input synapses
    m_input_synapses.push_back(synapse);
#endif
}

void NeuronBase::AddOutputSynapse(SynapseBase* synapse)
{
    // Add synapse to list of output synapses
    m_output_synapses.push_back(synapse);
}

void NeuronBase::ProcessIncomingSignal(signal_t signal)
{
    // Call activation function and see if this caused this neuron to fire
    signal_t activation_output;
    if (ActivationFunction(activation_output))
    {
        // Launch thread to notify all output synapses
        {
            lock_guard<mutex> thread_list_lock(m_thread_list_mutex);
            m_thread_list.push_back(async(launch::async, &NeuronBase::SignalingThread, this, activation_output));
        }

#if USE_POST_SYNAPTIC_CB
        // Notify all input synapses an event occurred
        for (list<SynapseBase*>::iterator itr = m_input_synapses.begin();
            itr != m_input_synapses.end(); itr++)
        {
            (*itr)->PostSynapticCallback(activation_output);
        }
#endif
    }
}

void NeuronBase::SignalingThread(signal_t activation_signal)
{
    list<SynapseBase*>::iterator itr = m_output_synapses.begin();
    while (!m_kill_neuron && itr != m_output_synapses.end())
    {
        (*itr)->ProcessSignal(activation_signal);
        itr++;
    }
}

void NeuronBase::CleanUpThread()
{
    while (!m_kill_neuron || m_thread_list.size() > 0)
    {

    }
}