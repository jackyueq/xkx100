// Npc: /d/kunlun/npc/zhu1.c �����
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����", ({ "zhu jiuzhen", "zhu"}));
	set("long", "�����ü�������ò���ģ��ְ����塣\n");
	set("nickname", HIW"ѩ��˫�"NOR);
	set("gender", "Ů��");
	set("per", 30);
	set("age", 17);

	set_skill("finger", 40);
	set_skill("sun-finger", 40);
	set_skill("dodge", 40);
	set_skill("tiannan-step", 40);
	set_skill("parry", 40);
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "sun-finger");
	map_skill("finger", "sun-finger");
	prepare_skill("finger", "sun-finger");

	set("combat_exp", 100000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/whitecloth")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
}

