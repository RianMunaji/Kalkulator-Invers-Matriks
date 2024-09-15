#include <iostream>   // Untuk input dan output dasar (cin, cout)
#include <iomanip>    // Untuk mengatur format output (setprecision, setw)

using namespace std;

// Fungsi untuk menghitung determinan matriks 3x3
float determinant3x3(float mat[3][3]) {
    float det =
        mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
        - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
        + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    
    return det;
}

// Fungsi untuk menghitung invers matriks 3x3
void inverse3x3(float mat[3][3]) {
    float det = determinant3x3(mat);

    if (det == 0) {
        cout << "Invers tidak dapat dihitung karena determinan = 0." << endl;
        return;
    }

    float invMat[3][3];

    // Menghitung matriks kofaktor dan kemudian membagi dengan determinan
    invMat[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) / det;
    invMat[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) / det;
    invMat[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) / det;
    invMat[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) / det;
    invMat[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) / det;
    invMat[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) / det;
    invMat[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) / det;
    invMat[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) / det;
    invMat[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) / det;

    // Output invers matriks dengan format rapi
    cout << "Invers Matriks 3x3:" << endl;
    cout << fixed << setprecision(4);  // Mengatur presisi hingga 4 digit desimal
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << invMat[i][j] << "\t";  // Mengatur lebar kolom
        }
        cout << endl;
    }
}

// Fungsi utama
int main() {
    float mat3x3[3][3];
    cout << "Masukkan elemen matriks 3x3:" << endl;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mat3x3[i][j];
        }
    }

    // Panggil fungsi untuk menghitung invers 3x3
    inverse3x3(mat3x3);

    return 0;
}
