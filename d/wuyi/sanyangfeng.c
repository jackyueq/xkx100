// Room: /d/wuyi/sanyangfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
λ������Ϫ���������壬��Ƭ��ʯ�����򶫣�ֱ��������Զ������
����ص���죬ӭ����չ�����Ϲ������ѡ���Ҷ���񣬱�������������
�������������顰������ߴ���������֡�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"       : __DIR__"path9",
		"south"      : __DIR__"path8",
		"northeast"  : __DIR__"path10",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 1370);
	set("coor/y", -4950);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

