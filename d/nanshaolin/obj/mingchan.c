// Obj: /d/nanshaolin/obj/mingchan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("����ʯ��", ({ "mingchan shiren", "mingchan", "shiren" }));
	set("long", "�����Զ���޷�����������֮��ò��\n"
		"����İ�С�������ƺ�һ�����ܽ�������\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 150);
	set_skill("yijinjing",150);
	set_skill("wuxiang-finger", 150);
	set_skill("dodge", 145);
	set_skill("yiwei-dujiang", 145);
	set_skill("finger", 145);
	set_skill("parry", 145);
	set_skill("buddhism", 145);
	map_skill("force", "yijinjing");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("finger", "wuxiang-finger");
	map_skill("parry", "wuxiang-finger");
	prepare_skill("finger", "wuxiang-finger");
	setup();
}
#include "chan.h"
