#include <iostream>
#include <time.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <iomanip>

using namespace std;

const string eyes = "^O$@X-";
const string keys = "hwgpds";
const vector<string> defualts = {
    "nyaa", "purr",
    "Naname nanajyuunana-do no narabi de nakunaku inanaku nanahan nanadai nannaku narabete naganagame",
    "prrrrrrrrrrrrrrrrrrrr", "wrrrao", "mrrowow",
    "*gags*", "meow", "hiss"
};

vector<string> split(const string& s, const char delim = ' ') {
    stringstream ss{ s };
    vector<string> v;
    string sub;
    while(getline(ss, sub, delim))
        v.push_back(sub);
    return v;
}

char getEye(char key) {
    int e = ( key == 'r' ) ? (rand() % keys.length()) : keys.find(key);
    return ( e != string::npos ) * eyes[e];
}

vector<string> wrappedString(vector<string> arr, int &max, const int wrap = 50) {
    vector<string> v;
    string line = "";
    for(int i = 0; i < arr.size();) {
        if(line.length() + arr[i].length() <= wrap) {
            line += arr[i++] + ' ';
            continue;
        }
        if(line.length() == 0) {
            line = arr[i].substr(0, wrap) + ' ';
            arr[i] = arr[i].substr(wrap, arr[i].length());
        }
        v.push_back(line);
        if(line.length() > max) max = line.length();
        line = "";
    }
    if(line.length() > max) max = line.length();
    if(line.length() != 0)
        v.push_back(line);
    return v;
}

void printCat(const vector<string> &lines, const size_t max, const char eye) {
    string ws = string(max+1, ' ');
    cout << '\n' << "  ." << string(max-1, '-') << '.' << endl;
    for(string s : lines)
        cout << " | " << s << string(max - s.length(), ' ') << "|" << '\n';
    cout.flush();
    cout << "  '" << string(max-4, '-') << "._  |   _" << '\n'
         << ws << "`.\\   \\`*-." << '\n'
         << ws << "  `    )  _`-." << '\n'
         << ws << "      .  : `. ." << '\n'
         << ws << "      : _   '  \\" << '\n'
         << ws << "      ; " << eye << "` _.   `*-._" << '\n'
         << ws << "      `-.-'          `-." << '\n'
         << ws << "        ;       `       `." << '\n'
         << ws << "        :.       .        \\" << '\n'
         << ws << "        . \\  .   :   .-'   ." << '\n'
         << ws << "        '  `+.;  ;  '      :" << '\n'
         << ws << "        :  '  |    ;       ;-." << '\n'
         << ws << "        ; '   : :`-:     _.`* ;" << '\n'
         << ws << "     .*' /  .*' ; .*`- +'  `*'" << '\n'
         << ws << "     `*-*   `*-*  `*-*'" << '\n' << endl;
}

void showHelp() {
    vector<string> lines = {
        "CatSay ^w^",
        "Usage: catsay [-" + keys + "] [message] ",
    };
    int max = 0;
    for(string s : lines)
        if(s.length() > max) max = s.length();
    printCat(lines, max, '*');
} 

void defaultChoices(vector<string> &args, char &eye) {
    int choice = rand() % defualts.size();
    if(!eye) {
        eye = '*';
        if(choice < 4) eye = '^';
        else if(choice == 6) eye = '@';
    }
    args = split(defualts[choice]);
}

bool readArgs(int argc, char **argv, vector<string> &args, char &eye) {
    if(argc > 1) {
        int i = 1;
        if(argv[1][0] == '-' && strlen(argv[1]) > 1) {
            if(strlen(argv[1]) == 2) {
                i = 2;
                eye = getEye(argv[1][1]);
            } else if(strcmp(argv[1], "--help") == 0) {
                showHelp();
                return 1;
            } 
        }
        for(; i < argc; i++)
            args.push_back(string(argv[i]));
        if(args.size() != 0 && !eye) eye = '*';
    }
    if(!args.size())
        defaultChoices(args, eye);
    return 0;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    char eye = 0;
    vector<string> args;
    if(readArgs(argc, argv, args, eye)) return 0;
    
    int max = 0;
    vector<string> lines = wrappedString(args, max);
    
    printCat(lines, std::max(max, 3), eye);
    
    return 0;
}
