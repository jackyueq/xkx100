// /d/shenlong/xianjing ����
// Last Modified by winder on Jul. 12 2002
// Mongol: All non shelong people die at once, that's not reasonable.
//	 Just disabled, and needs more polishments.

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ͻȻ�����ܵ�ǽ��ð���������ĸְ壬�������˹��������ˡ�����
LONG
	);
	set("exits", ([
	      "up" : __DIR__"tingkou",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me = this_player();

	if( interactive(me = this_player()) )
	{
		remove_call_out("dropping");
		call_out("dropping", 1);
	}

}

void dropping()
{
	object me = this_player();
	int f, d, p, s;
	float sn;
	sn = me->query("shen",1)*9/10;
//	s = int(sn);
	f = me->query_skill("force",1);
	d = me->query_skill("dodge",1);
	p = me->query_skill("parry",1);
	if( interactive(me = this_player()) )
	{
		message_vision( HIR "$N����ǰͻȻ����һ���޵׵���Ԩ...$N����������֮�С�\n" NOR, me);
		message_vision( HIR "�����еĸְ�ͻȻð���������ĸ��룬�����������$N��������...\n" NOR, me);
//		message_vision( HIR "һ���Һ���$N�������������С�\n" NOR, me);
//		if (f>=2) me->set_skill("force",f-2);
//		if (d>=2) me->set_skill("dodge",d-2);
//		if (p>=2) me->set_skill("parry",p-2);
//		me->set("shen",sn);
//		me->receive_wound("qi", me->query("max_qi")+10, "�����������ˡ�");
		me->unconcious();
	}
}

