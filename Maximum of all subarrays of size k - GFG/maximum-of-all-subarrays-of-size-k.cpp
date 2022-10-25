// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        
        for(int i = 0 ; i < n ; i++){
            while(!pq.empty() && pq.top().second <= (i-k)) pq.pop();
            
            pq.push({arr[i],i});
            
            if(i >= k-1)ans.push_back(pq.top().first);
        }
        return ans;
    }
};
/*make a max heap priority queue of pairs storing the data and the index
1. run a loop for all the elements and at each iteration check wheather the queue is not empty and
   the index of the top in queue belongs to the window or not. pq.index <= (i-k)
2. push the elements and then check the current itteration has complete the window or not.(i >= k-1)*/

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends