#include<iostream>
#include<stdio.h>
using namespace std;
class cashRegister{
	int cashOnHand;
	public:
		cashRegister();
		cashRegister(int);
		int getCurrentBalance(void);
		void acceptAmount(int);
};
cashRegister:: cashRegister(void){
	cashOnHand =500;
}
cashRegister:: cashRegister(int amount){
	cashOnHand = amount;
}
int cashRegister:: getCurrentBalance(void){
	return cashOnHand;
}
void cashRegister:: acceptAmount(int amount){
	cashOnHand+=amount;
}

class dispenserType{
		int *cost;
		int *no_of_items;
	public:
		dispenserType(void);
		dispenserType(int *);
		int getNoOfItems(int);
		int getCost(int);
		void makeSale(int);
};
dispenserType:: dispenserType(void){
	cost = new int[3];
	cost[0]=cost[1]=cost[2]=50;
	no_of_items = new int[3];
	no_of_items[0] = no_of_items[1]= no_of_items[2]=50;
	return;
}
dispenserType:: dispenserType(int *arr){
	int i;
	cost = new int[3];
	no_of_items = new int[3];
	for(i=0;i<3;i++){
		cost[i] = arr[2*i];
		no_of_items[i] = arr[2*i+1];
	}
}
int dispenserType:: getNoOfItems(int item){
	return no_of_items[item-1];
}
int dispenserType::getCost(int item){
	return cost[item-1];
}
void dispenserType:: makeSale(int item){
	no_of_items[item-1]--;
}
