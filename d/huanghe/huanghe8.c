// Room: /huanghe/huanghe8.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ��뺣��");
	set("long", @LONG
�ƺ�������ظ�ԭ��������ԭ������ƽԭ���ܳ�һ����Ű��
���������󺣡�
LONG );
	set("exits", ([
		"southwest" : __DIR__"huanghe7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", 800);
	set("coor/y", 1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}