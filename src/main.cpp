#include "./workspace/workspace.h"

workspace workspace;

int main() {
    int mode;
    cout << "input mode:";
    cin >> mode;
    workspace.init(mode);
    workspace.run();
}


