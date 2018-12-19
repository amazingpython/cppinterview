/**
 * This validate mustache string, basically compare a template string.
 * valid string: "{{#enable}} testing {{^notable}} {{/notable}} {{/enable}}"
 * invalid string: "{{#enable}} testing {{^notable}} {{/enable}}"
 * invalid string: "{{/enable}}
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<string> ss;
	string sd="{{", ed = "}}";
	string is = "{{#enable}} testing {{^notable}} {{/notable}} {{/enable}}";

	cout << is << endl;
	cout << "tags:" << endl;

	while (!is.empty()) {
		size_t pos = 0, epos = 0;
		if ((pos = is.find(sd)) != string::npos) {
			if ((epos = is.find(ed)) != string::npos) {
				string tag = is.substr(pos+sd.length(), epos-pos-ed.length());
				//cout << tag << endl;
				is = is.substr(epos+ed.length(), string::npos);
				// Encountered an end tag, so, look at the stack, if it is a valid entry.
				if (!tag.empty() && tag[0] == '/') {
					if (ss.empty()) {
						cout << "Error in input string" << endl;
						break;
					} else {
						string lasttag = ss.top();
						if (lasttag[0] == '#' || lasttag[0] == '^' && lasttag.substr(1, lasttag.length()) == tag.substr(1, tag.length())) {
							ss.pop();
						} else if (lasttag  == tag.substr(1, tag.length())) {
							ss.pop();
						} else {
							cout << "Error in input string" << endl;
							break;
						}
					}
				} else {
					if (!tag.empty())
						ss.push(tag);
				}
			} else {
				cout << "Error in input string" << endl;
				break;
			}
		}
	}
	if (!ss.empty()) {
        cout << "Error in input string" << endl;
	}

	return 0;
}
