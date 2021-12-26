// ���� V��, ���� E��
// 1 ~ V���� ���� �ִ� ��� �� ����ϱ�

/*
* ���� �ִ� 4���� ���� �ϸ� ���ͽ�Ʈ�� �˰��� ������ 1753 ���� ���� Ǯ�� �մϴ�.
* �� ������ �޸� ���ѿ� �Ȱɸ� �� ������ �׳� �ϴ� o^2�� Ǯ�ڽ��ϴ�.
* �̰� n^2���? ¼��
* 
* ���� 4ĭ�ΰ� �����ϴ��� ���ݸ� �����ּ��� �̤�
* 
* ù�� ���� V�ٿ� ���� => 1~V���� ���鼭
* i��° �ٿ� i�� ���������� �ִ� ����� ��ΰ� => [����][i]�� �ּڰ�
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_VERTEX_SIZE = 20001;
const int MAX_EDGE_SIZE = 300000;
const int INF = 11;

int values[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
int minValues = [MAX_VERTEX_SIZE];
int visitedVertexNumber= [MAX_VERTEX_SIZE];
int v, e;
int startVertexNumber;

void init() {
    memset(values, INF, sizeof values);
    memset(minValues, INF, sizeof minValues);

    cin >> v >> e >> startVertexNumber;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        values[u][v] = w;
    }
    minValues[startVertexNumber] = 0;
}

int getNextValues() {
    int min = INF;
    int index = -1;
    for (int i = 1; i < v; ++i) {
        if (!visitedVertexNumber[i] && minValues[i] < min) {
            min = minValues[i];
            index = i;
        }
    }

    return index;
}

void setVisitable(int current) {
    for (int i = 1; i <= v; ++i) {
        bool isVisited = visitedVertexNumber[i] == 1;
        int throughPathWeight = minValues[current] + values[current][i];

        if (!isVisited && minValues[i] > throughPathWeight) {
            minValues[i] = throughPathWeight;
        }
    }
}

void calcMinValues() {
    initMinValues();
    int visitedVertex = -1;
    while () {
        /*
            ������ �ȵǼ� ���鼭 �ҰԿ�
            1. �湮�� ��� ����
            2. �湮�� ��忡�� �� �� �ִ� ��� ��ġ �ѹ� �� ����
        */
        visitedVertex = getNextValues();
        if (visitedVertex < 0) {
            return;
        }
        visitedVertexNumber[visitedVertex] = 1;
        setVisitable(visitedVertex);
    }
}

// ���� ���� ������ ����մϴ�.
void printMinWeights() {
    for (int i = 1; i <= v; ++i) {
        if (minValues != INF) {
            cout << minValues[i] << endl;
        }
        cout << "INF" << endl;
    }
}

void main(void) {
    init();
    calcMinValues();
    printMinWeights();
    return;
}
