using namespace std;
class Teacher:public Staff,public Qualification{
	protected:
		char *subject;
		char *publish;
	public:
		Teacher(int,char *,char *,char *,char *,char *);
		char *getSubject(){ return subject;}
		char *getPublish(){ return publish;}
};
Teacher::Teacher(int Code,char *Name,char *sub,char *pub,char *gen,char *prof):Staff(Code,Name),Qualification(gen,prof){
	subject = new char[strlen(sub)];
	strcpy(subject,sub);
	publish = new char [strlen(pub)];
	strcpy(publish,pub);
}
