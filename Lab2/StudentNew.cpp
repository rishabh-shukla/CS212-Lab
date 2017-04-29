#include<iostream>
#include<string.h>
using namespace std;

int Number=0,SIZE =10;  // Some global variables


class Student{					// Student class definition
	char name[32];
	char roll_no[9];
	int marks[5];
	public:
		void set_name(char [],char []);
		void set_roll(char []);
		void set_marks(int []);
		char * get_name(void);
		char *get_roll(void);
		int *get_marks(void);
};

void Student::set_name(char first[],char last[]){			// set function for student name
	strcpy(name,first);
	strcat(name,"  ");
	strcat(name,last);
	return;
}
void Student::set_roll(char roll[]){					// Set function for roll no.
	strcpy(roll_no,roll);
	return;
}
void Student::set_marks(int mark[]){					// Set marks function
	for(int i=0;i<5;i++)
		marks[i] = mark[i];
	return;
}
char* Student::get_name(void){						// Get function for getting student name
	return name;
}
char* Student::get_roll(void){						// Get function for student roll no
	return roll_no;
}
int * Student::get_marks(void){						// Get function for student marks
	return marks;
}

Student student[10];			// Object creation

//Check Validity of Roll No function
int validateRollNo(char *roll){	
	if(strncmp("CS15B",roll,5)!=0)
		return 0;
	if(strlen(roll)!=8)
		return 0;
	if((roll[5]!='0')||(roll[6]>'9')||(roll[6]<'0')||(roll[7]>'9')||(roll[7]<'0'))
		return 0;
	return 1;
}

//Set Student Details Function
void setStudentRecord(void){
	int mark[5],i,j;
	char first[15],last[15],roll[9];
	cout<<"\n\t\tEnter first name : ";
	cin>>first;
	cout<<"\t\tEnter last name : ";
	cin>>last;
	cout<<"\t\tEnter Roll No. : ";
	cin>>roll;
	while(validateRollNo(roll)!=1){
		cout<<"Invalid Input !\n\tPlease Enter Again: ";
		cin>>roll;
	}
	cout<<"\t\tEnter marks in five courses :";
	cin>>mark[0]>>mark[1]>>mark[2]>>mark[3]>>mark[4];
	for(i=1;i<=Number;i++){
		if(strcmp(student[i].get_roll(),roll)==0){					//Checking whether student already exists.  If found, edit details !!! Not add !!!
			student[i].set_name(first,last);
			student[i].set_marks(mark);
			cout<<"\tSuccessfully changed student details !\n";
			return ;
		}
	}
	// If record not found for Roll No, add new student.
	Number++;
	student[i].set_name(first,last);
	student[i].set_roll(roll);
	student[i].set_marks(mark);
	cout<<"\tSuccessfully added Student details !\n";
	return ;
}


void getIndStudentRec(void){									// Get Individual Student details
	char roll[9];
	int i,j;
	int *A;
	cout<<"\t\tEnter Student Roll No. :";
	cin>>roll;
	for(i=1;i<=Number;i++){
		if(strcmp(student[i].get_roll(),roll)==0){
			cout<<"\t\t\tRecord Found\n\tRoll No. -"<<roll<<"\n\tName - "<<student[i].get_name()<<"\n\tSubject No.\t\t  Marks";
			A = student[i].get_marks();			
			for(j = 0;j<5;j++)
				cout<<"\n\t\t"<<j+1<<"\t\t\t"<<A[j];
			return ;
		}
	}
	cout<<"\t\t\tNo record found !!!\n";
}
void getAllStudentRec(void){							// Function to get all students' details.
	int i,j;
	int *A;
	cout<<"||\t\tDetails\t\t||\t\tMarks\t\t||\nS.No. Roll No.  Name\t\tS1\t S2\t S3\t S4 \tS5";
	for(i=1;i<=Number;i++){
		cout<<"\n"<<i<<". "<<student[i].get_roll()<<"  "<<student[i].get_name();
		A = student[i].get_marks();
		for(j=0;j<5;j++)
			cout<<"\t"<<A[j];
	}
	cout<<endl;
}
void getAvgMarks(void){									// Function to get average of marks in a given Subject.
	int code,i,sum=0;
	int *A;
	float avg;
	cout<<"\n\tEnter subject index (1 to 5) : ";
	cin>>code;
	if(code>5||code<1)
		return;
	for(i =0;i<=Number;i++){
		A = student[i].get_marks();
		sum += A[code-1];
	}
	avg  = (sum*1.0)/Number;
	cout<<"\t Average marks in Subject S"<<code<<" =  "<<avg<<"\n";
}


int main(){
	int option;
  while(1){
	cout<<"\t1 Set Student Record\n\t2 Get Individual Student Record\n\t3 Get Details of All Students\n\t4 Get Average Marks of a Given Subject\n\t\t 0 Exit\n";  // Menus for the user
	cin>>option;
	if(option == 1)	setStudentRecord();
	else if(option == 2) getIndStudentRec();
	else if(option == 3) getAllStudentRec();
	else if(option == 4) getAvgMarks();
	else return 0;
  }
	return 0;
}
