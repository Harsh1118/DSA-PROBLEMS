/*
santa wants to deliver Christmas presents to all the children in the city of Rotten Pepper.
 Help him to find out how much time it will take him.
The biggest issue that he has is his big belly. If the width of the chimney is 80 centimetres or more, 
he needs only one minute to come down the chimney. But if the width of the chimney is less than 80 centimetres, 
Santa will get stuck and it will take him twice as long (two minutes).
Santa is also very picky. He only eats chocolate chip cookies(chocolate_chip_cookies) TOGETHER with hot milk(hot_milk).
 Nothing else. If he finds this combination by the fireplace it will make him very happy but cause another 
 one minute delay.
His journey starts at destination one and finishes at his own house. 
Input Line 1: An integer H – number of destinations. 
Next H lines:Two integers W and T – Width of the chimney (in centimetres) 
and Time (in minutes) that Santa needs to get to another destination or back home when all the presents are delivered. 
Two strings F and D - The food and drink offered to Santa by the fireplace. Output One number without units. 
How many minutes it will take Santa to deliver all presents and get back home. 
Constraints
 5<H<200 
30<W<120, 
without units 2<T<12, without units 

*/

#include<iostream>
#include<string>
using namespace std;

int main ()
{
    int H;
    cout<<"Enter Number Destinations : ";
    cin>>H;

    cin.ignore();
    int totaltime = 0;
    for(int i = 0; i<H; i++)
    {
        int W;
        cout<<"Enter Width of House "<<i+1<<" : ";
        cin>>W;

        int T;
        cout<<"Enter The Time Santa Needs to get to another destination : ";
        cin>>T;

        totaltime+=T;

        cin.ignore();
        string F;
        cout<<"Enter The Food Present in the  Home : ";
        getline(cin,F);
        string D;
        cout<<"Enter The Name of Drinks that is Present in the Home : ";
        getline(cin,D);

        if(W<=80)
        {
            totaltime+=2;
        }

        else
        {
            totaltime+=1;
        }

        if(F=="Chocolate chip cookies"&&D=="Hot milk")
        {
            totaltime+=1;
        }
    }

    cout<<"Therefore, The Total Time Taken by santa to deleiver the Gifts and come back to home "<<totaltime<<endl;
    return 0;
}