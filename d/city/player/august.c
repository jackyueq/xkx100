// august.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("Ҷ��ѩ", ({ "august"}));
	set("gender", "����");
	set("class", "fighter");
	set("title", HIG"��ʿ����"NOR"�����Ž���"HIR"����ʹ��"NOR);
	set("nickname", HIM"Ʀ�Ӷ�����֮Ʀ��ˣ��Ʀ"NOR);
	set("age", 17);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
