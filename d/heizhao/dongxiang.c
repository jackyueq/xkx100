// Room: /heizhao/dongxiang.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "���᷿");
	set("long", @LONG
������һ�ƴ�ʦ�ĵ�������Ϣ�ĵط������������°�����һ��
����ϣ���������ڵ��������̸ǣ���̨��һ����Ⱦ������Ⱥɽ��
�㣬�����������������ڴ�һ�ޣ�����������űߵ�ϴ���þ�
Ҳ��ʰ�úܸɾ�����ש��������Ҳ�������ɨ�����޵㳾��
LONG );
	set("no_clean_up", 0);
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
	set("exits", ([
		"west"       : __DIR__"chanyuan",
	]));
	set("coor/x", -5010);
	set("coor/y", -1200);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}