// Room: /d/xingxiu/shuiliandong.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
����Ⱥ����ʣ������������֣����·ת��ʯ����¶���й��ζ��ߣ�����
ˮ����̦�����̰ವ����ʯ���ס��꼾ɽ������ֱ����ˮ�������д�����
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southeast" : __DIR__"xianrenya",
		"northeast" : __DIR__"chouchishan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -21000);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

