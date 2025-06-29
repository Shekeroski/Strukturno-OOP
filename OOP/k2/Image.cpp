#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Image {
protected:
  char *ime;
  char imeKorisnik[20];
  int sirina;
  int visina;
public:
  Image(const char *ime="untitled",const char *imeKorisnik="unknown",int sirina=800,int visina=800) {
    this->ime=new char[strlen(ime)+1];
    strcpy(this->ime,ime);
    this->sirina=sirina;
    this->visina=visina;
    strcpy(this->imeKorisnik,imeKorisnik);
  }
  virtual bool operator>(const Image &other) const {
    return this->fileSize()>other.fileSize();
  }
  virtual float fileSize() const{
    return visina*sirina*3;
  }
  virtual void print(ostream &os)const{
    os<<ime<<" "<<imeKorisnik<<" "<<fileSize()<<endl;
  }
};
class TransparentImage:public Image {
private:
  bool dalipoddrzuva;
  public:
  TransparentImage(const char *ime="untitled",const char *imeKorisnik="unknown",int sirina=800,int visina=800,bool dalipoddrzuva=false):
  Image(ime,imeKorisnik,sirina,visina) {
    this->dalipoddrzuva=dalipoddrzuva;
  }
  float fileSize() const override{
    if(dalipoddrzuva) {
      return sirina*visina*4;
    }else {
      return visina*sirina+((visina*sirina)/8);
    }
  }
  void print(ostream&os)const override {
    os<<ime<<" "<<imeKorisnik<<" "<<fileSize()<<endl;
  }
  bool operator>(const Image &other) const override {
    return this->fileSize()>other.fileSize();
  }
};
ostream& operator<<(ostream &os, const Image& image) {
  image.print(os);
  return os;
}
class Folder {
  char niza[20];
  char ime[20];
  Image *i[20];
public:
  Folder(char *niza,const char *ime="unknown",Image *i) {
    strcpy(niza,niza);
  }
};
int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};
