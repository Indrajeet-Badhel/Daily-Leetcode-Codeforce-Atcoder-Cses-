#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array:\n ";
    cin>>n;
    vector<int> ar(n);
    cout<<"Enter the elements of the array:\n ";
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            vector<int> subarray;
            for(int i=l;i<=r;i++){
                subarray.push_back(ar[i]);
            }
            // Do something with the generated subarray, e.g., print it or perform operations
            cout<<"the maximum element in the subarray from index "<<l<<" to "<<r<<" is: "<<*max_element(subarray.begin(), subarray.end())<<endl;
            cout<<"the minimum element in the subarray from index "<<l<<" to "<<r<<" is: "<<*min_element(subarray.begin(), subarray.end())<<endl;
            cout<<"the subarray from index "<<l<<" to "<<r<<" is: ";
            for(int x: subarray){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}