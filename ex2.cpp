#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int val;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        int ini = 59;
        val = ini * ini;
        cout << "Proceso 0 inicializado con variable =  " << ini << " y despues de elevarla al cuadrado = " << val << endl;
    }
    MPI_Bcast(&val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    cout << "Proceso " << rank << " tiene el valor: " << val << endl;
    MPI_Finalize();
    return 0;
}
