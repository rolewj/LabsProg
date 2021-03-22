#include "stdio.h"
#include "math.h"
#include "stdlib.h"

typedef struct{
	double a;
	double b;
	double c;
} Parabola;

typedef struct{
	int k;
	double points[2];
} Points;

double func_y(Parabola* p, double x){
  return fabs(p->a*x*x + p->b*x + p->c);
}

double Rect_Solve(Parabola* p, double a, double b){
	printf("Enter the lower(a) limit of integration: ");
	scanf("%lf", &a);
	printf("Enter the upper(b) limits of integration: ");
	scanf("%lf", &b);
	const double dx = 0.001;
  if(a > b){
    return 0;
  }
  double S = 0.0;
  for (double x = a; x <= b; x+=dx){
    S += dx*(func_y(p, x + dx/2.0));
  }
  printf("Area from a to b: %lf", S);
}

void Direction(Parabola* p){
	if (p->a > 0){
		printf("Branches up\n");
	}
	else if (p->a < 0){
		printf("Branches down\n");
	}
	else{
		printf("Parabola does not exist\n");
	}
}

void Apex(Parabola* p){
	double x0, y0;
	x0 = -p->b / (2 * p->a);
	y0 = (4 * p->a * p->c - p->b * p->b) / (4 * p->a);
	printf("Apex of parabola: A(%g, %g)\n", x0, y0);
}

void IntersectionY(Parabola* p){
	printf("Intersection with the y-axis at a point: (0, %g)\n", p->c);
}

	
void root(Points* points, Parabola* p){
	double x1, x2;
	if (p->a == 0){
		return;
	}
	double D = p->b * p->b - 4 * p->a * p->c;
	if (D < 0){
		points->k = 0;
	}
	else if (D == 0){
		points->k = 1;
		points->points[0] = -p->b / (2 * p->a);
	} 
	else {
		points->points[0] = (-p->b - sqrt(D)) / (2 * p->a);
		points->points[1] = (-p->b + sqrt(D)) / (2 * p->a);
		points->k = 2;
	}
}

int main(int argc, char** argv){
	double a, b, c;
	int n;
	printf("Enter the number of parabolas: ");
	scanf("%d", &n);
	Points* points = malloc(sizeof(Points)*n);
	Parabola* parables = malloc(sizeof(Parabola)*n);
	for(int i = 0; i < n; i++){
		printf("Please enter an `a` value: ");
		scanf("%lf", &parables[i].a);
		printf("Please enter a  `b` value: ");
		scanf("%lf", &parables[i].b);
		printf("Please enter a  `c` value: ");
		scanf("%lf", &parables[i].c);
		root(&points[i], &parables[i]);
		Direction(&parables[i]);
		Apex(&parables[i]);
		IntersectionY(&parables[i]);
		Rect_Solve(&parables[i], a, b);
		printf("\nThe points of intersection of the parabola with the x-axis: ");
		for(int j = 0; j < points[i].k; j++){
			printf("%f ", points[i].points[j]);
		}
		printf("\n");
	}
	free(parables);
	return 0;
}
