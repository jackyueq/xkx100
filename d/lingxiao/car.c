// Room: /d/lingxiao/car.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
int do_take(string arg);
void create()
{
	set("short","����");
	set("long",@LONG
�����������ǵı�����bing che����ɽ֮�����˱�����������Ϊ��
��ֱ�����ݣ������ƶ��ɣ��ܴ���ѩɽ֮�۷��ٻ��£��Ǵ�ѩɽȥ����
�ݵĽ�ͨ���ߡ�����Գ�����take�����������ݡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"iceroad3",
	])); 
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("item_desc", ([
		"bing che" : "һ̨�Ϻú�ɼľ���Ƶı�����������������ɽ֮�á�\n"
	]) );
	set("coor/x", -31010);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup();
}
void init()
{
	add_action("do_take", "take");
}
int do_take(string arg)
{
	object me=this_player();

	if( !arg || arg != "bing che" )
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if (me->query("family/family_name") != "������")
		return notify_fail("�������ӵ������ֲ��������ǵģ��߿���\n");

	message_vision(HIW"$N���ȵ������ϱ��������������Ӵ�����ơ�\n�ǵ��ӵ��˵�ͷ��������һ�⣬������������֮�������·��������\n"NOR, me);
	message_vision(HIW"����ѩɽ��$N����Ź�����׾�֮�ţ�����֮�С�$N�����죬�̲�ס������Х��\n"NOR, me);
	me->move("/d/city/shilijie4");
	return 1;
}

