
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

int mat[100][100];
int meg[100][100];

int tmain(){
	memset(mat,0,sizeof(mat)/sizeof(char));
	memset(meg,0,sizeof(meg)/sizeof(char));
	int n;
	cin>>n;
	cin.get();
	string s;
	getline(cin,s);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >>mat[i][j];
	if(s=="right"){
		for(int i=0;i<n;i++){
			int c=n-1,t;
			for(int j=n-1;j>=0;j--){
				if(!mat[i][j])
					continue;
				if(c==n-1||meg[i][c+1]){
					t=mat[i][j];
					mat[i][j]=0;
					mat[i][c--]=t;
				}
				else if(mat[i][c+1]==mat[i][j]){
					t=mat[i][j];
					mat[i][j]=0;
					meg[i][c+1]=1;
					mat[i][c+1]=2*t;
				}
				else {
					t=mat[i][j];
					mat[i][j]=0;
					mat[i][c--]=t;
				}
			}
		}
	}
	else if(s=="up"){
		for(int j=0;j<n;j++){
			int c=0,t;
			for(int i=0;i<n;i++){
				if(!mat[i][j])
					continue;
				if(c==0||meg[c-1][j]){
					t=mat[i][j];
					mat[i][j]=0;
					mat[c++][j]=t;
				}
				else if(mat[c-1][j]==mat[i][j]){
					t=mat[i][j];
					mat[i][j]=0;
					meg[c-1][j]=1;
					mat[c-1][j]=2*t;
				}
				else {
					t=mat[i][j];
					mat[i][j]=0;
					mat[c++][j]=t;
				}
			}
		}
	}else if(s=="down"){		
		for(int j=n-1;j>=0;j--){
			int c=n-1,t;
			for(int i=n-1;i>=0;i--){
				if(!mat[i][j])
					continue;
				if(c==n-1||meg[c+1][j]){
					t=mat[i][j];
					mat[i][j]=0;
					mat[c--][j]=t;
				}
				else if(mat[c+1][j]==mat[i][j]){
					t=mat[i][j];
					mat[i][j]=0;
					meg[c+1][j]=1;
					mat[c+1][j]=2*t;
				}
				else {
					t=mat[i][j];
					mat[i][j]=0;
					mat[c--][j]=t;
				}
			}
		}
	}
	else if(s=="left"){
	for(int i=0;i<n;i++){
			int c=0,t;
			for(int j=0;j<n;j++){
				if(!mat[i][j])
					continue;
				if(c==0||meg[i][c-1]){
					t=mat[i][j];
					mat[i][j]=0;
					mat[i][c++]=t;
				}
				else if(mat[i][c-1]==mat[i][j]){
					t=mat[i][j];
					mat[i][j]=0;
					meg[i][c-1]=1;
					mat[i][c-1]=2*t;
				}
				else {
					t=mat[i][j];
					mat[i][j]=0;
					mat[i][c++]=t;
				}
			}
		}
	}
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d", mat[i][j]);
			if(j!=n-1)
				printf(" ");
		}
		printf("\n");
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
	