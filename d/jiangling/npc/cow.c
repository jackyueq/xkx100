// cow.c ���ţ

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIY"���"NOR, ({ "cow" }));
        set("long","һͷ���ţ���������������ᣬͦͨ���Եġ�\n");
	set("race", "����");
        set("age", 5);
        set("int", 30);
        set("qi", 300);
        set("max_qi", 300);
        set("ridable", "1");
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
}

