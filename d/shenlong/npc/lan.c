// /d/shenlon/npc/lan.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
string ask_me(object who);

void create()
{
	set_name("�����", ({ "lan fenghuang", "lan" }));
	set("shen_type", 0);

	set("str", 20);
	set("con", 20);
	set("dex", 22);
	set("gender", "Ů��");
	set("age", 20);
	set("long","�����������嶾�̽�������ˣ�һ���������񣬴��������κ����Ӽ��Դ�ɫ��\n");
	set("combat_exp", 30000);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set_skill("poison", 80);
	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/damage", 40);

	set("attitude", "friendly");
	set("inquiry", ([
		"�嶾��" : "�ߣ���ƾ��Ҳ���������̣�\n",
		"�����" : "��Ϲ��������\n",
		"ҩ��" : "���嶾���洫�ڶ�Ź�ҩ�����������ض�������\n",
		"����ҩ��" : (: ask_me :),
	]));

	setup();
	carry_object("/d/city/obj/necklace")->wear();
	carry_object(CLOTH_DIR"cloth/feature")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
}

string ask_me(object who)
{
	object me = this_player();
	string myid = me->query("id");

	if( me->query("combat_exp") < 100000 ) {
		command("laugh " + myid);
		command("kick " + myid);
		return "�����������������ɱ����С�䡣\n";
	}
	say("����˶�ʱ��ɫһ�䣬ŭ����������ɴ�ҩ�ƣ��˵���������Ĳ�ҩ�����������㱲���У�\n");
	set("attitude", "aggressive");
	kill_ob(me);
	return "����˴��һ�����е�����������������ȥ������ƴ�ˡ���\n";
}

void unconcious()
{
	object ob;

	say("\nͻȻ�����һ����̾���ͳ�һƿҩ���������⡣\n");
	say("�漴�ҵ�һЦ������������ʲô���£����վ������������á�\n");
	ob = new("/d/shenlong/obj/yaofang");
	ob->move(this_object());
	::unconcious();
}

void die()
{
	object ob;

	say("\nͻȻ��ֻ������һ�Σ������һ�Ųȿյ�����\n");
	if( ob = present("yaofang", this_object()) ) destruct(ob);
	destruct(this_object());
}
