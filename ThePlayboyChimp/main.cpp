#include <bits/stdc++.h>

using namespace std;

int find_x(int *a, int left, int right, int playboy)
{
    if (left == right)
    {
       // printf("%s\n%d","igual ", left);
        return left;

     //   if (playboy == a[left]) return left;
     //   if(playboy < a[left] && left==0) return left;
     //   if(playboy > a[right] && right==n) return right;
    }

    int mid = (left + right) / 2;
    if (a[mid] == playboy) return mid;
    else if (playboy < a[mid]) return find_x(a, left, mid, playboy);
    else return find_x(a, mid+1, right, playboy);
}


int main() {


    int *ladys, *playboys;
    int n, q, play;

    scanf("%d",&n);

    ladys = (int *) malloc(sizeof(int) * (n+1));

    ladys[n+1] = std::numeric_limits<int>::max();
    ladys[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &ladys[i]);
    }




    scanf("%d",&q);

    playboys = (int *) malloc(sizeof(int) * q);

    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &playboys[i]);
    }


    int Llady, Rlady;

    for(int i=0;i < q; ++i) {

        int play = playboys[i];
        int equalLady = find_x(ladys, 0, n, play);


        if (play == ladys[equalLady]) {
            Llady = ladys[equalLady - 1];
            Rlady = ladys[equalLady + 1];
        } else if (play > ladys[equalLady]) {
            Llady = ladys[equalLady];
            Rlady = ladys[equalLady + 1];
        } else if (play < ladys[equalLady]) {
            Llady = ladys[equalLady - 1];
            Rlady = ladys[equalLady];
        }

        if ((Llady == -1) || (Llady == std::numeric_limits<int>::max())) {
            printf("%s ", "X");
        } else {
            printf("%d ", Llady);
        }

        if ((Rlady == -1) || (Rlady == std::numeric_limits<int>::max())) {
            printf("%s\n", "X");
        } else {
            printf("%d\n", Rlady);
        }
    }
    return 0;

}