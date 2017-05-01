using namespace std;
class Staff{
	protected:
	int code;
	char *name;
	public:
		Staff(int, char *Name);
		int getCode(){ return code;}
		char *getName(){ return name;}
};
Staff::Staff(int Code,char *Name):code(Code){
	name = new char[strlen(Name)];
	strcpy(name,Name);
}
