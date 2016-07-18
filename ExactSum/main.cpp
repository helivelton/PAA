#include <bits/stdc++.h>

using namespace std;


int find_x(vector<int> a, int left, int right, int playboy) {
    if (left == right) {
        if (a[left] == playboy) {
            return left;
        } else {
            return (left - 1);
        }
    }

    int mid = (left + right) / 2;
    if (a[mid] == playboy) return mid;
    else if (playboy < a[mid]) return find_x(a, left, mid, playboy);
    else return find_x(a, mid + 1, right, playboy);
}


vector<int> merge_sort(const vector<int> &data) {
    if (data.size() <= 1) {
        return data;
    }

    int middle = data.size() / 2;
    vector<int> left(data.begin(), data.begin() + middle);
    vector<int> right(data.begin() + middle, data.end());

    left = merge_sort(left);
    right = merge_sort(right);

    vector<int> result(data.size());

    merge(left.begin(), left.end(),
          right.begin(), right.end(),
          result.begin());

    return result;
}

int main() {
    int n, x, count;
    vector<int> moneys;

    vector<vector<int> > matrix;

    int endOfFile = 0;
    for (count = 0; endOfFile != EOF; ++count) {
        endOfFile = scanf("%d", &n);

        if (endOfFile != EOF) {

            vector<int> newColumn;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &x);
                newColumn.push_back(x);
            }
            matrix.push_back(newColumn);
            int money;
            scanf("%d", &money);
            moneys.push_back(money);
            //endOfFile = scanf("%d", &n);
        }
    }

    count--;

    for (int i = 0; i < count; ++i) {
        matrix.at(i) = merge_sort(matrix.at(i));
       /**
        for (int j = 0; j < matrix.at(i).size(); ++j) {

            printf("%d ", matrix.at(i)[j]);

        }
        printf("\n%d\n", moneys[i]);
        **/

        int money, book1, book2;
        money = moneys[i];
        book1 = book2 = 0;

        int halfPriceBook = find_x(matrix.at(i), 0, matrix.at(i).size(), (money / 2));


        // printf("%d\n", matrix.at(i)[halfPriceBook]);

        while ((book1 + book2) != money && halfPriceBook >= 0) {
            book2 = 0;
            int j = 0;
            while ((book1 + book2) < money) {
                ++j;
                book1 = matrix.at(i)[halfPriceBook];
                book2 = matrix.at(i)[halfPriceBook + j];

            }
            --halfPriceBook;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", book1, book2);
        //printf("%d %d\n\n", book1, book2);


    }
    return 0;
}