#include <iostream>
using namespace std;

class Matrix {
private:
    int row, col;
    int a[3][3];

public:

    void input() {
        cout << "Enter Rows and Columns: ";
        cin >> row >> col;

        cout << "Enter Matrix Elements:\n";

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> a[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix m) {

        Matrix temp;
        temp.row = row;
        temp.col = col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator-(Matrix m) {

        Matrix temp;
        temp.row = row;
        temp.col = col;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp.a[i][j] = a[i][j] - m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator*(Matrix m) {

        Matrix temp;

        temp.row = row;
        temp.col = m.col;

        for (int i = 0; i < temp.row; i++) {
            for (int j = 0; j < temp.col; j++) {

                temp.a[i][j] = 0;

                for (int k = 0; k < col; k++) {
                    temp.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }

        return temp;
    }

    void transpose() {

        cout << "\nTranspose Matrix:\n";

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                cout << a[j][i] << " ";
            }
            cout << endl;
        }
    }

    void checkSymmetric() {

        if (row != col) {
            cout << "Matrix is Not Symmetric.\n";
            return;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (a[i][j] != a[j][i]) {
                    cout << "Matrix is Not Symmetric.\n";
                    return;
                }
            }
        }

        cout << "Matrix is Symmetric.\n";
    }

    void determinant() {

        if (row != col) {
            cout << "Determinant Not Possible.\n";
            return;
        }

        if (row == 1) {

            cout << "Determinant = " << a[0][0] << endl;
        }

        else if (row == 2) {

            int det = a[0][0] * a[1][1] -
                      a[0][1] * a[1][0];

            cout << "Determinant = " << det << endl;
        }

        else if (row == 3) {

            int det =
            a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
          - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
          + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

            cout << "Determinant = " << det << endl;
        }

        else {

            cout << "Only up to 3x3 Supported.\n";
        }
    }
};

int main() {

    Matrix A, B, C;

    cout << "Enter First Matrix\n";
    A.input();

    cout << "\nEnter Second Matrix\n";
    B.input();

    cout << "\nAddition\n";
    C = A + B;
    C.display();

    cout << "\nSubtraction\n";
    C = A - B;
    C.display();

    cout << "\nMultiplication\n";
    C = A * B;
    C.display();

    cout << "\nFirst Matrix\n";
    A.transpose();

    cout << endl;
    A.checkSymmetric();

    A.determinant();

    return 0;
}
