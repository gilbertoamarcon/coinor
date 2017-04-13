#include <coin/ClpSimplex.hpp>
// This examples presents a basic use case of COIN-OR CLP
// linear programming solver

int main (int argc, const char *argv[]){

	if(argc<2){
		printf("Please provide problem file.\n");
		return 0;
	}

	ClpSimplex  model;
	if(model.readLp(argv[1])){
		printf("Error reading problem file.\n");
		return 0;
	}

	model.initialSolve();

	if(model.isProvenOptimal()){
		printf("Solution: ");
		const double *solution = model.getColSolution();
		for(int i=0; i<model.getNumCols(); i++)
			printf("%.3f ", solution[i]);
		printf("\nCost: %.3f\n",model.rawObjectiveValue());
	}

	return 0;
}