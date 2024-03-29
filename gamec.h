#pragma once

#define LIST_NUMBER ((sizeof qlist)/(sizeof(psycoquestion)))
#define JOB_Qty 32//職業の数、jobscore配列に使用
#define PDEF (pleyer.def/5)//バトルの計算で使う守備力
#define EDEF (enemy.def/5)//バトルの計算で使う敵の守備力
#define WAIT getchar()//Enter要求
#define WIN *winloose=winjudge()//勝ち判定をメイン関数に渡す
#define LOOSE *winloose=loosejudge()//負け判定をメイン関数に渡す


typedef struct {//ステータス関連構造体
	char name[32];
	int hp;
	int atk;
	int def;
	int stm;
	int mp;
	int agi;
	int tokugi;
	int ougi;
	char tokuginame[64];
	char tokugiinfo[1024];
	char ouginame[64];
	char ougiinfo[1024];

}status;

status kens = { "剣士",100,100,100,100,0,100,1,1,"燕返し","敵に二回攻撃する(スタミナを20使用)" ,"残心","通常攻撃後自身の体力を残りスタミナ分回復する(残りスタミナすべて使用)" };

status mahos = { "魔法使い", 80,150,50,0,120,50,2,2,"火球","自身の魔力量の2倍の攻撃(魔力量を20使用)","終焉の炎","自身の魔力量の3倍の攻撃(残り魔力量をすべて使用)" };

status syous = { "召喚士",50,50,50,50,130,150,3,3,"使い魔強化","自身の攻撃力、守備力、体力を魔力量分強化(魔力量を130使用)","神獣召喚","自身の攻撃力、守備力、体力を魔力量の3倍分強化(残り魔力量をすべて使用)" };

status sous = { "僧侶",100,50,50,0,150,70,4,4,"回復","自身の体力を魔力量分回復(魔力量を20使用)","心頭滅却","相手の攻撃を無効にし、自身の体力を魔力量分回復(残り魔力量をすべて使用)" };

status tates = { "盾使い",150,120,180,50,0,50,5,5,"盾突進","自身の守備力の2倍の攻撃(スタミナを20使用)","聖なる盾","自身の守備力を2倍にし、相手の攻撃を跳ね返す(残りスタミナすべて使用)" };

status e1s = { "ゴブリン",50,100,50,100,100,150 };

status e2s = { "ミノタウロス",200,250,150,200,200,250 };

status e3s = { "魔王",400,400,400,400,400,400 };

status pleyer = { "プレイヤー",0,0,0,0,0,0 };//転生後もステータスを引き継いで覚えておく用

status battle = { "プレイヤー",0,0,0,0,0,0 };//バトルの時の計算に使用

status enemy = { "敵",0,0,0,0,0,0 };//バトルの時の計算に使用


typedef struct {//質問関連構造体配列
	
	char q_contents[1024];//質問内容
	int answer;//質問回答

}psycoquestion;

psycoquestion qlist[] = {
	{
	"あなたが休日にするとしたら次のうちどれ？\n"
			"1.友人と遊びに行く\n"
			"2.ショッピング\n"
			"3.映画鑑賞\n"
			"4.家でゲーム\n"
			"5.読書\n"
			"1から5を入力してください\n",},

	{"あなたは多忙な時に友人に頼みごとをされました。\n"
			"1.必要以上に手を貸してしまう\n"
			"2.断れない\n"
			"3.自分のできる範囲で手伝う\n"
			"4.あまり気乗りしないが友人の頼みなので少し手伝う\n"
			"5.「忙しいから」と断る\n"
			"1から5を入力してください\n"},

	{"夏休みの課題が出ました。どうしますか？\n"
			"1.すぐにやり始め、できるだけ速く終わらせる\n"
			"2.計画的に少しずつやる\n"
			"3.すぐに始めるが残りはギリギリに終わらせる\n"
			"4.ぎりぎりになって終わらせる\n"
			"5.めんどくさいのでやらない\n"
			"1から5を入力してください\n"},

	{"あなたは理不尽に怒られました。\n"
			"1.八つ当たりされるとすごくストレスを感じる\n"
			"2.頭にくるがぐっとこらえる\n"
			"3.とりあえず適当に受け流す\n"
			"4.特に何も感じない\n"
			"5.切り替えようとする\n"
			"1から5を入力してください\n"},

	{"遅刻しそうです！どうしますか？\n"
			"1.使ったことのない細い道だが間に合うかもしれない道を見つけたので試してみる\n"
			"2.お金はかかるが遅刻はできないのでタクシーを拾う\n"
			"3.遅れることを伝える\n"
			"4.いつもの道を走る\n"
			"5.そもそも速めに出るから遅刻なんてしない\n"
			"1から5を入力してください\n"}
};

int jobscore[JOB_Qty] = {};