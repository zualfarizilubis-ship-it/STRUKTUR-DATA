#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int jumlahTitik;
    vector<vector<int>> adjMatrix;

public:
    Graf(int n) {
        jumlahTitik = n;
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < jumlahTitik && j >= 0 && j < jumlahTitik) {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        } else {
            cout << "Index tidak valid!" << endl;
        }
    }

    void tampil() {
        for (int i = 0; i < jumlahTitik; i++) {
            for (int j = 0; j < jumlahTitik; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graf graph(5);
    
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 4);
    graph.addEdge(1, 4, 7);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 8);
    
    graph.tampil();
    
    return 0;
}