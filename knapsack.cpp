//knapsack problem according to weight
#include<iostream>
using namespace std;
struct item
{
    int value;
    int weight;
};
//sorting according to weight
void sort(struct item *I,int size){
    int i,j;
    //temporary structure to hold values
    struct item temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1;j++)
        {
            if(I[j].weight>I[j+1].weight)
            {
               temp = I[j];
               I[j] = I[j + 1];
               I[j + 1] = temp;

            }
        }
    }
};
int main()
{
    int nitem, tweight, mprofit = 0, i;
    cout << "How many iteams are there? \n";
    cin >> nitem;
    cout << "Total capacity of knapsack\n";
    cin >> tweight;
    struct item I[nitem];
    for (i = 0; i < nitem;i++)
    {
        cout << "Enter Value of I[" << i + 1 << "]\n";
        cin >> I[i].value;
        cout << "Enter Weight of value " << I[i].value << "\n";
        cin >> I[i].weight;
    }
    sort(I,nitem);
    for (i = 0; i < nitem;i++)
    {
        if(!(tweight<I[i].weight))
        {
            mprofit = mprofit + I[i].value;
            tweight = tweight - I[i].weight;
        }
    }
    cout << "Total weight remains\n" << tweight;
    cout << "\nMax profit is " << mprofit;
    return 0;
}