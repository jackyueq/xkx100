// he.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit NPC;
void create()
{
	set_name(HIW"������"NOR, ({ "danding he", "he", "danding" }) );
	set("race", "����");
	set("age", 170);
	set("long", "һֻ�����ĵ����ף�ͨ��ѩ�ף�ͷ�ϵĳඥȴ�Ǻ��������
ȴ������ű�һ������˩ס����������һͷ����һ���ʯ�ϡ�\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("dex", 80);
	set("con", 50);
	set("combat_exp", 150000);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 150);
	set_temp("apply/dodge", 250);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 10);
	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵ������˼������˶��˼��¾Ͳ����ˡ�\n", this_object());
	ob = new("/d/baituo/obj/hdh");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
