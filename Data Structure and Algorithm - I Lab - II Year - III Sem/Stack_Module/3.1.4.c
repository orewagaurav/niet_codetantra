#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * BalancedBrackets(char *str) {
	char open[]={'(','{','['};
	char close[]={')','}',']'};
	static char b[]="Balanced";
	static char u[]="Not balanced";
	char stack[500];
	int top = -1;
	for(int i=0;str[i]!='\0';i++){
		for(int j=0;j<3;j++){
			if(str[i]==open[j]){
				stack[++top]=open[j];
			}
			else if(str[i]==close[j]){
				if(stack[top]==open[j])
					top--;
				else{
					return u;
				}
			}
		}
	}
	if(top==-1)
		return b;
	return u;
}

int main(int argc, char *argv[]) {
	char *str = argv[1];
	printf("%s\n", BalancedBrackets(str));
	return 0;
}