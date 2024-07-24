#ifndef MATH_H
#define MATH_H
double pow(double x, int y){
	for(int i = 0; i < y; i++){
		x = x*x;
	}
	return x;
}
#endif
