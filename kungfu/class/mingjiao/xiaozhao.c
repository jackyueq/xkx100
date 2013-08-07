// xiaozhao.c
// Last Modified by winder on Oct. 30 2001

#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;

int ask_tuijiao();
int ask_wuji();
int ask_jian();
int ask_gold();
int ask_ge();
int ask_qiankun();
int ask_jiuyang();
int do_break();

void create()
{
	set_name("小昭", ({ "xiao zhao", "xiao", "zhao"}));
	set("nickname", HIC "天涯思君不可忘" NOR);
	set("long",
		"她双目湛湛有神，修眉端鼻，颊边微现梨涡，真是秀美无伦，只是年纪幼\n"
		"小，身材尚未长成，虽然容貌绝丽，却掩不住容颜中的稚气。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_qi", 500);
	set("max_jing", 200);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("cuff", 80);
	set_skill("hand", 80);
	set_skill("sword", 80);
	set_skill("liehuo-jian", 70);
	set_skill("changquan", 70);
	set_skill("sanshou", 70);
	set_skill("qingfu-shenfa",50);
	map_skill("dodge", "qingfu-shenfa");
	map_skill("parry", "liehuo-jian");
	map_skill("sword", "liehuo-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
/*
	set("party/party_name", HIG "明教" NOR);
	set("party/rank", HIW "波斯圣教主" NOR);
	set("party/level", 1);
*/
	set("inquiry", ([
		"退教" :    (: ask_tuijiao :),
		"张无忌" :  (: ask_wuji :),
		"倚天剑" :  (: ask_jian :),
		"黄金" :    (: ask_gold :),
		"歌" :      (: ask_ge :),
		"九阳真经": (: ask_jiuyang :),
		"乾坤大挪移": (: ask_qiankun :),
		"乾坤大挪移心法": (: ask_qiankun :),
		"tuijiao" : (: ask_tuijiao :),
		"wuji" :    (: ask_wuji :),
		"jian" :    (: ask_jian :),
		"gold" :    (: ask_gold :),
		"ge" :      (: ask_ge :),
	]));

	set("chat_chance", 3);
	set("chat_msg", ({
	    "小昭低声吟道：天涯思君不可忘 武当山顶松柏长\n",
	    "小昭低声吟道：宝刀百炼生玄光 字作丧乱意彷徨\n",
	    "小昭低声吟道：皓臂似玉梅花妆 浮槎北溟海茫茫\n",
	    "小昭低声吟道：谁送冰舸来仙乡 穷发十载泛归航\n",
	    "小昭低声吟道：七侠聚会乐未央 百岁寿宴摧肝肠\n",
	    "小昭低声吟道：有女长舌如利枪 针其膏兮药其肓\n",
	    "小昭低声吟道：不悔仲子逾我墙 当道时见中山狼\n",
	    "小昭低声吟道：奇谋妙计梦一场 剥极而复参九阳\n",
	    "小昭低声吟道：青翼出没一笑扬 倚天长剑飞寒芒\n",
	    "小昭低声吟道：祸起萧墙破金汤 与子共穴相扶将\n",
	    "小昭低声吟道：排难解纷当六强 群雄归心约三章\n",
	    "小昭低声吟道：灵芙醉客绿柳庄 太极初传柔克刚\n",
	    "小昭低声吟道：举火燎天何煌煌 俊貌玉面甘损伤\n",
	    "小昭低声吟道：百尺高塔任回翔 恩断义绝紫衫王\n",
	    "小昭低声吟道：四女同舟何所望 东西永隔如参商\n",
	    "小昭低声吟道：刀剑齐失人云亡 冤蒙不白愁欲狂\n",
	    "小昭低声吟道：箫长琴短衣流黄 新妇素手裂红裳\n",
	    "小昭低声吟道：屠狮有会孰为殃 夭矫三松郁青苍\n",
	    "小昭低声吟道：天下英雄莫能当 君子可欺之以方\n",
	    "小昭低声吟道：秘笈兵书此中藏 不识张郎是张郎\n",
	}) );

	set("party/party_name",HIG"明教"NOR);
	set("party/rank",HIW"波斯圣教主"NOR);
	create_family("明教", 35, "弟子");
	setup();
	carry_object(__DIR__"obj/yitian-jian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold",1);
}
int ask_tuijiao()
{
	object ob;
	ob=this_player();

	if(ob->query("party/party_name") != HIG "明教" NOR )
	{
		message_vision("小昭莞尔一笑，对$N说道：你还没加入我明教呢，就想退教？\n",ob);
		return 1;
	}
	if(ob->query("family/family_name") == "明教" )
	{
		message_vision("小昭抬起俏脸对$N说道：你已经是我圣教弟子，如何能退教？\n", ob);
		return 1;
	}

	command("look "+ob->query("id"));
	command("sigh ");
	command("nod ");
	ob->delete("party");
	ob->delete("rank");
	ob->delete("level");
	return 1;
}

int ask_wuji()
{
	command("sigh "+this_player()->query("id"));
	say("小昭幽幽地说：天涯思君不可忘，东西永隔如参商。\n");
	return 1;
}

int ask_jian()
{
	command(":P "+this_player()->query("id"));
	command("say 不行啊，这是张公子托我保管的，不能随便给人。");
	return 1;
}

int ask_gold()
{
	command(":P "+this_player()->query("id"));
	command("say 不行啊，这不能随便给人。");
	return 1;
}

int ask_ge()
{
	command("nod "+this_player()->query("id"));
	say("小昭曼声唱道：\n\n"+
	"世情推物理  人生贵适意\n\n"+
	"想人间造物搬兴废  吉藏凶 凶藏吉  富贵那能长富贵\n\n"+
	"日盈昃  月满亏蚀  地下东南  天高西北  天地尚无完体\n\n"+
	"展放愁眉  休争闲气  今日容颜  老于昨日  古往今来  尽须如此\n\n"+
	"管他贤的愚的  贫的和富的  到头这一身  难逃那一日\n\n"+
	"受用了一朝  一朝便宜\n\n"+
	"百岁光阴  七十者稀  急急流年  滔滔逝水\n\n");
	return 1;
}

int ask_jiuyang()
{
}
int ask_qiankun()
{
	object me = this_player();
	if (me->query_temp("mark/qiankun") &&
		me->query("party/party_name") == HIG "明教" NOR)
	{
		message_vision( CYN"小昭莞尔一笑，对$N说道：乾坤大挪移心法在本教密道里，我们去取吧。\n"NOR,me);
		set_leader(me);
		me->delete_temp("mark/qiankun", 1);
	}
	else
	{
		command("say 自上代教主阳顶天离奇失踪，乾坤大挪移心法已经失落很久了。\n");
		me->set_temp("mark/qiankun", 1);
		set_leader(0);
	}
	return 1;
}
