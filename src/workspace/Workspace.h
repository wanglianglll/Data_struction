//
// Created by wangliang on 8/12/2023.
//

#ifndef DATA_STRUCTION_WORKSPACE_H
#define DATA_STRUCTION_WORKSPACE_H

#include <iostream>
#include <sstream>
#include <thread>
#include <fstream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<iostream>

using std::cout,std::cin,std::endl,std::thread;

struct  maze{
    int size;//大小
    int ** m;//根据size创建的二维矩阵,用来存储迷宫
};

class Workspace {
private:
    maze maze;

public:
    void create(int mode);
    void show() const;
    void init(int mode);

    void run();

    void ui_show();
};


#endif //DATA_STRUCTION_WORKSPACE_H
