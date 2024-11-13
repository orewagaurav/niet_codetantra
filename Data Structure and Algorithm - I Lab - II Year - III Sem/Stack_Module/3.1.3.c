#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int pre(char c){
	if(c=='+'||c=='-')return 1;
	if(c =='*'||c=='/')return 2;
	if(c == '^')return 3;
	return 0;
}
int isOperator(char ch){
	return ch=='+'||ch =='-'||ch=='*'||ch=='/'||ch=='^';
}

char * InfixToPostfix(char *expr) {
	char *postfix = (char *)malloc(MAX* sizeof(char));
	char stack[MAX];
	int top =-1;
	int k=0;
	for(int i =0;expr[i];i++){
		if(isdigit(expr[i])||isalpha(expr[i])){
			postfix[k++]=expr[i];
		}
		else if(expr[i]=='('){
			stack[++top]=expr[i];
		}
		else if(expr[i]== ')'){
			while (top!=-1&& stack[top] != '(')
				postfix[k++]=stack[top--];
			top--;
		}
		else if(isOperator(expr[i])){
			while(top != -1 && pre(stack[top]) >= pre(expr[i])){
				if(expr[i]=='^'&& stack[top ]=='^')break;
				postfix[k++]=stack[top--];
			}
			stack[++top]=expr[i];
		}
	}
	while(top!=-1){
		postfix[k++]=stack[top--];
	}
	postfix[k]='\0';
	return postfix;
}

int main(int argc, char *argv[]) {
	char *expr = argv[1];
	printf("%s\n", InfixToPostfix(expr));
	return 0;
}
