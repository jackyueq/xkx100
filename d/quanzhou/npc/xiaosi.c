// xiaosi.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("ҩ��С��", ({ "yaopu xiaosi", "xiaosi"}));
	set("long", "���������ݣ����в�ɫ����֪�������ƹ�Ŀ̱���\n");
	set("shen_type", 1);

	set("str", 20);
	set("age", 15);
	set("attitude", "friendly");
	set("combat_exp", 400);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

