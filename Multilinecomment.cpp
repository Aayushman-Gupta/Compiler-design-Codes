#include<bits/stdc++.h>
using namespace std;

bool hasMultiliineComment(const string& filename){
    ifstream file(filename);

    if(file.is_open()){
        cerr<<"Error: could not open file "<<filename<<endl;
    }

    string line;
    bool isMultiline=false;
    while(getline(file,line)){
        size_t pos=0;

        while(pos<line.length()){
            if(!isMultiline){
            size_t start=line.find("/*",pos);
            if(start!=string::npos){
                isMultiline=true;
                pos=start+2;
            }else{
                break;
            }

            }else{

                size_t end=line.find("*/",pos);
                if(end!=string::npos){
                    isMultiline=false;
                    pos=end+2;
                }else{
                    break;
                }
            }
        }
    }
    file.close();
    return isMultiline;
}