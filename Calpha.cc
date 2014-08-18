
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

typedef pair<string,string> PII;

int tmain(){
	int n;
	cin>>n;
	cin.get();
	map<PII,int> m;
	for(int i=0;i<n;i++){
		string s1,s2;
		getline(cin,s1,'+');
		cin.get();
		getline(cin,s2,'=');
		cin.get();
		int v;
		cin>>v;
		cin.get();
		m[make_pair(s1,s2)]=v;
		m[make_pair(s2,s1)]=v;
	}

	cin >>n;
	for(int i=0;i<n;i++){
	}
	return 0;
}

int main(){
	freopen("C:/Users/dingd/Desktop/input.in","r",stdin);
	freopen("C:/Users/dingd/Desktop/output.out","w",stdout);
	int T;
	scanf("%d\n", &T);
	for(int cn=1;cn<=T;cn++){
		printf("Case #%d:", cn);
		tmain();
	}
	return 0;
}
	