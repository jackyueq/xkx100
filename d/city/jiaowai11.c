// Room: /d/city/jiaowai11.c
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
		"east"   : __DIR__"jiaowai10",
		"north"  : __DIR__"jiaowai13",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 2,
		__DIR__"obj/shitou": 1,
	]));
	set("coor/x", 10);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}