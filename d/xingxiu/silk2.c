// /d/xingxiu/silk2.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "˿��֮·");
	set("long", @LONG
�������������˿��ŵ���һ��������ԭ������֮����̵�������
���������ɽ��������������º�����һ�������ӭ���������һ����
ɳ���������岼춻�ԭ֮�ϡ�һ���ɳ�������󵶸�һ��˺�����������
���Ϲ����ɽͨ�������أ����洩����Ħ�£���ͨ������
LONG );
	set("outdoors", "silu");
	set("exits", ([
	    "south"     : __DIR__"chouchishan",
	    "westup"    : __DIR__"songmoya",
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -20000);
	set("coor/y", 600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

