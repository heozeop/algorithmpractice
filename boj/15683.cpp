#include  <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int UNUSED = -1;
const int NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3;
const int MOVEONDIRECTION[4][2] = { {-1, 0},{0, 1}, {1, 0}, {0, -1} };
const int FIRSTCAMERAID = 1;
const int DEFAULTVALUE = 0;
const int EMPTY = 0;
const int WALL = 100;
const int CAMERA = 99;

class Camera {
public:
    pair<int, int> location;
    int type;
    int direction;
};
int office[20][20];
int numOfTypeDirection[5] = { 4,2,4,4,1 };
int row, col, numOfUncensoredArea, numOfCameras;
Camera camera[10];

int getThreshold(pair<int, int> location, int direction) {
    switch (direction) {
    case NORTH:
        return location.first;
    case EAST:
        return col - location.second - 1;
    case SOUTH:
        return row - location.first - 1;
    case WEST:
        return location.second;
    }
}

int makeUncovered(int id, pair<int, int> location, int direction) {
    int threshold = getThreshold(location, direction);

    for (int i = 1; i <= threshold; i++) {
        int tmpRow = location.first + i * MOVEONDIRECTION[direction][0];
        int tmpCol = location.second + i * MOVEONDIRECTION[direction][1];

        int officeVal = office[tmpRow][tmpCol];

        if (officeVal == WALL)
            break;
        if (officeVal == id) {
            office[tmpRow][tmpCol] = EMPTY;
        }
    }
    return 0;
}

int countCovered(int id, pair<int,int> location, int direction) {
    int threshold = getThreshold(location, direction);
    int count = 0;
    for (int i = 1; i <= threshold; i++) {
        int tmpRow = location.first + i * MOVEONDIRECTION[direction][0];
        int tmpCol = location.second + i * MOVEONDIRECTION[direction][1];

        int officeVal = office[tmpRow][tmpCol];
        
        if (officeVal == WALL)
            break;
        if (officeVal == EMPTY) {
            count++;
            office[tmpRow][tmpCol] = id;
        }
    }
    return count;
}

int setArea(int index, int (*const function)(int,pair<int,int>, int)) {
    int type = camera[index].type;
    int direction = camera[index].direction;
    pair<int, int> location = camera[index].location;
   
    switch (type) {
    case 1:
        return (*function)(index, location, direction); // on direction
    case 2:
        return (*function)(index, location, direction) // on direction 
            + (*function)(index, location, (direction + 2) % 4);  // opposite direction
    case 3:
        return (*function)(index, location, direction) // on direction
            + (*function)(index, location, (direction + 1) % 4); // righthand side direction
    case 4:
        return (*function)(index, location, direction) // ondirection
            + (*function)(index, location, (direction + 1) % 4) // righthand side direction
            + (*function)(index, location, (direction + 3) % 4); // lefthand side direction
    case 5:
        return (*function)(index, location, NORTH)
            + (*function)(index, location, EAST)
            + (*function)(index, location, SOUTH)
            + (*function)(index, location, WEST);
    }
}

int getNumOfCensoredArea(int index, int value) {
    if (index > numOfCameras) {
        return value;
    }

    Camera* tmpCamera = &camera[index];
    int nextNum = value;
    for (int i = 0; i < numOfTypeDirection[tmpCamera->type - 1]; i++) {
        tmpCamera->direction = i;
        int temp = value + setArea(index, countCovered);
        nextNum = max(nextNum, getNumOfCensoredArea(index + 1, temp));
        setArea(index, makeUncovered);
        tmpCamera->direction = UNUSED;
    }
    return nextNum;
}

int main(void) {
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int temp;
            cin >> temp;
            office[i][j] = temp;

            if (temp != 0) {
                if (temp != 6) {
                    numOfCameras++;
                    camera[numOfCameras].location.first = i;
                    camera[numOfCameras].location.second = j;
                    camera[numOfCameras].type = temp;
                    camera[numOfCameras].direction = UNUSED;
                    office[i][j] = CAMERA;
                }
                else {
                    office[i][j] = WALL;
                }
                numOfUncensoredArea++;
            }
        }
    }
    cout << row * col - numOfUncensoredArea - getNumOfCensoredArea(FIRSTCAMERAID, DEFAULTVALUE);
}