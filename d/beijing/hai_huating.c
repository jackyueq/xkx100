// /beijing/hai_huating.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","���ι�������");
	set("long", @LONG
��������ǺȾ����µļ�����һ��Сͤ�ӽ������������룬����Χ
����һЩ�����١�һ��΢�紵�����������ƺ��������Ļ���Ʈ��������
����
LONG );
	set("exits", ([
		"west" : __DIR__"hai_dayuan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
