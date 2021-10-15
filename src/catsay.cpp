#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

vector<string> split(const string& s, const char delim = ' ') {
	stringstream ss{ s };
	vector<string> v;
	string sub;
	while(getline(ss, sub, delim))
		v.push_back(sub);
	return v;
}

string whitespace(int len, char c = ' ') {
	string s = "";
	for(int i = 0; i < len; i++)
		s += c;
	return s;
}

vector<string> wrappedString(vector<string> arr, int *max, int wrap = 50) {
	vector<string> v;
	string line = "";
	for(int i = 0; i < arr.size(); i++) {
		if(line.length() == 0 && arr[i].length() > wrap) {
			string newLine = string(arr[i]).substr(0, wrap) + ' ';
			v.push_back(newLine);
			if(newLine.length() > *max) *max = newLine.length();
			arr[i] = arr[i].substr(wrap, arr[i].length());
			i--;
			continue;
		}
		if(line.length() + arr[i].length() > wrap) {
			v.push_back(line);
			if(line.length() > *max) *max = line.length();
			line = "";
			i--;
			continue;
		}
		line += arr[i] + ' ';
	}
	if(line.length() > *max) *max = line.length();
	if(line.length() != 0)
		v.push_back(line);
	return v;
}

int main(int argc, char **argv) {
	vector<string> args;
	if(argc <= 1) {
		srand(time(NULL));
		vector<string> choices = {"meow", "hiss", "nyaa", "purr", "uwu", "rawr", "pwease give me huggy wuggies", "Naname nanajyuunana-do no narabi de nakunaku inanaku nanahan nanadai nannaku narabete naganagame", "whos in paris"};
		string s = choices[rand() % choices.size()];
		args = split(s);
	}else
	for(int i = 1; i < argc; i++)
		args.push_back(string(argv[i]));
	
	
	int max = 0;
	vector<string> lines = wrappedString(args, &max);
	max = max < 5 ? 5 : max;
	cout << max << endl;
	string ws = whitespace(max-1);
	string un = whitespace(max-4, '-');
	cout << "  ." << whitespace(max-1, '-') << '.' << endl;
	for(string s : lines) {
		cout << " | " << s << whitespace(max - s.length()) << "|" << endl;
	}
	
	cout << "  '" << whitespace(max-4, '-') << "._  |   _" << endl;
	cout << ws << "  `.\\   \\`*-." << endl;
    cout << ws << "    `\\   )  _`-." << endl;
    cout << ws << "        .  : `. ." << endl;
    cout << ws << "        : _   '  \\" << endl;
    cout << ws << "        ; *` _.   `*-._" << endl;
    cout << ws << "        `-.-'          `-." << endl;
    cout << ws << "          ;       `       `." << endl;
    cout << ws << "          :.       .        \\" << endl;
    cout << ws << "          . \\  .   :   .-'   ." << endl;
    cout << ws << "          '  `+.;  ;  '      :" << endl;
    cout << ws << "          :  '  |    ;       ;-." << endl;
    cout << ws << "          ; '   : :`-:     _.`* ;" << endl;
    cout << ws << "       .*' /  .*' ; .*`- +'  `*'" << endl;
    cout << ws << "       `*-*   `*-*  `*-*'" << endl << endl;
	
	return 0;
}