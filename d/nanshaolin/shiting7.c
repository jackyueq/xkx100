// Room: /d/nanshaolin/shiting7.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","ʯͤ");
	set("long", @LONG
��������ص��µİ���ɫ��ʯͤ�����ǳ����޹�͸�룬һ�ж��Ե�
����ģ����һյ����������͵ƣ����������Ű���ɫ�ĵ��棬һ����
�ޱ��飬��������ʯ�ˣ�ľȻ��վ�����
LONG );
	set("exits", ([
		"south" : __DIR__"shiting6",
	]));
	set("objects",([
		__DIR__"obj/mingchan" : 1,
	]));
	setup();
}
