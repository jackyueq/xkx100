// yunbao.c �Ʊ�

#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("�Ʊ�", ({ "yun bao", "bao" }) );
	set("race", "����");
        set("gender", "����");
        set("age", 5);
        set("long", @LONG
����һֻ��Ҷ��Ƥ���Ʊ�������ëƤ��Ϊ��������ʵ��
LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("combat_exp", 30000);
        set("neili",800);
        set("jiali",100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

        setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N�������춯�ص�һ����𣬺�ص��ڵ��ϣ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/baotai");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
