// Mohammad Javad Jamshidian
#include <iostream>
using namespace std;

struct state
{
    int n;
    bool isFinal = false;
};

struct transition
{
    int homeState;
    char arc;
    int nextState;
};

char isDistinctive(state *states, transition *transitions, int nOTransitions, char **table, int s1, int s2)
{
    // checking if one of them is final and the other one is non-final
    if (states[s1].isFinal != states[s2].isFinal) {
        return 'x';
    }
    int s1By0, s1By1, s2By0, s2By1;
    // Finding transitions for s1 and s2
    for (int i = 0; i < nOTransitions; i++)
    {
        if (transitions[i].homeState == s1 && transitions[i].arc == '0')
        {
            s1By0 = transitions[i].nextState;
        }
        if (transitions[i].homeState == s1 && transitions[i].arc == '1')
        {
            s1By1 = transitions[i].nextState;
        }
        if (transitions[i].homeState == s2 && transitions[i].arc == '0')
        {
            s2By0 = transitions[i].nextState;
        }
        if (transitions[i].homeState == s2 && transitions[i].arc == '1')
        {
            s2By1 = transitions[i].nextState;
        }
    }
/*
    int s1By0 = transitions[s1 * 2].nextState;
    int s1By1 = transitions[s1 * 2 + 1].nextState;
    int s2By0 = transitions[s2 * 2].nextState;
    int s2By1 = transitions[s2 * 2 + 1].nextState;
*/
    if (states[s1By0].isFinal != states[s2By0].isFinal || states[s1By1].isFinal != states[s2By1].isFinal)
        return 'x';
    if (table[s1By0][s2By0] == 'x' || table[s1By1][s2By1] == 'x')
        return 'x';
    return '+';
}

int main()
{
    int nOStates;
    cin >> nOStates;
    state states[nOStates];
    for (int i = 0; i < nOStates; i++)
    {
        states[i].n = i;
    }
    int nOFinalStates;
    cin >> nOFinalStates;
    for (int i = 0; i < nOFinalStates; i++)
    {
        int finalState;
        cin >> finalState;
        states[finalState].isFinal = true;
    }
    int nOAlphabets = 2;
    int nOTransitions = nOStates * nOAlphabets;
    transition transitions[nOTransitions];
    for (int i = 0; i < nOTransitions; i++)
    {
        cin >> transitions[i].homeState;
        cin >> transitions[i].arc;
        cin >> transitions[i].nextState;
    }
    char **table = new char *[nOStates];
    for (int i = 0; i < nOStates; i++)
    {
        table[i] = new char[nOStates];
    }
    // initialization of table
    for (int i = 0; i < nOStates; i++)
    {
        for (int j = 0; j < nOStates; j++)
            table[i][j] = ' ';
    }
    // checking
    bool anyCrosses = true;
    while (anyCrosses)
    {
        anyCrosses = false;
        for (int i = 0; i < nOStates; i++)
        {
            for (int j = 0; j < nOStates; j++)
            {
                char check = isDistinctive(states, transitions, nOTransitions, table, i, j);
                if (check == 'x' && table[i][j] == ' ')
                    anyCrosses = true;
                table[i][j] = check;
            }
        }
    }
    // printing
    for (int i = 1; i < nOStates; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }
    // free allocated memmory
    for (int i = 0; i < nOStates; i++)
    {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}