// huangshalin.c
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
	set("short", "��ɳ��");
	set("long", @LONG
�˴�λ�����ɽ������ֻ��Զ������ԭ�ϣ�������һ���ɻ�ɳ�ѻ�
���ɵ�ɽ�룬����Ϊ���ء��ݵ�����˵���������̳���һλ����½����
���ˣ��÷���ǲ��һ�ɻ�ɳ���ɡ�������һƬ���֡�
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"east" : __DIR__"mumen",
	]));
	set("coor/x", -3230);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
