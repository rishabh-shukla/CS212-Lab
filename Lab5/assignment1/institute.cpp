#include<iostream>
#include "institute.h"

using namespace std;
Staff::Staff(int Code,char *Name):code(Code){
	name = new char[strlen(Name)];
	strcpy(name,Name);
}
Teacher::Teacher(int Code,char *Name,char *sub,char *pub):Staff(Code,Name){
	subject = new char[strlen(sub)];
	strcpy(subject,sub);
	publish = new char [strlen(pub)];
	strcpy(publish,pub);
}
Officer::Officer(int Code, char *Name,char Grade):Staff(Code,Name),grade(Grade){}
Typist::Typist(int Code,char*Name,int Type,int sal): Staff(Code,Name),type(Type),salary(sal){}
