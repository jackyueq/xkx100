//welcome.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("��־��", ({ "welcome"}));
	set("gender", "����");
	set("class", "quanzhen");
	set("title", "ȫ��̵ڶ�������");
	set("nickname", HIR"������ЦЦ��"NOR);
	set("age", 50);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 30);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	create_family("ȫ���" ,2, "����");	
	setup();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}
