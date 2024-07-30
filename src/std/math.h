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
int abs(int x){
	if(x > 0){return x;}
	else{
		return -x;
	}
}
double atan(double x){
	double result = 0.0;
	int sign = 1;
	double power = x;
	double term = x;
	for(int i = 0; i <= 25; i += 2){
		result += sign * term;
		sign = -sign;
		power *= pow(x,(double)2);
		term = power / i;
	}
	return result;

}

double sin(double x){
	double th = 0.6072529350088812;
	double y = 0.0;
	double phi = x;
	int n = 0;
	int change = 1;
	int maxit = 99;
	double d = 0.0;
	double x_next;
	double y_next;
	double phi_next;
	while (n < maxit && change > 0){
		d = phi/abs(phi);
		x_next = th - (d * y * pow(2, -n));
		y_next = y + (d * th * pow(2, -n));
		phi_next = phi - (d * atan(pow(2, -n)));
		change = abs(x_next - th) + abs(y_next - y);
		th = x_next;
		y = y_next;
		phi = phi_next;
		n += 1;
	}
	return y;

}
double cos(double x){
	double th = 0.6072529350088812;
	double y = 0.0;
	double phi = x;
	int n = 0;
	int change = 1;
	int maxit = 99;
	double d = 0.0;
	double x_next;
	double y_next;
	double phi_next;
	while (n < maxit && change > 0){
		d = phi/abs(phi);
		x_next = th - (d * y * pow(2, -n));
		y_next = y + (d * th * pow(2, -n));
		phi_next = phi - (d * atan(pow(2, -n)));
		change = abs(x_next - th) + abs(y_next - y);
		th = x_next;
		y = y_next;
		phi = phi_next;
		n += 1;
	}
	return th;
}
double tan(double x){
	double th = 0.6072529350088812;
	double y = 0.0;
	double phi = x;
	int n = 0;
	int change = 1;
	int maxit = 99;
	double d = 0.0;
	double x_next;
	double y_next;
	double phi_next;
	while (n < maxit && change > 0){
		d = phi/abs(phi);
		x_next = th - (d * y * pow(2, -n));
		y_next = y + (d * th * pow(2, -n));
		phi_next = phi - (d * atan(pow(2, -n)));
		change = abs(x_next - th) + abs(y_next - y);
		th = x_next;
		y = y_next;
		phi = phi_next;
		n += 1;
	}
	return y/th;

}
double tanh(double x){
	return (exp(x)-exp(-x))/(exp(x)+exp(-x));
}

double cosh(double x){
	return .5 * (exp(x)+exp(-x));
}

double sinh(double x){
	return .5 * (exp(x)-exp(-x));
}
double fmod(double x, double y){
	return (int)x % (int)y;
}
#endif
