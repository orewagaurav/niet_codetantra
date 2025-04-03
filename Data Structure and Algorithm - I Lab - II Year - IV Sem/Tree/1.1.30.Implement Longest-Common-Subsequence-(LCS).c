#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){
	return a > b ? a : b;
}

int lcs(char *str1,int n,char *str2,int m){
	if(n==0 || m==0){
		return 0;
	}
	if(str1[n-1]==str2[m-1]){
		return lcs(str1,n-1,str2,m-1)+1;
	}else{
		return max(lcs(str1,n-1,str2,m),lcs(str1,n,str2,m-1));
	}
}

int main(){
	char str1[100],str2[100];
	int i=0;
	char c;
	scanf("%c",&c);
	while(c!='\n'){
		str1[i++]=c;
		scanf("%c",&c);
	}
	int j=0;
	scanf("%c",&c);
	while(c!='\n'){
		str2[j++]=c;
		scanf("%c",&c);
	}
	printf("%d",lcs(str1,i,str2,j));
	return 0;
}
