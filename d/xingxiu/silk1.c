// /d/xingxiu/silk1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "˿��֮·");
	set("long", @LONG
����һ����ԭ������֮����̵���ӭ���������һ����ɳ��������
�岼춻�ԭ֮�ϡ�һ���ɳ�������󵶸�һ��˺�����������������һ
����ΰ�Ĺذ���������ͨ������
LONG );
	set("outdoors", "silu");
	set("exits", ([
		"east"      : __DIR__"jiayuguan",
		"northwest" : __DIR__"chouchishan",
		"southwest" : __DIR__"xianrenya",
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -19000);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

