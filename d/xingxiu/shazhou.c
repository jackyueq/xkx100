// Room: /d/xingxiu/shazhou.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "ɳ��");
	set("long", @LONG
�����Ƕػͳ����ڵأ���˿��֮·�ϵ��ʺ����������ǽ���ʣ�
���и߳���ǽһ���ĳǶա����ڻ������Χ�Ķ�����壬���ڴ���Ͽ�
�����������޲�͸�����档
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southeast" : __DIR__"silk4",
		"west"      : __DIR__"tugu",
		"northup"   : __DIR__"rentou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -23000);
	set("coor/y", 900);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";
