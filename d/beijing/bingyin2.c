#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�����
�еĶ������������е����š�����������Ϣ������Щ̫�����Ĵ��߶���
LONG );
	set("exits", ([
		"north" : __DIR__"xichangdamen",
	]));

	set("objects", ([
		"/d/huanggong/npc/taijian" : 1,
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
