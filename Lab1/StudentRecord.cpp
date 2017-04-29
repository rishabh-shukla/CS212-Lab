#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int Number = 0,SIZE = 10;

//Student structure
struct Student{
	char first_name[15],last_name[15];
	char roll_no[9];
	int marks[5];
};
Student *student = new Student[11];

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
		if(strcmp(student[i].roll_no,roll)==0){					//Checking whether student already exists.  If found, edit details !!! Not add !!!
			strcpy(student[i].first_name,first);
			strcpy(student[i].last_name,last);
			for(j = 0;j< 5;j++)
				student[i].marks[j] = mark[j];
			cout<<"\tSuccessfully changed student details !\n";
			return ;
		}
	}
			// If record not found for Roll No, add new student.
	Number++;
	strcpy(student[Number].first_name,first);
	strcpy(student[Number].last_name,last);
	strcpy(student[i].roll_no,roll);
	for(j = 0;j< 5;j++)
		student[Number].marks[j] = mark[j];
	cout<<"\tSuccessfully added Student details !\n";
	return ;
}

// Get Individual Student details
void getIndStudentRec(void){
	char roll[9];
	int i,j;
	cout<<"\t\tEnter Student Roll No. :";
	cin>>roll;
	for(i=1;i<=Number;i++){
		if(strcmp(student[i].roll_no,roll)==0){
			cout<<"\t\t\tRecord Found\n\tRoll No. -"<<roll<<"\n\tName - "<<student[i].first_name<<" "<<student[i].last_name<<"\n\tSubject No.\t\t  Marks";
			for(j = 0;j<5;j++)
				cout<<"\n\t\t"<<j+1<<"\t\t\t"<<student[i].marks[j];
			return ;
		}
	}
	cout<<"\t\t\tNo record found !!!\n";
}
void getAllStudentRec(void){							// Function to get all students' details.
	int i,j;
	cout<<"||\t\tDetails\t\t||\t\tMarks\t\t||\nS.No. Roll No.  Name\t\tS1\t S2\t S3\t S4 \tS5";
	for(i=1;i<=Number;i++){
		cout<<"\n"<<i<<". "<<student[i].roll_no<<"  "<<student[i].first_name<<"  "<<student[i].last_name;
		for(j=0;j<5;j++)
			cout<<"\t"<<student[i].marks[j];
	}
	cout<<endl;
}
void getAvgMarks(void){									// Function to get average of marks in a given Subject.
	int code,i,sum=0;
	float avg;
	cout<<"\n\tEnter subject index (1 to 5) : ";
	cin>>code;
	if(code>5||code<1)
		return;
	for(i =0;i<=Number;i++){
		sum += student[i].marks[code-1];
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
}
