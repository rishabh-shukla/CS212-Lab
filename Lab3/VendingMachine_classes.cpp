// Classes implementation part
class cashRegister{		// cash register definition								
	int cashOnHand;
	public:
		cashRegister();
		cashRegister(int);
		int getCurrentBalance(void);
		void acceptAmount(int);
};
// Constructor 1
cashRegister:: cashRegister(void){
	cashOnHand =500;
}
cashRegister:: cashRegister(int amount){			// Constructor 2
	cashOnHand = amount;
}
int cashRegister:: getCurrentBalance(void){			// Function to get balance
	return cashOnHand;
}
void cashRegister:: acceptAmount(int amount){			// Function to accept amount
	cashOnHand-=amount;
}

class dispenserType{ 						//Dispenser class definition
		int *cost;
		int *no_of_items;
	public:
		dispenserType(void);
		dispenserType(int *);
		int getNoOfItems(int);
		int getCost(int);
		void makeSale(int);
};
dispenserType:: dispenserType(void){				// Constructor 1
	cost = new int[3];
	cost[0]=cost[1]=cost[2]=50;
	no_of_items = new int[3];
	no_of_items[0] = no_of_items[1]= no_of_items[2]=50;
	return;
}
dispenserType:: dispenserType(int *arr){			// Constructor 2
	int i;
	cost = new int[3];
	no_of_items = new int[3];
	for(i=0;i<3;i++){
		cost[i] = arr[2*i];
		no_of_items[i] = arr[2*i+1];
	}
}
int dispenserType:: getNoOfItems(int item){			// Function to get No. of items of particular product
	return no_of_items[item-1];
}
int dispenserType::getCost(int item){				// function to get Cost of a particular product
	return cost[item-1];
}
void dispenserType:: makeSale(int item){			// Function to Sell a product and decreases the no. of items by one.
	no_of_items[item-1]--;
}
