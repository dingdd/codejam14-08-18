#include <sstream>
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

int seg[][7]={
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}};

	int broken[10][7]={0};

bool fit(int in, string &s, int *b){
	int *p=seg[in];
	for(int i=0;i<7;i++){
		if(p[i]){
			if(s[i]=='1'){
				if(b[i]!=2)
					b[i]=1;//OK
				else
					return false;
			}
			else
				b[i]=2;
		}
		else if(s[i]=='1')
			return false;
	}
	return true;
}

void pp(int in,int *b){
	for(int i=0;i<7;i++){
		if(seg[in][i]&&b[i]==1)
			printf("1");
		else 
			printf("0");
	}
	printf("\n");
}

int tmain(){
	int n;
	cin >>n;
	string s;
	vector<string> v;
	cin.get();
	getline(cin, s);
	stringstream ss(s);
	for(int i=0;i<n;i++){
		getline(ss, s, ' ');
		v.push_back(s);
	}
	vector<bool> ff(10,false);
	memset(broken, 0, sizeof(broken)/sizeof(char));
	for(int i=0;i<10;i++){
		int c=i;
		for(int j=0;j<n;j++){
			if(!fit(c,v[j],broken[i])){
				j=n;
				ff[i]=false;
				continue;
			}
			ff[i]=true;
			c+=9;
			c%=10;
		}
	}
	int c=0;
	for(int i=0;i<10;i++){
		if(ff[i])
			c++;
	}
	if(c!=1){
		cout <<"ERROR!"<<endl;
		return 0;
	}
	for(c=0;!ff[c];c++);
	int t=c;
	for(int i=0;i<7;i++){
		if(!broken[c][i]){
			cout <<"ERROR!"<<endl;
			return 0;
		}
	}
	c+=9*n;
	c%=10;
	pp(c,broken[t]);
	return 0;
}

int main(){
	freopen("C:/Users/dingd/Desktop/input.in","r",stdin);
	freopen("C:/Users/dingd/Desktop/output.out","w",stdout);
	int T;
	scanf("%d\n", &T);
	for(int cn=1;cn<=T;cn++){
		printf("Case #%d: ", cn);
		tmain();
	}
	return 0;
}
	