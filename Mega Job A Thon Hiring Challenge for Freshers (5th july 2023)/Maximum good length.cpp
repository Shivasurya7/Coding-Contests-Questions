/*
Maximum good length
Accuracy: 52.56% Submissions: 7K+ Points: 40
You are given a matrix A of size N*M. Any length 'L' can be called good length if there is at least one square matrix of size L*L in A such that all elements in that square matrix are greater than or equal to L. You need to output the maximum good length for given matrix.

Example 1:
Input:
N = 5, M = 4
A = [[4 4 6 3],
     [4 4 4 6],
     [3 5 5 5],
     [1 2 6 4],
     [4 3 2 1]]
Output:
3
Explanation:
There are two 3*3 matrices in which all the elements are greater than or equal to 3. 
For example :- [[4 4 6], and [[4 6 3],
                 [4 4 4],      [4 4 6],
                [3 5 5]]      [5 5 5]].
You cannot find maximum good length greater than 3.

Example 2:
Input:
N = 2, M = 3
A = [[1 1 1],
     [1 1 1]]
Output:
1
Explanation:
There are six 1*1 matrices in which all the elements are greater than or equal to 1. 
You cannot find maximum good length greater than 1.
Your task:
You don't need to read input or print anything. Your task is to complete the function maxGoodLength() which take two matrix A as an argument, and returns the maximum good length for that matrix.

Constraints:
1 <= N,M <=10^3
1 <= A[i][j] <= 10^6
*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
    public:
        int maxGoodLength(vector<vector<int>>&a)
        {
            int n = a.size(),m = a[0].size(),c;
            int ma;
            if(n < m){
                ma = n;
            }
            else{
                ma = m;
            }
            for(int s = 1; s <= ma; s++){
                int mi = s;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(i+mi <= n and j+mi <= m){
                            int f = 1;
                            for(int k = i; k < i+mi; k++){
                                for(int l = j; l < j+mi; l++){
                                    if(!(a[k][l] >= mi)){
                                        f = 0;
                                    }
                                }
                            }
                            if(f){
                                c = s;
                            }
                        }
                    }
                }
            }
            return c;
        }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,i,j;
        cin>>n>>m;
        vector<vector<int>>a(n,vector<int>(m));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        int ans=ob.maxGoodLength(a);
        cout<<ans<<endl;
    }
}

// } Driver Code Ends