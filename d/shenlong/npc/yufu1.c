// yufu1.c ���
// Last Modified by winder on Jul. 12 2002

inherit NPC;
string ask_shenlong();

void create()
{
	set_name("���", ({ "yu fu","fu" }) );
	set("gender", "����");
	set("age", 35);
	set("long", "�����Դ���Ϊ�������\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("inquiry",([
		"������" : (: ask_shenlong :),
		"������" : (: ask_shenlong :),
	]));

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("coin", 50);
}

string ask_shenlong()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "������")
	{
		this_player()->set_temp("marks/shenlong", 1);
		write("������˵�����������Ǹ���ȥ��������ȥ�ͺ�С��һ����\n");
		return "���ϴ����߰ɡ�\n";
	}
	else
	{
		command("nod");
		return "���Ǳ��̵��ӣ���һ�������ˡ�";
	}
}
