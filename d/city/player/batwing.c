// batwing.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�����", ({ "batwing"}));
	set("gender", "����");
	set("title", HIB"��ä"NOR"���¹��Ÿ���������ɽ�ɵ��Ĵ�����"NOR);
	set("nickname", HIR"������֪����Look Batwing��"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("����ɽ��" ,4, "����");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
