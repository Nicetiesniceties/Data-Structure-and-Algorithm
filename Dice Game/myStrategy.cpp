#include "game.h"
double ExpTable[5][5][211];//Expected Value Table [ten's][one's][value] 
bool CheckTable[5][5][211];
double Max(double a, double b){return (a > b) ? a : b;}
double Return(double ExpVal, int ten, int one, int value)
{
	CheckTable[ten][one][value] = true;
	ExpTable[ten][one][value] = ExpVal;
	//cout << ExpVal <<"\n";
	return ExpVal;
}
double Exp(int ten, int one, int value)//evaluate the expected value
{
	if(CheckTable[ten][one][value])return ExpTable[ten][one][value];
	if(value > SCOREMAX)return 0;
	if((one < 0) || (ten < 0)) return 0;
	if((!one) && (!ten) )return Return(value, ten, one, value); 
	double temp = 0;
	for(int i = 1; i <= 6; i++)temp += Max(Exp(ten - 1, one, value + i * 10), Exp(ten, one - 1, value + i)) / 6;
	//if(temp > SCOREMAX)return Return(0, ten, one, value);
	return Return(temp, ten, one, value);
}
// My strategy to play the dice sum game
// Returns 0 for ten's position, 1 for one's position
int myStrategy(int gameState[4][2], int diceValue){
	int tenAvailCount=0;	// No. of available ten's position
	for (int j=0; j<4; j++)
		if (gameState[j][0]<=0) {tenAvailCount=4-j; break;}
	int oneAvailCount=0;	// No. of available one's position
	for (int j=0; j<4; j++)
		if (gameState[j][1]<=0) {oneAvailCount=4-j; break;}
	if ((tenAvailCount!=0)&&(oneAvailCount==0)) return(0);
	if ((tenAvailCount==0)&&(oneAvailCount!=0)) return(1);
//	My strategy
	int nextPos;
	int total = (gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
				+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
	if(Exp(tenAvailCount, oneAvailCount - 1, total + diceValue) > Exp(tenAvailCount - 1, oneAvailCount, total + 10 * diceValue))
		nextPos = 1;
	else nextPos = 0;
	return(nextPos);
}
