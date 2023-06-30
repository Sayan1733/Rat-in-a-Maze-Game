//rat in maze
#include<iostream>
using namespace std;
bool issafe(int **arr,int x,int y,int n){
	if(x<n && y<n && arr[x][y] == 1){
		return true;
	}
	return false;
}

bool ratinmaze(int **arr,int x,int y,int n,int** solarr){
	if(x==(n-1) && y==(n-1)){		//base case
		solarr[x][y]=1;
		return true;
	}
	if(issafe(arr,x,y,n)){
		solarr[x][y] = 1;
		if(ratinmaze(arr,x+1,y,n,solarr)){			//(//recursion//)
			return true;						    //
		}											//For Movement horizontal and vertical
		if(ratinmaze(arr,x,y+1,n,solarr)){			//
			return true;							//
		}
		solarr[x][y] = 0;		//backtrack
		return false;
	}
	return false;
}
int main(){
	int n;
	cout<<"Enter the size of the maze:";
	cin>>n;
	
	int **arr=new int*[n];						//Dynamic Memory Allocation
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
	}
	cout<<"0 are the blocked paths in maze:"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	int **solarr=new int*[n];
	for(int i=0;i<n;i++){
		solarr[i]=new int[n];
		for(int j=0;j<n;j++){
			solarr[i][j]=0;
		}
	}
	
	if(ratinmaze(arr,0,0,n,solarr)){
		cout<<"The Rat will go in 1's direction: ";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<solarr[i][j]<<" ";
			}cout<<endl;
		}
	}
	return 0;
}
