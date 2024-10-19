#include <bits/stdc++.h>
using namespace std;

bool check(int n,vector<int> &helper,vector<vector<int>> &arr){
    
    for(int i=0;i<helper.size();i++){
        for(int num:arr[helper[i]]){
            if(num == n) return true;
        }
    }
    return false;
}
int main() {
	int nEmp,nPairs;
	cin>>nEmp>>nPairs;
	vector<vector<int>> arr(nEmp+1);
	for(int i=0;i<nPairs;i++){
	    int a,b;
	    cin>>a>>b;
	    arr[a].push_back(b);
	    arr[b].push_back(a);
	}
	
	vector<int> exp(nEmp);
	unordered_map<int,int> mpp;
	for(int i = 0;i<nEmp;i++){
	    cin>>exp[i];
	    mpp[exp[i]] = i+1;
	}
	
	sort(exp.rbegin(),exp.rend());
	
	vector<int> helper;
	helper.push_back(mpp[exp[0]]);
	int sum  = exp[0];
	
	for(int i = 1;i<nEmp;i++){
	    if(!check(mpp[exp[i]],helper,arr)){
	        sum+=exp[i];
	        helper.push_back(mpp[exp[i]]);
	    }
	    
	}
	cout<<sum;
    return 0;
}
