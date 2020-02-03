#include <iostream>
#include <deque>
using namespace std;

deque<int> dequeue;
deque<int> target;
int n, m;

int findIndex() {
    int index = 0;
    for (; index < dequeue.size(); index++) {
        if (target.front() == dequeue[index]) {
            break;
        }
    }

    return index;
}

bool getDirection(int index) {
    if (index <= dequeue.size() / 2) {
        return true;
    }
    else {
        return false;
    }
}

void rotate(bool direction) {
    int temp;
    if (direction) {
        temp = dequeue.front();
        dequeue.pop_front();
        dequeue.push_back(temp);
    }
    else {
        temp = dequeue.back();
        dequeue.pop_back();
        dequeue.push_front(temp);
    }
}

int rotationAmount(int index, bool direction) {
    if (direction) {
        return index;
    }
    else {
        return dequeue.size() - index;
    }
}

int main(void) {
    cin >> n >> m;

    while (m--) {
        int temp;
        cin >> temp;
        target.push_back(temp);
    }

    for (int i = 1; i <= n; i++) {
        dequeue.push_back(i);
    }

    int ans = 0;
    while (!target.empty()) {
        int index = findIndex();
        bool direction = getDirection(index);
        int rotations = rotationAmount(index, direction);

        ans += rotations;

        while (rotations > -1) {
            if (dequeue.front() == target.front()) {
                dequeue.pop_front();
                target.pop_front(); 
                break;
            }
            rotate(direction);
        }
    }
    cout << ans;
    return 0;
}