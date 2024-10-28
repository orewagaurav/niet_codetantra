#include <stdio.h>
#include <math.h>

int count(int n){
	int x =(pow(2,n))-1;
	return x;
}
int main(){
	int n;
	scanf("%d",&n);
	int k = count(n);
	printf("%d",k);
}