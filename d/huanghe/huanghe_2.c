// Room: /huanghe/huanghe_2.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ�");
	set("long", @LONG
�ƺӳ����ຣ��������֮�����ܵ�������ԭ���赲��ת����
����ȥ��������������ԭ�Ĺ�������ɳ����������ˮɫ�λƣ��ͱ���Ϊ
�ƺӡ�
LONG );
	set("exits", ([
		"west"      : __DIR__"huanghe_3",
		"northeast" : __DIR__"huangtu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -4000);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}