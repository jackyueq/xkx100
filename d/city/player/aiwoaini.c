//aiwoaini.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("���Ұ���", ({ "aiwoaini"}));
	set("gender", "Ů��");
	set("class", "swordman");
	set("title", HIR"�ڸ��ѧʿ"HIG"���̵����Ž���"NOR"��Ĺ�ɵڶ�������");	
	set("age", 48);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 23);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 20);
	create_family("��Ĺ��" ,2, "����");	
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}
