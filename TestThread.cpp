#include<iostream>
#include<windows.h>
using namespace std;

double pi[4];
//hàm tính pi voi cac gia tri nhan va la 0,1,2,3
DWORD WINAPI pi1(LPVOID p)
	{
    long num_steps = 100000;
    double step;
	int *j1=(int*)p;
	int j=*j1;
	double x,sum=0.0;
	step=1.0/(double)num_steps;
	for(j;j<num_steps;j=j+4){
	x=(j+0.5)*step;
	sum=sum+4.0/(1.0+x*x);
	}
	pi[*j1]=step*sum;
	}
	
int main(){
	int arri[4]={0,1,2,3};
	HANDLE arrthread[4];
	for(int i=0;i<4;i++){
	arrthread[i] = CreateThread(0,0,pi1,&arri[i],0,0);
    }
	WaitForMultipleObjects(4,arrthread,TRUE,INFINITE);
	
	cout<<"PI="<<pi[0]+pi[1]+pi[2]+pi[3];
}
