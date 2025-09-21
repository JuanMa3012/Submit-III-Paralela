#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[]) {
    const int N = 100;
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    float A[N], B[N];
    for (int i = 0; i < N; i++) {
        A[i] = (float)rank;
    }
    int left = (rank - 1 + size) % size;
    int right = (rank + 1) % size;
    MPI_Sendrecv(A, N, MPI_FLOAT, right, 0, B, N, MPI_FLOAT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    cout << "I am process ranked " << rank  << " and I have received b[0] = " << B[0] << endl;
    MPI_Finalize();
    return 0;
}
