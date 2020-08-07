#include <iostream>
#include "TestNeuronBase.hpp"

using namespace std;

int main()
{
    cout << "Creating TestNeuronBase." << endl;
    NeuronBase* nb = new TestNeuronBase();
    cout << "Deleting TestNeuronBase." << endl;
    delete nb;
    cout << "TestStatus: Passed." << endl;
    return 0;
}