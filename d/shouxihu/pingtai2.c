// Room: /yangzhou/pingtai2.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ƽ̨");
	set("long", @LONG
��ǰƽ̨Χ��ʯ����̨��ֲ��һ�Ժ��ɣ�����Ծ����ɼ���һ��ʯ
�����Ͽ̡�С�����������׭����������ɽ��ʯ���Ȥ����������Ϊ��
�㡱���������������ɴﴵ̨��
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north" : __DIR__"lunlian",
		"west"  : __DIR__"chuitai",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}