#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string randomizer(string &a, int length){
    char *random=new char[length];
    bool repeat=false;
    for (int i=0; i<length-1; i++){
        if (random[(i-1)/2]=='#'){
    		random[i]='#';
		}
        int random2=1+rand()%(200-1+1); //this is like rolling the dice for # 
        if (random2%2==0&&i%2==0){
            random[i]='#';
            continue;
        }
        else{
        	int random3=1+rand()%(9-1+1);
        	repeat=true;
            while (repeat){
                repeat=false;
                random3=1+rand()%(9-1+1);
                for (int j=0; j<i;j++){
                if (random3==random[j]-'0'){
                    repeat=true;
                    break;
                }
            }
            }
            random[i]=char(random3+'0');
        }
    }
    random[length-1]='\0';
    a=random;
    delete[] random;
    return a;
}

/*
int main(){
	srand(time(0));
	string a;
	int alength=1+rand()%(9-1+1);
	randomizer(a, alength);
	cout<<a;
}
    */