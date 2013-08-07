// zu.c

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
string ask_me();

void create()
{
	set_name("��ǧ��", ({ "zu qianqiu", "zu", "qianqiu" }) );
	set("nickname", "�ƺ�����");
	set("gender", "����" );
	set("age", 52);
	set("long", "һ���������ڵ�����������������Ƥ��һ������ǣ����������
�������ӣ���������������һƬ�͹⣬��������һ�������ȡ�\n");
	set("combat_exp", 400000);
	set("attitude", "friendly");

	set("max_jing",500);
	set("max_qi",500);
	set("per", 17);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("no_get", 1);

	set_skill("literate", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set("inquiry", ([
		"��������" : (: ask_me :),
		"8wan"     : (: ask_me :),
	]));

	set("book_count", 1);
	setup();
	add_money("gold", 1);
	carry_object("d/city/obj/cloth")->wear();
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/XUMING", 1, 1);
	wannum = atoi(wan_num);
	if (uptime() < 1000)
		return "��λ"+RANK_D->query_respect(this_player()) + 
		"���������軹����ͷ���������ô���㣿";
	if (wannum == 0)
		return "��λ"+RANK_D->query_respect(this_player()) + 
		"���������軹����ͷ�������أ�����ô���㣿";
	if (random(10) < 3)
		return "��λ"+RANK_D->query_respect(this_player()) + 
		"�����������������ӳԵ��ˣ�����ʲô���㣿";
	if (random(10) < 6)
		return "��λ"+RANK_D->query_respect(this_player()) + 
		"���������������Ҫ���ϲ�����ֶŮ��Ѫ�β������ܳ�ô��";
	if (random(10) < 9)
		return "��λ"+RANK_D->query_respect(this_player()) + 
		"���������������裬�������Һ���ͷ�ӵĻƺ������������";
	ob = new("/clone/medicine/nostrum/xuming8wan");
	ob->move(this_player());
	write_file("/data/XUMING", "0", 1);
	command("rumor "+this_player()->query("name")+"�õ���������������\n");
	return "�ðɣ�����ʥ�÷��Ͼ͸��㳢�����������ζ���ɡ�";
}

