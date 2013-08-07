// /d/yixing/npc/cl_bangzhong3.c  ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

string ask_food();

void create()
{
	set_name("����", ({ "changle bangzhong", "bangzhong" }));
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "������");
	set("long","����һ������Ϊ�������ĳ��ְ��ڡ�\n��������ת���ƺ�������ʲô�����⡣\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_neili", 100);
	set("neili", 100);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"���ְ�" : "������ǳ��ְ��ܶ����ڵء�",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"������" : "�Դ�չ������ԩ�󣬱����þ�ÿ�����¡�",
		"չ����" : "��������ʯ�ҡ�",
		"չ��" : "��������ʯ�ҡ�",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
		"ʳ��" : (: ask_food :),
		"��" : (: ask_food :),
		"food" : (: ask_food :),
		"��" : "������������Ǻȵ�ˮ���ʰɡ�",
		"drink" : "������������Ǻȵ�ˮ���ʰɡ�",
		"ˮ" : "�������һ����װˮ����װ��",
		"water" : "�������һ����װˮ����װ��",
	]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}

string ask_food()
{
	object ob, ling, me = this_player();
	string myfam;

	if( is_fighting() )
		return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

	myfam = (string)query("party/party_name");
	if( (string)me->query("party/party_name") != myfam )
		return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";

	if( uptime() < (int)query("foodtime") + 30 )
		return "����û�оƲˡ�";

	if( stringp(me->query("party/rank") == "����") )
	{
		command("bow " + me->query("id"));
		set("foodtime", uptime());
		ob = new("/d/hangzhou/obj/fish");
		ob->move(me);
		message_vision("$N��һ" + ob->query("unit") + ob->name() + "���$n��\n", this_object(), me);
		return "���������˼������ˡ�";
	}
	if( !(ling = present("bang ling", me)) )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";
	if( (string)ling->query("owner") != me->query("id") )
		return RANK_D->query_rude(me) + "�����Լ��İ���ܲ�ס��";
	command("nod");
	set("foodtime", uptime());
	switch((int)ling->query("score")/50)
	{
		case 0: ob = new("/d/city/obj/peanut"); break;
		case 1: ob = new("/d/city/obj/tofu"); break;
		case 2: ob = new("/d/city/obj/baozi"); break;
		case 3: ob = new("/d/city/obj/jitui"); break;
		case 4: ob = new("/d/hangzhou/obj/shrimp"); break;
		case 5: ob = new("/d/city/obj/gourou"); break;
		case 7: ob = new("/d/city/obj/ham"); break;
		default: ob = new("/d/city/obj/kaoya"); break;
	}

	ob->move(me);
	message_vision("$N��һ" + ob->query("unit") + ob->name() + "���$n��\n", this_object(), me);
	return RANK_D->query_respect(me) + "�����ˡ�";
}
