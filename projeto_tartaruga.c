#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>

#define N 50000000000

int main(int argc, char* argv[]) {
	long i;
	long double S = 0.0;
	double delta;
	double comeco = omp_get_wtime();
	int thread_count = strtol(argv[1], NULL, 10);
	
	#pragma omp parallel for num_threads(thread_count) reduction(+:S) private(i)
			for(i = 1; i<N;i++){
				
				#pragma omp atomic
				S += (1.0/i);

	}
	delta = omp_get_wtime() - comeco;
	printf("Valor de S= %Lf\n", S);
	printf("Valor de T= %14ld\n", N);
	printf("calculado em %.4g segundos\n", delta);

}

