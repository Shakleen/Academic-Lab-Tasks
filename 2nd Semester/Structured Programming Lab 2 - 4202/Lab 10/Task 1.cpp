#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, i = 0, x = 0;

    scanf("%d", &n);

    queue<int>q;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    printf("Discarded cards: ");

    while (q.size()>1){
        if (i%2){
            x = q.front();
            q.pop();
            q.push(x);
        }
        else{
            printf("%d ", q.front());
            q.pop();
        }

        i++;
    }

    printf("\nRemaining card: %d\n", q.front());

    return 0;
}
