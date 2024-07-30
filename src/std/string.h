#ifndef STRING_H
#define STRING_H
int memcmp(void *str1, void *str2, size_t n){
	char *bin1;
	char *bin2;
	for(int i = n - 1; i >= 0; i--){
		bin1[i] = (*str1 & 1) ? '1' : '0';
		bin2[i] = (*str2 & 1) ? '1' : '0';
		*str1 >>= 1;
		*str2 >>= 1;
	}
}
#endif
