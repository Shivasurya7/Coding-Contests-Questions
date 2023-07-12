/*
Count beautiful strings
Accuracy: 11.85% Submissions: 11K+ Points: 35
Geek love strings having atmost one character whose frequency is odd 
and rest all (if exists) characters have even frequencies, 
he calls such strings as beautiful strings. 
Geek has a box containing n strings. 
You have to help him in counting number of pairs (i,j) (0<i<j<n-1) 
such that a string formed by concatenating string at index i with string at index j 
is a beautiful string. 

Note: Strings consist of only lowercase English letters.

Example 1:
Input:
n = 3
box = {bbcb, abccc, abc}
Output:
3
Explanation:
Pairs which form beautiful string are (1,2), (1,3) and (2,3).

Concatenating 'bbcb' and 'abccc' we get 'bbcbabccc' in which characters 'b' and 'c' has frequecy of 4, and only 'a' has odd frequency. So the pair (1,2) forms a beautiful string.

Concatenating 'bbcb' and 'abc' we get 'bbcbabc' in which characters 'b' and 'c' has frequecy of 4 and 2 respectively, and only 'a' has odd frequency. So the pair (1,3) forms a beautiful string.

Concatenating 'abccc' and 'abc' we get 'abcccabc' in which all the characters have even frequency. So the pair (2,3) also forms a beautiful string.

Example 2:
Input:
n = 7
box = {aaaa, abba, ccc, caa, cbba, acaac, bcb}
Output:
16
Explanation:
There are total 16 pairs which form beautiful strings. Pairs which do not form beautiful string are (1,5), (2,5), (3,6), (4,6) and (6,7).
Your task:
You don't need to read input or print anything. Your task is to complete the function noOfPairs() which take array of strings as an argument, and returns the number pairs which form beautiful strings.

Constraints:
2 <= n <=10^5
Strings consist of lowercase English letters.
Sum of length of all the strings in a box does not exceed 10^6.
*/

//{ Driver Code Starts
//Initial Template for C++

#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long noOfPairs(vector<string> &s)
    {
        int n = s.size();
        long long c=0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string s1="";
                s1 += s[i];
                s1 += s[j];
    
                map <char,int> freq;
                for(int k = 0; k < (int)s1.length(); k++){
                    freq[s1[k]]++;
                }
                int oc = 0,ec = 0;
                map <char, int>::iterator it = freq.begin();
                while(it != freq.end()){
                    if(it->second % 2 == 1){
                        oc++;
                    }
                    else{
                      ec++;
                    }
                    ++it;
                }
                if(oc == 1 or ec == freq.size()){
                    c++;
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
        int n;
        cin>>n;
        vector<string>box(n);
        for(int i=0;i<n;i++)
            cin>>box[i];
        Solution ob;
        long long ans=ob.noOfPairs(box);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends