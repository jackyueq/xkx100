// autodami.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("������", ({ "autodami"}));
	set("gender", "����");
	set("class", "beggar");
	set("title", "ؤ��ڶ�ʮ������");
	set("nickname", HIY"��������3¥�Ĵ�����Ц���ٵĸ���"NOR);
	set("age", 14);
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
