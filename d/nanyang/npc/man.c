// Room: /d/nanyang/npc/man.c
// Last Modified by winder on Nov. 20 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��", ({ "da han","man" }) );
	set("title","");
	set("long","һλ���δ󺺡�\n");
	set("age", 20+random(20));
	set("gender", "����");
	seteuid(getuid());
	set_skill("unarmed",60);
	set_skill("blade",50);
	set("combat_exp", 1000);
	set("talk_msg",({
		"������������",
		"������������Ĺ���",
		"�¸���үΪ���������Ҷ��ж�����ѽ��",
		"�����Ǳ�����ԭ���϶ɺ�ˮ��",
	}));
	setup();
	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(CLOTH_DIR"cloth")->wear();
}
