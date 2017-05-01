#include<iostream>
#include<string.h>
#include<stdio.h>
#include "Staff.cpp"
#include "Education.cpp"
#include "Teacher.cpp"
#include "Officer.cpp"
#include "Typist.cpp"
using namespace std;
void f(int n){
  while(n){  cout<<endl;
		n--;}
}
void display(){
	Teacher **T = new Teacher *[10];
	Officer **O = new Officer *[10];
	Typist **Ty = new Typist *[10];
	int sizeT=0,sizeO=0,sizeTy=0;
	size_t lent=0;
	while(1){
		int option=0,type,salary;
		char name[20],subject[20],publish[30],gen[15],prof[20],grade;
		f(2);
		cout<<"0 See all employees list\n1 Add teacher\n2 Add officer\n3 Add Typist\n4 Search Staff\n\n\t\tAny other number to exit\n";
		cin>>option;
		if(option==1){
			f(100);
			if(sizeT>=10){cout<<"No space available ";continue;}
			cout<<"Enter name:";cin>>name;cout<<"Enter Subject:";cin>>subject;cout<<"Enter Publish:";cin>>publish;cout<<"Enter General Education:";cin>>gen;cout<<"Enter Professional education:";cin>>prof;
			T[sizeT] = new Teacher(sizeT+sizeO+sizeTy+1,name,subject,publish,gen,prof);
			sizeT++;
		}
		else if(option==2){
			f(100);
			if(sizeT>=10){cout<<"No space available ";continue;}
			cout<<"Enter name:";cin>>name;cout<<"Enter Grade:";cin>>grade;cout<<"Enter General Education:";cin>>gen;cout<<"Enter Professional education:";cin>>prof;
			O[sizeO] = new Officer(sizeT+sizeO+sizeTy+1,name,grade,gen,prof);
			sizeO++;
		}
		else if(option==3){f(100);
			if(sizeTy>=10){cout<<"No space available ";continue;}
			cout<<"Enter name:";cin>>name;cout<<"Enter Type( 1 or 2 ):";cin>>type;
			while(type!=1&&type!=2){
				cout<<"Invalid !!!\nRe-enter type(1 or 2) :";cin>>type;
			}
			cout<<"Enter Wages:";cin>>salary;
			while(salary<=0){
				cout<<"Invalid !!!\nRe-enter wages :";cin>>salary;
			}
			Ty[sizeTy] = new Typist(sizeTy+sizeT+sizeO+1,name,type,salary);
			sizeTy++;
		}
		else if(option==0){
			f(200);
			for(int i=0;i<sizeT;i++){
				cout<<" Teacher Code : "<<T[i]->getCode()<<endl;
				cout<<" Teacher Name : "<<T[i]->getName()<<"\n"<<" Teacher Subject: "<<T[i]->getSubject()<<endl<<" Publish : "<<T[i]->getPublish()<<endl<<" General Education: "<<T[i]->getGeneralEdu()<<endl<<" Professional Education: "<<T[i]->getProfessionalEdu()<<endl;
			}
			f(2);
			for(int i=0;i<sizeO;i++){
				cout<<" Officer Code : "<<O[i]->getCode()<<endl;
				cout<<" Officer Name : "<<O[i]->getName()<<"\n"<<" Officer Grade : "<<O[i]->getGrade()<<endl<<" General Education: "<<O[i]->getGeneralEdu()<<endl<<" Professional Education: "<<O[i]->getProfessionalEdu()<<endl<<endl;
			}
			for(int i=0;i<sizeTy;i++){
				cout<<" Typist Code : "<<Ty[i]->getCode()<<endl;
				cout<<"Typist Name : "<<Ty[i]->getName()<<"\n"<<" Typist Type : "<<Ty[i]->getType()<<endl;
				if(Ty[i]->getType()==1) cout<<" Monthly Salary : "<<Ty[i]->getSalary()<<endl;
				else if(Ty[i]->getType()==1) cout<<" Daily Wages : "<<Ty[i]->getSalary()<<endl;
			}
		}
		else if(option==4){
			int cd;
			cout<<"\tEnter code for staff: ";
			cin>>cd;
			if((cd>sizeT+sizeO+sizeTy)||cd<=0){
				cout<<"No record found !";
			}
			else{
				int iter,fd=0,id;
				for(iter=0;(iter<sizeT)&&(fd==0);iter++)
						if(T[iter]->getCode()==cd){fd=1;id=iter;}
				for(iter=0;(iter<sizeO)&&(fd==0);iter++)
						if(O[iter]->getCode()==cd){fd=2;id=iter;}
				for(iter=0;(iter<sizeTy)&&(fd==0);iter++)
						if(Ty[iter]->getCode()==cd){fd=3;id=iter;}
				if(fd==1){
					cout<<" Teacher Code : "<<cd<<endl;
				cout<<" Teacher Name : "<<T[id]->getName()<<"\n"<<" Teacher Subject: "<<T[id]->getSubject()<<endl<<" Publish : "<<T[id]->getPublish()<<endl<< "General Education: "<<T[id]->getGeneralEdu()<<endl<<" Professional Education: "<<T[id]->getProfessionalEdu()<<endl;
				}
				else if(fd==2){
				cout<<" Officer Code : "<<cd<<endl;
				cout<<" Officer Name : "<<O[id]->getName()<<"\n"<<" Officer Grade : "<<O[id]->getGrade()<<endl<<" General Education: "<<O[id]->getGeneralEdu()<<endl<<" Professional Education: "<<O[id]->getProfessionalEdu()<<endl<<endl;
				}
				else if(fd==3){
				cout<<" Typist Code : "<<cd<<endl;
				cout<<"Typist Name : "<<Ty[id]->getName()<<"\n"<<" Typist Type : "<<Ty[id]->getType()<<endl;
				if(Ty[id]->getType()==1) cout<<" Monthly Salary : "<<Ty[id]->getSalary()<<endl;
				else if(Ty[id]->getType()==1) cout<<" Daily Wages : "<<Ty[id]->getSalary()<<endl;
				}
			}
		}
		else break;
	}
}
int main(){
	display();
}
