#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>


void set_board(std::vector<std::vector<int>> &board,int k);
void print_board(std::vector<std::vector<int>> &board);
std::vector<int> next_move(int i,int j,int x);
void simulate_ant(int k);

int main()
{
	 /* ?\n;||(or) e &&(and)*/
	srand(time(NULL));

	simulate_ant(10);

	return 0;
}



std::vector<int> next_move(int i,int j,int x,bool positive){

	/*(i,j) -> position in the grid,x is a direction:UP:0,LEFT:1,DOWN:2,LEFT:3
	 * this function will give the new position base on the current and in the direction,the new direction y is just x+1
	 * if x == 3 then y = 0 instead.
	 */
	//positive:clockwise;negative:counter-clockwise
	std::vector<int> move = {-1,-1,-1};
	int unit = 1;
	if(!positive){
		unit *= -1;
	}
	if(x == 0){
		move[0] = i-1;
		move[1] = j;
		move[2] = x+unit;
	}
	if(x == 1){
		move[0] = i;
		move[1] = j+1;
		move[2] = x+unit;
	}
	if(x == 2){
		move[0] = i+1;
		move[1] = j;
		move[2] = x+unit;
	}
	if(x == 3){
		move[0] = i;
		move[1] = j-1;
		move[2] = x+unit;
	}
	if(move[2] > 3){
		move[2] = 0;
	}
	if(move[2] < 0){
		move[2] = 3;
	}

	return move;
}

void print_board(std::vector<std::vector<int>> &board){

	for(int i = 0;i < board.size();i++){

		for(int j = 0;j < board[i].size();j++){
			std::cout<< board[i][j] << " ";
		}
		std::cout << '\n';
	}

}

void set_board(std::vector<std::vector<int>> &board,int k){
	//randomlly place a white:0 or black:1
	for(int i = 0;i < 2*k;i++){
		std::vector<int> v;
		board.push_back(v);
		for(int j = 0;j < 2*k;j++){
			board[i].push_back(rand() % 2);//0 or 1
		}
	}

}

void simulate_ant(int k){

	std::vector<std::vector<int>> board;
	set_board(board,k);

	//I will place the ant at the position (k,k) and it will face right(1) initially
	int i = k;
	int j = k;
	int x = 1;

	std::vector<int> move;
	for(int l = 0;l < k;l++){

		if(!board[i][j]){

			board[i][j] = !board[i][j];

			//get next move,90 clockwise
			move = next_move(i,j,x,true);
			i = move[0];
			j = move[1];
			x = move[2];
		}
		else if(board[i][j]){

			board[i][j] = !board[i][j];

			//get next move,90 counter-clockwise
			move = next_move(i,j,x,false);
			i = move[0];
			j = move[1];
			x = move[2];
		}
	}
	print_board(board);

}
