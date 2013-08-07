// Room: /d/kunlun/conglinggu.c �����
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@long
�����ǰͻȻΪ֮һ����ֻ��һ����һ��������Ͽ����ʯ�䣬��
ɽ��ѩˮк�䵽ǧ�����µ�ɽ����ȥ����������ܵķ�ĭ����һ�־���
���ǵ��𺶡���������ɽҰ�ȵ�Ϫ���ߣ�ȴ�����˸��ָ����Ļ�����ľ��
���췱������Ͽ�������ʵѹ��ɽ�����˼�����������������(bird)��
��԰��
long );
	set("item_desc",([
		"bird" : "������������,�㲻�������˵��ϵ�ʯ��,������Ͷ(tou)ȥ��\n",
	]));
	set("exits",([
		"out" : __DIR__"shanlin"+(random(5)+1),
	]));
	set("objects", ([
		VEGETABLE_DIR"huangqi" : 1,
		VEGETABLE_DIR"dongchongcao" : 2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
}

int init()
{
	add_action("do_tou","tou");
}

int do_tou(string arg)
{
	object me = this_player();
	if ( !living(this_player()) || arg != "bird" )
		return notify_fail("����ʯͷͶ��˭��\n");
	if ((int)me->query_skill("throwing", 1) > 100)
		return notify_fail("��İ����������൱���ˣ�������С���ƺ�����Ȥ��\n");
	if ( (int)me->query("qi")<30)
	{
		me->receive_damage("qi", 10);
		write("��ĸ첲�Ѿ�����,��������Ϣһ��ɣ�\n");
		return 1;
	}
	me->receive_damage("qi", random(25));
	message_vision("$N������ʯͷ����\n", me);
	write("��ר����־������ȺͶ��ʯͷ���о����������ֽ���һ����\n");
	me->improve_skill("throwing", me->query_int());
	return 1;
} 
