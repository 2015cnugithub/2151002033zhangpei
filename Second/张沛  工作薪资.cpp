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
		cout<<"������"<<worker.name<<endl;
		cout<<"�Ա�"<<worker.sex<<endl;
		cout<<"���䣺"<<worker.age<<endl;
		cout<<"Сʱ���ʶ�:"<<worker.pay_per_hour<<endl;
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
		cout<<"�������"<<(i+1)<<"��Ա����Ϣ��"<<endl;
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
			cout<<"��ѡ��Ҫ��ѯ�Ĺ�����ţ�";
			cin>>number;
	
				cout<<*worker[number];
				cout<<"�����빤��һ�ܹ���ʱ�䣺";
				cin>>time;
				cout<<"�˹���н���ǣ�"<<worker[number]->Compute_pay(time)<<endl;
		
		
			cout<<"���Ƿ�Ҫ������ѯ��(y/n)";
            cin>>ch;
		
		}while(ch=='y');
			return 0;
			system("pause");

}