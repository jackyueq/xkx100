// Room: /d/huijiang/damen.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ܶ����");
	set("long",@LONG
��վ�����Ⱥ������ǰ�����϶�������ڴ�С��ͭ�����ſڵ�̨��
�ϲ���վ������������Բ�Ĵ󺺣����￴ȥ���Կ���һ���������۵���
��ͨ�������
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"enter" : __DIR__"zoulang1" ,
		"south" : __DIR__"xiagu",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
		CLASS_D("honghua")+"/wen-tailai" : 1,
		CLASS_D("honghua")+"/luo-bing" : 1,
	]));	
	set("coor/x", -50060);
	set("coor/y", 9140);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if ( interactive( this_player()) &&
		((string)me->query("family/family_name") != "�컨��") &&
		(!present("honghua ling", me)))
		message_vision(HIG"��������$N����һ�ۣ����������صĺ���һ����\n"NOR,me);
	else
		if ( present("honghua ling",me) &&
			!(present("honghua ling",me))->query("zizhi")) 
			message_vision(HIG"�����󺺹����������˸���,˵���������ã�\n"NOR,me);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "enter") &&
		((string)me->query("family/family_name") != "�컨��") &&
		objectp(present("wen tailai", environment(me))) &&
		(!present("honghua ling", me)))
		return notify_fail("��̩����ס��˵���Ǳ�����֣����ܽ�ȥ��\n");
	return ::valid_leave(me, dir);
}
