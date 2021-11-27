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
	int mod;	// = 0 主公   = 1 忠臣   = 2 反贼 
	
	vector <char> cds;
	int thinks[13];	// = 0 未知   = 1 敌方   = 2 友方 
	int op1, op2, op3;
	bool haveZ; // 是否有诸葛连弩 
	int ks; // 当前回合使用 ' 杀 ' 的次数
	
	int ros; // 当前读取卡牌 
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
	
	
	inline void addcard () {	// 膜牌 
		cds.push_back(cards.front());
		cards.pop();
	}
	inline void outst (char ch) {	// 打出手上某张牌, over 
		for (int i = 0; i < cds.size(); i++)
			if (cds[i] == ch) {
				dost(ch);
				cds.erase(cds.begin() + i);
				return;
			}
	}
	inline bool hav (char ch) {	// ros 位置有某张牌, over 
			if (cds[ros] == ch)
				return true;
		return false;
	}
	inline bool havst (char ch) {	// 拥有某张牌, over 
		bool flag = false;
		for (int i = 0; i < cds.size(); i++)
			if (cds[i] == ch)
				flag = true;
		return flag;
	}
	inline bool sldst (char ch) {	// 需要某张牌并打出之, 返回是否打出, over 
		if (havst(ch)) {
			outst(ch);
			return true;
		}
		return false;
	}
	
	inline void playstart () {	// 回合初始化, over
		ks = 0;
		addcard();
	} 
	 
	inline bool islive() {	// 是否存活, over 
		return hp > 0 ? true : false;
	}
	
	inline void P () {	// 桃, over 
		hp++;
	}
	inline void K () {	// 杀 
		
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
	inline void Z () {	// 诸葛连弩, over 
		haveZ = true;
	}
	inline void dost (char ch) {	// 执行某张牌的操作 
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
		if (hav('P') && hp < 4) {	// 桃 
			dost('P');
			return true;
		}
		if (hav('Z')) {	// 诸葛连弩 
			dost('Z');
			return true;
		}
		if (hav('N')) {	// 南蛮入侵 
			dost('N');
			return true;
		}
		if (hav('W')) {	// 万箭齐发 
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
inline int gcover () { // re 1, 正方胜利; re 2, 反方胜利; re 0 尚未结束. over 
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
