// /d/xingxiu/silk4.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "˿��֮·");
	set("long", @LONG
�������������˿���̵�����ɳ������һƬ�����������������
����ɽ��������������º�����һ�������ֻ���м��˺ϱ�֮�ֵĹ���
�����Ȼͦ���ڻ�ԭ�ϣ�Цӭ��ɳ��ƵƵ�к����ˡ�������һƬ��ɳ��
����ɳĮ�Ϳ��Ե�������ɽ����
LONG );
	set("outdoors", "silu");

	set("exits", ([
		"southeast" : __DIR__"shimen",
		"northwest" : __DIR__"shazhou",
		"west"      : "/d/mingjiao/westroad1",
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -22500);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

