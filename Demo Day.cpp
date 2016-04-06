时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
You work as an intern at a robotics startup. Today is your company's demo day. During the demo your company's robot will be put in a maze and without any information about the maze, it should be able to find a way out.

The maze consists of N * M grids. Each grid is either empty(represented by '.') or blocked by an obstacle(represented by 'b'). The robot will be release at the top left corner and the exit is at the bottom right corner.

Unfortunately some sensors on the robot go crazy just before the demo starts. As a result, the robot can only repeats two operations alternatively: keep moving to the right until it can't and keep moving to the bottom until it can't. At the beginning, the robot keeps moving to the right.

rrrrbb..            
...r....     ====> The robot route with broken sensors is marked by 'r'. 
...rrb..
...bb...
While the FTEs(full-time employees) are busy working on the sensors, you try to save the demo day by rearranging the maze in such a way that even with the broken sensors the robot can reach the exit successfully. You can change a grid from empty to blocked and vice versa. So as not to arouse suspision, you want to change as few grids as possible. What is the mininum number?

输入
Line 1: N, M.

Line 2-N+1: the N * M maze.



For 20% of the data, N * M <= 16.

For 50% of the data, 1 <= N, M <= 8.

For 100% of the data, 1<= N, M <= 100.

输出
The minimum number of grids to be changed.

样例输入
4 8
....bb..
........
.....b..
...bb...
样例输出
1

code:
#include<iostream>
#include<stdlib.h>
using namespace std;
char **data;
    int N,M;
int zou(int i,int j,bool state)
{
    if(i==0&&j==0)
        
        return 0;
    else if(i==0)
    {
        if(data[i][j]=='.')
            return zou(i,j-1,state);
        if(data[i][j]=='b')
            return zou(i,j-1,state)+1;
    }
    else if(j==0)
    {
        if(data[i][j]=='.')
            return zou(i-1,j,state);
        if(data[i][j]=='b')
            return zou(i-1,j,state)+1;
    }
    else if(state == 1&&data[i][j]=='.')
    {
        return (zou(i,j-1,state)<zou(i,j-1,!state)+1)?zou(i,j-1,state):zou(i,j-1,!state)+1;
    }
    else if(state == 1&&data[i][j]=='b')
    {
        return zou(i,j-1,!state)+1;
    }
    else if(state == 0&&data[i][j]=='.')
    {
        return (zou(i-1,j,state)<zou(i-1,j,!state)+1)?zou(i-1,j,state):zou(i-1,j,!state)+1;
    }
    else if(state == 0&&data[i][j]=='b')
    {
        return zou(i-1,j,!state)+1;
    }
    else return 1000;
}
int main()
{

        cin >> N >> M;
    data = new char*[N];
    for(int i = 0; i < N; i++)
        data[i] = new char[M];

    for(int i = 0; i<N;i++)
        for(int j = 0; j<M; j++)
        cin >> data[i][j];
    bool state = 1;
    int result1 = zou(N-1,M-1,1);
	int result0 = zou(N-1,M-1,0);
	if(result1<=result0)
    cout << result1<<endl;
    else cout<< result0<<endl;
}
