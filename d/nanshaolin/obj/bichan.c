// Obj: /d/nanshaolin/obj/bichan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("����ʯ��", ({ "bichan shiren", "bichan", "shiren" }));
	set("long", "�����Զ���޷�����������֮��ò��\n"
		"����ĸߴ�ͨ����͸������һ�귱ï�Ż���\n");
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
	set_skill("force", 140);
	set_skill("yijinjing",140);
	set_skill("boruo-strike", 140);
	set_skill("dodge", 140);
	set_skill("yiwei-dujiang", 140);
	set_skill("strike", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("strike", "boruo-strike");
	map_skill("parry", "boruo-strike");
	prepare_skill("strike", "boruo-strike");
	setup();
}
#include "chan.h"
