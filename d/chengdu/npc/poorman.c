// Room: /d/chengdu/npc/poorman.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;

void create()
{
	set_name("׳��", ({ "man"}) );
	set("gender", "����" );
	set("age", 33);
	set("long", "һ�����ǿ׳�ĺ��ӡ�\n");
	set("attitude", "friendly");
	set("combat_exp", 750);
//	set("shen", 50);
	set("shen_type", 1);
	set("str", 20);
	set("dex", 18);
	set("con", 17);
	set("int", 13);
	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"׳�����ִ��˸�������\n",
		"׳������׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ�ˡ� \n",
		(: random_move :)
	}) );
	carry_object(CLOTH_DIR"cloth")->wear();
}

