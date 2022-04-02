#include <iostream>
#include <string.h>

using namespace std;

int nrNoduri, nrTrazitii, stareInitiala, nrStariFinale, nrStringuri, nod1, nod2, i, j, stariFinale[100];
char val, M[100][100], Strings[100][100], s[1000];

void parcurgere(int startNode, int posInS, bool &sirPrelucrabil, int vPos[], char s[])
{
    int j;

    if(posInS == strlen(s))
    {
        bool stareFinala = false;
        for(j = 1; j <= nrStariFinale; j++)
            if(stariFinale[j] == startNode)
            {
                stareFinala = true;
                break;
            }

        if(stareFinala == true)
            sirPrelucrabil = true;
        else
            sirPrelucrabil = false;
    }
    else
    {
        for(j = 0; j < nrNoduri; j++)
            if(M[startNode][j] == s[posInS])
            {
                vPos[posInS + 1] = j;
                parcurgere(j, posInS + 1, sirPrelucrabil, vPos, s);
                if(sirPrelucrabil == true)
                    break;
            }
    }


}

int main()
{
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++)
            M[i][j] = '0';



    cin>>nrNoduri>>nrTrazitii;

    for(i = 1; i <= nrTrazitii; i++)
    {
        cin>>nod1>>nod2>>val;
        M[nod1][nod2] = val;
    }

    cin>>stareInitiala>>nrStariFinale;

    for(i = 1; i <= nrStariFinale; i++)
        cin>>stariFinale[i];

    cin>>nrStringuri;

    for(i = 1; i <= nrStringuri; i++)
    {
        cin>>Strings[i];
        cin.get();
    }

    cout<<endl<<endl;

    for(i = 1; i <= nrStringuri; i++)
    {
        bool sirPrelucrabil = false;
        int vPos[1000];
        memset(vPos, 0, sizeof(vPos));
        parcurgere(stareInitiala, 0, sirPrelucrabil, vPos, Strings[i]);

        if(sirPrelucrabil == true)
        {
            cout<<"DA"<<endl<<"Traseu: ";
            for(int j = 0; j <= strlen(Strings[i]); j++)
                cout<<vPos[j]<<" ";
            cout<<endl;
        }
        else
            cout<<"NU"<<endl;
    }



    return 0;
}
