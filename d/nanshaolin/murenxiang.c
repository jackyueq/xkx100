// Room: /d/nanshaolin/murenxiang.c ľ����
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

int do_quit();
int do_save();
void muren_attack(object me);

void create()
{
	set("short", "ľ����");
	set("long", @LONG
�������������µ�ľ������ҵ�С���ӵ�һ����ɽ������ͨ��ʮ
��ľ�˵Ŀ��顣����ֻ����ǰ��·�����޻�ͷ��·�ˡ�
LONG);
	set("exits", ([ 
		"north" : __FILE__,
	]) );
	set("no_sleep_room", 1);
	set("no_get_from", 1); 
	set("no_fight", 1); 
	set("coor/x", 1790);
	set("coor/y", -6080);
	set("coor/z", 10);
	setup();
}

void init()
{
	object me = this_player();
	if (userp(me))
	{
		if(interactive(me) && me->query("muren_winner") && !wizardp(me))
		{
			message_vision( HIR"һ��Ⱥɮ��һӿ���ϣ��Ұ����£���$N��û�����ȥ......\n"NOR, me);
			me->unconcious();
			me->set("eff_qi", 1);
			me->set("qi", 1);
			me->apply_condition("nbonze_jail", 120);
			me->move("/d/nanshaolin/jianyu");
		}
		set("busy", 1);
		add_action("do_save", "save");
		add_action("do_quit", "quit");
		me->add_temp("murenxiang", 1);
		muren_attack(me);
	}
}

void muren_attack(object me)
{
	remove_call_out("muren_attack");
	if (me && present(me, this_object()))
	{
		call_out("muren_attack", 3, me);
		new(__DIR__"npc/muren-fighter" + me->query_temp("murenxiang"))->move(this_object());
	}
	else delete("busy");
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && me->query_temp("murenxiang") >= 9)
	{
		me->delete_temp("murenxiang");
		me->delete_temp("ask_muren");
		me->add("combat_exp",10000);
		me->add("potential",3000);
		me->add("score",8000);
		me->move(__DIR__"ting");
		me->set("muren_winner", 1);
		me->delete_temp("ask_muren");
		message("channel:snow", HIR"�����š�����ǧ����࣬"+me->query("name")+"���ڴ�������������ľ���\n"NOR,users());		
		return notify_fail(HIY"�����ڴ�����ľ��� �����˴δ���������书�����\n"NOR);
	}
	return ::valid_leave(me, dir);
}
 
