#include <stdio.h>

typedef struct
{
    int coeff, exp;
}term;

void inputPoly(term p[], int n, char name){
    printf("Enter %d coefficients of %c(x): ",n,name);
    for(int i=0;i<n;i++) scanf("%d",&p[i].coeff);
    printf("Enter %d exponents of %c(x): ",n,name);
    for(int i=0;i<n;i++) scanf("%d",&p[i].exp);
}

int addPoly(term p[], int n1, term q[], int n2, term r[]){ 
  int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(p[i].exp == q[j].exp){
            r[k].coeff = p[i].coeff + q[j].coeff;
            r[k++].exp = p[i++].exp; 
            j++;
        }
        else if(p[i].exp > q[j].exp)
            r[k++] = p[i++];
        else
            r[k++] = q[j++];
    }
    while(i<n1) 
     r[k++] = p[i++];
    while(j<n2) 
     r[k++] = q[j++];
    return k;
}

void printPoly(term p[], int n, char name){
    printf("%c(x) = ", name);
    for(int i=0;i<n;i++) 
      printf("%dx^%d%s",p[i].coeff,p[i].exp,(i<n-1?" + ":"\n"));
}

int main(){
    term p[20],q[20],r[40]; int n1,n2,k;
    printf("No. of terms in P(x) and Q(x): "); scanf("%d%d",&n1,&n2);
    inputPoly(p,n1,'P'); 
    inputPoly(q,n2,'Q');
    printf("\n"); 
    printPoly(p,n1,'P'); 
    printPoly(q,n2,'Q');
    k=addPoly(p,n1,q,n2,r);
    printf("Resultant Polynomial "); 
    printPoly(r,k,'R');
}


