// Room: /d/xingxiu/yanzhishan.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", RED"��֬ɽ"NOR);
	set("long", @LONG
��֬ɽ��ɽʯ��������֬������������ˮ�ݷ�����������������ѩ
�ڻ��������������£��㼯������ɽ���̲��������Ӫ�ݳ�̲���Ǿø�
ʢ����������
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southdown" : __DIR__"shimen",
		"southeast" : __DIR__"silk3",
		"northwest" : __DIR__"rentou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -22000);
	set("coor/y", 800);
	set("coor/z", 100);
	setup();
	set("yushi_count", 1);
}
#include "/d/xingxiu/job2.h";

