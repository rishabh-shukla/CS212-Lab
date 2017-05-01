using namespace std;
class Typist: public Staff{
	protected:
		int type;
		int salary;
	public:
		Typist(int,char*,int,int);
		int getType(){ return type;}
		int getSalary(){ return salary;}
};
Typist::Typist(int Code,char*Name,int Type,int sal): Staff(Code,Name),type(Type),salary(sal){}
