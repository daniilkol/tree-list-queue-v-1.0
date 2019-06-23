#include "list_node.h"
class tree
{
private:
    list_node *root;
    list_node *curr;
public:
    tree(){root=0;curr=0;}
    ~tree(){root->del();}
    int read(FILE*fp,int n1,int n2,int n3)
    {

        list_node *p,*q;
        if(root)
        {
            q=new list_node();
            p=root->down;
            if(q->read(fp,n2,n3))
                {
                    q->koef=*root<*q;
                    printf("%d",q->koef);
                    p=p->add(q);
                }
            else return -1;
            root->down=p;
            return 1;

        }
        root=new list_node();
        if(root->read(fp,n2,n3));
        else return -1;
        p=root->down;
        for(int i=1;i<n1;i++)
        {
            q=new list_node();
            if(q->read(fp,n2,n3))
                {
                    q->koef=*root<*q;
                    //cout << q->koef<<endl;
                    if(q->kolvoel())p=p->add(q);
                    else delete q;
                }
            else return -1;
        }
        root->down=p;
        curr=root;
        return 1;

    }
    list_node* get_curr(){return curr;}
    list_node* get_root(){return root;}
    void goto_down(){if(curr->down)curr=curr->down;else printf("I'm sorry, current element haven't got a down element\n");}
    void goto_next(){if(curr->next)curr=curr->next;else printf("I'm sorry, current element haven't got a next element\n");}
    void goto_root(){curr=root;}
    bool empty() {if(root) return false; return true;}

    void menu()
    {
        int key;
        printf("-1. Info\n");
        printf("0: Quit\n");
        printf("1: print tree\n");
        printf("2: print subtree from current\n");
        printf("3: print curr el\n");
        printf("4: root menu\n");
        printf("5: curr menu\n");
        printf("6: delete tree\n");
        printf("7: delete subtree\n");


        printf("10: Go to next\n");
        printf("11: Go to down\n");
        printf("12: Go to root\n");
goto_root();
        for(;;)
        {
            printf("Number of the command\n");
            scanf("%d",&key);
        switch(key)
        {
        case -1:
            printf("0: Quit\n");
        printf("1: print tree\n");
        printf("2: print subtree from current\n");
        printf("3: print curr el\n");
        printf("4: root menu\n");
        printf("5: curr menu\n");
        printf("6: delete tree\n");
        printf("7: delete subtree\n");
        printf("10: Go to next\n");
        printf("11: Go to down\n");
        printf("12: Go to root\n");
        break;
        case 0:
            {

            return ;
            }
        case 1:
            {
                printf("##############TREE###########\n");
                root->print();
                printf("##############TREE###########\n");
                break;
            }
        case 2:
            {
                printf("##############SUBTREE###########\n");
                curr->print();
                printf("##############SUBTREE###########\n");
                break;
            }
        case 3:
            {
                curr->student_list::print();
                break;
            }
        case 4:
            {
                root->menu();

                break;
            }
        case 5:
            {
                curr->menu();

                break;
            }
        case 6:
            {
                printf("-- DELETED --\n");
                root->print();
                printf("-- DELETED --\n");
                root->del();
                break;
            }
        case 7:
            {
                printf("-- DELETED --\n");
                curr->print();
                printf("-- DELETED --\n");
                curr->del();
                break;
            }

        case 11:
            {
                goto_down();
                break;
            }
        case 10:
            {
                goto_next();
                break;
            }
        case 12:
            {
                goto_root();
                break;
            }

        default:
            {
                printf("Command is undefined\n");
                break;
            }
        }}
    }

};
