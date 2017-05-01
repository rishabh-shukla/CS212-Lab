using namespace std;
class Teacher:public Staff{
	protected:
		char *subject;
		char *publish;
	public:
		Teacher(int,char *Name,char *sub,char *pub);
		char *getSubject(){ return subject;}
		char *getPublish(){ return publish;}
};
Teacher::Teacher(int Code,char *Name,char *sub,char *pub):Staff(Code,Name){
	subject = new char[strlen(sub)];
	strcpy(subject,sub);
	publish = new char [strlen(pub)];
	strcpy(publish,pub);
}
