#include <mpi.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    const int N = 10000;
    vector<float> A(N), B(N);

    for (int i = 0; i < N; i++) {
        A[i] = (float)rank;
    }

    if (size != 2) {
        if (rank == 0) {
            cout << "Este programa debe ejecutarse con 2 procesos." << endl;
        }
        MPI_Finalize();
        return 0;
    }

    int other = (rank == 0) ? 1 : 0;

    MPI_Sendrecv(
        A.data(), N, MPI_FLOAT, other, 0,
        B.data(), N, MPI_FLOAT, other, 0,
        MPI_COMM_WORLD, MPI_STATUS_IGNORE
    );

    if (rank == 0) {
        cout << "Proceso " << rank << " recibió B[1234] = " << B[1234] << endl;

    }
    
    else{
        cout << "Proceso " << rank << " recibió B[4321] = " << B[4321] << endl;
    }
    
    MPI_Finalize();

    return 0;
}
