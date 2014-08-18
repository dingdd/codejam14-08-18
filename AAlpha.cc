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

	int broken[7]={0};

bool fit(int in, string &s){
	int *p=seg[in];
	for(int i=0;i<7;i++){
		if(p[i])
			continue;
		if(s[i]=='1'&&p[i]==0)
			return false;
	}
	return true;
}

void bb(int in, string &s){
	for(int i=0;i<7;i++){
		if(s[i]=='1'){
			broken[i]=1;//OK
			continue;
		}
		if(seg[in][i]){
			broken[i]=2;//BROKEN
		}
	}
}

void pp(int in){
	for(int i=0;i<7;i++){
		if(seg[in][i]&&broken[i]==1)
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
	
	vector<vector<int> >vv(100,vector<int>(10,0));

	for(int j=0;j<10;j++){
		if(fit(j,v[0]))
			vv[0][j]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<10;j++){
			if(!vv[i-1][j])
				continue;
			int c=j+9;
			c%=10;
			if(fit(c,v[i])){
				vv[i][c]=1;
			}
			else{
				vv[i-1][j]=0;
			}
		}
	}
	int c=0;
	for(int i=0;i<10;i++){
		if(vv[n-1][i])
			c++;
	}
	if(c!=1){
		printf("ERROR!\n");
		return 0;
	}
	for(c=0;c<10&&!vv[0][c];c++);

	memset(broken, 0, sizeof(broken)/sizeof(char));
	for(int i=0;i<n;i++){
		bb(c,v[i]);
		c+=9;
		c%=10;
	}
	for(int i=0;i<7;i++){
		if(!broken[i]){
			printf("ERROR!\n");
			return 0;
		}
	}
	pp(c);
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
	