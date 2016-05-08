#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h> // atoi

using namespace std;

struct Data {
    string day;
    string userId;
    string message;
};
int lineNum=0;

bool szame(string szo){
    bool valasz=true;

    for(int i=0;i<szo.length();i++){
        if(szo[i]<'0' || szo[i]>'9'){
            valasz=false;
        }
    }
    cout<<valasz<<endl;
    return valasz;
}

int main(){
    ifstream fileCounter("veetel.txt");
    ifstream fileInput("veetel.txt");

    if(fileCounter.is_open()){
        string line="";
        while(getline(fileCounter,line)){
            lineNum++;
        }
        fileCounter.close();
        //cout<<lineNum<<endl;
    }

    Data * dataArray = new Data[lineNum];
    if(fileInput.is_open()){
        int index=0;
        string temp="";
        while(index<lineNum/2){
            getline(fileInput, temp);
            getline(fileInput, dataArray[index].message);

            if(temp[1]==' '){
                dataArray[index].day = temp.substr(0,1);
                dataArray[index].userId = temp.substr(2,temp.length()-2);
            }else if(temp[2]==' '){
                dataArray[index].day = temp.substr(0,2);
                dataArray[index].userId = temp.substr(3,temp.length()-3);
            }
            //cout<<index<<endl;
            //cout<<dataArray[index].day<<endl<<dataArray[index].userId<<endl;
            //cout<<dataArray[index].message<<endl;
            index++;
        }
        fileInput.close();
    }else{ cout<<"Unable to open."<<endl; }


    cout<<"1. Feladat"<<endl;
    cout<<"Fajl beolvasva."<<endl;
    cout<<endl;
    cout<<"2. Feladat"<<endl;
    cout<<"Az elso uzenet rugzitoje: "<<dataArray[0].userId<<endl<<"Az utolso uzenet rogzitoje: "<<dataArray[(lineNum/2)-1].userId<<endl;
    cout<<endl;
    cout<<"3. Feladat"<<endl;

    for(int i=0;i<lineNum/2;i++){
        if(dataArray[i].message.find("farkas")<dataArray[i].message.length()){
            cout<<dataArray[i].day<<".nap "<<dataArray[i].userId<<". radioamator"<<endl;
        }
    }

    cout<<endl;
    cout<<"4. Feladat"<<endl;

    int daySum[11];
    for(int i=0;i<11;i++){
        daySum[i]=0;
    }
    for(int i=0;i<lineNum/2;i++){
        if(dataArray[i].day=="1"){
            daySum[0]++;
        }else if(dataArray[i].day=="2"){
            daySum[1]++;
        }else if(dataArray[i].day=="3"){
            daySum[2]++;
        }else if(dataArray[i].day=="4"){
            daySum[3]++;
        }else if(dataArray[i].day=="5"){
            daySum[4]++;
        }else if(dataArray[i].day=="6"){
            daySum[5]++;
        }else if(dataArray[i].day=="7"){
            daySum[6]++;
        }else if(dataArray[i].day=="8"){
            daySum[7]++;
        }else if(dataArray[i].day=="9"){
            daySum[8]++;
        }else if(dataArray[i].day=="10"){
            daySum[9]++;
        }else if(dataArray[i].day=="11"){
            daySum[10]++;
        }
    }
    for(int i=0;i<11;i++){
        cout<<i+1<<". nap: "<<daySum[i]<<" radioamator"<<endl;
    }

    cout<<endl;
    cout<<"5. Feladat"<<endl;

    ofstream fileOutput("adaas.txt");
    string restoredMessages[11];
    string dayMessages[11][20]; // nap-uzenetFromRadios
    int indexArray[11];
    int userIdArrayForMessages[11][20]; // nap-userId
    for(int i=0;i<11;i++){ // Init indexes
        indexArray[i]=0;
    }

    for(int i=0;i<lineNum/2;i++){ // Init - Fill up matrix with messages
        if(dataArray[i].day=="1"){
            dayMessages[0][indexArray[0]]=dataArray[i].message;
            userIdArrayForMessages[0][indexArray[0]]=atoi(dataArray[i].userId.c_str());
            indexArray[0]++;
        }else if(dataArray[i].day=="2"){
            dayMessages[1][indexArray[1]]=dataArray[i].message;
            userIdArrayForMessages[1][indexArray[1]]=atoi(dataArray[i].userId.c_str());
            indexArray[1]++;
        }else if(dataArray[i].day=="3"){
            dayMessages[2][indexArray[2]]=dataArray[i].message;
            userIdArrayForMessages[2][indexArray[2]]=atoi(dataArray[i].userId.c_str());
            indexArray[2]++;
        }else if(dataArray[i].day=="4"){
            dayMessages[3][indexArray[3]]=dataArray[i].message;
            userIdArrayForMessages[3][indexArray[3]]=atoi(dataArray[i].userId.c_str());
            indexArray[3]++;
        }else if(dataArray[i].day=="5"){
            dayMessages[4][indexArray[4]]=dataArray[i].message;
            userIdArrayForMessages[4][indexArray[4]]=atoi(dataArray[i].userId.c_str());
            indexArray[4]++;
        }else if(dataArray[i].day=="6"){
            dayMessages[5][indexArray[5]]=dataArray[i].message;
            userIdArrayForMessages[5][indexArray[5]]=atoi(dataArray[i].userId.c_str());
            indexArray[5]++;
        }else if(dataArray[i].day=="7"){
            dayMessages[6][indexArray[6]]=dataArray[i].message;
            userIdArrayForMessages[6][indexArray[6]]=atoi(dataArray[i].userId.c_str());
            indexArray[6]++;
        }else if(dataArray[i].day=="8"){
            dayMessages[7][indexArray[7]]=dataArray[i].message;
            userIdArrayForMessages[7][indexArray[7]]=atoi(dataArray[i].userId.c_str());
            indexArray[7]++;
        }else if(dataArray[i].day=="9"){
            dayMessages[8][indexArray[8]]=dataArray[i].message;
            userIdArrayForMessages[8][indexArray[8]]=atoi(dataArray[i].userId.c_str());
            indexArray[8]++;
        }else if(dataArray[i].day=="10"){
            dayMessages[9][indexArray[9]]=dataArray[i].message;
            userIdArrayForMessages[9][indexArray[9]]=atoi(dataArray[i].userId.c_str());
            indexArray[9]++;
        }else if(dataArray[i].day=="11"){
            dayMessages[10][indexArray[10]]=dataArray[i].message;
            userIdArrayForMessages[10][indexArray[10]]=atoi(dataArray[i].userId.c_str());
            indexArray[10]++;
        }
    }

    for(int i=0;i<11;i++){ // Init restoredMessages
        restoredMessages[i]=dayMessages[i][0];
    }

    for(int i=0;i<11;i++){ // napok
        for(int k=0;k<restoredMessages[i].length();k++){ // karakterek
            //cout<<restoredMessages[i][k]<<" ";
            if(restoredMessages[i][k]=='#'){
                for(int c=0;c<indexArray[i];c++){ //radiosok
                    if(dayMessages[i][c][k]!='#'){
                        //cout<<"*"<<c<<"*";
                        restoredMessages[i][k]=dayMessages[i][c][k];
                    }
                }
            }
            //cout<<endl;
        }

        // dayMessages[i][c]
    }

    for(int i=0;i<11;i++){ // Save result
        fileOutput<<restoredMessages[i]<<"\n";
    }
    cout<<"Fajl elmentve."<<endl;
    cout<<endl;
    cout<<"6. Feladat"<<endl;
    cout<<"Fuggveny letrehozva."<<endl;
    cout<<endl;
    cout<<"7. Feladat"<<endl;

    int userNapInput, userRadioInput;

    cout<<"Adja meg a nap sorszamat: ";
    cin>>userNapInput;
    cout<<"Adja meg a radioamator sorszamat: ";
    cin>>userRadioInput;

    userNapInput-=1; // Fix - to be able to use as index

    string userRequestedMessage="";
    for(int c=0;c<20;c++){ // Get search result
        if(userIdArrayForMessages[userNapInput][c]==userRadioInput){
            userRequestedMessage=dayMessages[userNapInput][c];
            break;
        }
    }

    string num1="";
    string num2="";
    if(userRequestedMessage[1]=='/' || userRequestedMessage[2]=='/'){ // Check for number
        //cout<<userRequestedMessage<<endl;
        if(userRequestedMessage[1]=='/' && userRequestedMessage[3]==' '){ // 1/1
            num1 = userRequestedMessage.substr(0,1);
            num2 = userRequestedMessage.substr(2,1);
        }else if(userRequestedMessage[2]=='/' && userRequestedMessage[4]==' '){ // 2/1
            num1 = userRequestedMessage.substr(0,2);
            num2 = userRequestedMessage.substr(3,1);
        }else if(userRequestedMessage[1]=='/' && userRequestedMessage[4]==' '){ // 1/2
            num1 = userRequestedMessage.substr(0,1);
            num2 = userRequestedMessage.substr(2,2);
        }else if(userRequestedMessage[2]=='/' && userRequestedMessage[5]==' '){ // 2/2
            num1 = userRequestedMessage.substr(0,2);
            num2 = userRequestedMessage.substr(3,2);
        }else { // Szam utan #
            cout<<"Nincs informacio."<<endl;
        }

        if(num1=="#" || num1=="##" || num2=="#" || num2=="##"){
            cout<<"Nincs informacio."<<endl;
        }else{
            cout<<num1<<"+"<<num2<<endl; // Should convert to string and sum them
        }

    }else if(userRequestedMessage==""){ // Check fro result
        cout<<"Nincs ilyen feljegyzes."<<endl;
    }else{ // 404
        cout<<"Nincs informacio."<<endl;
    }

    cout<<endl;
    return 0;
}
