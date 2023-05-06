#pragma once
//開始の文言
void begin();
void jobtestbegin();

//心理テスト質問用関数
void psycotestrun();

//心理テスト採点用関数
void scorejudge();

//心理テスト結果の最大値計算用関数
void maxcalculate(int m, int* max);

//職業判定と職業ステータス読み込み用関数
void jobdecide(int max, int tensei);

//職業の特技と奥義表示用関数



//バトル用関数↓

//現在のバトル数、自身と敵ステータス初期化用関数
void battlestart(int stage, int c, int* count);

//ターン選択用関数
int moveselect(int tensei);

//素早さ判定用関数
int agijudge();

//勝ち負け判定
int winjudge();
int loosejudge();

//通常攻撃計算用関数
void firstattack(int* winloose);
void secondattack(int* winloose);

//ステータス表示用関数
void pstatuscheck();
void estatuscheck();

//勝ち負け処理関数
void winprocess(int c, int s, int* count, int* stage);
int looseprocess(int ten);

//敵からの攻撃計算処理関数
void enemyattack();

//特技計算用関数
void tubamegaesi();
void kakyuu();
void tukaimakyouka();
void kaifuku();
void tatetossin();
//覚えた特技を判断後、発動用関数
void tokugiact(int* winloose);

//奥義計算用関数
void zansin();
void syuuennohonoo();
void sinjyuusyoukan();
void sintoumekkyaku();
void seinarutate();
//覚えた奥義を判断後、発動用関数
void ougiact(int* winloose);