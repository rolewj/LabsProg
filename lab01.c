#include "stdio.h"
#include "math.h"

int fact(int n){
	if (n == 0 || n == 1){
		return 1;
	}
	else{
		return n * fact(n - 1);
	}
}

double arccos_rec(double x, int n){
	double a = fact(2*n);
	double b = pow(2, 2*n);
	double c = pow(fact(n), 2);
	double d = pow(x, 2*n+1);
	double e = 2*n+1;
	const double E = 0.001;
	double res = (a/(b*c))*(d/e);
	if (res < E){
		return res;
	}
	return res + arccos_rec(x, n+1);
}

double arccos(double p){
	return M_PI_2 - arccos_rec(p, 0);
}

int main(int argc, char** argv){
	double x;
	printf("Enter x: ");
	scanf("%lf", &x);
	if (fabs(x) > 1){
		printf("Invalid x. It must be less than 1 but greater than -1.");
		return 1;
	}
	printf ("Result: %.3f", arccos(x));
  return 0;
}
