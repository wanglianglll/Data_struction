#include "./workspace/Workspace.h"

Workspace workspace;

int main() {
    int mode;
    cout << "input mode:";
    cin >> mode;
    workspace.init(mode);
//    workspace.run();
}


