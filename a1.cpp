#include<iostream>
using namespace std;

struct graph{

    char ch;
    int c,h;
    struct graph *next;
};
graph *a[5];
struct prior_queue{

    string path = "";
    int g;
    int f;
    struct prior_queue *next;

};
prior_queue *q=NULL;

void bubbleSort(struct prior_queue *q5)
{
    struct prior_queue *i,*j;

    /* Checking for empty list */
    if (q5 == NULL)
        return;
    for(i=q5;i->next!=NULL;i=i->next){

        for(j=i->next;j!=NULL;j=j->next){
            if(i->f >=j->f){

                string s;
                s=i->path;
                i->path=j->path;
                j->path=s;

                int t1;
                t1=i->g;
                i->g=j->g;
                j->g=t1;

                int t2;
                t2=i->f;
                i->f=j->f;
                j->f=t2;

            }
        }
    }


}


void priorityqueue(prior_queue *q2){
    if(q==NULL){
        q=q2;

    }
    else{
        q2->next=q;
        q=q2;
    }

}

void printq(struct prior_queue *q2){
    while(q2!=NULL){
        cout<<q2->path<<endl<<q2->g<<endl<<q2->f<<endl;
        q2=q2->next;
    }
}


void a_star(int s, int d){

    char x,z;
    graph *t1;
    t1=a[s];

    int h[]={366,0,160,242,176,244,241,380,10,193,253,329,374};

    switch(s)
    {
        case 0:
            x='A';
            break;
        case 1:
            x='B';
            break;
        case 2:
            x='C';
            break;
        case 3:
            x='D';
            break;
        case 4:
            x='F';
            break;
        case 5:
            x='Z';
            break;
        case 6:
            x='O';
            break;
        case 7:
            x='S';
            break;
        case 8:
            x='R';
            break;
        case 9:
            x='P';
            break;
        case 10:
            x='T';
            break;
        case 11:
            x='L';
            break;
        case 12:
            x='M';
            break;
    }

     switch(d)
    {
        case 0:
            z='A';
            break;
        case 1:
            z='B';
            break;
        case 2:
            z='C';
            break;
        case 3:
            z='D';
            break;
        case 4:
            z='F';
            break;
        case 5:
            z='Z';
            break;
        case 6:
            z='O';
            break;
        case 7:
            z='S';
            break;
        case 8:
            z='R';
            break;
        case 9:
            z='P';
            break;
        case 10:
            z='T';
            break;
        case 11:
            z='L';
            break;
        case 12:
            z='M';
            break;
    }

    q=(struct prior_queue*)malloc(sizeof(struct prior_queue));
    q->path=x;
    q->g=0;
    q->f=h[s];
    q->next=NULL;
    int r=0;
    while(1){
        prior_queue *q1;
        q1=q;
        q=q->next;
        int y;
        switch(q1->path[0])
        {
            case 'A':
                y=0;
                break;
            case 'B':
                y=1;
                break;
            case 'C':
                y=2;
                break;
            case 'D':
                y=3;
                break;
            case 'F':
                y=4;
                break;
            case 'Z':
                y=5;
                break;
            case 'O':
                y=6;
                break;
            case 'S':
                y=7;
                break;
            case 'R':
                y=8;
                break;
            case 'P':
                y=9;
                break;
            case 'T':
                y=10;
                break;
            case 'L':
                y=11;
                break;
            case 'M':
                y=12;
                break;
        }

        graph *t;
        t=a[y];
        while(t!=NULL){
            prior_queue *q2;
            q2=(struct prior_queue*)malloc(sizeof(struct prior_queue));
            int fn=(q1->g+t->c)+t->h;
            q2->path=t->ch+q1->path;
            q2->g=q1->g+t->c;
            q2->f=fn;
            q2->next=NULL;

            priorityqueue(q2);
            t=t->next;
        }
        bubbleSort(q);
        if(q->path[0]==z)
            break;


    }
   // printq(q);
    string s1=q->path;
    int l1=s1.length();
    cout<<endl<<q->path[l1-1];
    for(int m=l1-2;m>=0;m--){
        cout<<" -> "<<s1[m];
    }
    cout<<endl<<"Path cost:"<<q->g<<endl;
}


int main(){

    graph *t1,*t2;

    /* A */
    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[0] = t1;
    t1->ch = 'Z';
    t1->c = 75;
    t1->h = 374;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'S';
    t2->c = 140;
    t2->h = 253;
    t1 = (struct graph*)malloc(sizeof(struct graph));
    t2->next = t1;
    t1->ch = 'T';
    t1->c = 118;
    t1->h = 329;
    t1->next = NULL;

    /* B */
    t1=(struct graph*)malloc(sizeof(struct graph));
    a[1] = t1;
    t1->ch = 'F';
    t1->c = 211;
    t1->h = 176;
    t2=(struct graph*)malloc(sizeof(struct graph));
    t1->next=t2;
    t2->ch = 'P';
    t2->c = 101;
    t2->h = 10;
    t2->next = NULL;

    /* C */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[2] = t1;
    t1->ch = 'D';
    t1->c = 120;
    t1->h = 242;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'P';
    t2->c = 138;
    t2->h = 10;
    t1 = (struct graph*)malloc(sizeof(struct graph));
    t2->next = t1;
    t1->ch = 'R';
    t1->c = 146;
    t1->h = 193;
    t1->next=NULL;

    /* D */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[3] = t1;
    t1->ch = 'C';
    t1->c = 120;
    t1->h = 160;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'M';
    t2->c = 75;
    t2->h = 241;
    t2->next = NULL;


    /* F */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[4] = t1;
    t1->ch = 'B';
    t1->c = 211;
    t1->h = 0;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'S';
    t2->c = 99;
    t2->h = 253;
    t2->next = NULL;

     /* Z */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[5] = t1;
    t1->ch = 'A';
    t1->c = 75;
    t1->h = 366;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'O';
    t2->c = 71;
    t2->h = 380;
    t2->next = NULL;

     /* O */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[6] = t1;
    t1->ch = 'Z';
    t1->c = 71;
    t1->h = 374;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'S';
    t2->c = 151;
    t2->h = 253;
    t2->next = NULL;

    /* S */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[7] = t1;
    t1->ch = 'O';
    t1->c = 151;
    t1->h = 380;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'A';
    t2->c = 140;
    t2->h = 366;
    t1 = (struct graph*)malloc(sizeof(struct graph));
    t2->next = t1;
    t1->ch = 'F';
    t1->c = 99;
    t1->h = 176;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next=t2;
    t2->ch = 'R';
    t2->c = 80;
    t2->h = 193;
    t2->next = NULL;

    /* R */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[8] = t1;
    t1->ch = 'S';
    t1->c = 80;
    t1->h = 253;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'C';
    t2->c = 146;
    t2->h = 160;
    t1 = (struct graph*)malloc(sizeof(struct graph));
    t2->next = t1;
    t1->ch = 'P';
    t1->c = 97;
    t1->h = 10;
    t1->next=NULL;

    /* P */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[9] = t1;
    t1->ch = 'R';
    t1->c = 97;
    t1->h = 193;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'C';
    t2->c = 138;
    t2->h = 160;
    t1 = (struct graph*)malloc(sizeof(struct graph));
    t2->next = t1;
    t1->ch = 'B';
    t1->c = 101;
    t1->h = 0;
    t1->next=NULL;

     /* T */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[10] = t1;
    t1->ch = 'A';
    t1->c = 118;
    t1->h = 366;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'L';
    t2->c = 111;
    t2->h = 244;
    t2->next = NULL;

     /* L */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[5] = t1;
    t1->ch = 'T';
    t1->c = 111;
    t1->h = 329;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'M';
    t2->c = 70;
    t2->h = 241;
    t2->next = NULL;

     /* M */

    t1 = (struct graph*)malloc(sizeof(struct graph));
    a[5] = t1;
    t1->ch = 'L';
    t1->c = 70;
    t1->h = 244;
    t2 = (struct graph*)malloc(sizeof(struct graph));
    t1->next = t2;
    t2->ch = 'D';
    t2->c = 75;
    t2->h = 242;
    t2->next = NULL;

    /* graph created */

    int s,d;
    cout<<"Enter the source:\na-0\nb-1\nc-2\nd-3\nf-4\nz-5\no-6\ns-7\nr-8\np-9\nt-10\nl-11\nm-12: ";
    cin>>s;
    cout<<"Enter the destination:\na-0\nb-1\nc-2\nd-3\nf-4\nz-5\no-6\ns-7\nr-8\np-9\nt-10\nl-11\nm-12: ";
    cin>>d;

    a_star(s,d);

return 0;
}
