# include <iostream>
using namespace std;
struct Node
{
    Node *prev;
    int data;
    string taskName;
    bool isDone;
    Node *next;
} *head=nullptr, *rear=nullptr;
void createNode (int x, string t, bool i)
{
    Node *temp=new Node ();
    temp->data=x;
    temp->taskName=t;
    temp->isDone=i;
    temp->next=nullptr;
    temp->prev=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    cout<<"\nCreated node with task having all required data..\n";
}
int getSize ()
{
    int num=0;
    Node *temp=head;
    while (temp!=nullptr)
    {
        num++;
        temp=temp->next;
    }
    return num;
}
void displayForward ()
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nLinked List (Forward) : ";
        Node *temp=head;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->data<<", "<<temp->taskName<<", ";
            if (!temp->isDone)
            {
                cout<<"Not Done ] -> ";
            }
            else
            {
                cout<<"Done ] -> ";
            }
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void displayBackward ()
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nLinked list (Backward) : ";
        Node *temp=rear;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->data<<", "<<temp->taskName<<", ";
            if (!temp->isDone)
            {
                cout<<"Not Done ] -> ";
            }
            else
            {
                cout<<"Done ] -> ";
            }
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }
}
void insert_first (int x, string t, bool i)
{
    Node *temp=new Node ();
    temp->data=x;
    temp->taskName=t;
    temp->isDone=i;
    temp->next=nullptr;
    temp->prev=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    cout<<"\nInserted node with task having all required data at first..\n";
}
void insert_last (int x, string t, bool i)
{
    Node *temp=new Node ();
    temp->data=x;
    temp->taskName=t;
    temp->isDone=i;
    temp->next=nullptr;
    temp->prev=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    cout<<"\nInserted node with task having all required data at last..\n";
}
void insert_specified (int x, string t, bool i, int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for insertion of node!\n";
    }
    else
    {
        if (pos==1)
        {
            insert_first (x, t, i);
        }
        else
        {
            Node *n=head->next, *p=head, *temp=new Node ();
            temp->data=x;
            temp->taskName=t;
            temp->isDone=i;
            temp->next=nullptr;
            temp->prev=nullptr;
            int num=getSize ();
            if (pos>1 && pos<=num)
            {
                int i=1;
                while (i<pos-1)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                p->next=temp;
                temp->prev=p;
                temp->next=n;
                n->prev=temp;
                cout<<"\nInserted node with task having all required data at position : "<<pos<<endl;
            }
            else if (pos==num+1)
            {
                insert_last (x, t, i);
            }
            else
            {
                cout<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void delete_first ()
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nDeleted head node with task!\n";
    }
    else
    {
        Node *temp=head;
        head=head->next;
        delete temp;
        temp=nullptr;
        head->prev=nullptr;
        cout<<"\nDeleted first node with task!\n";
    }
}
void delete_last ()
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nDeleted head node with task!\n";
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        delete temp;
        temp=nullptr;
        rear->next=nullptr;
        cout<<"\nDeleted last node with task\n";
    }
}
void delete_specified (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for deletion of node with task!\n";
    }
    else
    {
        if (pos==1)
        {
            delete_first ();
        }
        else
        {
            Node *temp, *n=head->next, *p=head;
            int num=getSize (), i=1;
            if (pos>1 && pos<num)
            {
                while (i<pos-1)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                temp=p->next;
                p->next=temp->next;
                temp->next->prev=p;
                delete temp;
                temp=nullptr;
                cout<<"\nDeleted node with task at position : "<<pos<<endl;
            }
            else if (pos==num)
            {
                delete_last ();
            }
            else
            {
                cout<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void searchNodeByData (int d)
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to search for\n";
    }
    else
    {
        bool flag=0;
        Node *temp=head;
        int i=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->data==d)
            {
                flag=1;
                cout<<"\nNode [ "<<temp->data<<", "<<temp->taskName<<", ";
                if (!temp->isDone)
                {
                    cout<<"Not Done ]";
                }
                else
                {
                    cout<<"Done ]";
                }
                cout<<" found at position : "<<i<<endl;
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nNode with given TaskID : "<<d<<" NOT found!\n";
        }
    }
}
void searchNodeByPosition (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for task searching!\n";
    }
    else
    {
        if (head==nullptr)
        {
            cout<<"\nList is empty!\nNothing to search for\n";
        }
        else
        {
            bool flag=0;
            Node *temp=rear;
            int i=getSize ();
            while (temp!=nullptr)
            {
                if (i==pos)
                {
                    flag=1;
                    cout<<"\nNode [ "<<temp->data<<", "<<temp->taskName<<", ";
                    if (!temp->isDone)
                    {
                        cout<<"Not Done ] ";
                    }
                    else
                    {
                        cout<<"Done ] ";
                    }
                    cout<<"found at position : "<<i<<endl;
                    break;
                }
                i--;
                temp=temp->prev;
            }
            if (!flag)
            {
                cout<<"\nNode NOT found!\n";
            }
        }
    }
}
void deleteNodeByData (int d)
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else
    {
        int p=0;
        bool flag=0;
        Node *temp=head;
        while (temp!=nullptr)
        {
            p++;
            if (temp->data==d)
            {
                delete_specified (p);
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nNode NOT found!\n";
        }
    }
}
void findMidTasks ()
{
    int num=getSize ();
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to find\n";
    }
    else
    {
        int i=0;
        Node *temp=head;
        if (num%2==0)
        {
            while (temp!=nullptr)
            {
                i++;
                if (i==(num/2))
                {
                    cout<<"\nTwo middle tasks are : [ "<<temp->data<<", "<<temp->taskName<<", ";
                    if (!temp->isDone)
                    {
                        cout<<"Not Done ] and ";
                    }
                    else
                    {
                        cout<<"Done ] and ";
                    }
                    temp=temp->next;
                    cout<<"[ "<<temp->data<<", "<<temp->taskName<<", ";
                    if (!temp->isDone)
                    {
                        cout<<"Not Done ]"<<endl;
                    }
                    else
                    {
                        cout<<"Done ]"<<endl;
                    }
                    break;
                }
                temp=temp->next;
            }
        }
        else
        {
            while (temp!=nullptr)
            {
                i++;
                if (i==((num+1)/2))
                {
                    cout<<"\nMiddle task is : [ "<<temp->data<<", "<<temp->taskName<<", ";
                    if (!temp->isDone)
                    {
                        cout<<"Not Done ]"<<endl;
                    }
                    else
                    {
                        cout<<"Done ]"<<endl;
                    }
                    break;
                }
                temp=temp->next;
            }
        }
    }
}
void displayMenu ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Create task              2.Display List (Forward)\t3.Display List (Backward)\n";
    cout<<"4.Insert task at first\t   5.Insert task at last        6.Insert task at specified position\n";
    cout<<"7.Delete first task\t   8.Delete last task\t        9.Delete task at specified position\n";
    cout<<"10.Search task by taskID   11.Count tasks\t        12.Search task by position";
    cout<<"\n13.Delete task by taskID   14.Find middle task(s)\t15.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int d, pos, ch, ch1;
    string taskName;
    bool isDone;
    do
    {
        displayMenu ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput taskID : ";
            cin>>d;
            cout<<"\nInput task name : ";
            cin>>taskName;
            cout<<"\n1.Task Complete\t2.Task Incomplete\n";
            cout<<"\nInput choice : ";
            cin>>ch1;
            switch (ch1)
            {
            case 1:
                isDone=1;
                break;
            case 2:
                isDone=0;
                break;
            default:
                isDone=0;
            }
            createNode (d, taskName, isDone);
            break;
        case 2:
            displayForward ();
            break;
        case 3:
            displayBackward ();
            break;
        case 4:
            cout<<"\nInput taskID : ";
            cin>>d;
            cout<<"\nInput task name : ";
            cin>>taskName;
            cout<<"\n1.Task Complete\t2.Task Incomplete\n";
            cout<<"\nInput choice : ";
            cin>>ch1;
            switch (ch1)
            {
            case 1:
                isDone=1;
                break;
            case 2:
                isDone=0;
                break;
            default:
                isDone=0;
            }
            insert_first (d, taskName, isDone);
            break;
        case 5:
            cout<<"\nInput taskID : ";
            cin>>d;
            cout<<"\nInput task name : ";
            cin>>taskName;
            cout<<"\n1.Task Complete\t2.Task Incomplete\n";
            cout<<"\nInput choice : ";
            cin>>ch1;
            switch (ch1)
            {
            case 1:
                isDone=1;
                break;
            case 2:
                isDone=0;
                break;
            default:
                isDone=0;
            }
            insert_last (d, taskName, isDone);
            break;
        case 6:
            cout<<"\nInput position for insertion of task : ";
            cin>>pos;
            cout<<"\nInput taskID : ";
            cin>>d;
            cout<<"\nInput task name : ";
            cin>>taskName;
            cout<<"\n1.Task Complete\t2.Task Incomplete\n";
            cout<<"\nInput choice : ";
            cin>>ch1;
            switch (ch1)
            {
            case 1:
                isDone=1;
                break;
            case 2:
                isDone=0;
                break;
            default:
                isDone=0;
            }
            insert_specified (d, taskName, isDone, pos);
            break;
        case 7:
            delete_first ();
            break;
        case 8:
            delete_last ();
            break;
        case 9:
            cout<<"\nInput position for deletion of task : ";
            cin>>pos;
            delete_specified (pos);
            break;
        case 10:
            cout<<"\nInput task ID of the task to be searched : ";
            cin>>d;
            searchNodeByData (d);
            break;
        case 11:
            cout<<"\nNumber of tasks : "<<getSize ()<<endl;
            break;
        case 12:
            cout<<"\nInput position of task to be searched : ";
            cin>>pos;
            searchNodeByPosition (pos);
            break;
        case 13:
            cout<<"\nInput taskID of task to be deleted : ";
            cin>>d;
            deleteNodeByData (d);
            break;
        case 14:
            findMidTasks ();
            break;
        case 15:
            cout<<"\n======[Exiting the program...]======\n";
            exit (0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=15);
    return 0;
}
