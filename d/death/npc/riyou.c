// riyou.c

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("������", ({ "ri you" }) );
	set("long",HIY @LONG
               ����֮��
LONG NOR);
        set("gender","����");
        set("str",1000);
        set("title",HIY "����֮��" NOR);            
	set("attitude", "peaceful");
	set("age", 1000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
        set("max_neili",10000);
        set("neili",10000);
	setup();
}
