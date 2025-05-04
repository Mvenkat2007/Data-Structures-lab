#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

//function prototype
void maximum_block();

int main()
{
    int t=0;//variable to store number of test cases

    printf("Enter the number of test cases:");
    scanf("%d",&t);

    while(t)
    {
        maximum_block();
        t--;
    }
}

void maximum_block()
{
    int n=0;//variable to store number of towers
    int blocks=0;//variable to store number of blocks in each tower

    printf("Enter the number of towers:");
    scanf("%d",&n);

    vector<int> towers(n);//vector to store blocks of each tower
    
    printf("Enter the blocks in each tower:");
    for(int i=0;i<n;i++)//loop to get user input and store it in the vector
    {
        scanf("%d",&blocks);
        towers.at(i)=blocks;
    }
    
    sort(towers.begin()+1,towers.end());
    
    int result=towers.at(0);
    int excess=0;

    for(int i=1;i<n;i++)
    {
        if(towers.at(i)>result)
        {
            excess=(towers.at(i)-result+1)/2;
            result+=excess;
            towers.at(i)-=excess;
        }
    }

    printf("%d\n",result);
}