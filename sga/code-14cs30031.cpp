#include <bits/stdc++.h>
using namespace std;
double LR(double sumoff)
{
	double val;
	val=exp(sumoff);
	return 1/(1+1/val);
}
int check(double x1,double x2,double x3,double x4,double t[])
{
	if((abs(x1-t[0])<1e-5 && abs(x2-t[1]) <1e-5 && abs(x3-t[2])<1e-5 && abs(x4-t[3])<1e-5))
	 return 0;
	return 1;
}
void shuffle(double a[100][4]){
	int i,j;
	double temp;
	srand ( time(NULL) );

	j = rand()%100;
	for(i=0;i<50;i++){
		j = rand()%100;
		temp = a[i][0];
		a[i][0]= a[j][0];
		a[j][0]=temp;  
		temp = a[i][1];
		a[i][1]= a[j][1];
		a[j][1]=temp;
		temp = a[i][2];
		a[i][2]= a[j][2];
		a[j][2]=temp;
		temp = a[i][3];
		a[i][3]= a[j][3];
		a[j][3]=temp;


	}

}
int main()
{
	srand ( time(NULL) );
	int sno;
    double r =1e-4;
	double results[100][4];
	//assign random values to thetas
	double t[4];
	t[0] = rand()%10 +1;
	t[1] = rand()%10 +1;
	t[2] =rand()%10 +1;
	t[3] = rand()%10 +1;
	cout<<"Values of initial thetas are ..."<<endl;
	cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl;
	double sumoff;
	double D1,D2,D3,D4;
	double lr;
	double x1,x2,x3,x4;
	for(int i=0;i<100;i++)
	{
		cin>>sno;
		cin>>results[i][0];
		cin>>results[i][1];
		cin>>results[i][2];
		cin>>results[i][3];
	}
	shuffle(results);//randomly shuffle the array
	/*for(int i=0;i<100;i++)
	{
		cout<<i<<" ";
		cout<<results[i][0]<<" ";
		cout<<results[i][1]<<" ";
			cout<<results[i][2]<<" ";
				cout<<results[i][3]<<" ";
				cout<<endl;
	}*/
    int i=0;
	for(;i<1e6;i++)
	{
		for(int j=0;j< 100;j++)
		{
			sumoff = t[0] + t[1]*results[j][0] + t[2]*results[j][1] + t[3]*results[j][2];
			lr= LR(sumoff);
			D1 = (results[j][3] -lr);
			D2 = (results[j][3] -lr)*results[j][0];
			D3 = (results[j][3] -lr)*results[j][1];
			D4 = (results[j][3]-lr)*results[j][2]; 	
			t[0] = t[0] + r * D1;
			t[1] = t[1] + r * D2;
			t[2] = t[2] + r * D3;
			t[3] = t[3] + r * D4;
		}
		if(i!=0 && !check(x1,x2,x3,x4,t))
			break;
		x1=t[0];
		x2=t[1];
		x3=t[2];
		x4=t[3];
 
	}
	printf("Total Number of iterations: %d\n",i);
	printf("values of thetas 1,2,3,4 are ");
	cout<<t[0]<<" ";
	cout<<t[1]<<" ";
	cout<<t[2]<<" ";
	cout<<t[3]<<endl;
 
}