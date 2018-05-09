#include <bits/stdc++.h>

using namespace std;

struct type{
    int number;
    struct type *next;
};

struct type* input(struct type *head, int n){
    cout<<"Enter numbers:\n";

    struct type *prev = NULL;

    for(int i=0; i<n; i++){
        struct type *cur = (struct type*) malloc(sizeof(struct type));
        cin>>cur->number;

        if(!i)  head = cur;
        else    prev->next = cur;

        cur->next = NULL;
        prev = cur;
    }

    return head;
}

bool Find(struct type *head, int x, int n){
    struct type *itr = head;
    int i=0, lim=n/2;

    while(lim <= n){
//        printf("i = %d lim = %d *itr = %d\n", i, lim, itr->number);
        if(itr->number == x)    return 1;
        itr = itr->next;
        i++;
        if(i==lim){
            int temp = ceil((n-lim)/2);
            if(!temp)   lim++;
            else        lim += temp;
        }
    }

    return 0;
}

void view(struct type *head){
    struct type *itr = head;

    cout<<"Entered Numbers:\n";

    while(itr!=NULL){
        cout<<itr->number<<' ';
        itr = itr->next;
    }

    cout<<'\n';

    return;
}

int main(){
    int n=0, x=0;

    cout<<"Enter how many numbers:\n";
    cin>>n;

    struct type *head = NULL;
    head = input(head, n);

    view(head);

    cout<<"Enter number to search:\n";
    cin>>x;

    if(Find(head,x,n))      cout<<"PRESENT IN LINKED LIST";
    else                    cout<<"ABSENT IN LINKED LIST";

    return 0;
}
