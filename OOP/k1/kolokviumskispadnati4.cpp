#include<iostream>
#include<cstring>
using namespace std;
enum tip {
 txt,pdf,exe
};
class File {
 char ime[10];
 tip t;
 char ime_sopstvenik[10];
 int golemina;
public:
 File() {}
 File(const char *ime, tip t,const char *ime_sopstvenik,int golemina) {
  strcpy(this->ime,ime);
  this->t = t;
  strcpy(this->ime_sopstvenik,ime_sopstvenik);
  this->golemina = golemina;
 }
 File(const File &f) {
  strcpy(this->ime,f.ime);
  strcpy(this->ime_sopstvenik,f.ime_sopstvenik);
  this->golemina = f.golemina;
  this->t = f.t;
 }
 ~File() {}
 bool ednakvi(const File &f) {
  if(strcmp(ime_sopstvenik,f.ime_sopstvenik)==0 && strcmp(ime,f.ime)==0 && t==f.t) {
   return true;
  }else {
   return false;
  }
 }
 bool tipequal(const File &f) {
  if(strcmp(ime,f.ime)==0 && t==f.t) {
   return true;
  }
  return false;
 }
};
class Folder {
 char ime[10];
 int br;
 File f[10];
public:
 Folder() {
  br=0;
 }
 Folder(const char *ime,int br,File f[]) {
  strcpy(this->ime,ime);
  this->br = br;
  for(int i=0;i<br;i++) {
   this->f[i] = f[i];
  }
 }
 void remove(const File &fi) {
  int idx=0;
  for(int i=0;i<br;i++) {
   if(f[i].ednakvi(fi)==0) {
    idx=i;
    break;
   }
  }
    for(int j=idx;j<br-1;j++) {
       f[j]=f[j+1];
    }
  br--;
 }
 void add(const File &fi) {
  f[br++]=fi;
 }
};
int main() {

}