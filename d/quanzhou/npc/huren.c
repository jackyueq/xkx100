// huren.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("����", ({ "hu ren", "huren" }));
	set("shen_type", 1);
	set("gender", "����");
	set("age", 35);
	set("long", "һ���𷢱��۵ĺ��ˣ���ֺ�������ߺ���š�\n");
	set("combat_exp", 3800);
	set("attitude", "friendly");
	setup();
}
