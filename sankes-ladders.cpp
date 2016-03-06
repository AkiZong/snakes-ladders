#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <stack>
using namespace std;

int cellNum, ladderNum, snakesNum;
bool impossible = false;
bool infinity = false;
int *visited;
int *isladder;
int *issnake;
map<int,int> steps;


void longest (int index, map<int,int>&steps, int size, int *visited, int *issnake, int *isladder) {
    if (index == size) {
        visited[index] = 1;
        steps.find(index)->second = 0;
        return;
        // if vertex is a snake
    } else if (issnake[index] != 0) {
        visited[index] = 1;
        int next = issnake[index];
        // if vertex is a snake, and its tail is visited, infinity
        if (visited[next] == 1) {
            infinity = true;
            return;
        } else {
            longest(next, steps, size, visited, issnake, isladder);
            return;
        }
        // if vertex is a ladder
    } else if (isladder[index] != 0) {
        visited[index] = 1;
        int next = isladder[index];
        int nextstep = steps.find(next)->second;
        if (nextstep == -1) {
            longest(next, steps, size, visited, issnake, isladder);
        }
        next = steps.find(next)->second;
        steps.find(index)->second = next;
        return;
        // if vertex is normal
    } else {
        visited[index] = 1;
        int dis = size - index;
        dis = min(dis, 6);
        int max = -1;
        for (int i = index+1; i < index+1+dis; i++) {
            int s = steps.find(i)->second;
            if (s == -1) {
                longest(i, steps, size, visited, issnake, isladder);
            }
            s = steps.find(i)->second;
            if (max <= s) {
                max = s;
            }
        }
        steps[index] = max+1;
    }
}

int main() {
    //readinput;
    cin >> cellNum >> ladderNum >> snakesNum;
    int head, dest;
    int size = cellNum * cellNum;
    
    // set steps
    for (int i = 0; i < cellNum * cellNum +1; i++) {
        steps[i] = -1;
    }
    
    // set visited
    int visited[cellNum*cellNum+1];
    for (int i = 0; i < cellNum * cellNum +1; i++) {
        visited[i] = 0;
    }
    
    // set ladder
    int isladder[size+1];
    for (int i = 0; i < size+1; i++) {
        isladder[i] = 0;
    }
    for (int i = 0; i < ladderNum; i++) {
        cin >> head >> dest;
        isladder[head] = dest;
    }
    
    // set snakes
    int issnake[size+1];
    for (int i = 0; i < size+1; i++) {
        issnake[i] = 0;
    }
    for (int i = 0; i < snakesNum; i++) {
        cin >> head >> dest;
        issnake[head] = dest;
    }

    
    longest(1, steps, size, visited, issnake, isladder);
    
    int laststep = steps.find(size)->second;
    
    if (laststep == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    if (infinity == true) {
        cout << "infinity" << endl;
        return 0;
    }
    
    int s = steps.find(1)->second;
    cout << s << endl;
    return 0;
}
<<<<<<< HEAD
=======


>>>>>>> origin/master
