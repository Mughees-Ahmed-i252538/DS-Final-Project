#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
using namespace std;

void makeld(){
    ifstream file("leaderboard.txt");
	ifstream file2("times.txt");
	if(!file){
		cout<<"No scores yet"<<endl;
		return;
	}
	int scores[500];
	char times[500*26]; //ctime gives eahc date as 26 characters
	int count=0;
	int s;
	int count2=0;
	char each;
	while(count<500 && file>>s){
		scores[count]=s;
		count++;
	}
	
	while(count2<count*26 && file2.get(each)){
			times[count2]=each;
			count2++;
	}
		
	file.close();
	file2.close();
	for(int i=0;i<count-1;i++){
		for(int j=0;j<count-1-i;j++){
			if(scores[j]<scores[j+1]){
				int temp=scores[j];
				scores[j]=scores[j+1];
				scores[j+1]=temp;

				for(int k=0; k<26; k++) {
					char temp2 = times[j*26 + k];
					times[j*26 + k] = times[(j+1)*26 + k];
					times[(j+1)*26 + k] = temp2;
				}
			}
		}
	}

	for(int i=0;i<count;i++){
		char* arr=times;
		arr+=i*26;
		int count2=0;
		while(count2!=24){ //the last two chars are \r and \n which were causing crashes
			cout<<*arr;
			arr++;
			count2++;
		}
		cout<<". "<<scores[i]<<endl;
}
}
void notescores(int score){
	time_t now=time(NULL); //gives in seconds
	string exacttime=ctime(&now); 
	ofstream file2("times.txt", ios::app);
	file2<<exacttime;
	file2.close();
	ofstream file("leaderboard.txt", ios::app);
	file<<score<<endl;
	file.close();
}

/*
int main(){
	ofstream file2("times.txt");
	ofstream file("leaderboard.txt"); //to clear file from past items, I opened without ios::app
	notescores(5);
	notescores(12);
	notescores(30);
	notescores(21);
	makeld();
}
	*/