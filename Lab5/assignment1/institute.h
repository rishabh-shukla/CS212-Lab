#include<string.h>
class Staff{
	protected:
	int code;
	char *name;
	public:
		Staff(int, char *Name);
		int getCode(){ return code;}
		char *getName(){ return name;}
};
class Teacher:public Staff{
	protected:
		char *subject;
		char *publish;
	public:
		Teacher(int,char *Name,char *sub,char *pub);
		char *getSubject(){ return subject;}
		char *getPublish(){ return publish;}
};
class Officer: public Staff{
	protected:
		char grade;
	public:
		Officer(int, char *,char);
		char getGrade(){ return grade;}
};
class Typist: public Staff{
	protected:
		int type;
		int salary;
	public:
		Typist(int,char*,int,int);
		int getType(){ return type;}
		int getSalary(){ return salary;}
};
