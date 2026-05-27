#include <iostream>
#include<cstdlib>
using namespace std;

int lives = 3;
int hintCount = 0;

void gameOver() {
    cout << "\nNo lives left...\nGAME OVER.\n";
    exit(0);
}

void wrongAnswer() {
    lives--;
    cout << "\nWrong answer! Lives left: " << lives << endl;
    if (lives <= 0) gameOver();
}

void useHint() {
    hintCount++;
    if (hintCount > 3) {
        cout << "\nYou used too many hints...\nGAME OVER.\n";
        exit(0);
    }
}

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

class Story {
public:
    virtual ~Story() {}
    virtual void play(string name, int role) = 0;
};

//story 1
class LabAssistant: public Story {
public:
    void play(string name, int role) {
    clear();
    cout << "----------------------------------\n";
    cout << "     LAB ASSISTANT MYSTERY \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the lab...\n";
    cout << "Something feels off.\n";
    cout << "An important experiment is missing.\n\n";

    cout << "Press Enter to start your investigation...";
    cin.ignore();
    cin.get();

lab();
security();
sdflab();
library();
staffroom();
meetingroom();
}

void lab(){
    clear();
    int choice;
    cout << "----------------------------------\n";
    cout << "               LAB                \n";
    cout << "----------------------------------\n\n";
    cout << "You are working late in the lab...\n";
    cout << "The system feels unusually slow.\n";
    cout << "You check the logs...\n\n";

    cout << "\"Login detected at 2:13 AM using temporary override.\"\n\n";

    while(true){
        cout << "What does this suggest?\n";
        cout << "1. Normal system usage\n";
        cout << "2. Unauthorized access\n";
        cout << "3. System error only\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==2){
            cout << "\nCorrect!\n";
            cout << "-> Someone accessed the system without permission.\n\n";
            break;
        }
        else if(choice==4){
            cout << "Game over..\n";
            exit(0);
        }
       else{
    wrongAnswer();
}
    }
}

void security(){
    clear();
    int choice, attempts = 0;
    cout << "----------------------------------\n";
    cout << "          Security Room           \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the security room...\n";
    cout << "CCTV screens flicker.\n";
    cout << "System is locked.\n\n";

    while(true){
        cout << "Riddle:\n";
        cout << "What can travel around the world while staying in the same place?\n\n";

        cout << "1. Car\n";
        cout << "2. Stamp\n";
        cout << "3. Airplane\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==2){
            cout << "\nCorrect!\n";
            cout << "Access granted...\n";
            cout << "You check CCTV footage.\n";
            cout << "A person enters the exam cell.\n";
            cout << "Face unclear due to glitch.\n\n";
            break;
        }
        else if(choice==4){
            cout << "Game over..\n";
            exit(0);
        }
       else{
    attempts++;
    if(attempts>=2){
        useHint();
        cout << "Hint: Think about letters and postage.\n\n";
    }
    else{
        wrongAnswer();
    }
}
    }
}

void sdflab(){
    clear();
    int choice;

    cout << "----------------------------------\n";
    cout << "             SDF Lab          \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the SDF Lab...\n";
    cout << "Systems are locked.\n";
    cout << "A terminal lights up:\n";
    cout << "\"ACCESS RESTRICTED\"\n\n";

    while(true){
        cout << "Puzzle:\n";
        cout << "If A=1, B=2, C=3...\n";
        cout << "What does 3-1-20 spell?\n\n";

        cout << "1. BAT\n";
        cout << "2. CAT\n";
        cout << "3. CAR\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==2){
            cout << "\nCorrect!\n";
            cout << "Access granted...\n";
            cout << "Decrypting files...\n";
            cout << "\"Meeting postponed... paper will be handled tonight...\"\n\n";
            break;
        }
        else if(choice==4){
            cout << "Game over..\n";
            exit(0);
        }
        else{
    wrongAnswer();
}
    }
}

void accuse(){
    clear();
    int choice, accuseChoice;
    int subchoice;

        cout << "----------------------------------\n";
        cout << "            ACCUSATION          \n";
        cout << "----------------------------------\n\n";
        cout << "You have connected the dots...\n\n";

    while (true) {
        cout << "Do you want to accuse the culprit?\n";
        cout << "1. Yes\n2. No\n";
        cout << "3. End the game"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nWho do you accuse?\n";
            cout << "1.Faculty Member\n";
            cout << "2. Principal\n";
            cout << "3. Lab Incharge\n";
            cout << "4. Vice President\n";
            cout << "5. Administrative Staff\n";
            cout << "6. Student Representative\n";
            cout << "7. Someone else\n";
            cout << "Enter choice: ";
            cin >> accuseChoice;

            if (accuseChoice == 4) {
               cout << "\nYou’ve made your accusation...\n";
               cout << "The atmosphere grows tense...\n";
               chessroom();
            }
            else {
                cout << "\nWrong accusation...\n";
                cout << "The real culprit escapes.\n";
                cout << "GAME OVER.\n";
                exit(0);
            }
            break;
        }
        else if (choice==2) {
          cout << "\nYou decide not to accuse yet...\n";
          cout << "Maybe you need more evidence.\n\n";
          while (true) {
                cout << "What would you like to do?\n";
                cout << "1. Check Evidence\n";
                cout << "2. Hint\n";
                cout << "3. Exit\n";
                cout << "Enter choice: ";
                cin >> subchoice;
                if (subchoice == 1) {
                    cout << "\nEvidence Summary:\n\n";

                    cout << "Library Clue:\n";
                    cout << "- A meeting was scheduled but suddenly cancelled.\n\n";

                    cout << " Staff Room Clue:\n";
                    cout << "- Someone important did not attend the meeting.\n\n";

                    cout << " Meeting Room Clue:\n";
                    cout << "- Meeting time: 2:00 AM\n";

                    cout << "Additional Observation:\n";
                    cout << "- Lab activity recorded at 2:13 AM\n\n";

                    cout << "Think carefully...\n";
                    cout << "Do these details align?\n\n";
                    break;
}
                else if (subchoice == 2) {
                    cout << "\nHint: Focus on the time mismatch...\n\n";
                    break;
                }
                else if (subchoice == 3) {
                   cout<<"Game over.."<<endl;
                   exit(0);
                }
                else {
                    cout << "Invalid choice. Try again.\n\n";
                }
}
        }
        else if(choice==3){
            cout<<"Game over.."<<endl;
           exit(0);
}

        else {
            cout << "Invalid choice. Try again.\n\n";
        }
    }
}

void library(){
    clear();
    string answer;

    cout << "----------------------------------\n";
    cout << "              LIBRARY         \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the library....\n";
    cout << "A book lies open on the table.\n";
    cout << "Some letters are circled strangely...You look at then suspiciously\n\n";

while(true){
   cout << "M T E I N E G\n";
   cout << "Rearrange to form a meaningful word:\n";
   cout << "(Type 'hint' if needed and 'exit' to end the game)\n";
   cout << "Enter your answer: ";
   cin >> answer;

for(int i=0;i<answer.length();i++){
    answer[i]=tolower(answer[i]);
}
if (answer == "hint") {
   useHint();
   cout << "Hint: It is something that can be cancelled...\n\n";
}
else if(answer=="meeting"){
   cout << "\nCorrect! MEETING\n";
   cout << "A torn note falls out of the book:\n";
   cout << "\"A scheduled meeting was suddenly cancelled that day.\"\n";
   break;
}
else if(answer=="exit"){
    cout<<"Game over.."<<endl;
    exit(0);
}
else {
   wrongAnswer();
}
}
}


void staffroom(){
    clear();
    int choice;

    cout << "----------------------------------\n";
    cout << "            STAFF ROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the staff room...\n";
    cout << "Professors are talking quietly.\n";
    cout << "One of them looks concerned.\n\n";
    while (true) {
        cout << "Do you want to talk?\n";
        cout << "1. Yes\n2. No\n";
        cout << "3. End the game\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n\"Hmm... something strange did happen that day...\"\n";
            cout << "\"A meeting was scheduled...\"\n";
            cout << "\"But someone important did not show up...\"\n";
            cout << "\"I thought it was odd at the time.\"\n";
            cout << "\nIf someone important missed the meeting...\n";
            cout << "Where were they instead?\n";
            break;
        }
        else if (choice == 2) {
            cout << "\nYou decide not to talk...\n";
            cout << "But maybe you are missing something important.\n\n";
            break;
        }
        else if(choice==3){
            cout<<"Game over.."<<endl;
            exit(0);
}
       else {
    wrongAnswer();
}
        }
    }


void meetingroom(){
    clear();
    int choice;
    cout << "----------------------------------\n";
    cout << "          MEETING ROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the meeting room...\n";
    cout << "Files are neatly arranged.\n";
    cout << "A register catches your attention.\n\n";

    while (true) {
        cout << "What do you want to check?\n";
        cout << "1. Attendees\n2. Time\n3. Notes\n";
        cout << "4. Hint\n";
        cout << "5. Accuse\n";
        cout << "6. End the game\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n Attendees List:\n";
            cout << "- Principal\n";
            cout << "- Vice President\n";
            cout << "- Faculty Members\n";
            cout << "- Lab Incharge\n";
            cout << "- Administrative Staff\n";
            cout << "- Student Representative\n\n";
        }
        else if (choice == 2) {
            cout << "\nMeeting Time: 2:00 AM\n\n";
        }
        else if (choice == 3) {
            cout << "\nNotes:\n";
            cout << "Meeting was brief.\n";
            cout << "No major discussions recorded.\n\n";
        }
        else if (choice == 4) {
            cout << "\nHint: Focus on time + presence mismatch...\n\n";
        }
       else if(choice==6){
            cout<<"Game over.."<<endl;
           exit(0);
}
       else if(choice==5){
            accuse();
       }

       else {
    wrongAnswer();
    continue;
}
    }
}

void chessroom(){
    clear();
    int choice;
   cout << "----------------------------------\n";
    cout << "          CHESS ROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You enter a dimly lit room...\n";
    cout << "A chess board is placed on the table.\n";
    cout << "The Vice President is waiting.\n\n";

    cout << "\"So... you figured it out?\"\n\n";

    cout << "1. Confront him\n";
    cout << "2. Stay silent\n";
    cout << "Enter choice: ";
    cin >> choice;
    if (choice == 1) {
        cout << "\n\"It was you.\"\n";
        cout << "\"The meeting... the records...\"\n";
        cout << "\"Everything points to you.\"\n\n";

        cout << "He smiles...\n";
        cout << "\"Impressive.\"\n";
        cout << "\"Most people wouldn't have noticed.\"\n\n";

        cout << "\"Exams control everything...\"\n";
        cout << "\"Power, rankings, future...\"\n";
        cout << "\"I just took control.\"\n\n";

        cout << "He leans back, calm and confident...\n\n";

        cout << "CASE CLOSED.\n";
        cout << "You solved the mystery!\n";
        exit(0);
    }
    else if (choice == 2) {
        cout << "\nYou hesitate...\n";
        cout << "The moment slips away.\n\n";
        cout << "The truth remains hidden.\n";
        cout << "GAME OVER.\n";
        exit(0);
}
    else {
        cout << "\nInvalid choice.\n";
    }
}

};

//story 2
class Student: public Story {
public:
    void play(string name, int role) {
    clear();
    cout << "====================================\n";
    cout << "        THE SDF-II HEIST\n";
    cout << "====================================\n\n";
    cout << "You’re in class when suddenly...\n";
    cout << "\"SDF-II paper is missing.\"\n\n";

    cout << "Something feels off.\n";
    cout << "You decide to investigate.\n\n";
    cout << "Press Enter to start your investigation...";
    cin.ignore();
    cin.get();


classroom();
StaffRoom();
Library();
basketballRoom();
securityRoom();
meetingRoom();

    cout << "\nEND OF GAME\n";
    cout << "Thanks for playing!\n";
}

   void classroom(){
    clear();
    int choice;

    cout << "----------------------------------\n";
    cout << "          CLASSROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You are sitting in class when your phone buzzes...\n";
    cout << "\"SDF-II paper is missing.\"\n\n";

    cout << "Students start whispering.\n";
    cout << "You notice a slip near the notice board.\n\n";

    cout << "\"Staff Room lock checked at 10:45 PM - working fine.\"\n\n";

    while(true){
        cout << "What does this mean?\n";
        cout << "1. The lock was broken\n";
        cout << "2. Someone opened it normally\n";
        cout << "3. It was just routine checking\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==2){
            cout << "\nCorrect.\n";
            cout << "-> The lock was not broken.\n";
            cout << "-> Someone used proper access.\n\n";
            cin.ignore();
    cin.get();
            break;
        }
        else if(choice==4){
            cout<<"Game over.."<<endl;
            exit(0);
        }
       else{
    wrongAnswer();
}
    }
}

void StaffRoom(){
    clear();
    int choice;

    cout << "----------------------------------\n";
    cout << "          STAFF ROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the staff room...\n";
    cout << "Everything looks normal.\n";
    cout << "But one chair is slightly pulled out.\n\n";

    while(true){
        cout << "Find the odd one:\n";
        cout << "1. Marker\n";
        cout << "2. Chalk\n";
        cout << "3. Duster\n";
        cout << "4. USB Drive\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==4){
            cout << "\nCorrect.\n";
            cout << "You pick up the USB drive.\n\n";

            cout << "You quickly check it...\n";
            cout << "File found: SDF_draft_v2\n\n";

            cout << "-> The paper existed digitally.\n";
            cout << "-> Someone accessed or copied it.\n\n";
          cin.ignore();
    cin.get();
            break;
        }
        else if(choice==5){
            cout<<"Game over.."<<endl;
            exit(0);
        }
        else{
           wrongAnswer();
        }
    }
}

void Library(){
    clear();
    int choice;

   cout << "----------------------------------\n";
    cout << "          LIBRARY        \n";
    cout << "----------------------------------\n\n";
    cout << "You enter the library...\n";
    cout << "It is unusually quiet.\n";
    cout << "You check the register.\n\n";

    while(true){
        cout << "Arrange the letters:\n";
        cout << "G H I T N \n\n";

        cout << "1. Thing\n";
        cout << "2. Night\n";
        cout << "3. Hint\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==2){
            cout << "\nCorrect.\n\n";

            cout << "You scan the late-night entries...\n";
            cout << "\"Admin Staff - 11:20 PM\"\n";
            cout << "No exit recorded.\n\n";

            cout << "-> Someone stayed late.\n";
            cout << "-> Activity not properly logged.\n\n";
            cin.ignore();
    cin.get();
            break;
        }
        else if(choice==4){
            cout<<"Game over.."<<endl;
            exit(0);
        }
        else{
    wrongAnswer();
}
    }
}

void basketballRoom() {
    clear();
    int choice;
    cout << "----------------------------------\n";
    cout << "          BASKETBALL COURT        \n";
    cout << "----------------------------------\n\n";
    cout << "You head to the court...\n";
    cout << "It is empty except for the captain, casually shooting hoops.\n";
    cout << "He notices you.\n\n";
    cout << "\"You are not here to play.\"\n\n";

    while (true) {
        cout << "Ask about last night?\n";
        cout << "1. Yes\n2. No\n";
        cout << "3. End the game\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nYou: \"Hey… were you here last night?\"\n\n";
            cout << "Him: \"Yeah. Practice ran late.\"\n";
            cout << "(He pauses, thinking...)\n";
            cout << "\"There was someone else though.\"\n\n";
            cout << "You wait.\n\n";
            cout << "\"Did not look like they belonged here.\"\n";
            cout << "\"Just sitting on the bench... with a bag.\"\n\n";
            cout << "You: \"Student?\"\n";
            cout << "He shrugs.\n";
            cout << "\"Did not look like one.\"\n\n";
            cout << "You think:\n";
            cout << "\"They were not rushing… they were waiting.\"\n";
            cout << "\"This was planned.\"\n\n";

            //break;
            cout << "\nPress Enter to continue...";
  cin.ignore();
    cin.get();
    break;
        }
        else if (choice == 2) {
            cout << "\nYou decide not to ask...\n";
            cout << "But something about this place feels important.\n\n";
        }
        else if(choice==3) {
             cout<<"Game over.."<<endl;
            exit(0);
        }
        else {
            cout << "Invalid choice. Try again.\n\n";
        }
    }
}

void accuse(){
    clear();
    int choice, accuseChoice;
    int subchoice;

    cout << "----------------------------------\n";
    cout << "          ACCUSATION       \n";
    cout << "----------------------------------\n\n";
    cout << "You have connected the dots...\n\n";

    while (true) {
        cout << "you surely want to accuse the culprit?\n";
        cout << "1. Yes\n2. No\n";
        cout << "3. End the game"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nWho do you accuse?\n";
            cout << "1.Faculty Member\n";
            cout << "2. Principal\n";
            cout << "3. Lab Incharge\n";
            cout << "4. Vice President\n";
            cout << "5. Admin Staff\n";
            cout << "6. Student Representative\n";
            cout << "7. Someone else\n";
            cout << "Enter choice: ";
            cin >> accuseChoice;

            if (accuseChoice == 5) {
                cout << "\nYou have made your accusation...\n";
                cout << "The atmosphere grows tense...\n";

                cout << "\"It was not a student.\"\n\n";
                cout << "People exchange glances.\n\n";

                cout << "\"The access...the timing the movement...\n";
                cout << "\"It had to be someone from admin.\"\n\n";

                cout << "Silence.\n\n";

                cout << "One staff member shifts uncomfortably.\n";
                cout << "\"Yeah.\"\n\n";

                cout << "They sigh.\n";
                cout << "\"I did not think it would go this far.\"\n";
                cout << "\"I copied the file then took the paper too.\"\n\n";

                cout << "No drama. Just a mistake.\n\n";

                cout << "CASE CLOSED.\n";
                cout << "The paper is recovered.\n";
                cout << "Things slowly return to normal.\n";
                exit(0);
            }
            else {
                cout << "\nWrong accusation\n";
                cout << "The real culprit escapes.\n";
                cout << "GAME OVER.\n";
                exit(0);
            }
            break;
        }
        else if (choice==2) {
          cout << "\nYou decide not to accuse yet...\n";
          cout << "Maybe you need more evidence.\n\n";
          while (true) {
                cout << "What would you like to do?\n";
                cout << "1. Check Evidence\n";
                cout << "2. Hint\n";
                cout << "3. Exit\n";
                cout << "Enter choice: ";
                cin >> subchoice;
                if (subchoice == 1) {
                    cout << "\nEvidence Summary:\n\n";
                    cout << "\nYou go over everything again...\n\n";

                    cout << "- No forced entry in staff room\n";
                    cout << "- Digital file was accessed\n";
                    cout << "- Late night movement in library\n";
                    cout << "- Unknown person seen at court with a bag\n";
                    cout << "- Security footage shows official ID\n\n";
                    cout << "Think carefully...\n";
                    cout << "Do these details align?\n\n";

                    break;
}
                else if (subchoice == 2) {
                    cout << "\nHint:\n";
                    cout << "Think about who had:\n";
                    cout << "- Access to the staff room\n";
                    cout << "- Access to digital files\n";
                    cout << "- Freedom to move at night\n\n";
                    break;
                }
                else if (subchoice == 3) {
                    cout << "\nYou step back and prepare your accusation...\n\n";
                    break;
                }
                else {
                    cout << "Invalid choice. Try again.\n\n";
                }
}
        }
        else if(choice==3){
            cout<<"Game over.."<<endl;
           exit(0);
}
        else {
            cout << "Invalid choice. Try again.\n\n";
        }
    }
}
void securityRoom() {
    clear();
    string answer;

   cout << "----------------------------------\n";
    cout << "          SECURITY ROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You manage to get into the security room...\n";
    cout << "The screens flicker slightly.\n";
    cout << "The guard is not around.\n\n";

    while (true) {
        cout << "Puzzle:\n";
        cout << "What has to be broken before you can use it?\n";
        cout << "Enter your answer: ";
        cout << "(Type 'hint' if needed and 'exit' to end the game)\n";
        cin >> answer;

        for (int i = 0; i < answer.length(); i++) {
            answer[i] = tolower(answer[i]);
        }

        if (answer == "egg") {
            cout << "\nCorrect.\n\n";
            cout << "You scroll through the footage...\n\n";
            cout << "There\n";
            cout << "Someone enters the staff room.\n";
            cout << "Later appears near the court.\n";
            cout << "Carrying a bag.\n\n";
            cout << "You zoom in...\n";
            cout << "Blurry… but visible enough.\n\n";
            cout << "Wearing an official ID card.\n\n";
            cout << "You lean back.\n";
            cout << "\"Yeah… that’s not a student.\"\n\n";
            cout << "You are starting to see the full picture now...\n\n";
            cout << "- No forced entry\n";
            cout << "- Late night movement\n";
            cout << "- Access to files\n";
            cout << "- Official identity\n\n";
            cout << "Something about this is very deliberate...\n\n";
            cin.ignore();
    cin.get();
            break;
        }
        else if (answer == "hint") {
    useHint();
    cout << "Hint: You probably had it for breakfast.\n\n";
}
        else if(answer=="exit"){
            cout<<"Game over.."<<endl;
            exit(0);
        }
        else {
    wrongAnswer();
}
    }
}

    void meetingRoom() {
    clear();
    int choice;

    cout << "----------------------------------\n";
    cout << "          MEETING ROOM        \n";
    cout << "----------------------------------\n\n";
    cout << "You walk into the meeting room...\n";
    cout << "A few members are already discussing the situation.\n\n";
    cout << "\"We need to figure this out fast.\"\n\n";
    cout << "You take a breath.\n";
    cout << "You have seen enough.\n\n";

    while (true) {
        cout << "What do you want to do?\n";
        cout << "1. Review evidence\n";
        cout << "2. Make an accusation\n";
        cout << "3. End the game\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nYou go over everything again...\n\n";

            cout << "- No forced entry in staff room\n";
            cout << "- Digital file was accessed\n";
            cout << "- Late night movement in library\n";
            cout << "- Unknown person seen at court with a bag\n";
            cout << "- Security footage shows official ID\n\n";

            cout << "You pause...\n";
            cout << "Everything connects somehow.\n\n";
        }
        else if (choice == 2) {
            cout << "\nYou step forward.\n";
            cout << "Everyone turns to look at you...\n\n";

            accuse();
            return;
        }
        else if(choice==3){
            cout<<"Game over.."<<endl;
           exit(0);
}
        else {
            cout << "Invalid choice. Try again.\n\n";
        }
    }
}
};

int main(){
string name;
int role;

cout << "========================================" << endl;
cout << "       WELCOME TO THE MYSTERY GAME      " << endl;
cout << "========================================\n" << endl;

cout<<"Enter Your Name : ";
cin>>name;

cout << "\nHello " << name << "! Choose your role to begin:" << endl;
  while (true) {
cout << "\nChoose your role:\n";
cout<<"--------------------\n";
cout << "1. Lab Assistant\n2. Student\n";
cout<<"--------------------\n"<<endl;
cin >> role;
if (role >= 1 && role <= 2){ break;}
    cout << "\nInvalid choice. Please select 1-2.\n";
}

Story* game;

     if (role == 1) game = new LabAssistant();
     else
        game = new Student();

    game->play(name, role);

    delete game;

    cout << "\n========================================" << endl;
    cout << "       THANK YOU FOR PLAYING!          " << endl;
    cout << "========================================" << endl;

    return 0;
}
