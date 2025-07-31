#include<iostream>
using namespace std;

void inputMatrix(int &r, int &c, int mat[100][100], int tuple[100][3], int &count) {
    count = 0;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    cout << "Enter the elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0) {
                tuple[++count][0] = i;
                tuple[count][1] = j;
                tuple[count][2] = mat[i][j];
            }
        }
    }
    tuple[0][0] = r;
    tuple[0][1] = c;
    tuple[0][2] = count;
}

void displayMatrix(int r, int c, int mat[100][100]) {
    cout << "Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void displayTuple(int tuple[100][3], int count) {
    cout << "Tuple representation:\n";
    for (int i = 0; i <= count; i++) {
        for (int j = 0; j < 3; j++)
            cout << tuple[i][j] << " ";
        cout << "\n";
    }
}

void transpose(int tuple[100][3], int result[100][3]) {
    int rows = tuple[0][0], cols = tuple[0][1], terms = tuple[0][2];
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = terms;
    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (tuple[j][1] == i) {
                result[k][0] = tuple[j][1];
                result[k][1] = tuple[j][0];
                result[k][2] = tuple[j][2];
                k++;
            }
        }
    }
    cout << "Transpose of sparse matrix (in tuple form):\n";
    for (int i = 0; i <= terms; i++) {
        for (int j = 0; j < 3; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}

void addSparse(int a[100][3], int b[100][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrix dimensions do not match for addition!\n";
        return;
    }
    int res[200][3], i = 1, j = 1, k = 1;
    int termsA = a[0][2], termsB = b[0][2];
    while (i <= termsA && j <= termsB) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                res[k][0] = a[i][0];
                res[k][1] = a[i][1];
                res[k][2] = sum;
                k++;
            }
            i++; j++;
        }
        else if ((a[i][0] < b[j][0]) || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k][2] = a[i][2];
            i++; k++;
        }
        else {
            res[k][0] = b[j][0];
            res[k][1] = b[j][1];
            res[k][2] = b[j][2];
            j++; k++;
        }
    }
    while (i <= termsA) {
        res[k][0] = a[i][0];
        res[k][1] = a[i][1];
        res[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= termsB) {
        res[k][0] = b[j][0];
        res[k][1] = b[j][1];
        res[k][2] = b[j][2];
        j++; k++;
    }

    res[0][0] = a[0][0];
    res[0][1] = a[0][1];
    res[0][2] = k - 1;

    cout << "Resultant Sparse Matrix (Tuple form):\n";
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < 3; y++)
            cout << res[x][y] << " ";
        cout << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nChoose Operation:\n1. Transpose of Sparse Matrix\n2. Addition of Two Sparse Matrices\n0. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int r, c, mat[100][100], tuple[100][3], result[100][3], count;
            inputMatrix(r, c, mat, tuple, count);
            displayMatrix(r, c, mat);
            displayTuple(tuple, count);
            transpose(tuple, result);
        }
        else if (choice == 2) {
            int r1, c1, mat1[100][100], tuple1[100][3], count1;
            int r2, c2, mat2[100][100], tuple2[100][3], count2;
            cout << "Enter Matrix 1:\n";
            inputMatrix(r1, c1, mat1, tuple1, count1);
            cout << "Enter Matrix 2:\n";
            inputMatrix(r2, c2, mat2, tuple2, count2);
            addSparse(tuple1, tuple2);
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
