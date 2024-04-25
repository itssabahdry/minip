#include<iostream>
#include<string>
using namespace std;
class ostad {
private:
    string user , pass;
    string answer , question ;
    string descriptiveQuestion[30] , testQuestion[30] , fouranswer[200];
    int n = 0;
    float totalPoint = 0;
    float descriptivePoint[30], testPoint[30];
    int i = 0 , j = 0 , correctAnswer[30];
public:
    ostad(string s1 , string s2) {
        user = s1;
        pass = s2;
    }
};

