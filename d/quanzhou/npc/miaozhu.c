// miaozhu.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("��ף", ({ "miao zhu", "zhu", "miaozhu" }));
	set("class", "taoist");
	set("gender", "����");
	set("age", 65);
	set("long", "����һλ���ϵ���ף���ڴ��Ѽ�ʮ���ˣ��Դ˵�һ�ж�ʮ����Ϥ��\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

