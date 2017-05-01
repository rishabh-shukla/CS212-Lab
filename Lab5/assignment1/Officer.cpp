using namespace std;
class Officer: public Staff{
	protected:
		char grade;
	public:
		Officer(int, char *,char);
		char getGrade(){ return grade;}
};
Officer::Officer(int Code, char *Name,char Grade):Staff(Code,Name),grade(Grade){}
