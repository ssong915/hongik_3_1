#include<stdio.h>

int sudo[9][9] = { 0, };

void print() {
    int i = 0;
    int j = 0;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++) {
            printf(" %d", sudo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int promising(int num,int row,int col) {
    int k = 0;
    int j = 0;
   //checkrow    
    for (j = 0; j < 9; j++) {
        if (sudo[row][j] == num)
            return 0;
    }
    //checkcol
    for (j = 0; j < 9; j++) {
        if (sudo[j][col] == num)
            return 0;
    }
    //checkbox
    int box_x = (row/ 3) * 3;
    int box_y = (col/ 3) * 3;
    for (k = 0; k < 3; k++) {
        for (j = 0; j < 3; j++) {
            if (sudo[box_x+k][box_y+j] == num)
                return 0;
        }
    }

    return 1;
}

int sudoku() {
    int i = 0;
    int j = 0;
    int row = 0;
    int col = 0;
    int num = 0;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (sudo[row][col] == 0) {
                for (num = 1; num < 10; num++) {
                    if (promising(num, row, col) == 1) {
                        sudo[row][col] = num;                         
                        if (sudoku()==1) return 1;
                        sudo[row][col] = 0;                        
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {

    FILE* fp;
    fp = fopen("input.txt", "r");
    int i = 0;
    int j = 0;
    int k = 0;
    int datanum = 0;

    if (fp == NULL)
        return 0;

    fscanf(fp, "%d\n", &datanum);

    for (i = 0; i < datanum; i++) {

        for (j = 0; j < 9; j++) {
            for (k = 0; k < 9; k++) {
                fscanf(fp, "%d", &sudo[j][k]);
            }
        }
        printf("sudoku %d\n", i + 1);
        sudoku();
        print();
        int sudo[9][9] = { 0, };
    }
    return 0;
}