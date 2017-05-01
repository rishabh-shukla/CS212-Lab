using namespace std;
class Officer: public Staff,public Qualification{
	protected:
		char grade;
	public:
		Officer(int, char *,char,char *,char *);
		char getGrade(){ return grade;}
};
Officer::Officer(int Code, char *Name,char Grade,char *gen,char *prof):Staff(Code,Name),Qualification(gen,prof),grade(Grade){}
