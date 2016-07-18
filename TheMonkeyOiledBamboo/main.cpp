#include <iostream>
#include <vector>

using namespace std;


bool simulation(int energy, const vector<int> &heights, int size) {
    int distance = 0;
    for (int i = 0; i < size; ++i) {
        if ((heights[i] - distance) < energy) {
            distance += (heights[i] - distance);
        } else if ((heights[i] - distance) == energy) {
            distance += (heights[i] - distance);
            energy--;
        } else {
            return false;
        }
    }

    return true;
}


int main() {


    int inputs;
    scanf("%d", &inputs);
    vector<vector<int> > matrix;

    int *heights;
    heights = (int *) malloc(sizeof(int) * (inputs));

    for (int i = 0; i < inputs; ++i) {
        int size;
        scanf("%d", &size);

        int maxD = 0;
        int before = 0;
        int j;
        vector<int> newColumn;
        for (j = 0; j < size; ++j) {
            int height;
            scanf("%d", &height);

            if((height - before) > maxD)
            {
                maxD = (height - before);
            }
            before = height;

            newColumn.push_back(height);
        }

        heights[i] = maxD;
        matrix.push_back(newColumn);

    }

    for(int i = 0; i<inputs; ++i)
    {


        //int middle = matrix.at(i).size()/2;
        //int energy = (matrix.at(i).at(middle)  - matrix.at(i).at((middle - 1)));
        int energy = heights[i];

        bool pass = simulation(energy, matrix.at(i), matrix.at(i).size());

        if (pass) {
            while (simulation(energy, matrix.at(i), matrix.at(i).size())) {
                energy--;
            }
                energy++;
        } else {
            while (!(simulation(energy, matrix.at(i), matrix.at(i).size()))) {
                energy++;
            }

        }

        printf("Case %d: %d\n",(i+1), energy);


    }
    return 0;
}