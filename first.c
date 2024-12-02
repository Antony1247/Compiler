#include<stdio.h>
#include<string.h>
#include<ctype.h>

char prod[50][50];
int m=0,num=0,n1=0;
char c;
char res[50];

void first(char c, int num);
void result(char c);
void follow(char c,int num);

int main(){
    printf("enter the number of productions");
    scanf("%d",&num);
    printf("enter the production rules");
    for(int i=0;i<num;i++){
        scanf("%s", prod[i]);
    }
    printf("enter the chacater whose first and follow to be found out\n");
    scanf(" %c",&c);
    if(isupper(c))
        first(c,num);
        follow(c,num);
    //printf("%c",c);
	for (int i = 0; i < m; ++i)
		printf("%c ", res[i]);
}


void first(char c,int num){
    int n=num;
    for(int i=0;i<n;i++){
        if(prod[i][0]==c){
            for(int j=2;j<strlen(prod[i]);j++){
                if(prod[i][j] >= 'A' && prod[i][j] <= 'Z'){
                    printf("-------%c",prod[i][j]);
                    first(prod[i][j],n);
                    break;
                }
                else{
                    result(prod[i][j]);
                    break;
                }
            }
        }
    }
}


void follow(char c,int num){
    int n1=num;
    if(prod[0][0]==c)
        result('$');
    for(int i=0;i<n1;i++){
        for(int j=2;j<strlen(prod[i]);j++){
            if (prod[i][j] == c)
			{
				if (prod[i][j + 1] != '\0')
					first(prod[i][j + 1],n1);
				if (prod[i][j + 1] == '\0' && c != prod[i][0])
					follow(prod[i][0],n1);
			}
            
        }
    }
}


void result(char c)
{
	int i;
	for (i = 0; i <= m; ++i)
		if (res[i] == c)
			return;
	res[m++] = c;
}