#include <iostream>
#include "clsMyString.h"
using namespace std;

int main()
{
    cout << "\n\n\t\t\t\t\t\t Undo/Redo Project\n\n";

    clsMyString S1;

    cout << "\nS1 = " << S1.Value() << endl; //

    S1.SetValue("Mohammed1");

    cout << "S1 = " << S1.Value() << endl;

    S1.SetValue("Mohammed2");

    cout << "S1 = " << S1.Value() << endl;

    S1.SetValue("Mohammed3");

    cout << "S1 = " << S1.Value() << endl;

    cout << "\n\nUndo: ";
    cout << "\n-----------\n";

    S1.Undo();
    cout << "\nS1 after Undo = " << S1.Value() << endl;

    S1.Undo();
    cout << "\nS1 after Undo = " << S1.Value() << endl;

    S1.Undo();
    cout << "\nS1 after Undo = " << S1.Value() << endl;

    cout << "\n\nRedo: ";
    cout << "\n-----------\n";

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value() << endl;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value() << endl;

    S1.Redo();
    cout << "\nS1 after Redo = " << S1.Value() << endl;
}