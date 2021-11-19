#include <iostream>
using namespace std;

template<typename T>
class SortedList{
    void add(T item);
    T least();
    T greatest();
    int indexOf(T item);
    void remove (int i);
    SortedList<T> searchRange(T from, T to);
    bool isEmpty();
};

template<typename T, typename T1>
class LinkedList: public SortedList<T>
{
    struct node{
        T data;
        node *link;
    };
    node *head=NULL;

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    T least(){
        T min= head->data;
        while(head!=NULL) {
            if (head->data < min) {
                min = head->data;
            }
            head = head->link;
        }
        return min;
    }
    T greatest(){
        T max= head->data;
        while(head!=NULL){
            if(head->data>max){
                max=head->data;
            }
            head=head->link;
        }
        return max;
    }
    T get(int i){
        struct node *k,*j;
        T temp;
        for(k=head; k->link != NULL;k->next){
            for(j=k->next;j!=NULL;j->link){
                if(k->data>j->data){
                    temp=k->data;
                    k->data=j->data;
                    j->data=temp;
                }
            }
        }
        int counter=0;
        struct node *current=head;
        while(current!=NULL){
            if(counter==i){
                return current->data;
            }
            counter++;
            current=current->link;
        }
    }
    int indexOf(T item){
        int count=0;
        struct node* current=head;
        while(current!=NULL){
            if(current->data==item){
                return count;
            }
            count++;
        }

    }
    void remove(int i){
        struct node *k,*j;
        T temp;
        for(k=head; k->link != NULL;k->next){
            for(j=k->next;j!=NULL;j->link){
                if(k->data>j->data){
                    temp=k->data;
                    k->data=j->data;
                    j->data=temp;
                }
            }
        }
        struct node *p,*tmp;
        p=head;
        int counter=0;
        while(p->link!=NULL){
            if(counter==i){
                tmp=p->link;
                p->link=tmp->link;
                free(tmp);
            }
            p=p->link;
            counter++;
        }
    }
    SortedList<T> searchRange(T from, T to){
        struct node* current=head;
        struct node*k;
        int count=0;
        while(current->data!=from){
            if(current->data==from){
                k=current;
                while(k->data!=to){
                    return k->data;
                }
            }
        }
    };
    int size(){
        struct node* current=head;
        int count=0;
        while(current!=NULL){
            count++;
            current->link;
        }
        return count;
    };

public:
    void add(T item) {
        if (isEmpty()) {
            node *point = new node();
            point->data = item;
            point->link = head;
            head = point;
        } else {
            node point = new node();
            point->data = item;
            point->link = NULL;
            node *temp = head;
            while (temp->link != NULL) {
                temp->link;
            }
            temp->link = point;
        }
    }
};

