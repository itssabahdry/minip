#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<vector>
using namespace std;

const int sizeOfExam = 10;
class ostad {
protected:
    string user , pass , s1;
    string answer , ask , question ;
    string descriptiveQuestion[30] , testQuestion[30] , fouranswer[200];
    int n = 0;
    float totalPoint = 0;
    float descriptivePoint[30], testPoint[30];
    int i = 0 , j = 0 , correctAnswer[30];
    string examList[10];
    int nameNum = 0 , four = 0;
    char abcd[4] = { 'a' , 'b' , 'c' , 'd' };
    vector <string> nameStudent;
public:
    void Exam() {
            while(totalPoint != 20) {
                cout << "Test or Descriptive ?";
                cin >> answer;
                if(answer == "Descriptive" || answer == "descriptive") {
                    cin >> ws;
                    getline(cin , question);
                    descriptiveQuestion[i] = question;
                    cin >> ws;
                    cout << "Score for this question" << i + 1 << " : ";
                    cin >> descriptivePoint[i];
                    while((descriptivePoint[i] + totalPoint) > 20) {
                        cout << "Score for this exam is more than 20!" << endl
                        << "your total score is " << totalPoint << " . " << endl
                        << "you can use up to " << 20 - totalPoint << " no more than this is allowed." << endl;
                        cin >> descriptivePoint[i];
                    }
                    totalPoint += descriptivePoint[i];
                    i++;
                } else if(answer == "test" || answer == "Test") {
                    cin >> ws;
                    getline(cin , ask);
                    testQuestion[j] = ask;
                    for(int j = 0 + n; j < 4 + n ; j++) {
                        getline(cin , fouranswer[j + n]);
                    }
                    cout << "correct answer is : (please enter the number --> (1,2,,3,4))";
                    cin >> correctAnswer[j];
                    n += 4;
                    cout << "score for this question " << j + 1 << " : " << endl;
                    cin >> testPoint[j];
                    while((testPoint[j] + totalPoint) > 20) {
                        cout << "score for this Exam is more than 20!" << endl <<
                        "your total score is " << totalPoint << " . " << endl <<
                        "you can use up to " << 20 - totalPoint << " ,no more than this is allowed. "
                        << endl;
                        cin >> testPoint[j];
                    }
                    totalPoint += testPoint[j];
                    j++;
                }
            }
        }
    void newExam( string namelist){
        examList [ nameNum ] = namelist ;
        cout << "new exam list '" << namelist << "' created succesfuly :)." << endl;
        nameNum ++;
    }
    void displayExam( int listNumber){
        if ( listNumber >= 0 && listNumber < 10 ){
            cout << "Exam list " << listNumber + 1 << " : " << examList [listNumber] << endl;
            for (int i = 0; testQuestion[i] != "\0"; ++i) {
                int p = 0;
                cout << testQuestion[i] << " ( " << testPoint[i] << " point )" << endl;
                for (int k = four; k < four + 4 ; ++k) {
                    cout << abcd[p] << " ) " << fouranswer[k] << endl;
                    p++;
                }
            four +=4;
            }
            for (int i = 0; descriptiveQuestion[i] != "\0" ; ++i) {
                cout << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl;
            }

        } else {
            cout << "Invalid list number!" << endl;
        }
    }
    void addStudent(){
        int numberOfStudent;
        cout << "how many student do you want to add ?" << endl;
        cin >> numberOfStudent;
        cout << "the list of student who can take the exam: ";
        for (int i = 0; i < numberOfStudent ; ++i) {
            string name;
            cin >> name;
            nameStudent.push_back( name );
        }
    }
   bool searchName( string name ){
        for (int k = 0; k < nameStudent.size() ; ++k) {
            if ( nameStudent.at( k ) == name )
                return true;
        }
    }
};
class student : public ostad {
private: 
    string testAnswer [ 30 ] , descriptiveAnswer [ 30 ] ;
    int num  , count , numberOfTestQuestion  ;
    int unansweredQuestions[ 30 ];
public:
    student(ostad *pOstad) {
    }
    void displayExamForStudent(int listNumber) {
        if ( listNumber >= 0 && listNumber < sizeOfExam ) {
            cout << "Exam list " << listNumber + 1 << " : " << examList [ listNumber ] << endl;
            count = 0;
            num = 1;
            for (int i = 0; testQuestion[i] != "\0"; ++i) {
                cout << "Question " << num  << " : " << endl;
                int p = 0;

                cout << testQuestion[i] << " ( " << testPoint[i] << " point )" << endl;
                for (int k = four; k < four + 4 ; ++k) {
                    cout << abcd[p] << " ) " << fouranswer[k] << endl;
                    p++;
                }
                four +=4;
                num++;
            }
            numberOfTestQuestion = num - 1;
            for (int i = 0; descriptiveQuestion[i] != "\0" ; ++i) {
                cout << "Question " << num << " : " << endl;
                cout << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl;
                num++;
            }

        } else {
            cout << "Invalid list number!" << endl;
            for (int i = 0; i < num  ; ++i) { // student answer
                string answer;
                getline( cin , answer );
                if( answer.empty() ){
                    unansweredQuestions [ count ] = i;
                    count++;
                }
                if( i <= numberOfTestQuestion ){
                    testAnswer [ i ] = answer;
                }
                if ( i > numberOfTestQuestion ){
                    descriptiveAnswer [ i ] = answer;
                }
            }

        }
    }
    bool isTime() {
        auto start = chrono:: steady_clock ::now();
        auto TimeLimit = chrono:: minutes(30);
        this_thread::sleep_for(TimeLimit);
        auto end = chrono:: steady_clock ::now();
        return(end - start) >= TimeLimit;
    }
};

int main() {
    string user, pass, person, nameList, sentence;
    int flag = 0;
    int i = 0, num;
    while ( flag != 2 ) {
        cout << "ostad or student ?";
        cin >> person;
        cout << "enter your ID : ";
        cin >> user;
        cout << "enter your pasword : ";
        cin >> pass;
        ostad ob[sizeOfExam];
        student *ob1[sizeOfExam];
        if (person == "ostad" && user == "Lotfi" && pass == "1234") {
            while (i <= 9) {
                cout
                        << "which one ? ( 1 : create new list , 2 : display exam , 3 : add student , 4 : check the answer )"
                        << endl;
                cout << "the maximum of exam list is '" << sizeOfExam << "' "
                     << "and your number of your exam list is '" << i << "' ." << endl;
                cout << "if you type ( end ), the app will be close." << endl;
                cin >> ws;
                getline(cin, sentence);
                if (sentence == "1" || sentence == "create new list") {
                    cout << "namelist: ";
                    getline(cin, nameList);
                    ob[i].newExam(nameList);
                    ob[i].Exam();
                    ob[i].addStudent();
                    i++;
                }
                if (sentence == "2" || sentence == "display exam") {
                    cout << "Which exam list do you want?" << endl
                         << "Sort that list by typing in the natural numbers. ";
                    cin >> num;
                    ob[num - 1].displayExam(num - 1);
                }
                if (sentence == "3" || sentence == "add student") {
                    int numberList;
                    cout << "for which exam list ?";
                    cin >> numberList;
                    ob[numberList - 1].addStudent();
                }
                if (sentence == "end" || sentence == "End") {
                    flag++;
                    break;
                }
            }
        } else if (person == "student" || person == "Student") {
            string nameStudent;
            int numberOfExam [ sizeOfExam ] , count = 0 , n ;
            cout << "what is your name?";
            cin >> nameStudent;
            for (int j = 0; j < i; ++j) {

                if( ob[ j ].searchName( nameStudent ) ){
                    numberOfExam [ count ] = j;
                    count++;
                }
            }
            cout << "Exam lists that are there for you : ";
            for (int j = 0; j < count + 1  ; ++j) { //display number of list exam
                if ( numberOfExam [ 0 ] == '\0' )
                    cout << "not found any exam!";
                else
                    cout << numberOfExam [ j ] + 1 << " ";
            }
            cout << "which exam do you want to start ? ";
            cin >> n;
            * ob1 [n - 1] = &ob [n - 1];
            ob1[n - 1]->displayExamForStudent(n - 1);

        } else
            cout << "Login error." << endl << "One of the parts name , user or pass Wrong!";
        }
    return 0;
}
