// mingzhu.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIY "明珠" NOR, ({"ming zhu", "ming"}));
	set("title", "兵部尚书");
	set("gender", "男性");
	set("age", 36);
	set("str", 25);
	set("dex", 20);
	set("int", 28);
	set("con", 28);
	set("per", 20);
	set("long", "这可是熙朝第一大滑头、第一大马屁精。\n");

	set("combat_exp", 1000);
	set("score", 200);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("literate", 100);
	set_skill("force", 10);
	set_skill("hunyuan-yiqi", 10);
	set_skill("shaolin-shenfa", 10);
	set_skill("finger", 10);
	set_skill("nianhua-zhi", 10);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");
	prepare_skill("finger", "nianhua-zhi");

	set_temp("apply/attack", 50);
	set_temp("apply/defence", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 35);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 80);

	setup();
	carry_object(__DIR__"obj/chaofu")->wear();
	add_money("gold", 5);
}

