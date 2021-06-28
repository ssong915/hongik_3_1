#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define nodeNum 1000

typedef struct tree {
    int left;
    int right;
    int chk;
    int parent;
}Tree;


// 노드 개수만큼 배열 선언
Tree tree[nodeNum];

void init() {
    int i;
    for (i = 0; i < nodeNum - 1; i++)
    {
        tree[i].chk = -1;
        tree[i].right = -1;
        tree[i].left = -1;
        tree[i].parent = -1;
    }
}

int main() {
    init();
    FILE* fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL)
        return 0;

    int data_num;
    fscanf(fp, "%d\n", &data_num);

    while (data_num > 0) {
        int node_num;
        int ans = 0;
        fscanf(fp, "%d\n", &node_num);
        int i;
        for (i = 0; i < node_num; i++) {
            int parent, left_child, right_child;
            fscanf(fp, "%d %d %d\n", &parent, &left_child, &right_child);
            add(parent, left_child, right_child);
        }

        for (i = 1; i < node_num + 1; i++) {
            int left_num = countnode(tree[i].left);
            int right_num = countnode(tree[i].right);
            if (left_num < right_num) {
                ans++;
            }
        }
        printf("%d\n", ans);
        data_num--;
        init();
    }
}

add(int parent, int left_child, int right_child) {
    if (left_child == -1 && right_child != -1) {
        tree[parent].right = right_child;
        tree[parent].chk = 1;
        tree[right_child].chk = 1;
        tree[right_child].parent = parent;
    }
    else if (left_child != -1 && right_child == -1) {
        tree[parent].left = left_child;
        tree[parent].chk = 1;
        tree[left_child].chk = 1;
        tree[left_child].parent = parent;
    }
    else {
        tree[parent].left = left_child;
        tree[parent].chk = 1;
        tree[left_child].chk = 1;
        tree[left_child].parent = parent;
        tree[parent].right = right_child;
        tree[parent].chk = 1;
        tree[right_child].chk = 1;
        tree[right_child].parent = parent;


    }
}

int countnode(int root) {
    int count = 0;
    if (tree[root].chk != -1) {
        count = 1 + countnode(tree[root].left) + countnode(tree[root].right);
    }
    return count;
}