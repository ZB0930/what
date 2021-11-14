#include <stdio.h>
#include <stdlib.h>
typedef struct Polyn{
    int data;
    int index;
    struct Polyn *next;
}Polyn,*Polynlist;
void CreatPolyn(Polynlist &p,int m)//����m���ϵ����ָ��,����һԪ����ʽP
{
    //��ͷ���
    Polyn *q=p;
    for(int i=0;i<m;i++)
    {
        q->next=(Polyn*)malloc(sizeof(Polyn));
        q=q->next;
//        printf("��%d��ϵ����ָ��:",i+1);
        scanf("%d%d",&q->data,&q->index);
    }
    q->next=0;
}
void PrintPolyn(Polynlist &p)//��ӡһԪ����ʽP
{
    Polyn *q=p->next;
    //(x^0)��(x^1)Ҫ���ر���
    if(q->index == 0)
    {
        printf("%d",q->data);
        //���ܵڶ���ָ��Ϊx
        q=q->next;
        if(q && q->index == 1)
        {
            if(q->data != 1)
                printf("%+dx",q->data);//��������ǰ���+,���򲻼�
            else
                printf("+x");
            q = q->next;
        }
    }
    else if(q->index == 1){
        if(q->data != 1)
            printf("%dx",q->data);
        else
            printf("x");
        q = q->next;
    }
    else{
        printf("%dx^%d",q->data,q->index);
        q = q->next;
    }
    while(q)
    {
        printf("%+dx^%d",q->data,q->index);
        q=q->next;
    }
    printf("\n");
}
void CopyPolyn(Polynlist &q,Polyn *r)//��ָ���������ȥ����,�¿��ٽ����������(�������ָ����)
{
    q = (Polyn *)malloc(sizeof(Polyn));
    Polyn *q1 = q,*r1 = r->next;
    while(r1)
    {
        q1->next = (Polyn *)malloc(sizeof(Polyn));
        q1 = q1->next;
        q1->data = r1->data;
        q1->index = r1->index;
        r1 = r1->next;
    }
    q1->next = NULL;
}
void ShowMenu()
{
    printf("\t\t\t1.����ʽ���\n");
    printf("\t\t\t2.����ʽ���\n");
    printf("\t\t\t3.����ʽ���\n");
    printf("\t\t\t4.�˳�\n");
}
void AddPolyn(Polyn *p,Polyn *p1)//��ɶ���ʽ�������,p=p+p1,������p1
{
    Polyn *qa,*qb,*prior,*r;//����prior��ΪB�����еĽ�����A������
    prior = p;
    qa = p->next;
    qb = p1->next;
    while(qa && qb)
    {
        if(qa->index < qb->index)
        {
            prior = qa;
            qa = qa->next;
        }
        else if(qa->index > qb->index){
            r = qb;
            qb = qb->next;
            //ժȡqb�����Ͷ���ʽ��������
            r->next = qa;
            prior->next = r;
            //����prior
            prior = r;
        }
        else{
            if(qa->data + qb->data != 0)
            {
                //�޸�qa��ָ����ϵ��ֵ,ͬʱ�ͷ�qb��ָ�Ľ��
                qa->data = qa->data + qb->data;
                r = qb;
                qb = qb->next;
                free(r);
            }
            else{
                //�ͷ�ָ��qa��qb��ָ�Ľ��
                r = qa;
                qa = qa->next;
                prior->next = qa;//�ν�
                free(r);
                r = qb;
                qb = qb->next;
                free(r);
            }
        }
    }
    //B�����н��
    if(qb)
    {
        prior->next = qb;//��ʱqa��Ϊ��ָ��
    }
    free(p1);//�ͷ�Bͷ���
}
void reverse(Polyn *p)
{
    Polyn *q = p->next;
    while(q)
    {
        q->data = -(q->data);
        q = q->next;
    }
}
void DestroyPolyn(Polyn *r)
{
    Polyn *q;
    do{
        q = r;
        r = r->next;
        free(q);
    }while(r);
}
void AdjustPolyn(Polyn *r,int data,int index)//����ÿһ��
{
    Polyn *q = r->next;
    while(q)
    {
        q->data *= data;
        q->index += index;
        q = q->next;
    }
}
void SubtractPolyn(Polynlist &p,Polynlist &p1)//��ɶ���ʽ�������,p=p-p1,������p1
{
    reverse(p1);//��B�����data���÷�
    AddPolyn(p,p1);
}
void MultiplyPolyn(Polynlist &p,Polyn *p1)//��ɶ���ʽ�������,p=p*p1,������p1
{
    Polyn *q,*r = NULL,*r1 = NULL;
    q = p1->next;
    //A(x)--��bi*A(x)*x^ei
    CopyPolyn(r,p);
    AdjustPolyn(r,q->data,q->index);
    q = q->next;
    while(q)
    {
        CopyPolyn(r1,p);
        AdjustPolyn(r1,q->data,q->index);
        AddPolyn(r,r1);//r1��������
        r1 = NULL;//���뽫r1�ÿ�
        q = q->next;
    }
    //r-->p��ͬʱ�ͷ�r����
    DestroyPolyn(p);
    p = NULL;
    CopyPolyn(p,r);
    DestroyPolyn(r);
}
int main()
{
    int m;
    Polyn *p=(Polyn*)malloc(sizeof(Polyn));
    Polyn *p1=(Polyn*)malloc(sizeof(Polyn));
    Polyn *p2 = NULL,*p3 = NULL;
    printf("�������������ʽA(x),B(x)��ϵ��,ָ��\n");
    printf("A(x)������:");
    scanf("%d",&m);
    CreatPolyn(p,m);
    printf("A(x)=");
    PrintPolyn(p);
    printf("B(x)������:");
    scanf("%d",&m);
    CreatPolyn(p1,m);
    printf("B(x)=");
    PrintPolyn(p1);
    //����A,Bԭʼ����ʽ,�˴��ĸ������¿��ٽ������
    CopyPolyn(p2,p);
    CopyPolyn(p3,p1);
    system("pause");
    system("cls");
    printf("A(x)=");
    PrintPolyn(p);
    printf("B(x)=");
    PrintPolyn(p1);
    printf("ѡ������һ�ֲ�����ʽ:\n");
    ShowMenu();
    do{
        printf("���������ѡ��:");
        scanf("%d",&m);
        switch(m)
        {
        case 1:
            AddPolyn(p,p1);
            printf("A(x)+B(x)=");
            PrintPolyn(p);
            break;
        case 2:
            SubtractPolyn(p,p1);
            printf("A(x)-B(x)=");
            PrintPolyn(p);
            break;
        case 3:
            MultiplyPolyn(p,p1);
            printf("A(x)*B(x)=");
            PrintPolyn(p);
            break;
        default:
            exit(0);
        }
        fflush(stdin);
        DestroyPolyn(p);
        p1 = p = NULL;//��ʱ��p��p1Ϊ����ָ��,����Ҫ�ÿ�
        CopyPolyn(p,p2);
        CopyPolyn(p1,p3);
    }while(1);
    return 0;
}
