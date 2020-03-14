//HOLI AT KASHMERE GATE
#include <iostream>
using namespace std;

struct House //contains attributes of a house
{
    int Pink;
    int Orange;
    int Yellow;
    int color;
};
int returnmin(int A=-1, int B=-1, int C=-1) //Function to decide the color of the houses
{
    if(A==-1)
    {
        if(B<C)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if(B==-1)
    {
        if(A<C)
        {
            return 0;
        }
        else{
            return 2;
        }
    }
    if(C==-1)
    {
        if(A<B)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    if(A<B)
    {
        if(A<C)
        {
            return 0;
        }
        else
        {
            return 2;
        }

    }
    else
    {
        if(B<C)
        {
            return 1;
        }
        else
        {
            return 2;
        }

    }
}
int mincost() //Function to find minimum cost for painting the houses
{
    int H, i, cost=0, temp;
    cin>>H;
    House C[H];
    for(i=0; i<H; i++)
    {
        cin>>C[i].Pink;
        cin>>C[i].Orange;
        cin>>C[i].Yellow;
        if(i==0)
        {
            temp=returnmin(C[i].Pink, C[i].Orange, C[i].Yellow);
            switch(temp)
            {
                case 0: cost+= C[i].Pink;
                        C[i].color=0;
                        break;
                case 1: cost+= C[i].Orange;
                        C[i].color=1;
                        break;
                case 2: cost+= C[i].Yellow;
                        C[i].color=2;
                        break;
            }


        }
        else if(i==1)
        {
            switch(C[0].color)
            {
                case 0: temp= returnmin(-1, C[i].Orange, C[i].Yellow);
                        break;
                case 1: temp= returnmin(C[i].Pink , -1, C[i].Yellow);
                        break;
                case 2: temp= returnmin(C[i].Pink , C[i].Orange, -1);
                        break;
            }
            switch(temp)
            {
                case 0: cost+= C[i].Pink;
                        C[i].color=0;
                        break;
                case 1: cost+= C[i].Orange;
                        C[i].color=1;
                        break;
                case 2: cost+= C[i].Yellow;
                        C[i].color=2;
                        break;

            }
        }

        else
        {
           switch(C[i-1].color)
            {
                case 0: switch(C[i-2].color)
                        {
                            case 1: cost+= C[i].Yellow;
                                    C[i].color=2;
                                    break;
                            case 2: cost+= C[i].Orange;
                                    C[i].color=1;
                                    break;
                        }
                        break;
                case 1: switch(C[i-2].color)
                        {
                            case 0: cost+= C[i].Yellow;
                                    C[i].color=2;
                                    break;
                            case 2: cost+= C[i].Pink;
                                    C[i].color=0;
                                    break;
                        }
                        break;
                case 2: switch(C[i-2].color)
                        {
                            case 0: cost+= C[i].Orange;
                                    C[i].color=1;
                                    break;
                            case 1: cost+= C[i].Pink;
                                    C[i].color=0;
                                    break;
                        }
                        break;
            }
        }
    }

    return cost;


}
int main() {
	int T, i;
	cin>>T;
	int R[T];
	for(i=0; i<T; i++)
	{
	    R[i]= mincost(); //Takes values of minimum cost for each test case
	}
    for(i=0; i<T; i++)
	{
	    cout<<R[i]<<endl;
	}
    return 0;
}
