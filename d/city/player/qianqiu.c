// qianqiu.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("һ�����", ({ "qianqiu"}));
	set("gender", "����");
	set("class", "bonze");
	set("title", "��ԯ�������������ɵ���ʮ�˴�����");
	set("nickname", "���⴩��������������");
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("������" , 38, "����");
	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}
