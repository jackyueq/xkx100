// wangjiaju.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("���Ҿ�", ({ "wang jiaju", "wang", "jiaju" }) );
	set("title", HIY"����"NOR"���������");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 15);
	set("per", 15);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
"��������ǿ��С���ӣ��书�����������������������У���ѵ���Ʀ��å
�����ǵ��ǹ��ˡ�\n" );
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set_skill("blade", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("jinwu-daofa", 20);
	set_skill("yanfly", 20);
	set_skill("parry", 20);
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "jinwu-daofa");
	map_skill("dodge", "yanfly");

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
	carry_object(CLOTH_DIR"jinduan")->wear();
	add_money("gold", 2);
}

