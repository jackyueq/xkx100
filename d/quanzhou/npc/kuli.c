// kuli.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("����", ({ "ku li", "kuli" }));
	set("shen_type", 1);
	set("gender", "����");
	set("age", 25);
	set("long", "���Ǹ���ʵ�ͽ��Ŀ��������ð�����Բ��һ���⡣\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
}
