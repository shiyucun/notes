
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  string filepath("093_io_file.cpp");

  ifstream ifs(filepath.c_str());
  if (!ifs) {
    cout << "open file failed!" << endl;
  }

  // int c;
  // while ((c = ifs.get()) != EOF) {
  //   cout.put(c);
  // }

  // char cc;
  // while (ifs.get(cc)) {
  //   cout.put(cc);
  // }

  char ccc;
  while (ifs >> ccc) {
    cout.put(ccc);
  }

  cout.put('\n');

  ifs.close();

  return 0;
}

// #include<fstream>#include<iostream>usingnamespacestd;intmain(){stringfilepath("093_io_file.cpp");ifstreamifs(filepath.c_str());if(!ifs){cout<<"openfilefailed!"<<endl;}//intc;//while((c=ifs.get())!=EOF){//cout.put(c);//}//charcc;//while(ifs.get(cc)){//cout.put(cc);//}charccc;while(ifs>>ccc){cout.put(ccc);}cout.put('\n');ifs.close();return0;}
