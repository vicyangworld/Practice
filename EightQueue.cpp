/*
Author:yangwk
Data  :2018-1-21

*/
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

const int QUEUES = 8;
static int count = 1;

int lengthOfState(int *&pState){
	int len = 0; 
	for (int i = 0; i < QUEUES; ++i)
	{
		if (pState[i] != -1) len++;
	}
	return len;
}

//pState is 1D array, the element stands for col position of queue
//the index of element stands for row position of queue
//col: is the col position of next queue on next row 
bool conflict(int *&pState, int col){
	int len = lengthOfState(pState);
	if (len==0) return false;
	for (int i = 0; i < len; ++i)
	{
		if (abs(pState[i]-col)==0 || abs(pState[i]-col)==len-i)
		{
			return true;
		}
	}
	return false;
}

void queue(int *&pState,int row){
	for (int col = 0; col < QUEUES; ++col)
	{
		//restore current state to eliminate the record of the position choice of the next queue(row)
		for (int i = row; i < QUEUES; ++i)
		{
			pState[i] = -1;
		}
		if (!conflict(pState, col))
		{
			//if the col position of next queue on next row doesn't
			// conflict with the current state, we add the postion to current state.
			pState[row] = col;
			if (row == QUEUES-1)
			{
				//if we have find a solution, print it,
				// and then the code will return to last level and contine the out for-loop
				// and the state will restore
				cout<< count++ <<"  (";
				for (int j = 0; j < QUEUES; ++j)
				{
					cout<<" "<<pState[j];
				}
				cout<<" )"<<endl;
				return;
			}
			else
			{
				queue(pState,row+1);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int *state = new int[QUEUES];
	for (int i = 0; i < QUEUES; ++i)
	{
		state[i] = -1;
	}
	queue(state,0);
	return 0;
}
