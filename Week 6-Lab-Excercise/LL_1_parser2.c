#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int i=0,top=0;
char stack[20],ip[20];

void push(char c)
{
	if (top>=20)
		printf("Stack Overflow");
	else
		stack[top++]=c;
}

void pop(void)
{
	if(top<0)
		printf("Stack underflow");
	else
		top--;
}

void error(void){
    printf("\n\nSyntax Error!!!! String is invalid\n");
    getch();
    exit(0);
}

int main(){
    int n;
    printf("The given grammar is\n");
    printf("E -> TG\n");
    printf("G -> +TG\n");
    printf("G -> epsilon\n");
    printf("T -> FH\n");
    printf("H -> *FH\n");
    printf("H -> epsilon\n");
    printf("F -> i\n");
    printf("F -> (E)\n");

    printf("\nEnter the string to be parsed: ");
    scanf("%s",ip);
    n=strlen(ip);
    ip[n]='$';
    ip[n+1]='\0';
    push('$');
    push('E');

    while(ip[i]!='\0'){ 
        if(ip[i]=='$' && stack[top-1]=='$'){
	        printf("\n\n Successful parsing of string \n\n");
	        return(1);
            }
        else{
	        if(ip[i]==stack[top-1]){
	            printf("\nmatch of %c occured ",ip[i]);
	            i++; pop();
	        }
	        else{
		        if(stack[top-1]=='E' && ip[i]=='i' || ip[i]=='(')
		        {
		            printf(" \n E -> TG");
		            pop();
		            push('G');
 		            push('T');
		        }
		        else{
		            if(stack[top-1]=='G' && ip[i]=='+'){
			            printf("\n G -> +TG");
			            pop();push('G');push('T');push('+');
		            }
		            else{
		                if(stack[top-1]=='G' && ip[i]==')' || ip[i]=='$'){
			                printf("\n G -> epsilon");
			                pop();
		                }
		                else{
                            if(stack[top-1]=='T' && ip[i]=='i' || ip[i]=='('){
			                    printf("\n T -> FH");
			                    pop();push('H');push('F');
		                    }
                            else{
                                if(stack[top-1]=='H' && ip[i]=='*'){
			                        printf("\n H -> *FH");
			                        pop();push('H');push('F');push('*');
		                        }
                                else{
                                    if(stack[top-1]=='H' && (ip[i]=='+' || ip[i]==')' || ip[i]=='$')){
			                            printf("\n H -> epsilon");
			                            pop();
		                            }
                                    else{
                                        if(stack[top-1]=='F' && ip[i]=='i'){
			                                printf("\n F -> i");
			                                pop(),push('i');
		                                }
                                        else{
                                            if(stack[top-1]=='F' && ip[i]=='('){
			                                    printf("\n F -> epsilon");
			                                    pop();
		                                    }
                                            else{
                                                error();
                                            }
                                        }
                                    } 
                                }                                
                            }
                        }
                    }
                }
            }
        }
	}
}
