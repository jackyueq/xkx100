// karice.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("����", ({ "karice"}));
	set("gender", "����");
	set("class", "beggar");
	set("title", "�����ɵ���������");
	set("nickname", HIR"һ��һ��"NOR);
	set("age", 26);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("������" , 3, "����");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

