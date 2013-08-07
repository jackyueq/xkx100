// /d/yixing/npc/bangzhong2.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
#include <ansi.h>;
#include "/d/yixing/doc/bangskills.h"

int auto_check();

void create()
{
	string *bc_skills, *weapons;
	int i, level, exp = 100000 + random(200000);
	set_name("����", ({ "bang zhong", "zhong" }));
	set("gender", "����");
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "������");
	set("age", 20 + random(10));
	set("long", "һ����ĸߴ��׳��������ɱ����һ�������ɷ��ģ����\n");
	set("attitude", "heroism");
	set("shen_type", -1);

	set("str", 24);
	set("int", 10);
	set("con", 24);
	set("dex", 24);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: auto_check :),
	}) );

	set("combat_exp", exp); 
	level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

	set("max_qi",    level * 8 + 100);
	set("max_jing",  level * 5 + 100);
	set("max_neili", level * 6 + 200);
	set("neili",     level * 6 + 200);

	set_skill("dodge", level);
	set_skill("force", level);
	set_skill("parry", level);

	bc_skills = keys(unarmed_skills);
	set_skill(bc_skills[random(sizeof(bc_skills))], level);

	i = random(sizeof(info_weapon));
	set_skill(info_weapon[i]["type"], level);

	level /= 2;
	set_temp("apply/defense", level);
	set_temp("apply/armor",   level);
	set_temp("apply/damage",  level);
	set_temp("apply/attack",  level);

	setup();

	if( !random(2) )
	{
		weapons = info_weapon[i]["weapons"];
		carry_object(weapons[random(sizeof(weapons))])->wield();
	}
}

int auto_check()
{
	object me = this_object();

	if( !living(me) ) return 1;

	if( is_busy() || is_fighting() ) return 1;

	message("vision", name() + "����ææ���뿪�ˡ�\n", environment(me), ({me}));
	destruct(me);
	return 1;
}
