//
// Created by wangliang on 8/12/2023.
//
#include "../workspace.h"
struct ps{
    int x,y;
};
void clearConsole() {
    cout << "\x1B[2J\x1B[H";
}

void generateMazeDFS(struct maze &maze,int p,stack<struct ps> &temp1,struct ps temp2){
    int mode=0;
    //0上1右2下3左
    if(!temp1.empty())
    {
        if(temp1.top().x-2>0&&maze.m[temp1.top().x-2][temp1.top().y]!=0)//随机到上并且不越界并且上结点未扩展
        {
            mode=1;
            if(p==0)
            {
                temp2.x=temp1.top().x-2;
                temp2.y=temp1.top().y;
                maze.m[temp2.x][temp2.y]=0;
                maze.m[temp2.x+1][temp2.y]=0;
                temp1.push(temp2);
            }
        }
        if(temp1.top().y+2<(maze.size-1)&&maze.m[temp1.top().x][temp1.top().y+2]!=0)
        {
            mode=1;
            if(p==1)
            {
                temp2.x=temp1.top().x;
                temp2.y=temp1.top().y+2;
                maze.m[temp2.x][temp2.y]=0;
                maze.m[temp2.x][temp2.y-1]=0;
                temp1.push(temp2);
            }
        }
        if(temp1.top().x+2<(maze.size-1)&&maze.m[temp1.top().x+2][temp1.top().y]!=0)
        {
            mode=1;
            if(p==2)
            {
                temp2.x=temp1.top().x+2;
                temp2.y=temp1.top().y;
                maze.m[temp2.x][temp2.y]=0;
                maze.m[temp2.x-1][temp2.y]=0;
                temp1.push(temp2);
            }
        }
        if(temp1.top().y-2>0&&maze.m[temp1.top().x][temp1.top().y-2]!=0)
        {
            mode=1;
            if(p==3)
            {
                temp2.x=temp1.top().x;
                temp2.y=temp1.top().y-2;
                maze.m[temp2.x][temp2.y]=0;
                maze.m[temp2.x][temp2.y+1]=0;
                temp1.push(temp2);
            }
        }
        if(mode==0)
        {
            temp1.pop();
        }
    }
}
void generateMazePirm(struct maze &maze,int p,stack<struct ps> &temp1,struct ps temp2){

}

void workspace::ui_show() { // NOLINT(*-convert-member-functions-to-static)
    const int targetLoopTime = 500;  // 目标循环时间，单位毫秒
    random_device rd;// 生成随机数
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0,3);
    int random_number;

    stack<struct ps> temp1;//深度优先搜索需要用到的栈
    struct ps temp2{};//中间变量
    maze.m[1][1]=0;//三代表最小生成树的路径
    temp2.x=1;temp2.y=1;
    temp1.push(temp2);
    while (true) {
        auto start = high_resolution_clock::now();

        clearConsole();
        random_number = distribution(gen);
//        generateMazeDFS(maze,random_number,temp1,temp2);
        workspace::show();

        auto end = high_resolution_clock::now();
        auto elapsedMilliseconds = duration_cast<milliseconds>(end - start).count();
        cout << elapsedMilliseconds;
        cout << "random number:" << random_number << endl;
        // 计算实际执行时间，并休眠剩余时间
        sleep_for(milliseconds(targetLoopTime - elapsedMilliseconds));
    }
}