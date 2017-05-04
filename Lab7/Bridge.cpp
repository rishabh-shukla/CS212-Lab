#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

class Card{
		public:
	int valueOfCard;
	int numberOfCard;
	string suite;
		Card(int number=0,int value=0,string suit=""): valueOfCard(value), numberOfCard(number){
			suite.assign(suit);
		}
		void fillCard(int number,int value,string suit){
		 	valueOfCard=value;
		 	numberOfCard = number;
			suite.assign(suit);
		}
};
class PlayerHand{
	public:
		vector<Card> cards;
		int size;
		int played[13];
		PlayerHand(){size=13;
			for(int i=0;i<13;i++)
				played[i]=0;
		};
		Card playCard(int best,string bestStr);
};
Card PlayerHand::playCard(int best,string bestStr){
	int n= cards.size();
	n = size--;
	if(best==-1){
		int p = rand()%n;
		int i,j;
		Card c = cards[p];
		cards.erase(cards.begin()+i);
		return c;
	}
	else{
		int match=0,max=0,var,i;
		for(i=0;i<n;i++){
			if((cards[i].suite.compare(bestStr)==0)&&(cards[i].numberOfCard>best)){
				if(match==0){
				 match=1;
				 var=i;
				 max = cards[i].numberOfCard;
				}
				else if(cards[i].numberOfCard>max){
					var=i;
					max = cards[i].numberOfCard;
				}
			}
		}
		if(match!=0){
			Card c(cards[var]);
			cards.erase(cards.begin()+var);
			return c;
		}
		int min=20;
		for(i=0;i<n;i++){
			if((cards[i].suite.compare(bestStr)==0)){
				if(match==0){
				 match=1;
				 var=i;
				 min = cards[i].numberOfCard;
				}
				else if(cards[i].numberOfCard<min){
					var=i;
					min = cards[i].numberOfCard;
				}
			}
		}
		if(match==0){
			int p = rand()%n;
			int i,j;
			Card c = cards[p];
			cards.erase(cards.begin()+p);
			return c;
		}
		else{
			Card c(cards[var]);
			cards.erase(cards.begin()+var);
			return c;
		}
	}
}
//int evaluatePoints(PlayerHand P);
void game(){
	int i,j;
	vector<Card> pack(53);
	PlayerHand player[4];
	for(i=1;i<=13;i++)
		pack[i].fillCard(i+1,(i/10)*(i-9),"spades");
	for(i=14;i<=26;i++)
		pack[i].fillCard(i+1-13,(i/23)*(i-22),"hearts");
	for(i=27;i<=39;i++)
		pack[i].fillCard(i+1-26,(i/36)*(i-35),"diamonds");
	for(i=40;i<=52;i++)
		pack[i].fillCard(i+1-39,(i/49)*(i-48),"clubs");
	random_shuffle(pack.begin(),pack.end());
	for(i=1;i<=13;i++)
		for(j=0;j<4;j++)
			player[j].cards.push_back(pack[i*4-j]);
	for(i=0;i<4;i++){
	 cout<<" Player :"<<i+1<<"   ";
		for(j=0;j<13;j++)
			cout<<" "<<player[i].cards[j].suite<<" "<<player[i].cards[j].numberOfCard;
		cout<<endl;
	}
	int best;
	string bestStr;
	for(j = 1;j<=13;j++){
	for(i=0;i<4;i++){
		if(i==0){
		 Card c(player[i].playCard(-1,""));
		 best = c.numberOfCard;
		 bestStr = c.suite;
		 cout<<"Turn No: "<<j<<" Player No: "<<i+1<<" "<<best<<"  "<<bestStr<<endl; 
		}
		else{
			Card c = player[i].playCard(best,bestStr);
			if(c.suite== bestStr){
				best = c.numberOfCard;
				bestStr = c.suite;
			}
			cout<<"Turn No: "<<j<<" Player No: "<<i+1<<" "<<c.numberOfCard<<"  "<<c.suite<<endl; 
		}
	}
	}
}

int main(){
	game();
	return 0;
}



















