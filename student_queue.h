#include "student_node.h"
class student_queue
{
private:
    student_node* head;
    student_node* tail;
public:
    student_queue(){head=0;tail=0;}
    ~student_queue()
    {
        student_node* tmp=head;
        while(tmp!=0)
        {
            tmp=head->next;
            delete head;
            head=tmp;
        }
    }
    void add (student_node&a)
    {

         if(head!=0)
         {
             a.next=0;
             tail->next=&a;
             tail=&a;
         } else head=tail=&a;
    }
    student_node* get_head() {if(!empty()) return head;}
    /*int read(const char*name,student_queue& a)
    {
        FILE *fp;
        char b[1000];
        int c;
        student_node* q;
        if(!(fp=fopen(name,"r"))) return -1;
        if(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node(b,c);
            a.add(*q);
        }
        else{fclose(fp);return -3;}

        while(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node(b,c);
            a.add(*q);
        }
        if(!feof(fp))
            {
                fclose(fp);
                return -2;
            }
        fclose(fp);
         return 1;
    }*/
    int read(FILE* fp,int n3)
    {
        student_node* node;
        for(int i=0;i<n3;i++)
        {
            node=new student_node;
            if(node->read(fp)<0)
                return -1;
            add(*node);
        }
        return 1;

    }
    void print(int tab=0)
    {
       student_node* tmp=head;
       int k=0;
       while(tmp!=0&&(k++)<10)
       {
           for(int i=0;i<tab;i++) printf("            ");
           printf("%s %d\n",tmp->get_name(),tmp->get_value());
           tmp=tmp->next;
       }
    }
    void printlast()
    {
        student_node* tmp=head;
        int large=size();
        for(int i=0;i<large-10;i++)
            tmp=tmp->next;
        while(tmp!=0)
            {
                printf("%s %d\n",tmp->get_name(),tmp->get_value());
                tmp=tmp->next;
            }
    }
    bool empty(){if(head) return false; return true;}
    /*void print()
    {
       student_node* tmp=head;
       while(tmp!=0)
       {
           printf("%s %d\n",tmp->get_name(),tmp->get_value());
           tmp=tmp->next;
       }
    }*/
    void del()
    {
        if(head!=0)
        {
            student_node* tmp=head;
            printf("Element <%s %d> is out\n",tmp->get_name(),tmp->get_value());
            head=head->next;
            delete tmp;
        }
    }
    int size ()
    {
       student_node* tmp=head;
       int i=0;
       while(tmp)
       {
           i++;
           tmp=tmp->next;
       }
       return i;
    }
    void menu()
    {
        int key;
        printf("-1. Info\n");
        printf("0. Quit\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Size of queue\n");
        printf("4. Print head of queue\n");
        printf("5. Print the queue\n");
        printf("6. Print first decade\n");
        printf("7. Print last decade\n");

        for(;;)
        {
            printf("Number of the command\n");
            scanf("%d",&key);
            switch (key)
            {
                case -1:
                     printf("0. Quit\n");
                     printf("1. Add element\n");
                     printf("2. Delete element\n");
                     printf("3. Size of queue\n");
                     printf("4. Print head of queue\n");
                     printf("5. Print the queue\n");
                     printf("6. Print first decade\n");
                     printf("7. Print last decade\n");
                     break;
                case 0:
                     return;
                case 1:
                    {
                        char b[1000];
                        int c;
                        printf("Input student:");
                        scanf("%s%d",b,&c);
                        student_node *tmp=new student_node(b,c);
                        add(*tmp);
                        break;
                    }
                case 2: del(); break;
                case 3: {int c=size(); printf("Size is equal to:%d\n",c); break;}
                case 4: printf("%s %d\n",head->get_name(),head->get_value()); break;
                case 5: print(); break;
                case 6: print(); break;
                case 7: printlast(); break;
                default: printf("Command is undefined\n");break;
            }
        }

    }
};


