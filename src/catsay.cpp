#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

string whitespace(int len, char c = ' ') {
	string s = "";
	for(int i = 0; i < len; i++)
		s += c;
	return s;
}

int main(int argc, char** argv) {
	string s = "";
	for(int i = 1; i < argc; i++) {
		s += string(argv[i]) + " ";
	}
	if(argc > 1)
		s[s.length()-1] = ' ';
	else {
		srand(time(NULL));
		vector<string> choices = {"meow", "hiss", "nyaa", "purr", "uwu", "rawr", "pwease give me huggy wuggies", "Naname nanajyuunana-do no narabi de nakunaku inanaku nanahan nanadai nannaku narabete naganagame", "whos in paris"};
		s = choices[rand() % choices.size()];
		s += ' ';
	}
	string ws = whitespace(s.length()+2);
	string un = whitespace(s.length()+1, '-');
	cout << ws << "   _" << endl;
	cout << "/" << un << '\\' << "  \\`*-." << endl;
    cout << "| " << s  << "|" << "   )  _`-." << endl;
    cout << "\\" << un << '/' << "   .  : `. ." << endl;
    cout << ws << "\\  : _   '  \\" << endl;
    cout << ws << " \\ ; *` _.   `*-._" << endl;
    cout << ws << "   `-.-'          `-." << endl;
    cout << ws << "     ;       `       `." << endl;
    cout << ws << "     :.       .        \\" << endl;
    cout << ws << "     . \\  .   :   .-'   ." << endl;
    cout << ws << "     '  `+.;  ;  '      :" << endl;
    cout << ws << "     :  '  |    ;       ;-." << endl;
    cout << ws << "     ; '   : :`-:     _.`* ;" << endl;
    cout << ws << "  .*' /  .*' ; .*`- +'  `*'" << endl;
    cout << ws << "  `*-*   `*-*  `*-*'" << endl << endl;
	
	return 0;
}