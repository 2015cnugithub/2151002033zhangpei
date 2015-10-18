#include <iostream>
using namespace std;


class GGoods{
private:
	static int count;        //count 应该被定义为静态变量，这样有一个GGoods的对象产生，count的值就加1.
	long no;
	char *p_name;
	double price;

public:
	GGoods(long a,char b,double c);
	GGoods(GGoods &goods);
	void print();
	~GGoods();
     getCount();
	 friend char getName(GGoods g1);
	 GGoods operator<(GGoods g1);
	 GGoods operator>=(GGoods g1);

};


GGoods::GGoods(long a,char b,double c)
{
	no=a;
	*p_name=b;
    price=c;
}


GGoods::GGoods(GGoods &goods)
{
	no=goods.no;
	p_name=goods.p_name;
	price=goods.price;
}


GGoods::~GGoods(){
cout<<"hello";
}


void GGoods::print(){
cout<<no<<" "<<p_name<<" "<<price<<endl;
}


 int GGoods::getCount(){
return count;
}


 char getName(GGoods g1){
 return *g1.p_name;
 }

 int GGoods::count=0;

 GGoods GGoods::operator<(GGoods g1){
	 if (price<g1.price){
	 return *this;
	 }
	 else return g1;
 }

  GGoods GGoods::operator>=(GGoods g1){
	 if (price<g1.price){
	 return g1;
	 }
	 else return *this;
 }



  class CClothes:public GGoods{
  private:
	  char *p_brand;
  public:
	  CClothes(long a, char b, double c, char* d);
	  void usedFor();
	  ~CClothes();
      
  };

  CClothes::CClothes(long a, char b, double c, char *d):GGoods(a,b,c){
       p_brand=d;
  }

  CClothes::~CClothes(){
  cout<<"success";
  }

  void CClothes::usedFor(){
  cout<<"this is clothes";
  }



  class CFoods:public GGoods{
  private:
	  char *p_brand;
  public:
	  CFoods(long a,char b,double c,char *d);
	  void usedFor();
	  ~CFoods();
  };
  

  void CFoods::usedFor(){
  cout<<"this is food";
  }

    CFoods::CFoods(long a, char b, double c, char *d):GGoods(a,b,c){
       p_brand=d;
  }

  CFoods::~CFoods(){
  cout<<"success";
  }



void main(){

}

