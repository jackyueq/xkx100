// Room: /d/city/jiaowai13.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ��������
���������ĵط��������߳��ε����
LONG );
	set("exits", ([
		"south" : __DIR__"jiaowai11",
		"east"  : __DIR__"jiaowai12",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/mo-bu" : 1,
		__DIR__"obj/shuzhi": 1,
	]));
	set("coor/x", 10);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}