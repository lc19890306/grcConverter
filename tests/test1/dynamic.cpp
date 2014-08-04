//============================================================================
// Name        : dynamic.cpp
// Author      : torytin
// Version     :
// Copyright   :
// Description :Object dynamic create in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Example.h"
#include "Example1.h"
//#include "fuck.h"
#include "afunc.h"

using namespace std;
/*
void createExample(Class *cls){
  if(cls==Example::theClass){
    cout<<"it's a Example Class"<<endl;
    cls->newInstance();
  }else{
    cout<<"it's not a Example Class"<<endl;
  }
}*/
int main() {
  Class::forName("Example")->newInstance()->print();
  Class::forName("Example1")->newInstance()->print();
  Class::forName("afunc")->newInstance()->print();
  //  Class::forName("Example")->newInstance()->print();


  return 0;
}
