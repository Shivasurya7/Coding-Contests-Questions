/*
Magic and toy shop
Accuracy: 45.85% Submissions: 20K+ Points: 25
Geek goes to a toy shop having N toys, the prices of these toys are given as price array. He wants to buy all the N toys, but he has only M rupees to spend. He has a magical Trident which reduces the price of each toy. This reduced price for each toy is given in magical_price array. That is for ith toy (0<i<N-1) price[i] is the original price and magical_price[i] is the price after applying magic. Since applying magic reduces the power of Trident, he wants to apply it as minimum times as possible.
Find the minimum number of toys on which he should apply this magic so as to buy all the N toys for atmost M rupees. If it is not possible for Geek to buy the toys even after applying the magic on all the toys the return -1.

Example 1:
Input:
N = 5, M = 13 
price = {3,4,6,2,4}
magical_price = {1,2,5,1,3}
Output:
4
Explanation:
Geek can apply the magic on first four toys so as to buy all the toys for 13. He will require minimum 4 magical operations.

Example 2:
Input:
N = 3, M = 6 
price = {4,3,4}
magical_price = {2,2,3}
Output:
-1
Explanation:
Even after applying the maigc on all the toys, he cannot buy all the toys at rupees 6.
Your task:
You don't need to read input or print anything. Your task is to complete the function minimumMagic() which takes four arguments N, M, price, and magical_price. It returns an integer that is minimum magical operations required or -1, if not possible.

Constraints:
1 <= N <= 10^5
1 <= M <= 10^9
1 <= magical_price[i] <= price[i] <= 10^4
*/

//{ Driver Code Starts
#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int minimumMagic(int n, int m, vector<int> &price, vector<int> &magical_price)
    {
      int sp=0;
        for(int i = 0; i < n; i++){
            sp += price[i];
        }
        if(m >= sp){
            return 0;
        }
        for(int i = 0; i < n; i++){
            m -= magical_price[i];
            sp -= price[i];
            if(m >= sp){
              return i+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>price(n),magical_price(n);
        for(int i=0;i<n;i++)
            cin>>price[i];
        for(int i=0;i<n;i++)
            cin>>magical_price[i];
        Solution ob;
        int ans=ob.minimumMagic(n,m,price,magical_price);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends