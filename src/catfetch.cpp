#include <iostream>
#include <time.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <string>

using namespace std;

bool dev = true;

const string eyes("^O$@X-.");
const string keys("hwgpdsy");

string shorten(string s, int max) {
	return (s.length() <= max) ? s : s.substr(0,max-3) + "...";
}

char getEye(char key) {
	int e = key == 'r' ? (rand() % keys.length()) : keys.find(key);
	return e != keys.npos ? eyes[e] : 0;
}

void printCat(const string &sfx, const char eye, const bool yell, const int max) {
	string ws(max+1, ' ');
	
	system("pfetch");
	cout << ws << " O    _" << endl;
	cout << ws << "  o   \\`*-." << endl;
    cout << ws << "   .   )  _`-." << endl;
    cout << ws << "      .  : `. ." << endl;
    cout << ws << "      : _   '  \\" << endl;
    cout << ws << "      ; " << eye << "` _.   `*-._" << endl;
	if(yell) {
		cout << ws << "     _`-.-'          `-." << endl;
		cout << ws << "     /| ;       `       `." << endl;
		cout << string(max-sfx.length()+6, ' ') << sfx << "   :.       .        \\" << endl;
	} else {
		cout << ws << "      `-.-'          `-." << endl;
		cout << string(max-sfx.length()+6, ' ') << sfx << "   ;       `       `." << endl;
		cout << ws << "        :.       .        \\" << endl;
	}
    cout << ws << "        . \\  .   :   .-'   ." << endl;
    cout << ws << "        '  `+.;  ;  '      :" << endl;
    cout << ws << "        :  '  |    ;       ;-." << endl;
    cout << ws << "        ; '   : :`-:     _.`* ;" << endl;
    cout << ws << "     .*' /  .*' ; .*`- +'  `*'" << endl;
    cout << ws << "     `*-*   `*-*  `*-*'" << endl << endl;
}

void readArgs(int argc, char **argv, string &sfx, char &eye, bool &yell) {
	int i = 1;
	
	if(strlen(argv[1]) >= 2 && argv[1][0] == '-') {
		i = 2;
		if(yell = (argv[1][1] == 'Y') && strlen(argv[1]) >= 3)
			eye = getEye(argv[1][2]);
		eye = eye ?: getEye(argv[1][1]);
	}
	
	for(; i < argc; i++)
		sfx += string(argv[i]) + ' ';
	if(sfx.length() != 0 && !eye) eye = '*';
}

void defaultChoices(string &sfx, char &eye, bool &yell) {
	vector<string> choices = {
		"nyaa", "purr", "prrrrrrrrrrrrrrrrrr", "wrrrao", 
		"mrrowow", "meowww", "hiss"
	};
	int choice = rand() % choices.size();
	if(!eye) {
		eye = '*';
		if(choice == 1 || choice == 2) eye = '-';
		else if(choice == 0) eye = '^';
	}
	if(choice == 6) yell = true;
	sfx = '*' + choices[choice] + '*';
}

int main(int argc, char **argv) {
	srand(time(NULL));
	char eye = 0;
	string sfx = "";
	bool yell = false;
	
	if(argc > 1)
		readArgs(argc, argv, sfx, eye, yell);
	if(!sfx.length())
		defaultChoices(sfx, eye, yell);
	
	int max = 10;
	sfx = shorten(sfx, max+6);
	printCat(sfx, eye, yell, max);
	return 0;
}