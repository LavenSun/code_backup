#include<iostream>
#include<string>
using namespace std;

string getResult(long input) 
{
	int i = 2;  
    string result="";   
    for (; input >= 2;) 
	{
		if(input%i == 0)
        {       
            result += to_string(i) + " ";     
	        input /=i ; 
	    }   
	    else 
		i++; 
	}  
	return result;
}

int main() 
{    
	long input;   
    cin >> input;   
    cout << getResult(input);
	return 0;
}
