//wrong.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("����", ({ "wrong"}));
	set("gender", "Ů��");
	set("class", "swordman");
	set("title", GRN"״Ԫ"HIG"���̵����Ž���"NOR"��ɽ�ɵ�ʮ��������");	
	set("age", 34);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 17);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	create_family("��ɽ��" ,13, "����");	
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}
