#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

const int sizeOfExam = 10;
const int maximumExamForStudent = 400;
const int maximumtestQuestion = 30 , maximumDescriptiveQuestion = 30;
class saveNameAndExam{
private:
    vector<pair< string , int >> forCheckAnswer;
    vector <int> numExam;
public:
    void setNameAndExam( string name , int listnumber , int num){
        forCheckAnswer.push_back(make_pair(name , listnumber));
        numExam.push_back(num);
    }
    void search(int numlist){
        for (int i = 0 ; i < forCheckAnswer.size() ; ++i) {
            if ( forCheckAnswer[i].second == numlist ){
                cout << forCheckAnswer[i].first << "\t";
            }
        }
    }
 void search2(string name){
        for (int i = 0; i < forCheckAnswer.size(); ++i) {
            if (forCheckAnswer[i].first == name)
                cout << forCheckAnswer[i].second << "\t";
        }
    }
    int search3( string name , int numlist ){
        for (int i = 0; i < forCheckAnswer.size(); ++i) {
            if ( forCheckAnswer[i].first == name && forCheckAnswer[i].second == numlist )
                return numExam[i];
        }
    }
    int selectAnswerExam( string name){
        for (int i = 0; i < forCheckAnswer.size() ; ++i) {
            if ( forCheckAnswer[i].first == name ){
                return numExam[i];
            }
        }
    }
};
class ostad {
protected:
    string user , pass , s1;
    string answer , ask;
    string descriptiveQuestion[30] , testQuestion[30] , fouranswer[200];
    int n = 0;
    float totalPoint = 0;
    float descriptivePoint[30], testPoint[30];
    int i = 0 , j = 0;
    int nameNum = 0 , four = 0;
    char abcd[4] = { 'a' , 'b' , 'c' , 'd' } , correctAnswer[30];
    vector <string> nameStudent , examList;
    string testAnswer [30] , descriptiveAnswer [30] ;
    int num  , count , numberOfTestQuestion  ;
    int unansweredQuestions[30];
public:
    void Exam() {
            while(totalPoint != 20) {
                cout << "Test or Descriptive ?";
                cin >> answer;
                cin.ignore();
                if(answer == "Descriptive" || answer == "descriptive") {
                    cout << "Descriptive question " << i + 1 << " : ";
                    getline(cin , descriptiveQuestion[i]);
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
                    cout << "Test question " << j + 1 << " : ";
                    getline(cin , testQuestion[i]);
                    int p = 0;
                    for(int j = 0 + n; j < 4 + n ; j++) {
                        cout << abcd[p] << " ) ";
                        getline(cin , fouranswer[j + n]);
                        p++;
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
        examList.push_back( namelist );
        cout << "new exam list '" << namelist << "' created succesfuly :)." << endl;
    }
    void displayExam( int listNumber){
        if ( listNumber >= 0 && listNumber < 10 ){
            cout << "Exam list " << listNumber + 1 << " : " << examList [listNumber] << endl
                 << "list of student who can take the exam : ";
            for (size_t k = 0; k < nameStudent.size() ; ++k) {
                if ( k == 0 )
                    cout << nameStudent[k] ;
                else
                    cout << " , " <<  nameStudent[k] ;
            }
            cout << " ." << endl;
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
   string searchName( string name ){
        for (size_t k = 0; k < nameStudent.size() ; ++k) {
            if ( nameStudent.at( k ) == name )
                return name;
        }
    }
   
};
class student : public ostad {
public:
 void displayExamForStudent(int listNumber) {
        if ( listNumber >= 0 && listNumber < sizeOfExam ) {
            cout << "Exam list " << listNumber + 1 << " : " << examList [ listNumber ] << endl;
            count = 0;
            num = 1;
            four = 0
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
         for (int i = 0; i < this->i; ++i) {
                    cout << "Question " << num << " : " << endl;
                    cout << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl;
                    num++;
                }
                for (int i = 0; i < j; ++i) {
                    cin >> answer;
                    if (answer.empty()) {
                        testAnswer[i] = 'f';
                    } else
                        testAnswer[i] = answer.at(0);
                }
                cin.ignore();
                for (int k = 0; k < this->i; ++k) {
                    getline(cin, answer);
                    if (answer.empty()) {
                        descriptiveAnswer[k] = "No answer";
                    } else
                        descriptiveAnswer[k] = answer;
                }
        } else {
            cout << "Invalid list number!" << endl;
        }
    }
 void displayAnswer( int listNumber , string nameStudent){
        if ( listNumber >= 0 && listNumber < sizeOfExam ) {
            cout << "Exam list " << listNumber + 1 << " : " << examList [ listNumber ] << endl;
            count = 0;
            num = 1;
            four = 0;
            float point = 0;
            for (int i = 0; i < j  ; ++i) {
                cout << "Question " << i + 1 << " :  "
                     << testQuestion[i] <<  " ( " << testPoint[i] << " point )" << endl
                     << "student awnser:  " << testAnswer[i] << endl
                     << "correct awnser:  " << correctAnswer[i] << endl;
                if ( testAnswer[i] == correctAnswer[i] )
                    point +=testPoint[i];
                num++;
            }
            if( num > 0 )
              cout << "total test score:" << "  " << point << endl;
            for (int i = 0; i < this-> i ; ++i) {
                cout << "Question " << i + 1 << " :  "
                     << descriptiveQuestion[i] << " ( " << descriptivePoint[i] << " point )" << endl
                     << "student answer:  " << descriptiveAnswer[i] << endl
                     << "Enter score for this answer: ";
                int score;
                cin >> score;
                while ( score > descriptivePoint[i]){
                    cout << "The entered score exceeds the maximum score for this question. please enter a valid score: ";
                    cin >> score;
                }
                point += score;
                cin.ignore();
                num++;
                cout << "Do you have an explanation for this question?" << endl ;
                string s;
                getline(cin , s);
                if ( s == "yes" || s == "Yes" ){
                    cin >> s;
                    explanation.push_back(s);
                }
                else
                    continue;
            }
            pointForStudent.push_back( make_pair( nameStudent , point ) );
            numlistforAwnser.push_back( listNumber );
        } else {
            cout << "Invalid list number!" << endl;
          }
    }
};

int main() {
    string user, pass, person, nameList, sentence;
    int flag = 0 , i = 0, num;
    ostad ob[sizeOfExam];
    student ob1[sizeOfExam];
    while ( flag != 2 ) {
        cout << "ostad or student ?";
        cin >> person;
        cout << "enter your ID : ";
        cin >> user;
        cout << "enter your pasword : ";
        cin >> pass;
        if (person == "ostad" && user == "Lotfi" && pass == "1234") {
            while (i <= sizeOfExam) {
                cout<< "which one ? ( 1 : create new list , 2 : display exam , 3 : add student , 4 : check the answer )"
                << endl << "the maximum of exam list is '" << sizeOfExam << "' "
                << "and your number of your exam list is '" << i << "' ." << endl
                << "if you type ( end ), the app will be close." << endl;
                cin >> ws;
                getline(cin, sentence);
                if (sentence == "1" || sentence == "create new list") {
                    cout << "namelist: ";
                    getline(cin, nameList);
                    ob[i].newExam( nameList );
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
                if (sentence == "4" || sentence == "check the answer") {
                        int numberList;
                        cout << "for which exam list ?";
                        cin >> numberList;
                        ob3.search( numberList );
                        cout << endl << "which one ?";
                        string nameStudent;
                        cin.ignore();
                        getline(cin , nameStudent );
                        ob1[ ob3.selectAnswerExam( nameStudent ) ] = static_cast<student *>(&ob[ numberList - 1]);
                        ob1[ ob3.selectAnswerExam( nameStudent ) ] -> displayAnswer( numberList - 1 , nameStudent );

                    }
                    if (sentence == "5" || sentence == "see the max avarge point of studets") {

                    }
                if (sentence == "end" || sentence == "End") {
                    flag++;
                    break;
                }
            }
        } else if (person == "student" || person == "Student") {
            string sentence;
            string nameStudent;
            cout << "what is your name?";
            cin >> nameStudent;
            cout<< "which one ? ( 1 : check your exam , 2 : show exam to answer it , 3 : examination protest , 4 : history of exams , 5 : see your score )" << endl
                << "if you type ( end ), the app will be close." << endl;
            cin.ignore();
            getline(cin,sentence);
            if (sentence == "end" || sentence == "End") {
                flag++;
                break;
            }
            else {
                if (sentence == "1" || sentence == "check my exam" || sentence == "check your exam") {
                    int numberOfExam[sizeOfExam], count = 0;

                    for (int j = 0; j < i; ++j) {
                        if (ob[j].searchName(nameStudent) == nameStudent) {
                            numberOfExam[count] = j;
                            count++;
                        }
                    }
                    cout << "Exam lists that are there for you : ";
                    if (count == 0)
                        cout << "not found any exam!" << endl;
                    else {
                        for (int j = 0; j < count; ++j) {
                            cout << numberOfExam[j] + 1 << " ";
                        }
                    }
                }
        if (sentence == "2" || sentence == "show exam to answer it") {
                    int numberOfExam[sizeOfExam], count = 0;
                    for (int j = 0; j < i; ++j) {
                        if (ob[j].searchName(nameStudent) == nameStudent) {
                            numberOfExam[count] = j;
                            count++;
                        }
                    }
                    cout << "Exam lists that are there for you : ";
                    if (count == 0)
                        cout << "not found any exam!" << endl;
                    else {
                        for (int j = 0; j < count; ++j) {
                            cout << numberOfExam[j] + 1 << " ";
                        }
                        int n;
                        cout << endl <<  "which exam do you want to start ? ";
                        cin >> n;
                        ob1[countForStudent] = static_cast<student *>(&ob[n - 1]);
                        ob1[ countForStudent ]->displayExamForStudent(n - 1);
                        ob3.setNameAndExam(nameStudent, n, countForStudent);
                        countForStudent++;
                    }
                }
        }else
            cout << "Login error." << endl << "One of the parts name , user or pass Wrong!";
        }
    return 0;
}
