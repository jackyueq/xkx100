// Room: /d/nanshaolin/zhaitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"ի��"NOR);
	set("long", @LONG
����ǰ��һ��˶���ޱȵķ��ݣ������������ȫ����ɮ��ի��ի�á�
����ʮ���䷿���������ɣ���������ȫ�µ�ɮ��һͬ��ի����ǰ��Ժ��
��������������ÿ�����¶���һ���޴�����ף�����ʢ������ˮ������
ɮ��������æµ�ţ���Ժ�ڴ�ɨ��ʮ�ָɾ���
LONG );

	set("exits", ([
		"west" : __DIR__"celang-4",
		"east" : __DIR__"fanting1",
		"north" :__DIR__"xjchu",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangshi" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "west") &&
		(present("mizhi tianou", me) ||
		present("mala doufu", me) ||
		present("furong huagu", me)) &&
		objectp(present("fang shi", environment(me))) )
	switch ( random(2) ) 
	{
		case 0: 
			return notify_fail("���ź��а���һ�죬˵����ʳ�ﲻ�ô���ի�ã��������еĹ涨��\n");
			break;
		case 1:
			message_vision("���ź��ж�$N�������˸�Ҿ�������ַ��ɷԸ�����ʳ�ﲻ�ô���ի�á�", me);
			return notify_fail("\n");
			break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
