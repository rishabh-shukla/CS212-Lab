#include<iostream>
#include "Matrix.cpp"
using namespace std;
 
 // Dislay function  (public)
void display(){
	int rowa,cola,rowb,colb;
	cout<<"Enter size of matrix A(rows cols) - "<<endl;
	cin>>rowa>>cola;
	cout<<"Enter size of matrix B(rows cols) - "<<endl;
	cin>>rowb>>colb;
	Matrix m1(rowa,cola),m2(rowb,colb);
	cout<<"Matrix A : \n";
	m1.inputMatrix();
	cout<<"Matrix B : \n";
	m2.inputMatrix();
	cout<<"\n\nMatrix A is :\n";
	m1.showMatrix();
	cout<<"\nMatrix B is :\n";
	m2.showMatrix();
	Matrix m3(rowa,cola),m4(rowa,colb),m5(cola,rowa),m8(rowa,cola);
	if(rowa==rowb&&cola==colb){
		m3 = m1+m2;
		cout<<"\n\tM1+M2 = "<<endl;
		m3.showMatrix();
		m8 = m1-m2;
		cout<<"\n\tM1-M2 ="<<endl;
		m8.showMatrix();
	}
	else cout<<"\n\tAddition and subtraction can not be done !!"<<endl;
	if(cola==rowb){
		cout<<"\n\tM1*M2 = "<<endl;
		m4 = m1*m2;
		m4.showMatrix();
	}
	else cout<<"\n\tMultiplication can not be done !!"<<endl;
	m5 = m1.transpose();
	cout<<"\n\tTranspose of M1 = "<<endl;
	m5.showMatrix();
	Matrix m6 = 2*m1;
	cout<<"\n\t2*M1 = "<<endl;
	m6.showMatrix();
	cout<<"\n\tM1*3 = "<<endl;
	Matrix m7= m1*3;
	m7.showMatrix();
}

// Main function
int main(){
	display();
}
