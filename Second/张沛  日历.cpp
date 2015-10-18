#include  <iostream>
using namespace std;

int isYear(int x);
int isMouth(int x,int y);
int isDay(int x,int y,int z);
void show(int first,int days);

void main(){
cout<<"请输入年月:";
int x,y;
cin>>x>>y;
int n=isDay(x,y,1);
show(n,isMouth(x,y));
}


int isYear(int x){
	if(x%400==0||x%4==0&&x%100!=0){ 
	return 1;
	}
return 0;
}


int isMouth(int x,int y){
	if(y==2&&isYear(x)==1){
	return 29;}
	else if(y==2&&isYear(x)==0){
	return 28;}
	else if(y==4||y==6||y==9||y==11){
	return 30;}

	return 31;
}


int isDay(int x,int y,int z)
{
	int max=4;
	for(int i=1970;x>i;i++){
		if(isYear(i)==0){
		max+=365;
		}
		if(isYear(i)==1){
		max+=366;
		}
	}

	for(int j=1;y>j;j++)
	{
	max=max+isMouth(x,j);
	}
return (max+z-1)%7;
}

void show(int first,int days){
 cout<<"日\t一\t二\t三\t四\t五\t六"<<endl;
 int a=first;

 while(a>0){
 cout<<"\t";
 a--;
 }

 for(int i=1;i<=days;i++){
 cout<<i<<"\t";
 if((first+i)%7==0){
 cout<<endl;
 }
 }
}
