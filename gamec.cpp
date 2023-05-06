
#include<stdio.h>
#include "gamec.h"
#include"prototype.h"

int main(void)
{	begin();
	for (int tensei = 0; tensei < 3; tensei++) {
		jobtestbegin();
		psycotestrun();
		scorejudge();
		int max;
		maxcalculate(max, &max);
		jobdecide(max, tensei);
		//battle____________________________________________________________________________________________________
		int giveup = 0;
		int stage = 1;
		int count = 0;
		for (;;) {
			battlestart(stage, count, &count);//バトル数表示とバトルで計算に使う構造体にステータス読み込み
			int act = moveselect(tensei);//行動選択
			int speed = 0;
			int vicdef = 0;
			speed = agijudge();
			if (act == 1) {
				if (speed == 0) {
					firstattack(&vicdef);
				}
				else if (speed == 1) {
					secondattack(&vicdef);
				}
			}
			if (act == 2) {
				pstatuscheck();
			}
			if (act == 3) {
				estatuscheck();
			}
			if (act == 4) {
				tokugiact(&vicdef);
			}
			if (act == 5) {
				ougiact(&vicdef);
			}
			if (vicdef == 1) {
				winprocess(count, stage, &count, &stage);
			}
			if (vicdef == 2) {
				giveup = looseprocess(tensei);
				break;
			}
			if (stage == 4) {
				printf("GAMECLEAR\n");
				return(0);
			}
		}
		if (giveup == 1) {
			break;
		}
	}
	printf("GAMEOVER\n");
	return(0);
}


void begin() {//冒頭--------------------------------------
	printf("Enterを押して開始\n");
	WAIT;
	printf("？？？「あなたには死んでしまっても前世のステータスを引き継いで転生することができる力を与えます。」\n");
	WAIT;
	printf("？？？「この世界の魔王を倒してください。」\n");
	
}

void jobtestbegin() {
	WAIT;
	printf("神官「職業適正検査を行います。\n"
		"最も自分にあった番号を選んでください。」\n");
	WAIT;
}

void psycotestrun(){
	int seikaku;
	for (int qnum = 0;; qnum++) {
		if (qnum >= LIST_NUMBER) {
			break;
		}
		//↓↓ここに質問内容
		printf("%s", qlist[qnum].q_contents);
		//↑↑ここに質問内容
		
		scanf_s("%d", &seikaku);

		if (seikaku < 1 || 5 < seikaku) {
			printf("正しい数値を入力してください\n");
			WAIT;
			qnum--;
			continue;
		}
		qlist[qnum].answer = seikaku;
	}
}


void scorejudge() {
	//心理テスト質問1外向性についてスコア計算
	if (qlist[0].answer == 1) {
		jobscore[4] += 1;
	}
	if (qlist[0].answer == 2) {
		jobscore[3] += 2;
	}
	if (qlist[0].answer == 3) {
		jobscore[1] += 3;
	}
	if (qlist[0].answer == 4) {
		jobscore[2] += 4;
	}
	if (qlist[0].answer == 5) {
		jobscore[0] += 5;
	}
	//質問2協調性についてのスコア計算
	if (qlist[1].answer == 1) {
		jobscore[1] += 1;
	}
	if (qlist[1].answer == 2) {
		jobscore[0] += 2;
	}
	if (qlist[1].answer == 3) {
		jobscore[4] += 3;
	}
	if (qlist[1].answer == 4) {
		jobscore[3] += 4;
	}
	if (qlist[1].answer == 5) {
		jobscore[2] += 5;
	}
	//質問3誠実性についてのスコア計算
	if (qlist[2].answer == 1) {
		jobscore[2] += 1;
	}
	if (qlist[2].answer == 2) {
		jobscore[1] += 2;
	}
	if (qlist[2].answer == 3) {
		jobscore[3] += 3;
	}
	if (qlist[2].answer == 4) {
		jobscore[0] += 4;
	}
	if (qlist[2].answer == 5) {
		jobscore[4] += 5;
	}
	//質問4神経症傾向についてのスコア計算
	if (qlist[3].answer == 1) {
		jobscore[3] += 1;
	}
	if (qlist[3].answer == 2) {
		jobscore[2] += 2;
	}
	if (qlist[3].answer == 3) {
		jobscore[0] += 3;
	}
	if (qlist[3].answer == 4) {
		jobscore[4] += 4;
	}
	if (qlist[3].answer == 5) {
		jobscore[1] += 5;
	}
	//質問5解放性についてのスコア計算
	if (qlist[4].answer == 1) {
		jobscore[0] += 1;
	}
	if (qlist[4].answer == 2) {
		jobscore[4] += 2;
	}
	if (qlist[4].answer == 3) {
		jobscore[2] += 3;
	}
	if (qlist[4].answer == 4) {
		jobscore[1] += 4;
	}
	if (qlist[4].answer == 5) {
		jobscore[3] += 5;
	}


}


void maxcalculate(int m, int* max) {//最大値計算


	for (int i = 0; i < JOB_Qty; i++) {

		if (m < jobscore[i]) {
			m = jobscore[i];
		}

	}
	*max = m;

}

void jobdecide(int max,int tensei) {
	int job;
	for (int i = 0; i < JOB_Qty; i++) {
		if (max == jobscore[i]) {

			job = i;
		}
	}

	if (job == 0) {
		sprintf_s(pleyer.name, "%s", kens.name);
		pleyer.hp += kens.hp;
		pleyer.atk += kens.atk;
		pleyer.def += kens.def;
		pleyer.stm += kens.stm;
		pleyer.mp += kens.mp;
		pleyer.agi += kens.agi;
		if (tensei == 1) {
			pleyer.tokugi = kens.tokugi;
			sprintf_s(pleyer.tokuginame, "%s", kens.tokuginame);
			sprintf_s(pleyer.tokugiinfo, "%s", kens.tokugiinfo);
		}
		if (tensei == 2) {
			pleyer.ougi = kens.ougi;
			sprintf_s(pleyer.ouginame, "%s", kens.ouginame);
			sprintf_s(pleyer.ougiinfo, "%s", kens.ougiinfo);
		}
	}
	if (job == 1) {
		sprintf_s(pleyer.name, "%s", mahos.name);
		pleyer.hp += mahos.hp;
		pleyer.atk += mahos.atk;
		pleyer.def += mahos.def;
		pleyer.stm += mahos.stm;
		pleyer.mp += mahos.mp;
		pleyer.agi += mahos.agi;
		if (tensei == 1) {
			pleyer.tokugi = mahos.tokugi;
			sprintf_s(pleyer.tokuginame, "%s", mahos.tokuginame);
			sprintf_s(pleyer.tokugiinfo, "%s", mahos.tokugiinfo);
		}
		if (tensei == 2) {
			pleyer.ougi = mahos.ougi;
			sprintf_s(pleyer.ouginame, "%s", mahos.ouginame);
			sprintf_s(pleyer.ougiinfo, "%s", mahos.ougiinfo);
		}
	}
	if (job == 2) {
		sprintf_s(pleyer.name, "%s", syous.name);
		pleyer.hp += syous.hp;
		pleyer.atk += syous.atk;
		pleyer.def += syous.def;
		pleyer.stm += syous.stm;
		pleyer.mp += syous.mp;
		pleyer.agi += syous.agi;
		if (tensei == 1) {
			pleyer.tokugi = syous.tokugi;
			sprintf_s(pleyer.tokuginame, "%s", syous.tokuginame);
			sprintf_s(pleyer.tokugiinfo, "%s", syous.tokugiinfo);
		}
		if (tensei == 2) {
			pleyer.ougi = syous.ougi;
			sprintf_s(pleyer.ouginame, "%s", syous.ouginame);
			sprintf_s(pleyer.ougiinfo, "%s", syous.ougiinfo);
		}
	}
	if (job == 3) {
		sprintf_s(pleyer.name, "%s", sous.name);
		pleyer.hp += sous.hp;
		pleyer.atk += sous.atk;
		pleyer.def += sous.def;
		pleyer.stm += sous.stm;
		pleyer.mp += sous.mp;
		pleyer.agi += sous.agi;
		if (tensei == 1) {
			pleyer.tokugi = sous.tokugi;
			sprintf_s(pleyer.tokuginame, "%s", sous.tokuginame);
			sprintf_s(pleyer.tokugiinfo, "%s", sous.tokugiinfo);
		}
		if (tensei == 2) {
			pleyer.ougi = sous.ougi;
			sprintf_s(pleyer.ouginame, "%s", sous.ouginame);
			sprintf_s(pleyer.ougiinfo, "%s", sous.ougiinfo);
		}
	}
	if (job == 4) {
		sprintf_s(pleyer.name, "%s", tates.name);
		pleyer.hp += tates.hp;
		pleyer.atk += tates.atk;
		pleyer.def += tates.def;
		pleyer.stm += tates.stm;
		pleyer.mp += tates.mp;
		pleyer.agi += tates.agi;
		if (tensei == 1) {
			pleyer.tokugi = tates.tokugi;
			sprintf_s(pleyer.tokuginame, "%s", tates.tokuginame);
			sprintf_s(pleyer.tokugiinfo, "%s", tates.tokugiinfo);
		}
		if (tensei == 2) {
			pleyer.ougi = tates.ougi;
			sprintf_s(pleyer.ouginame, "%s", tates.ouginame);
			sprintf_s(pleyer.ougiinfo, "%s", tates.ougiinfo);
		}
	}

	printf("あなたの適正職は%sです。\n"
		"ステータス\n"
		"体力 = %d\n"
		"攻撃力 = %d\n"
		"守備力 = %d\n"
		"スタミナ = %d\n"
		"魔力量 = %d\n"
		"素早さ = %d\n",
		pleyer.name, pleyer.hp, pleyer.atk, pleyer.def, pleyer.stm, pleyer.mp, pleyer.agi);
	WAIT;
	if (tensei == 1) {
		WAIT;
		printf("特殊攻撃：%sを覚えた！\n"
			"%s：%s\n", pleyer.tokuginame, pleyer.tokuginame, pleyer.tokugiinfo);
	}
	if (tensei == 2) {
		WAIT;
		printf("奥義：%sを覚えた！\n"
			"%s：%s\n", pleyer.ouginame, pleyer.ouginame, pleyer.ougiinfo);
	}

}




void battlestart(int stage, int c, int* count) {
	if (c == 0) {
		WAIT;
		printf("バトル%d\n", stage);
		c++;
		*count = c;
		switch (stage) {
		case 1:

			battle.hp = pleyer.hp;
			battle.atk = pleyer.atk;
			battle.def = pleyer.def;
			battle.stm = pleyer.stm;
			battle.mp = pleyer.mp;
			battle.agi = pleyer.agi;

			enemy.hp = e1s.hp;
			enemy.atk = e1s.atk;
			enemy.def = e1s.def;
			enemy.stm = e1s.stm;
			enemy.mp = e1s.mp;
			enemy.agi = e1s.agi;
			break;

		case 2:

			battle.hp = pleyer.hp;
			battle.atk = pleyer.atk;
			battle.def = pleyer.def;
			battle.stm = pleyer.stm;
			battle.mp = pleyer.mp;
			battle.agi = pleyer.agi;

			enemy.hp = e2s.hp;
			enemy.atk = e2s.atk;
			enemy.def = e2s.def;
			enemy.stm = e2s.stm;
			enemy.mp = e2s.mp;
			enemy.agi = e2s.agi;
			break;

		case 3:
			battle.hp = pleyer.hp;
			battle.atk = pleyer.atk;
			battle.def = pleyer.def;
			battle.stm = pleyer.stm;
			battle.mp = pleyer.mp;
			battle.agi = pleyer.agi;

			enemy.hp = e3s.hp;
			enemy.atk = e3s.atk;
			enemy.def = e3s.def;
			enemy.stm = e3s.stm;
			enemy.mp = e3s.mp;
			enemy.agi = e3s.agi;
			break;

		}


	}


}



int moveselect(int tensei) {
	int action;
	WAIT;
	printf("行動を選択してください。\n");
	WAIT;
	printf("1.通常攻撃\n2.自身のステータス確認\n3.敵のステータス確認\n");
	if (tensei >= 1) {
		printf("4.特殊攻撃\n");
	}
	if (tensei >= 2) {
		printf("5.奥義！\n");
	}
	scanf_s("%d", &action);
	return action;
}

int agijudge() {
	int agiflag = 0;//プレイヤーのほうが早い
	if (enemy.agi > battle.agi) {
		agiflag = 1;//敵のほうが早い
	}
	return agiflag;
}

void firstattack(int* winloose) {

	enemy.hp -= battle.atk - EDEF;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WIN;
	if (enemy.hp > 0) {
		battle.hp -= enemy.atk - PDEF;
		WAIT;
		printf("プレイヤーの残り体力%d\n", battle.hp);
		LOOSE;
	}
}

void secondattack(int* winloose) {

	battle.hp -= enemy.atk - PDEF;
	WAIT;
	printf("プレイヤーの残り体力%d\n", battle.hp);
	LOOSE;
	if (battle.hp > 0) {
		enemy.hp -= battle.atk - EDEF;
		WAIT;
		printf("敵の残り体力%d\n", enemy.hp);
		WIN;
	}
}

int winjudge() {
	int win = 0;
	if (enemy.hp <= 0) {
		win = 1;
	}
	return win;
}

int loosejudge() {
	int loose = 0;
	if (battle.hp <= 0) {
		loose = 2;
	}
	return loose;
}

void pstatuscheck() {
	WAIT;
	printf("プレイヤー：体力%d,攻撃力%d,守備力%d,スタミナ%d,魔力量%d,素早さ%d\n", battle.hp, battle.atk, battle.def, battle.stm, battle.mp, battle.agi);
}

void estatuscheck() {
	WAIT;
	printf("敵：体力%d,攻撃力%d,守備力%d,スタミナ%d,魔力量%d,素早さ%d\n", enemy.hp, enemy.atk, enemy.def, enemy.stm, enemy.mp, enemy.agi);
}

void winprocess(int c,int s,int *count,int *stage) {
	WAIT;
	printf("敵をたおした！\n");
	c = 0;
	s++;
	*count = c;
	*stage=s;
}

int looseprocess(int ten) {
	WAIT;
	printf("死んでしまった\n");
	WAIT;
	printf("転生しますか？\n");
	WAIT;
	printf("1.はい、2.いいえ\n");
	int ans = 0;
	scanf_s("%d", &ans);
	if (ans == 1) {
		if (ten == 2) {
			WAIT;
			printf("もうこれ以上転生することはできません\n");

			return 1;
		}
		else {
			WAIT;
			printf("次は死なないように頑張ってください。\n");
		}
	}
	else {
		return 1;
	}

}

void enemyattack() {
	battle.hp -= enemy.atk - PDEF;
	WAIT;
	printf("プレイヤーの残り体力%d\n", battle.hp);
}

void tubamegaesi() {
	WAIT;
	printf("燕返し！\n");
	enemy.hp -= battle.atk * 2 - EDEF;
	battle.stm -= 20;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WAIT;
	printf("プレイヤーの残りスタミナ%d\n", battle.stm);
}

void kakyuu() {
	WAIT;
	printf("火球！\n");
	enemy.hp -= battle.mp * 2 - EDEF;
	battle.mp -= 20;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WAIT;
	printf("プレイヤーの残り魔力量%d\n", battle.mp);
}

void tukaimakyouka() {
	WAIT;
	printf("使い魔強化！\n");
	battle.hp += battle.mp;
	battle.atk += battle.mp;
	battle.def += battle.mp;
	battle.mp -= 130;
	WAIT;
	printf("プレイヤーの体力%dに上昇\n", battle.hp);
	printf("プレイヤーの攻撃力%dに上昇\n", battle.atk);
	printf("プレイヤーの守備力%dに上昇\n", battle.def);
	printf("プレイヤーの残り魔力量%d\n", battle.mp);
}

void kaifuku() {
	WAIT;
	printf("回復！\n");
	battle.hp += battle.mp;
	battle.mp -= 20;
	WAIT;
	printf("プレイヤーの体力が%dに回復\n", battle.hp);
	printf("プレイヤーの残り魔力量%d\n", battle.mp);
}

void tatetossin() {
	WAIT;
	printf("盾突進！\n");
	enemy.hp -= battle.def * 2 - EDEF;
	battle.stm -= 20;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WAIT;
	printf("プレイヤーの残りスタミナ%d\n", battle.stm);
}

void tokugiact(int* winloose) {
	int speed = agijudge();
	if (speed == 0) {
		if (pleyer.tokugi == 1 && battle.stm > 20) {
			tubamegaesi();
		}
		if (pleyer.tokugi == 2 && battle.mp > 20) {
			kakyuu();
		}
		if (pleyer.tokugi == 3 && battle.mp > 130) {
			tukaimakyouka();
		}
		if (pleyer.tokugi == 4 && battle.mp > 20) {
			kaifuku();
		}
		if (pleyer.tokugi == 5 && battle.stm > 20) {
			tatetossin();
		}

		WIN;
		if (enemy.hp > 0) {
			enemyattack();
			LOOSE;
		}
	}

	else if (speed == 1) {
		enemyattack();
		LOOSE;
		if (battle.hp > 0) {
			if (pleyer.tokugi == 1 && battle.stm > 20) {
				tubamegaesi();
			}
			if (pleyer.tokugi == 2 && battle.mp > 20) {
				kakyuu();
			}
			if (pleyer.tokugi == 3 && battle.mp > 130) {
				tukaimakyouka();
			}
			if (pleyer.tokugi == 4 && battle.mp > 20) {
				kaifuku();
			}
			if (pleyer.tokugi == 5 && battle.stm > 20) {
				tatetossin();
			}
			WIN;
		}
	}
	else {
		printf("特技発動失敗\n");
		enemyattack();
		LOOSE;
	}
}

void zansin() {
	WAIT;
	printf("残心！\n");
	enemy.hp -= battle.atk - EDEF;
	battle.hp += battle.stm;
	battle.stm = 0;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WAIT;
	printf("プレイヤーの残り体力%d\n", battle.hp);
	printf("プレイヤーの残りスタミナ%d\n", battle.stm);
}

void syuuennohonoo() {
	WAIT;
	printf("終焉の炎！\n");
	enemy.hp -= battle.mp * 3 - EDEF;
	battle.mp = 0;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WAIT;
	printf("プレイヤーの残り魔力量%d\n", battle.mp);
}

void sinjyuusyoukan() {
	WAIT;
	printf("神獣召喚！\n");
	battle.hp += battle.stm * 3;
	battle.atk += battle.stm * 3;
	battle.def += battle.stm * 3;
	battle.mp = 0;
	WAIT;
	printf("プレイヤーの体力が%dに上昇\n", battle.hp);
	printf("プレイヤーの攻撃力が%dに上昇\n", battle.atk);
	printf("プレイヤーの守備力が%dに上昇\n", battle.def);
	printf("プレイヤーの残り魔力量%d\n", battle.mp);
}

void sintoumekkyaku() {
	WAIT;
	printf("心頭滅却！\n");
	WAIT;
	printf("相手の攻撃を無効にし、プレイヤーの体力を回復した\n");
	battle.hp += battle.mp;
	battle.mp = 0;
	WAIT;
	printf("プレイヤーの残り体力%d\n", battle.hp);
	printf("プレイヤーの残り魔力量%d\n", battle.mp);
}

void seinarutate() {
	WAIT;
	printf("聖なる盾！\n");
	battle.def *= 2;
	WAIT;
	printf("プレイヤーの守備力が%dに上昇\n", battle.def);
	WAIT;
	printf("相手の攻撃を跳ね返した\n");
	enemy.hp -= enemy.atk;
	battle.stm = 0;
	WAIT;
	printf("敵の残り体力%d\n", enemy.hp);
	WAIT;
	printf("プレイヤーの残りスタミナ%d\n", battle.stm);
}

void ougiact(int* winloose) {
	int speed = agijudge();

	if (pleyer.ougi == 4 && battle.mp > 0) {
		sintoumekkyaku();
	}
	else if (pleyer.ougi == 5 && battle.stm > 0) {
		seinarutate();
		WIN;
	}
	else if (speed == 0) {
		if (pleyer.ougi == 1 && battle.mp > 0) {
			zansin();
		}
		if (pleyer.ougi == 2 && battle.mp > 0) {
			syuuennohonoo();
		}
		if (pleyer.ougi == 3 && battle.mp > 0) {
			sinjyuusyoukan();
		}
		WIN;
		if (enemy.hp > 0) {
			enemyattack();
			LOOSE;
		}

	}
	else if (speed == 1) {
		enemyattack();
		LOOSE;
		if (battle.hp > 0) {
			if (pleyer.ougi == 1 && battle.mp > 0) {
				zansin();
			}
			if (pleyer.ougi == 2 && battle.mp > 0) {
				syuuennohonoo();
			}
			if (pleyer.ougi == 3 && battle.mp > 0) {
				sinjyuusyoukan();
			}
		}
	}
	else {
		printf("奥義発動失敗\n");
		enemyattack();
		LOOSE;
	}

}



// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
