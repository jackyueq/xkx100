//yzjiang.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("����", ({ "yzjiang"}));
	set("gender", "����");
	set("class", "fighter");
	set("title", "����ɽ�ɵڶ�������");
	set("nickname", HIY"��ʱ����û "NOR HIR" ����ˮ�̺�"NOR);
	set("age", 28);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	create_family("����ɽ��" ,2, "����");	
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
