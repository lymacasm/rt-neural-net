#include <iostream>
#include "SynapseBase.hpp"
#include "TestNeuronBase.hpp"

using namespace std;

int main()
{
    cout << "Creating TestNeuronBase." << endl;
    NeuronBase* nb = new TestNeuronBase();
    cout << "Creating SynapseBase." << endl;
    SynapseBase* sb = new SynapseBase(nb);

    cout << "Deleting SynapseBase." << endl;
    delete sb;
    cout << "Deleting TestNeuronBase." << endl;
    delete nb;
    cout << "TestStatus: Passed." << endl;
    
    return 0;
}