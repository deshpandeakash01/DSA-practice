#include<iostream>
using namespace std;

struct node {
    int col;
    int val;
    struct node *next;
};

void create(node* a[], int m, int n) {
    for (int i = 0; i < m; i++) {
        a[i] = NULL;
        node* tail = NULL;

        for (int j = 0; j < n; j++) {
            int v;
            cout << "Enter value at [" << i << "][" << j << "]: ";
            cin >> v;

            if (v != 0) {
                node* t = new node;
                t->col = j;
                t->val = v;
                t->next = NULL;

                if (a[i] == NULL) {
                    a[i] = t;
                    tail = t;
                } else {
                    tail->next = t;
                    tail = t;
                }
            }
        }
    }
}

void display(node* a[], int row, int col) {
    for (int i = 0; i < row; i++) {
        node* p = a[i];
        for (int j = 0; j < col; j++) {
            if (p != NULL && j == p->col) {
                cout << p->val << " ";
                p = p->next;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void Add(struct node *a[],struct node *b[])
{
    
}
int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    node* a[m]; // Array of linked list heads
    create(a, m, n);
    cout << "\nSparse Matrix:\n";
    display(a, m, n);
}


