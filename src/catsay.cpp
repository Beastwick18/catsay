#include <iostream>
#include <time.h>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

const string eyes = "^O$@X-.";
const string keys = "hwgpdsy";

vector<string> split(const string& s, const char delim = ' ') {
	stringstream ss{ s };
	vector<string> v;
	string sub;
	while(getline(ss, sub, delim))
		v.push_back(sub);
	return v;
}

char getEye(char key) {
	
	int e = key == 'r' ? (rand() % keys.length()) : keys.find(key);
	return e != keys.npos ? eyes[e] : 0;
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
	cout << endl << "  ." << string(max-1, '-') << '.' << endl;
	for(string s : lines)
		cout << " | " << s << string(max - s.length(), ' ') << "|" << endl;
	cout << "  '" << string(max-4, '-') << "._  |   _" << endl;
	cout << ws << "`.\\   \\`*-." << endl;
    cout << ws << "  `    )  _`-." << endl;
    cout << ws << "      .  : `. ." << endl;
    cout << ws << "      : _   '  \\" << endl;
    cout << ws << "      ; " << eye << "` _.   `*-._" << endl;
    cout << ws << "      `-.-'          `-." << endl;
    cout << ws << "        ;       `       `." << endl;
    cout << ws << "        :.       .        \\" << endl;
    cout << ws << "        . \\  .   :   .-'   ." << endl;
    cout << ws << "        '  `+.;  ;  '      :" << endl;
    cout << ws << "        :  '  |    ;       ;-." << endl;
    cout << ws << "        ; '   : :`-:     _.`* ;" << endl;
    cout << ws << "     .*' /  .*' ; .*`- +'  `*'" << endl;
    cout << ws << "     `*-*   `*-*  `*-*'" << endl << endl;
}

void readArgs(int argc, char **argv, vector<string> &args, char &eye) {
	int i = 1;
	if(strlen(argv[1]) == 2 && argv[1][0] == '-') {
		i = 2;
		eye = getEye(argv[1][1]);
	}
	for(; i < argc; i++)
		args.push_back(string(argv[i]));
	if(args.size() != 0 && !eye) eye = '*';
}

void defaultChoices(vector<string> &args, char &eye) {
	vector<string> choices = {
		"nyaa", "purr",
		"Naname nanajyuunana-do no narabi de nakunaku inanaku nanahan nanadai nannaku narabete naganagame",
		"prrrrrrrrrrrrrrrrrrrr", "wrrrao", "mrrowow",
		"*gags*", "meow", "hiss"
	};
	int choice = rand() % choices.size();
	if(!eye) {
		eye = '*';
		if(choice < 4) eye = '^';
		else if(choice == 6) eye = '@';
	}
	args = split(choices[choice]);
}

int main(int argc, char **argv) {
	srand(time(NULL));
	char eye = 0;
	vector<string> args;
	
	if(argc > 1)
		readArgs(argc, argv, args, eye);
	if(!args.size())
		defaultChoices(args, eye);
	
	int max = 0;
	vector<string> lines = wrappedString(args, max);
	
	printCat(lines, std::max(max, 3), eye);
	
	return 0;
}