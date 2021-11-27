#include <iostream>
#include <deque>
#include <string>

int main () {
	std:: string str;
	std:: deque <std:: string> dq;
	bool af = true; // add at front
	while (1) {
		char ch;
		if (!(~scanf("%c", &ch)))
			break;
		if (ch == '[' || ch == ']' || ch == '\n') {
			if (af)
				dq.push_front(str);
			else
				dq.push_back(str);
		}
		if (ch == '\n') {
			while (!dq.empty())
				std:: cout << dq.front(),
				dq.pop_front();
			std:: cout << '\n';
			str.clear();
			continue;
		}
		if (ch == '[') 
			af = true, str.clear();
		else if (ch == ']') 
			af = false, str.clear();
		else
			str.push_back(ch);
	}
	return 0;
}
