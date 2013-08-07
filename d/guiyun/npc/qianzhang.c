// Npc: /d/guiyun/npc/qianzhang.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;
int ask_me();

void create()
{
	set_name("����", ({ "old man", "old" }));
	set("gender", "����");
	set("age", 70);
	set("long","����߰˳����࣬�׷����룬�����⣬̫��Ѩ�߸�¡�𡣿�������������\n");
	set("attitude", "friendly");
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set("combat_exp", 90000);
	set("shen_type", -1);
	set("shen", -300);
	set("str", 20);
	set("dex", 24);
	set("con", 19);
	set("int", 21);
	set("inquiry",([
		"name" : "�Ҿ��ǽ������˳ơ�����ˮ��Ʈ������ǧ��",
		"��ǧ��" : (: ask_me :),       
	]));
	setup();
	set("chat_chance",10);
	set("chat_msg",({
		"���߽�һ�ڴ����׶���ͷ�ϣ��߳�����������΢�ڣ����к�Ȼ�ó�Щˮ����\n",
		"�����㲻ͣ���شӺ��������˹�ȥ���������ȣ���ˮֻ����С�ȡ�\n",
		"������ϥ������˫Ŀ΢�գ����������һ���Ƶ������������ϡ�\n",
	}));
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	say( "������ɫ��䣺��ô˵�㶼֪���ˣ�������ǧ�����߱��ˡ��Ҹ�������ô���ӡ�\n");
	write("����˵����ˮ���а�׮��jump river���ɹ��ӡ�\n");
	say("���߼���ææ���뿪�ˡ�\n");
	this_player()->set_temp("guiyun_river", 1);
	destruct(this_object());
	return 1;
}

void unconcious()
{
	say("���߽е�������ǧ��������ˣ��书�Ѵ���ǰ������������ȴ��û���ġ�\n");
	say("���߽е����������ҷŹ��㣬���������ʣ�\n");
	say("���ߵ�ͷ������ȥ��\n");
	destruct(this_object());
}
