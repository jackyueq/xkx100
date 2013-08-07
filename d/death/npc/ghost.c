// ghost.c ���

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW "���" NOR, ({BLK "ghost" NOR,"ghost" }) );
	set("long",
		BLU "һ��������Ĺ�꣬���ڻ�Ȫ����ϲ�ΡΡ�����ߡ�\n" NOR);
	set("chat_chance", 15);
	set("chat_msg", ({
		BLU "���̾��һ����......\n" NOR,
		HIY "������˵�����벻����������������.....!��\n" NOR,
                GRN "����������.........\n" NOR,
	}) );
        set("age",30+random(40));
	set("combat_exp", random(10)*100000+random(10000));
    
	set_temp("apply/armor", random(60));
	set_temp("apply/damage", random(100));
        
	setup();
}

void init()
{
	command("tell " +this_player()->query("id")+" ����Ķ���ѽ?......\n\n");
}
int is_ghost()
{  
	return 1;
}
int accept_fight(object me)
{    
	command("sigh " +(string)me->query("id"));
	command("say �����ⲽ����ˣ��㻹���ѽ��");
	return 0;
}
