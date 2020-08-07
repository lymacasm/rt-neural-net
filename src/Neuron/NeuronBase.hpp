#pragma once
#include <cstdint>
#include <list>
#include <map>
#include <mutex>
#include <future>
#include "SynapseBase.hpp"
#include "Common.hpp"
#include "RtNeuralNetsOptions.hpp"

class NeuronBase
{
public:
    NeuronBase();
    virtual ~NeuronBase();

    void AddInputSynapse(SynapseBase* synapse);
    void AddOutputSynapse(SynapseBase* synapse);
    void ProcessIncomingSignal(signal_t signal);

protected:
    // Activation function. Returns true if a spike is triggered in the case of STDP
    virtual bool ActivationFunction(signal_t& result) = 0;

private:
    void CleanUpThread();
    void SignalingThread(signal_t activation_signal);

#if USE_POST_SYNAPTIC_CB
    std::list<SynapseBase*> m_input_synapses;
#endif // USE_POST_SYNAPTIC_CB
    std::list<SynapseBase*> m_output_synapses;
    std::thread m_clean_up_thread;
    std::list<std::future<void>> m_thread_list;
    std::mutex m_thread_list_mutex;
    bool m_kill_neuron;
};
