#include <iostream>
#include <deque>
#include <string>

struct NODE {
	std:: string str;
	int la;
	int ne;
} ;
class kagari {
	private:
		#define MAXLEN 1000003
		int maxlen;
		NODE a[MAXLEN];
		int ccnt;
	public:
		int size;
		int front, back;
		inline void clear () {
			maxlen = MAXLEN;
			front = back = size = ccnt = 0;
			for (int i = 0; i < maxlen; i++)
				a[i].la = a[i].ne = 0, a[i].str.clear();
		}
		inline void push_front (std:: string str) {
			a[++ccnt].str = str, a[ccnt].ne = front, a[front].la = ccnt;
			front = ccnt;
			size++;
		}
		inline void push_back (std:: string str) {
			a[++ccnt].str = str, a[ccnt].la = back, a[back].ne = ccnt;
			back = ccnt;
			size++;
		}
		inline void pop_front () {
			if (size) {
				front = a[front].ne;
				size--;
			}
		}
		inline void pop_back () {
			if (size) {
				back = a[back].la;
				size--;
			}
		}
		inline std:: string val_front () {
			return a[front].str;
		}
		inline std:: string val_back () {
			return a[back].str;
		}
		inline bool empty () {
			return (size == 0 ? true : false);
		}
} ;

int main () {
	std:: string str;
	kagari dq;
	dq.clear();
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
				std:: cout << dq.val_front(),
				dq.pop_front();
			std:: cout << dq.val_front() << '\n';
			str.clear();
			dq.clear();
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
