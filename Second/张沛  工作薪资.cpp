#include <iostream>
#include <string>
using namespace std;

class Worker{
public:
	string name;
	int age;
	string sex;
	int pay_per_hour;

    void input(string n,string s,int a,double p)
	{
		name=n;
		sex=s;
		age=a;
		pay_per_hour=p;
	}
    virtual double Compute_pay(double hours)
	{
		return 0;
	}

	string getName(){
	return name;
	}

	friend ostream& operator<<(ostream& out, Worker& worker){
		cout<<"姓名："<<worker.name<<endl;
		cout<<"性别："<<worker.sex<<endl;
		cout<<"年龄："<<worker.age<<endl;
		cout<<"小时工资额:"<<worker.pay_per_hour<<endl;
		return out;
	}
};

class HourlyWorker:public Worker{
public: 
	HourlyWorker(string n,string s,int a,double p){
	   input(n,s,a,p);
	}
	double Compute_pay(double hours){
		if(hours<=40){
		return hours*pay_per_hour;
		}
		else return pay_per_hour*40+1.5*pay_per_hour*(hours-40);
	}
    
};

class SalariedWorker:public Worker{
public:
    SalariedWorker(string n,string s,int a,double p){
		input(n,s,a,p);
	}
	double Compute_pay(double hours){
		if(hours>=35){
		return 40*pay_per_hour;
		}
		else return hours*pay_per_hour+0.5*pay_per_hour*(35-hours);
	}

};
int main(){
	Worker *worker[5];
	string name;
	string sex;
	int age;
	double pay_per_hour;

	for(int i=0;i<5;i++){
		cout<<"请输入第"<<(i+1)<<"个员工信息："<<endl;
		cin>>name>>sex>>age>>pay_per_hour;
		if(pay_per_hour==30||pay_per_hour==50)
		{
			worker[i]=new SalariedWorker(name,sex,age,pay_per_hour);
		}
		else if(pay_per_hour==10||pay_per_hour==20||pay_per_hour==40)
		{
			worker[i]=new HourlyWorker(name,sex,age,pay_per_hour);
		}
	}


	char ch;
	int number;
	double time;
	do
	{
		
			fflush(stdin);
			for(int i=1;i<=5;i++)
			{
				cout<<i<<":"<<worker[i-1]->getName()<<endl;
			}
			cout<<"请选择要查询的工人序号：";
			cin>>number;
	
				cout<<*worker[number];
				cout<<"请输入工人一周工作时间：";
				cin>>time;
				cout<<"此工人薪资是："<<worker[number]->Compute_pay(time)<<endl;
		
		
			cout<<"你是否要继续查询？(y/n)";
            cin>>ch;
		
		}while(ch=='y');
			return 0;
			system("pause");

}