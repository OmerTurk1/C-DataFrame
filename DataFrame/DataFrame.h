#include <iostream>
using namespace std;
class Element{
    public:
    Element* next;
    int val;
    Element(int v){
        val=v;
        next=nullptr;
    }
};
class Column{
    public:
    Column* next;
    Element* bot;
    string name;
    Column(string n){
        name=n;
        next=nullptr;
        bot=nullptr;
    }
};
class DataFrame{
    public:
    Column* head;
    DataFrame(){
        head = nullptr;
    }
    void addColumn(string n){
        Column* newCol = new Column(n);
        if(head==nullptr){
            head=newCol;
            return;
        }
        Column* curr = head;
        while(curr->next)
            curr = curr->next;
        curr->next = newCol;
    }
    void addValue(string n, int v) {
        Column* curr = head;
        while(curr){
            if(curr->name == n){
                Element* newEle = new Element(v);
                Element* temp = curr->bot;
                if(temp == nullptr){
                    curr->bot = newEle;
                    return;
                }
                while(temp->next)
                    temp = temp->next;
                temp->next = newEle;
                return;
            }
            curr = curr->next;
        }
        cerr << "Error: Could not find the column!" << endl;
    }
    void print(int num = 5){
        Column* curr = head;
        while(curr){
            cout<<endl<<curr->name;
            Element* temp = curr->bot;
            for(int i=0;i<num && temp;i++){
                cout<<"\t"<<temp->val;
                temp = temp->next;
            }
            curr = curr->next;
        }
        cout<<endl;
    }
    pair<int,int> shape(){
        Column* curr = head;
        int max_row = 0;
        int max_col = 0;
        while(curr){
            max_col++;
            Element* temp = curr->bot;
            int row = 0;
            while(temp){
                row++;
                temp = temp->next;
            }
            if(max_row<row)
                max_row = row;
            curr = curr->next;
        }
        return {max_row,max_col};
    }
};
