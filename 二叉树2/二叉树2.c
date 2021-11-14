#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct binode{
        int  data;
        struct binode *lchild;
        struct binode *rchild;
}binode;
binode* creatbitree(char *instr,char *afterstr,int length){
        if(length==0){return NULL;}
        char c=afterstr[length-1];
        int i=0;
        while((instr[i]!=c)&&i<length){
            i=i+1;
        }
        int leftlength=i;
        int rightlength=length-i-1;
        binode *t;
        t=(binode*)malloc(sizeof(binode));
        t->data=c;
        t->lchild=NULL;
        t->rchild=NULL;
        t->lchild=creatbitree(&instr[0],&afterstr[0],leftlength);
        t->rchild=creatbitree(&instr[i+1],&afterstr[i],rightlength);
        return t;
}
void PreOrderTraverse(binode *T)
{
    if (T)
    {
        printf("%c", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
int main(){
        char instr[MAXSIZE];
        char afterstr[MAXSIZE];
        scanf("%s",instr);
        scanf("%s",afterstr);
        int length=strlen(instr);
        binode *t;
        t=(binode*)malloc(sizeof(binode));
        t=creatbitree(instr,afterstr,length);
        PreOrderTraverse(t);
        return 0;
}
