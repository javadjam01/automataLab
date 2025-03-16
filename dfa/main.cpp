#include <iostream>
using namespace std;

int main()
{
    int nOStates, nOAlphabets;
    cin >> nOStates;
    cin >> nOAlphabets;
    char alphabets[nOAlphabets];
    for (int i = 0; i < nOAlphabets; i++)
    {
        cin >> alphabets[i];
    }
    int nOFinalStates;
    cin >> nOFinalStates;
    int finalstates[nOFinalStates];
    for (int i = 0; i < nOFinalStates; i++)
    {
        cin >> finalstates[i];
    }

    int nOTransitions = nOStates * nOAlphabets;
    struct transition
    {
        int homeState;
        char arc;
        int nextState;
    };
    transition transitions[nOTransitions];
    for (int i = 0; i < nOTransitions; i++)
    {
        cin >> transitions[i].homeState;
        cin >> transitions[i].arc;
        cin >> transitions[i].nextState;
    }
    int nOStrings;
    cin >> nOStrings;
    string strings[nOStrings];
    for (int i = 0; i < nOStrings; i++)
    {
        cin >> strings[i];
    }
    for (int i = 0; i < nOStrings; i++)
    {
        int currentState = 0;
        for (int j = 0; j < strings[i].length(); j++)
        {
            char currentChar = strings[i][j];
            for (int k = 0; k < nOTransitions; k++)
            {
                if (transitions[k].homeState == currentState && transitions[k].arc == currentChar)
                {
                    currentState = transitions[k].nextState;
                    break;
                }
            }
        }
        bool isFinal = false;
        for (int j = 0; j < nOFinalStates; j++)
        {
            if (currentState == finalstates[j])
            {
                isFinal = true;
                break;
            }
        }
        if (isFinal)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}