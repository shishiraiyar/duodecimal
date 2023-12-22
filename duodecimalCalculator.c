#include<stdio.h>
#include<string.h>

int b12tob10(char *s);
int calculate(int a, char op, int b);
void b10tob12(int n, char *str);

int main(int argc, char * argv[]){

	char * op1 = argv[1];
	char op = *argv[2];
	char * op2 = argv[3];
	int a = b12tob10(op1);
	int b = b12tob10(op2);

	int ans = calculate(a, op, b);
	
	char b12ans[10];
	b10tob12(ans, b12ans);
	printf("%s %c %s = %s\n",op1, op, op2, b12ans);
	
	return 0;
}

int getVal(char c){
	switch(c){
		case 'X': return 10;
		case 'E': return 11;
		default: return c - 48;
	}
}

char getChar(int n){
	switch(n){
		case 10: return 'X';
		case 11: return 'E';
		default: return n + 48;
	}

} 

int b12tob10(char *b12){
	int n = 0;
	for (char *ptr = b12; *ptr!=0; ptr++){
		n*=12;
		n+=getVal(*ptr);	
	}
	return n;
}

void reverse(char *str){
	int n = strlen(str);
	char temp;
	for (int i=0; i<n/2; i++){
		temp = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = temp;
	}
	return;
}

void b10tob12(int n, char *str){
	char *ptr = str;
	while (n){
	*ptr = getChar(n%12);
	ptr++;
	n/=12;
	}
	*ptr = 0;
	reverse(str);
	return;
}

int calculate(int a, char op, int b){
	switch(op){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
}
