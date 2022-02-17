/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int countsubstrings(string s);
bool unittest_standard();
bool unittest_empty();
bool unittest_smallstr();
bool unittest_casesensitive();
bool unittest_filereader_empty();
bool unittest_filereader_std();

int main(int argc, char *argv[])
{
    //grab console input example
    std::string inputstr(argv[1]);
    int res = countsubstrings(inputstr);
    cout << res;
    
    //grab input from txt file example
    string inputstrfromfile;
    inputstrfromfile = readFiletoString("text.txt"); 
    res = countsubstrings(inputstrfile);
    cout << res;
    
    //unit tests
    cout << unittest_filereader_empty()
    cout << unittest_filereader_std()
    cout << unittest_standard();
    cout << unittest_empty();
    cout << unittest_smallstr();
    cout << unittest_casesensitive();
    return 0;
}

int countsubstrings(string s)
{
    int N = s.length();
    string str = "cat";
    int count = 0;
    int occur = 0;
    for (int i = 0; i < N-3; i++) {
        occur = 0;
        for (int j = 0; j < 3; j++) {
            if (s[i+j] == str[j])
            {
                occur += 1;
            }
        }
        if (occur == 3) {
            count += 1;
        }
    }
    
    return count;
}

string readFiletoString(string filepath) 
{
    ifstream inputfile;
    inputfile.open(filepath);
    char output[100];
    if (inputfile.is_open()) {
        while (!inputfile.eof()) {
            inputfile >> output;
        }
    } else {
        cerr << "Could not open file";
        exit(EXIT_FAILURE);
    }
    inputfile.close();
    std::string inputstrfile(output);
    return inputstrfile;
}

bool unittest_standard()
{
    string s = "I love my cats.";
    int expected = 1;
    int actual = countsubstrings(s);
    if (expected == actual) {
        return true;
    }
    return false;
}

bool unittest_empty()
{
    string s = "";
    int expected = 0;
    int actual = countsubstrings(s);
    if (expected == actual) {
        return true;
    }
    return false;
}

bool unittest_smallstr()
{
    string s = "ca";
    int expected = 0;
    int actual = countsubstrings(s);
    if (expected == actual) {
        return true;
    }
    return false;
}

bool unittest_casesensitive()
{
    string s = "catCatcatCatcatCat";
    int expected = 3;
    int actual = countsubstrings(s);
    if (expected == actual) {
        return true;
    }
    return false;
}

bool unittest_filereader_empty()
{
    string emptyFile = "emptyfile.txt";
    string expected = "";
    string actual = readFiletoString(emptyfile);
    if (expected == actual) {
        return true;
    }
    return false;
}

bool unittest_filereader_std()
{
    string filepath = "cat.txt";
    string expected = "I love cats.";
    string actual = readFiletoString(filepath);
    if (expected == actual) {
        return true;
    }
    return false;
}