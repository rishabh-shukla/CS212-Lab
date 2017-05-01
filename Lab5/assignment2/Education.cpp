using namespace std;
class Qualification{
	protected:
	char *gen_edu;
	char *prof_edu;
	public:
		Qualification(char *,char *);
		char *getGeneralEdu(){ return gen_edu;}
		char *getProfessionalEdu(){ return prof_edu;}
};
Qualification::Qualification(char *general,char *professional){
	gen_edu = new char[strlen(general)];
	strcpy(gen_edu,general);
	prof_edu = new char [strlen(professional)];
	strcpy(prof_edu,professional);
}
