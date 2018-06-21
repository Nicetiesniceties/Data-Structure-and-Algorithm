#include "game.h"
double table[5][5][211];

double optimize_value(int tens_position , int ones_position , int total)
{
    if(!table[tens_position][ones_position][total])return table[tens_position][ones_position][total];
	double result;
    if (total > 150)
        return 0;
    else if (!tens_position && !ones_position)
        return  total;
    else if((tens_position < 0) || (ones_position < 0))return 0;
   	else 
   	{
        result = (MAX(optimize_value(tens_position - 1 , ones_position , total + 10) , optimize_value(tens_position , ones_position - 1 , total + 1)) +
                MAX(optimize_value(tens_position - 1 , ones_position , total + 20) , optimize_value(tens_position , ones_position - 1 , total + 2)) +
                MAX(optimize_value(tens_position - 1 , ones_position , total + 30) , optimize_value(tens_position , ones_position - 1 , total + 3)) +
                MAX(optimize_value(tens_position - 1 , ones_position , total + 40) , optimize_value(tens_position , ones_position - 1 , total + 4)) +
                MAX(optimize_value(tens_position - 1 , ones_position , total + 50) , optimize_value(tens_position , ones_position - 1 , total + 5)) +
                MAX(optimize_value(tens_position - 1 , ones_position , total + 60) , optimize_value(tens_position , ones_position - 1 , total + 6))) / 6;
    }
    table[tens_position][ones_position][total] = result;
	return result;
}

// My strategy to play the dice sum game
// Returns 0 for ten's position, 1 for one's position
int myStrategy(int gameState[4][2], int diceValue){
	static int initialized;		// Static variable, default to zero
	// Add your declaration of DP structure here
	if (!initialized){
		initialized=1;
		optimize_value(4 , 4 , 0);
	}
	int tenAvailCount=0;	// No. of available ten's position
	for (int j=0; j<4; j++)
		if (gameState[j][0]<=0) {tenAvailCount=4-j; break;}
	int oneAvailCount=0;	// No. of available one's position
	for (int j=0; j<4; j++)
		if (gameState[j][1]<=0) {oneAvailCount=4-j; break;}
	if ((tenAvailCount!=0)&&(oneAvailCount==0)) return(0);
	if ((tenAvailCount==0)&&(oneAvailCount!=0)) return(1);
//	My strategy
	int strategy=3;
	int nextPos, total;
	switch(strategy){
		case 1:
			nextPos=rand()%2;
			break;
		case 2:
			nextPos=0;
			total=(gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
					+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
			if (total+diceValue*10>SCOREMAX)
				nextPos=1;
			break;
		case 3:
		    total=(gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
					+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
			nextPos = (table[tenAvailCount - 1][oneAvailCount][total + diceValue * 10] > table[tenAvailCount][oneAvailCount - 1][total + diceValue])? 0 : 1;
			break;
		default:
			printf("Error!\n");
	}
	return(nextPos);
}
