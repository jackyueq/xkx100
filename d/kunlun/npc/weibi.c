// Npc: /d/kunlun/npc/weibi.c ���
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���", ({ "wei bi", "wei"}));
	set("long","����òӢ��������������������ȴ����ȴֻ\n����һ�������ĵ���ɫ���ۣ������ڹ�������\n");
	set("gender", "����");
	set("per", 30);
	set("age", 18);

	set_skill("finger", 40);
	set_skill("sun-finger", 40);
	set_skill("dodge", 40);
	set_skill("tiannan-step", 40);
	set_skill("parry", 40);
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "sun-finger");
	map_skill("finger", "sun-finger");
	prepare_skill("finger", "sun-finger");

	set("combat_exp", 150000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
}

