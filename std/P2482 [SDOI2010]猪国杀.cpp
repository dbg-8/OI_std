#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;

int n, m;
queue <char> cards;

inline void scan();
inline void gameover();
inline int gcover();

struct PLAYER {
	int id;
	int hp;
	int mod;	// = 0 ����   = 1 �ҳ�   = 2 ���� 
	
	vector <char> cds;
	int thinks[13];	// = 0 δ֪   = 1 �з�   = 2 �ѷ� 
	int op1, op2, op3;
	bool haveZ; // �Ƿ���������� 
	int ks; // ��ǰ�غ�ʹ�� ' ɱ ' �Ĵ���
	
	int ros; // ��ǰ��ȡ���� 
	/**************************
	
	inline void addcard();
	inline bool dying();
	inline void playstart();
	inline bool islive();
	inline void P();
	inline void K();
	inline void D();
	inline void F();
	inline void N();
	inline void W();
	inline void J();
	inline void Z();
	
	inline void dost();
	inline void outst();
	inline void doing();
	inline bool hav();
	inline void playing();
	**************************/
	
	
	inline void addcard () {	// Ĥ�� 
		cds.push_back(cards.front());
		cards.pop();
	}
	inline void outst (char ch) {	// �������ĳ����, over 
		for (int i = 0; i < cds.size(); i++)
			if (cds[i] == ch) {
				dost(ch);
				cds.erase(cds.begin() + i);
				return;
			}
	}
	inline bool hav (char ch) {	// ros λ����ĳ����, over 
			if (cds[ros] == ch)
				return true;
		return false;
	}
	inline bool havst (char ch) {	// ӵ��ĳ����, over 
		bool flag = false;
		for (int i = 0; i < cds.size(); i++)
			if (cds[i] == ch)
				flag = true;
		return flag;
	}
	inline bool sldst (char ch) {	// ��Ҫĳ���Ʋ����֮, �����Ƿ���, over 
		if (havst(ch)) {
			outst(ch);
			return true;
		}
		return false;
	}
	
	inline void playstart () {	// �غϳ�ʼ��, over
		ks = 0;
		addcard();
	} 
	 
	inline bool islive() {	// �Ƿ���, over 
		return hp > 0 ? true : false;
	}
	
	inline void P () {	// ��, over 
		hp++;
	}
	inline void K () {	// ɱ 
		
	}
	inline bool D () {
		
	}
	inline void F () {
		
	}
	inline void N () {
		
	}
	inline void M () {
		
	}
	inline void J () {
		
	}
	inline void Z () {	// �������, over 
		haveZ = true;
	}
	inline void dost (char ch) {	// ִ��ĳ���ƵĲ��� 
		if (ch == 'P') P();
		if (ch == 'K') K();
		if (ch == 'D') D();
		if (ch == 'F') F();
		if (ch == 'N') N();
		if (ch == 'M') M();
		if (ch == 'J') J();
		if (ch == 'Z') Z();
		outst(ch);
	}
	inline bool doing () {
		if (hav('P') && hp < 4) {	// �� 
			dost('P');
			return true;
		}
		if (hav('Z')) {	// ������� 
			dost('Z');
			return true;
		}
		if (hav('N')) {	// �������� 
			dost('N');
			return true;
		}
		if (hav('W')) {	// ����뷢 
			dost('W');
			return true;
		}
		
	}
	inline void playing () {
		playstart();
		for (int i = 0; i < cds.size(); i++) {
			ros = i;
			if (doing())
				i--;
			if (gcover())
				gameover();
		}
	}
} pl[13];


inline void scan() {
	scanf("%d %d\n", &n, &m);
	
}
inline int gcover () { // re 1, ����ʤ��; re 2, ����ʤ��; re 0 ��δ����. over 
	if (pl[1].hp <= 0)
		return 2;
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (pl[i].mod == 2 && pl[i].hp > 0)
			flag = false;
	if (flag == true)
		return 1;
	return 0;
}
inline void gameover() {
	
	exit(0);
}

int main() {
	
	return 0;
}
