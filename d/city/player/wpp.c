//wpp.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("չ��", ({ "wpp"}));
	set("gender", "����");
	set("class", "taoist");
	set("title", HIW"ʥ��"HIG"���̷����Ž���"NOR"����̩���䵱�����Ŵ�ʦ��");
	set("nickname", HIW"��è"HIR"����"NOR);
	set("age", 51);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 13);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 25);
	set("weiwang", 30);
	create_family("�䵱��" ,2, "����");	
	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}
