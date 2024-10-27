// brute, better, optimal all given here

//brute

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

//better(hashing: hash map)
 
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v){
    int n= v.size();
    map<int,int>mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }
    

    for(auto it: mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
}


int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}


//optimal (moore's voting algo)

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v){
    int cnt= 0;
    int el;
    int n= v.size();
    for (int i = 0; i < n; i++)
    {
        if(cnt==0){
            cnt= 1;
            el= v[i];
        }
        else if(v[i]== el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    //checking is el is mojority element
    int cnt1= 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]== el) cnt1++;
    }
    if(cnt1> (n/2)){
        return el;
    }
    else{
        return -1;
    }
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
