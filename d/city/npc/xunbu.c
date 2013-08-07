// xunbu.c
#include <ansi.h>
#define THIEF 3
#define ROBBER 5
#define GO 0
#define BACK 1

inherit NPC;

int direction=GO;

mapping BigWay=([
	"/d/city/yamen":({"south",0}),
	"/d/city/tongsijie":({"east","north"}),
	"/d/city/caohexiaojie":({"east","west"}),
	"/d/city/tongsiqiao":({"east","west"}),
	"/d/city/shilijie4":({"north","south"}),
	"/d/city/shilijie4":({"east","west"}),
	"/d/city/shilijie3":({"north","south"}),
	"/d/city/shilijie2":({"north","south"}),
	"/d/city/shilijie1":({"north","south"}),
	"/d/city/shilijie5":({"north","south"}),
	"/d/city/shilijie6":({"east","south"}),
	"/d/city/shilijie7":({"east","south"}),
	"/d/city/ganquanjie": ({0,"west"}),
	"/d/city/nanmendajie": ({0,"north"}),
	"/d/city/beimendajie": ({0,"south"}),
]);

void create()
{
	string *surname=({"Ľ��","����","����","�Ϲ�","�Ϲ�","ŷ��","˾ͽ",});
	set_name(surname[random(sizeof(surname))]+"Ѳ��",({"xun bu","police"}));
	set("gender", "����" );
	set("age", 25);
	set("str", 45);
	set("cor", 50);
	set("cps", 35);
	set("int", 20);
	set("per", 20);
	set("kar", 15);
	set("long",@LONG
Ѳ���������ֽý���ǿ����ɽ���޲��ŷ�ɥ����
LONG );
	set("status","patrol");
	set("CatchWho",0);
	set("combat_exp", 500000);
	set("attitude", "heroism");
	set("chat_chance", 3);
	set("chat_msg", ({
		"Ѳ��˵���������ʲô����������ȥ�������󣡣�\n",
		"Ѳ��˵�����󵨣���Ȼ�ҵ��־ܲ������췴��\n",
		"Ѳ��˵����������ˣ����ǹԹԵĸ����߰ɡ�\n"
	}) );
	set ("inquiry",([
		"bribery":
			"˵���ﻰ������̫ү��ƶ���������������µ�������û����������\n�������Ǯ�ɣ�\n",
		"salary": "������үٺ��΢�������ǵ�������Ȼ������......\n",
		"money": "˵ʵ�ڵģ���Ҳ��ҪǮ����Ҫ������ү֪���������ܻ�¸(bribery)��\n����Ҳ�ðǲ�Ƥ\n",
	]));
	 set("pursuer",1);
	 set_skill("blade", 100);
	 set_skill("parry", 90);
	 set_skill("dodge", 70);
	 setup();
	 direction=GO;
	 carry_object("/clone/weapon/gangdao")->wield();
	 carry_object("/clone/misc/cloth")->wear();
	 add_money("silver",30);
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
	message_vision( "Ѳ������$N���һ�������󵨵��񣬾���ɱ�˷Ż�����������εأ������� \n", ob );
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

