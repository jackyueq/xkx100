// yuwife.c

inherit NPC;

void create()
{
	set_name("��С��",({ "yu wife"}) );
	set("gender", "Ů��" );
	set("age", 26);
	set("long", 
"���Ǹ���ʮ��������Ĵ����ӣ���֪�������ϵ��ĵڼ���С檡�\n");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/female-cloth")->wear();
}

