// wugu.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���", ({ "wu gu", "wugu" }));
	set("long",
"���Ǻ�̫�����Ӱ���С檣�ԭ�����õ�Ҳ��̬�򷽡�
����һ�����׵�������˽�һ�㣬˫�����������
�������������������������ǳ��ŷ��䡣\n");
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 12);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);

	set("max_qi", 100);
	set("max_jing", 100);
	set("combat_exp", 500);
	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
}

