
// Water and Jug
//  Bézout's identity which states that for any integers a and b, the equation ax + by = d has a solution if and only if d is a multiple of gcd(a, b). In the context of water jugs:
// a and b are the jug capacities x and y.
// d is the target amount of water.
// Thus, the target must be a multiple of gcd(x, y) for it to be possible to measure exactly target liters.



#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int gcd(int a,int b){
	    if(a==0)return b;
	    return gcd(b%a,a);
	}
	
	int pour(int fromCap, int toCap, int d)
	{
	    int from = fromCap;
	    int to = 0;
	    int step = 1;
	    
	    //Loop until one of the jugs has the desired amount of water.
	    while (from != d && to != d)
	    {
	        //Find the amount of water that can be transferred from one jug to another.
	        int temp = min(from, toCap - to);
	        to   += temp;
	        from -= temp;
	        step++;
	 
	        //Check if desired amount of water has been achieved.
	        if (from == d || to == d)
	            break;
	        
	        //If one jug becomes empty, refill it and increment the step count.
	        if (from == 0)
	        {
	            from = fromCap;
	            step++;
	        }
	        
	        //If one jug becomes full, empty it and increment the step count.
	        if (to == toCap)
	        {
	            to = 0;
	            step++;
	        }
	    }
	    
	    //Return the minimum number of steps required to achieve the desired amount of water.
	    return step;
	}
	
	int minSteps(int m, int n, int d)
	{  
	    int rem = gcd(m,n);
	    if(d%rem)return -1;
	    
	    return min(pour(m,n,d),pour(n,m,d));
	}
};