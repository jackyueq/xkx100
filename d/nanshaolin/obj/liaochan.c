// Obj: /d/nanshaolin/obj/liaochan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("����ʯ��", ({ "liaochan shiren", "liaochan", "shiren" }));
	set("long", "�����Զ���޷�����������֮��ò��\n"
		"������ƽ��֮�����������������̱���˼���Ѱ��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 145);
	set_skill("dragon-claw",145);
	set_skill("yijinjing",140);
	set_skill("dodge", 145);
	set_skill("yiwei-dujiang", 145);
	set_skill("claw", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("claw", "dragon-claw");
	map_skill("parry", "dragon-claw");
	prepare_skill("claw", "dragon-claw");
	setup();
}
#include "chan.h"
