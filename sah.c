#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio_ext.h>

void veze(char *Nodes,char **tabla,int **Edges,int nodenum,int x,int y);
int putanja(char *Nodes,int **Edges,int start,int end);

int main(){
    FILE *fp;
    int y,x,**Edge;
    int nodenum,start=0,end;
    char **tabla;
    char *Nodes;

    fp = fopen("ispis.txt","w");
    if(fp==NULL)
        exit(1);

//UNOS
    printf("Unesite broj polja visine i sirine table: ");
    scanf("%d%d",&y,&x);
    nodenum =x*y;
    end=nodenum-1;
    tabla = (char**)malloc(y*sizeof(char*));

    for(int i=0;i<y;i++)
        tabla[i] = (char*)malloc(x*sizeof(char));

    for (int i = 0; i < y; i++)
    {
        __fpurge(stdin);
        fgets(tabla[i],x+1,stdin);
    }

//STVARANJE MEMORIJSKIH LOKACIJA
    Nodes = (char*)malloc(nodenum*sizeof(char*));

    Edge = (int**)malloc(nodenum*sizeof(int*));
    for(int i=0;i<nodenum;i++)
        Edge[i] = (int*)malloc(nodenum*sizeof(int));//veze izmedju tacaka se cuva u matrici npr:
//                                                veza izmedju A i B Edge[0][1] = 1 Edge[1][0] = 1   

    for(int i=0;i<nodenum;i++)
        for(int j=0;j<nodenum;j++)
            Edge[i][j] = 0;

    for(int i=0;i<nodenum;i++){
        Nodes[i]='A' + i;//imenovanje svake pozicije na tabli tabla[0][0] ce biti 'A' u Nodes[0];
    }

    for(int i=0;i<y;i++)
        for(int j=0;j<x;j++){
            if(tabla[i][j]=='S' || tabla[i][j]=='s')
                start = i*x+j;
            if(tabla[i][j]=='E' || tabla[i][j]=='e')
                end = i*x+j;
        }

//ISPISI
    veze(Nodes,tabla,Edge,nodenum,x,y);
    fprintf(fp,"  ");
    for(int i=0;i<nodenum;i++)
        fprintf(fp,"%c ",Nodes[i]);
    for(int i=0;i<nodenum;i++){
        fprintf(fp,"\n%c ",Nodes[i]);
    
        for (int j=0;j<nodenum;j++)
            fprintf(fp,"%d ",Edge[i][j]);
    }
    fprintf(fp,"\nStart: %c ",Nodes[start]);
    fprintf(fp,"\nEnd: %c ",Nodes[end]);
    fprintf(fp,"\n ");
    for(int i=0;i<y;i++){
        fprintf(fp,"\n");
        for(int j=0;j<x;j++)
            fprintf(fp,"%c ",Nodes[i*x+j]);
    }
    fprintf(fp,"\n\nVeze: ");

    for(int i=0;i<nodenum;i++)
        for(int j=i;j<nodenum;j++){
            if(Edge[i][j]==1)
                fprintf(fp,"\n%c <=> %c ",Nodes[i],Nodes[j]);
            }
    return 0;
}


void veze(char *Nodes,char **tabla,int **Edges,int nodenum,int x,int y){
    int trenutno_y,trenutno_x;
    int i,j,prvi,drugi;

    for(trenutno_y=0;trenutno_y<y;trenutno_y++)
        for(trenutno_x=0;trenutno_x<x;trenutno_x++){

            if(tabla[trenutno_y][trenutno_x]=='.' || tabla[trenutno_y][trenutno_x]=='S' || tabla[trenutno_y][trenutno_x]=='E' || tabla[trenutno_y][trenutno_x]=='s' || tabla[trenutno_y][trenutno_x]=='e'){
                //za kralja
                for(i=-1;i<=1;i++){
                    for(j=-1;j<=1;j++){

                        if(trenutno_x+j < 0 || trenutno_x+j > x-1 || trenutno_y+i < 0 || trenutno_y+i > y-1)
                            continue;
                        if(i==0 && j==0)//ne treba svoju poziciju da gleda
                            continue;

                        if(tabla[trenutno_y+i][trenutno_x+j]!='#'){
                        prvi = (trenutno_y)*x+trenutno_x;
                        drugi = (trenutno_y+i)*x+trenutno_x+j;
                            Edges[prvi][drugi] = 1;
                            Edges[drugi][prvi] = 1;
                        }
                    }
                }
            }else
                continue;
    }
}


int putanja(char *Nodes,int **Edges,int start,int end){
    int potezi=-1;
    int _od = start;
    int _do;

    return potezi;
}
