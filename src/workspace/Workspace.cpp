//
// Created by wangliang on 8/12/2023.
//

#include "Workspace.h"
void Workspace::create(int mode)//给迷宫根据模式分配空间
{
    if(mode==1)
    {
        maze.size=11;
        maze.m=new int*[maze.size];
        for(int i=0;i<maze.size;++i)
        {
            maze.m[i]=new int[maze.size];
            for(int j=0;j<maze.size;++j)
            {
                if(j%2==1&&i%2==1)
                {
                    maze.m[i][j]=0;
                }
                else{
                    maze.m[i][j]=1;
                }
            }
        }
    }
    else if(mode==2)
    {
        maze.size=19;
        maze.m=new int*[maze.size];
        for(int i=0;i<maze.size;++i)
        {
            maze.m[i]=new int[maze.size];
            for(int j=0;j<maze.size;++j)
            {
                if(j%2==1&&i%2==1)
                {
                    maze.m[i][j]=0;
                }
                else{
                    maze.m[i][j]=1;
                }            }
        }
    }
    else if(mode == 3){
        maze.size=35;
        maze.m=new int*[maze.size];
        for(int i=0;i<maze.size;++i)
        {
            maze.m[i]=new int[maze.size];
            for(int j=0;j<maze.size;++j)
            {
                if(j%2==1&&i%2==1)
                {
                    maze.m[i][j]=0;
                }
                else{
                    maze.m[i][j]=1;
                }
            }
        }
    }
    else{
        cout<<"请自定义大小:";
        cin>>maze.size;
        maze.m=new int*[maze.size];
        for(int i=0;i<maze.size;++i)
        {
            maze.m[i]=new int[maze.size];
            for(int j=0;j<maze.size;++j)
            {
                if(j%2==1&&i%2==1)
                {
                    maze.m[i][j]=0;
                }
                else{
                    maze.m[i][j]=1;
                }
            }
        }
    }

}

void Workspace::show() const {
    for(int i=0;i<maze.size;++i)
    {
        for(int j=0;j<maze.size;++j)
        {
            printf("%d ",maze.m[i][j]);
        }
        printf("\n");
    }
}
void Workspace::init(int mode){
    int i;
    create(mode);
    for(i=0;i<maze.size;++i)
    {
        maze.m[0][i]=2;
        maze.m[maze.size-1][i]=2;
        maze.m[i][0]=2;
        maze.m[i][maze.size-1]=2;
    }
    show();
}

void Workspace::run() {
    thread ui_stream(&Workspace::ui_show,this);

    ui_stream.join();
}