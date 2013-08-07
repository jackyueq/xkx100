// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"�����ܼ�"NOR, ({ "mi jian"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ܼ����������������ؾ��ı�������\n");
		set("value", 0);
		set("material", "paper");
	}
}
void init()
{    
	add_action("do_xiaohui", "xiaohui");
}
int do_xiaohui(string arg)
{
	int i,exp,pot,count,base_exp,time;
	object ob,me,*team;
	me=this_player();
	ob=this_object();
	if(!arg||arg!="mi jian") return notify_fail("��Ҫ����ʲô��\n");
	if(ob->query_temp("host")!= me->query("id") ||
		!me->query_condition("guojx_mis") ||
		!me->query_temp("guojx_mis_tcount"))
		return notify_fail("����º������û��ϵ�ɣ�\n");
	if (!present("mi jian",me) )
		return notify_fail("������û���ܼ���\n"); 
	message_vision("$N�ӻ����ͳ�һֻ���۵�ȼ���ܼ���\n"+HIR"ֻ�����䡹��һ�����ܼ��ڻ���������Ϊ�ҽ���\n"NOR, me);
	count=me->query_temp("guojx_mis_tcount");
	if (count<2) count=2;	
	base_exp=300;
	time = me->query_temp("guojx_mis_time",time);
	team=me->query_team();
	count=sizeof(team);
	for(i=0;i<count;i++)
	{
		if(team[i]!=0)
		{
			if (team[i]->query_condition("guojx_mis"))
			{
				exp=base_exp*time + random(300);
				pot=exp/3+random(100);
        log_file("mission/guo_team",sprintf("%-20s ����ؼ�ϸ������ %-5s ���� %-5s Ǳ��",team[i]->query("name")+"("+team[i]->query("id")+")",exp,pot));
				team[i]->add("potential",pot);
				team[i]->add("combat_exp",exp);
	team[i]->set_temp("prize_reason","�ѻ�");
	team[i]->set_temp("can_give_prize",1);
	team[i]->set_temp("prize_exp",exp);
	team[i]->set_temp("prize_pot",pot);
				tell_object(team[i],HIW"�㱻�����ˣ�" + 
				chinese_number(exp) + "��ʵս���飬" +
				chinese_number(pot) + "��Ǳ�ܡ�\n"+ NOR);
				team[i]->delete_temp("guojx_mis_tcount");
				team[i]->delete_temp("guojx_mis_where");
				team[i]->delete_temp("guojx_mis_flag");
				team[i]->delete_temp("guojx_mis_time");
				team[i]->delete_temp("guojx_mis_max");
				team[i]->clear_condition("guojx_mis");
			}
		} 
	}
	destruct(this_object());
	return 1;
}

