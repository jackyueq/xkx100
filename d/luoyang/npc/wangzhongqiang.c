// wangzhongqiang.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����ǿ", ({ "wang zhongqiang", "wang", "zhongqiang" }) );
	set("title", HIY"����"NOR"���Ĵ�����");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 45);
	set("per", 15);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
"���ǽ��޵���Ԫ�ԵĴ��ӡ�һ�ڵ���ʹ�ó���֮������������ԥ����
������ͷ����������������ߣ����Ƿ��֣�̫��Ѩ�߸߹������Ͻ��
ͻ������Ȼ���⹦���趼���˵á�\n" );
	set("combat_exp", 300000);
	set("attitude", "friendly");
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("jinwu-daofa", 100);
	set_skill("yanfly", 100);
	set_skill("parry", 100);
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "jinwu-daofa");
	map_skill("dodge", "yanfly");

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(CLOTH_DIR"jinduan")->wear();
	add_money("gold", 2);
}

