// Last Modified by winder on Nov. 17 2000

inherit NPC;

int ask_location();
string ask_name();
string ask_rumors();
string ask_thd();

void create()
{
	set_name("����", ({ "gong", "shaogong" }) );
	set("gender", "����" );
	set("age", 50);
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϴ���");
	set("inquiry", ([
		"name": (: ask_name :),
		"rumors": (: ask_rumors :),
		"here": "���������������˵�ĺ�������Ķ�������ס��ˮ�ס�",
		"λ��": (: ask_location :),
		"taohuadao": (: ask_thd :),
		"�һ���": (: ask_thd :),
		"weizhi": (: ask_location :),
		"��": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"����": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"����": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"��": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
		"����": "���ø��������ı߿�ѽ(turn n|w|s|e)��",
	]) );
	setup();
}

int ask_location()
{
	object ob=this_player();

	say("�������˿���ͼ��˵�����������ڵ�λ����(" + ob->query_temp("thd_locx") + "," + ob->query_temp("thd_locy") + ")��\n");
	return 1;
}

string ask_name()
{
	object ob=this_player();

	if (ob->query_temp("thd_target") == "thd")
		return "���Ҳ��ң��Ϻ������°������Ѿ������ﻮ����ʮ���괬�ˡ�\n";
	if (ob->query_temp("thd_target") == "bay")
		return "�Ϻ�ֻ�����ǻƵ��������¶��ѣ�����ʲô���֡�\n";
}

string ask_rumors()
{
	object ob=this_player();

	if (ob->query_temp("thd_target") == "thd")
		return "��˵�һ�����ס��һ����ħ������Ҫ����Ϊ����ÿ���������ӵ�����ѣ�\n�Ϻ���˵ʲôҲ����ȥ�ġ�\n";
	if (ob->query_temp("thd_target") == "bay")
		return "�Ϻ������һ�����û��˵��ʲô���ԡ�\n";
}

string ask_thd()
{
	object ob=this_player();

	if (ob->query_temp("thd_target") == "thd")
		return "��˵�һ�����ס��һ����ħ������Ҫ����Ϊ����ÿ��20�����ӵ�����ѣ�\n�Ϻ���˵ʲôҲ����ȥ�ġ�\n";
	if (ob->query_temp("thd_target") == "bay")
		return "�Ϻ������һ������Ƶ��������Ǻܺá�\n";
}
