// jiefei.c �ƺӰ�ٷ�
#include <ansi.h>
#include "jinit.h"
inherit NPC;
string *xing=({"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��","��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��","³","Τ","��","��","��","��","��","��","��","��","Ԭ","��","ۺ","��","ʷ","��","��","��","�","Ѧ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","��","ƽ","��","��","��","��","��","Ҧ","��"}); 
	string *id=({"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","zhu","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang","kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu","bai","shui","dou","zhang","yun","su","pan","ge","xi","fan","pen","lang","lu","wei","chang","ma","miao","feng","hua","fang","yu","ren","yuan","liu","feng","bao","shi","tang","fei","lian","cen","xue","lei","he","ni","tang","teng","yin","luo","bi","hao","wu","an","chang","le","yu","shi","fu","pi","bian","qi","kang","wu","yu","yuan","piao","gu","meng","ping","huang","he","mu","xiao","yin","yao","shao"}); 
	string *ming1=({"��","��","��","��","��","��","��","��","��","��","ӯ","�","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","¶","˪","��","��","��","ˮ","��","��","��","��","��","��","��","ҹ","��","��","��","��","��","��","��","��","��","ʦ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ƽ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ľ"}); 
	string *ming2=({"��","��","��","��","��","��","��","��","��","��","ӯ","�","��","��","��","��","��","��","��","��","¶","˪","��","��","��","ˮ","��","��","��","��","��","��","��","ҹ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ƽ","��","��","��","��","��","��","��","��","��","��","��","ʫ","��","��","��","��","ʥ","��","��","��","��","��","��","��","��","��","��","��","��"}); 

void create()
{
	int i;
	i = random(sizeof(xing));
	set_name(xing[i]+ming1[random(sizeof(ming1))]+ming2[random(sizeof(ming2))], ({id[i]}));
	set("title","�ƺӰ�ٷ�");
	set("long",
		"����һλ�뺷�ı������ӣ�һ��ƺӰ�Ļ��¡�\n");
	set("gender", "����" );
	set("age", 20 + random(25) );
	set("attitude", "heroism");
	set("str", 20 + random(11));	// ����
	set("per", 20 + random(11));	// ��ò
	set("int", 20 + random(11));	// ����
	set("con", 20 + random(11));	// ����
	set("dex", 20 + random(11)); 	// ��
	set("kar", 20 + random(11));	// ��Ե
	set("shen", -10);
	set("demogorgon",1);
	set("no_suck",1);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge", 40);
	setup();
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.sanqing" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "parry.ju" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );
	carry_object(__DIR__"obj/ycloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 2);
}

