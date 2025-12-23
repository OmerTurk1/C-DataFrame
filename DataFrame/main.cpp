#include <iostream>
#include "DataFrame.h"
using namespace std;
int main(){
    DataFrame df;
    df.addColumn("val1");
    df.addColumn("val2");
    df.addColumn("cls");
    for(int i=1;i<10;i++){
        df.addValue("val1",i);
        df.addValue("val2",2*i);
        df.addValue("cls",3*i>10);
    }
    df.print();
    auto [rows, cols] = df.shape();
    cout<<rows<<" "<<cols<<endl;
    return 0;
}
