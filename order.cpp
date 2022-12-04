#include<iostream>//..
#include<fstream>
#include<string>//..
#include<conio.h>//..
#include<iomanip>
#include<stdio.h>//..
using namespace std;

class Process{ //Process class to use in entire program from creating it's object.
public:
    string getNumberAsChar(){//from this we can get numbers as string console with validation
        string s="";
        char c;
        do{
            c=getch();
            if(c>=48&&c<=57 || c==32){
                cout<<c;
                s+=c;
            }else if(c==8){
                cout<<"\b";
                s=s.substr(0,s.length()-1);
            }else if(c==13){
                cout<<endl;
                break;
            }
        }while(true);
        return s;
    }
    int getNumber(){//from this we can get numbers from console with validation
        int num=0;
        char c;
        do{
            c=getch();
            if(c>=48&&c<=57){
                cout<<c;
                num=num*10+(c-48);
            }else if(c==8){
                cout<<"\b";
                num/=10;
            }else if(c==13){
                cout<<endl;
                break;
            }
        }while(true);
        return num;
    }
    string getString(){//from this we can get space containing string from console with validation
        string s="";
        char c;
        do{
            c=getch();
            if(c>=65&&c<=91 || c>=97&&c<=122 || c==32){
                cout<<c;
                s+=c;
            }else if(c==8){
                cout<<"\b";
                s=s.substr(0,s.length()-1);
            }else if(c==13){
                cout<<endl;
                break;
            }
        }while(true);
        return s;
    }
    string getPass(){//from this we can get hidden text from console with any type of characters
        string s="";
        char c;
        do{
            c=getch();
            if(c==8){
                s=s.substr(0,s.length()-1);
            }else if(c==13){
                cout<<endl;
                break;
            }else{
                s+=c;
            }
        }while(true);
        return s;
    }
    char getCharacter(){//from this we can get a single character from console that is only y and n for yes and no
        char c;
        do{
            c=getch();
            if(c=='Y'||c=='y'||c=='n'||c=='N'){
                cout<<c;
                return c;
            }else{
                cout<<"\bUse only 'y' or 'n'"<<endl;
            }
        }while(true);
        return 'n';
    }
    void clearscreen(){
        system("cls");
    }
    string generateId(string className){
        if(className=="order"||className=="Order"||className=="ORDER"){
            //FIND LAST ID INCREASE IT BY 1 AND RETURN IT
        }else if(className=="order"||className=="Order"||className=="ORDER"){
            //FIND LAST ID INCREASE IT BY 1 AND RETURN IT
        }else if(className=="table"||className=="Table"||className=="TABLE"){
            //FIND LAST ID INCREASE IT BY 1 AND RETURN IT
        }else if(className=="item"||className=="Item"||className=="ITEM"){
            //FIND LAST ID INCREASE IT BY 1 AND RETURN IT
        }else if(className=="bill"||className=="Bill"||className=="BILL"){
            //FIND LAST ID INCREASE IT BY 1 AND RETURN IT
        }else{

        }
        return "7540";
    }
};

class Table{};
class Item{
    string item_name;
    int item_id,item_price;
    int getId(){
        ifstream itemfile;
        item_id=0;
        itemfile.open("file\\item.dat",ios::in);
        if(itemfile){
            itemfile.read((char*)this,sizeof(*this));
            while(!itemfile.eof()){
                itemfile.read((char*)this,sizeof(*this));
            }
            itemfile.close();
        }else{
            cout<<"failed to open file";
        }
        return ++item_id;
    }
public:
    void add_item(){
        Process process;
        item_id=getId();
        cout<<"Enter Item Name:";
        item_name=process.getString();
        cout<<"Enter Item Price:";
        item_price=process.getNumber();
        ofstream itemfile;
        itemfile.open("file\\item.dat",ios::app);
        if(itemfile){
            itemfile.write((char*)this,sizeof(*this));
            cout<<"Item Added Successfully"<<endl;
        }else{
            cout<<"failed";
        }
        itemfile.close();
    }
    void update_item(){
        Process process;
        cout<<"Have you got Item ID (y/n):";
        char c=process.getCharacter();//geting a single character
        int id;
        if(c=='n'||c=='N'){
            system("cls");
            show_menu();
        }
        cout<<endl<<"Please Enter Item ID To Update:";
        id=process.getNumber();//getting only the number entry
        ifstream item;
        ofstream item2;
        item.open("file\\item.dat",ios::in);
        item2.open("file\\itemdemo.dat",ios::out);
        if(item&&item2){
            item.read((char*)this,sizeof(*this));
            bool found=false;
            while(!item.eof()){
                if(id==item_id){
                    cout<<"Enter Item Price:";
                    item_price=process.getNumber();//getting only the number entry
                    found=true;
                }
                item2.write((char*)this,sizeof(*this));
                item.read((char*)this,sizeof(*this));
            }
            item.close();
            item2.close();
            remove("file\\item.dat");
            rename("file\\itemdemo.dat","file\\item.dat");
            found?cout<<"Item updated Successfully."<<endl:cout<<"Item Not Found"<<endl;
        }else{
            cout<<"file does not exist";
        }
    }
    void delete_item(){
        Process itemProcess;
        cout<<"Have you got Item ID (y/n):";
        char c=itemProcess.getCharacter();
        int id;
        if(c=='n'||c=='N'){
            itemProcess.clearscreen();
            show_menu();
        }
        cout<<endl<<"Please Enter Item ID to Delete :";
        id=itemProcess.getNumber();
        ifstream item;
        ofstream item2;
        item.open("file\\item.dat",ios::in);
        item2.open("file\\itemdemo.dat",ios::out);
        if(item&&item2){
            item.read((char*)this,sizeof(*this));
            while(!item.eof()){
                if(id!=item_id){
                   item2.write((char*)this,sizeof(*this));
                }
                item.read((char*)this,sizeof(*this));
            }
            item.close();
            item2.close();
            remove("file\\item.dat");
            rename("file\\itemdemo.dat","file\\item.dat");
            cout<<"Item deleted Successfully."<<endl;
        }else{
            cout<<"failed to open file";
        }
    }
    void show_item(){
        cout<<setw(15)<<item_id<<setw(20)<<item_name<<setw(15)<<item_price<<endl;
    }
    void show_menu(){
        ifstream itemfile;
        itemfile.open("file\\item.dat",ios::in);
        if(itemfile){
            itemfile.read((char*)this,sizeof(*this));
            cout<<endl<<setw(15)<<"ITEM ID"<<setw(20)<<"ITEM NAME"<<setw(15)<<"ITEM PRICE"<<endl;
            cout<<setfill('-')<<setw(50)<<""<<endl<<setfill(' ');
            while(!itemfile.eof()){
                show_item();
                itemfile.read((char*)this,sizeof(*this));
            }
            itemfile.close();
        }else{
            cout<<"failed to open file";
        }
    }
};
class Order{};
class Bill{};

class Person{
    string pid,name,contact;
public:
    Person(string p,string n,string c){

    }
    virtual void showDetail()=0;
};

class Admin:public Person{
    string pwd;
public:
    Admin():Person("12207540","admin","9546747447"){
        pwd="pass@word";
    }
    string getPersonPass(){return pwd;}
    void showDetail(){
        cout<<"Details..."<<endl;
    }
    void dashboard(){
        Process adminProcess;
        bool adminloop=true;
        do{
            adminProcess.clearscreen();
            cout<<"FOOD ORDERING SYSTEM (ADMIN mode)"<<endl<<endl;
            cout<<"Please select Operations"<<endl<<"1. Show Item Menu"<<endl<<"2. Add Item"<<endl<<"3. Update Item Price"<<endl
            <<"4. Delete Item"<<endl<<"5. Order List By ID"<<endl<<"6. Show All Orders"<<endl<<"7. Bill By ID"<<endl
            <<"8. Show All Bill"<<endl<<"9. Add Table"<<endl<<"10. Log Out"<<endl;
            cout<<endl<<setw(15)<<left<<"Your selection:";
            int selection=adminProcess.getNumber();
            adminProcess.clearscreen();
            switch(selection){
            case 1:
                {
                    cout<<"Showing Item Menu"<<endl;
                    Item showItem;
                    showItem.show_menu();
                    break;
                }
            case 2:
                {
                    cout<<"Adding Food Item"<<endl;
                    Item addItem;
                    addItem.add_item();
                    break;
                }
            case 3:
                {
                    cout<<"Updating Item Price"<<endl;
                    Item updateItem;
                    updateItem.update_item();
                    break;
                }
            case 4:
                {
                    cout<<"Deleting Food Item"<<endl;
                    Item deleteItem;
                    deleteItem.delete_item();
                    break;
                }
            case 5:
                cout<<"order list by id"<<endl;
                getch();
                break;
            case 6:
                cout<<"show all orders"<<endl;
                getch();
                break;
            case 7:
                cout<<"bill by id"<<endl;
                getch();
                break;
            case 8:
                cout<<"show all bill"<<endl;
                getch();
                break;
            case 9:
                cout<<"add table"<<endl;
                getch();
                break;
            case 10:
                adminloop=false;
                break;
            default:
                cout<<endl<<"Invalid Input!"<<endl;
            }
            if(adminloop){
                cout<<endl<<"Press any key to go to the Dashboard:";
                getch();
            }
        }while(adminloop);
    }
};

class Operator:public Person{
    string pwd;
public:
    Operator():Person("12207540","admin","9546747447"){
        pwd="pass@word";
    }
    string getPersonPass(){return pwd;}
    void showDetail(){
        cout<<"Details..."<<endl;
    }
    void dashboard(){
        Process adminProcess;
        bool adminloop=true;
        do{
            adminProcess.clearscreen();
            cout<<"FOOD ORDERING SYSTEM (OPERATOR mode)"<<endl<<endl;
            cout<<"Please select Operations"<<endl<<"1. Create Order"<<endl<<"2. Order Detail by ID"<<endl<<"3. Show Pending Order"<<endl
            <<"4. Generate Bill"<<endl<<"10. Log Out"<<endl;
            cout<<endl<<setw(15)<<left<<"Your selection:";
            int selection=adminProcess.getNumber();
            switch(selection){
            case 1:
                cout<<"Create Order"<<endl;
                getch();
                break;
            case 2:
                cout<<"Order Detail by ID"<<endl;
                getch();
                break;
            case 3:
                cout<<"Show Pending Order"<<endl;
                getch();
                break;
            case 4:
                cout<<"Generate Bill"<<endl;
                getch();
                break;
            case 10:
                adminloop=false;
                break;
            default:
                cout<<endl<<"Invalid Input! Press any key to Try Again."<<endl;
                getch();
            }
        }while(adminloop);
    }
};


bool login(string post){ // login started
    Process newProcess;
    newProcess.clearscreen();
    cout<<"WELCOME TO THE FOOD ORDERING SYSTEM."<<endl;
    cout<<setfill('-')<<"LOGIN "<<setw(20)<<post<<endl;
    cout<<setfill(' ')<<endl;
    cout<<setw(16)<<"Enter Password:";
    string pwd = newProcess.getPass();
    if(post=="admin"){
        Admin admin;
        if(pwd==admin.getPersonPass()){
            newProcess.clearscreen();
            admin.dashboard();//admin dashboard panel
        }else{
            cout<<endl<<"Oops! Password Incorrect"<<endl<<"Press any key for main menu :";
            getch();
        }
    }else if(post=="operator"){
        Operator operate;
        if(pwd==operate.getPersonPass()){
            newProcess.clearscreen();
            operate.dashboard();//operator dashboard panel
        }else{
            cout<<endl<<"Oops! Password Incorrect"<<endl<<"Press any key for main menu :";
            getch();
        }
    }else{
        return false;
    }
    return false;
}
int main(){
    Process process;
    bool systemloop=true;
    do{
        process.clearscreen();
        cout<<"WELCOME TO THE FOOD ORDERING SYSTEM."<<endl<<endl;
        cout<<"Please Select..."<<endl<<"1. Admin Login"<<endl<<"2. Operator Login"<<endl<<"3. Close"<<endl;
        cout<<endl<<setw(16)<<left<<"Your selection:";
        int selection=process.getNumber();
        if(selection==1){
            login("admin");
        }else if(selection==2){
            login("operator");
        }else if(selection==3){
            cout<<endl<<"Sorry To See You Go.";
            systemloop=false;
        }else{
            cout<<endl<<"Invalid Input! Press any key to Try Again."<<endl;
            getch();
        }
    }while(systemloop);
    return 0;
}
