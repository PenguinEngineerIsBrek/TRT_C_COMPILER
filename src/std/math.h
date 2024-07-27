#ifndef MATH_H
#define MATH_H
#define M_E 2.71828182845904523536
#define M_PI 3.14159265358979323846
double pow(double x, double y){
	for(int i = 0; i < y; i++){
		x = x*x;
	}
	return x;
}

double exp(double x){
	return pow(M_E, x);
}
#endif
