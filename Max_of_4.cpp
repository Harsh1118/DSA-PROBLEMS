/*
Write a function int max_of_four(int a, int b, int c, int d) which returns the maximum of the 
four arguments it receives.

+= : Add and assignment operator. It adds the right operand to the left operand and assigns the 
result to the left operand.
a += b is equivalent to a = a + b;
Input Format

Input will contain four integers -  , one per line.

Output Format

Return the greatest of the four integers.
PS: I/O will be automatically handled.

Sample Input

3
4
6
5
Sample Output

6
*/

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

int grt_of_4(int a , int b , int c , int d)
{
    if(a>b)
    {
        if(a>c)
        {
            if(a>d)
            {
                return a;
            }
            
            else 
            {
                return d;
            }
        }
        
        else if(c>d)
    {
        return c;
    }
        
    }
    
    else if(b>c)
    {
        if(b>d)
        {
            return b;
        }
        
        else if(c>d)
        {
            return d;
        }
    }
    
    else if(c>d)
    {
        return c;
    }
    return d;
}

int main ()
{
    int a , b, c ,d;
    cin >> a >> b >> c >> d;
    cout << grt_of_4(a,b,c,d);
    return 0;
}
