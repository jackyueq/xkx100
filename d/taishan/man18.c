// Room: /d/taishan/man18.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ʮ����");
	set("long", @LONG
̩ɽ������ʮ����֮˵���Կ�ɽ������Ϊ����ʮ�ˡ����������ɷ�
Ϊ������������ʮ�ˡ�������������Ϊ����ʮ�ˡ�������һǧ������ʮ
��ס���������������ʮ�����ϣ���ͷ�Ϳ���ʯ�ס������Ա�������ɽ
�����򣬶�ʱ��̾���硣
LONG );
	set("exits", ([
		"northup"   : __DIR__"longmen",
		"southdown" : __DIR__"kaishan",
	]));
	set("objects", ([
		__DIR__"npc/tiao-fu" : 2,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 720);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
