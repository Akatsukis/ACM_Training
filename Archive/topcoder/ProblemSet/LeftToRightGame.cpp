#include <bits/stdc++.h>
using namespace std;
  
class LeftToRightGame  
{  
    public:  
    string whoWins(int length, int divisor)  
    {  
        if(length%2 == 1){
            if(divisor == 1)return "Bob";
            else return "Alice";
        }
        else{
            if(divisor >= 1 && divisor <= 11)return "Bob";
            else return "Alice";
        }
    } 
  
};  
  


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
