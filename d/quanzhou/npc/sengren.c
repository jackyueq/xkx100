// sengren.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("ɮ��", ({ "seng ren", "seng", "ren" }));
	set("class", "bonze");
	set("gender", "����");
	set("age", 65);
	set("long","����һλ���ϵ�ɮ�ˣ��ڴ˿��زؾ����Ѽ�ʮ���ˣ��Դ˵�һ�ж�ʮ����Ϥ��\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/seng-cloth")->wear();
}

