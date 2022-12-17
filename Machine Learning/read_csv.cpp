#include <iostream>
#include <fstream>
using namespace std;


void read_line(string line)
{
    string * word;
    int count=0,i,j ;
    for (int i=0;i<line.length();i++)
        if(line[i] == ',')
            count ++;
    count++;
    word = new string[count];
    cout << count << endl;

    j=0;
    for(i=0;i<count;i++)
    {
        for(;j<line.length();j++)
        {
            if(line[j]!= ',')
                word[i] = word[i] + line[j];
            else 
            {
                j++;    
                break;
            }
        }
    }

    for(i=0;i<count;i++)
        cout << word[i] << "\t" ;
    cout << endl;

}

void read_csv(string file_name)
{
    ifstream fp;
    string line;
    fp.open(file_name);
    int i=0;
    while(fp)
    {
        getline(fp, line);
        //cout << line << endl;
        read_line(line);
        i++;
        if (i==1)
        break;
    }

    fp.close();
}

int main()
{
    read_csv("horse.csv");
}
