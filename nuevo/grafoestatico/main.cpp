//marco antonio gallegos loaeza
//estructura de datos 2 D09

#include <iostream>

using namespace std;


bool buscarcamino(bool m[8][8],int ori,int des);

bool tieneconexion(bool m[8][8],int renglon):

int main()
{


    bool a[8][8]={{1,1,1,1,0,0,0,0},
                  {1,0,0,0,0,0,0,0},
                  {1,0,0,1,0,1,0,0},
                  {1,0,1,0,0,0,0,0},
                  {0,0,0,0,0,0,1,0},
                  {0,0,1,0,0,0,0,0},
                  {0,0,0,0,1,0,0,0},
                  {0,0,0,0,0,0,0,0}
                 };

   /* for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    unsigned int o,d;
    cout<<"nodos a=1 b=2 c=3 d=4 e=5 f=6 g=7 h=8"<<endl;
    cout<<"nodo origen"<<endl;
    cin>>o;
    o--;
    cout<<"nodo destino"<<endl;
    cin>>d;
    d--;

    cout << "Hello World!" << endl;
    return 0;
}

bool buscarcamino(bool m[8][8], int ori, int des)
{
    if(ori>7 || des>7)
        return false;
    if(m[ori][des]==true)
        return true;
    int band=orig,suband=0;
    while (1)
    {
        cout<<
    }

}

bool tieneconexion(bool m[8][8],int renglon)
{
    for (int i = 0; i < 8; ++i)
    {
        if(m[renglon][i]==true)
            return true;

    }
    return false;
}
