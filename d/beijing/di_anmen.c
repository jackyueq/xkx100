// Room: /beijing/di_anmen.c

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ذ���");
	set("long", @LONG
������ǵذ��Ź㳡����ɫ�ĳ�ǽ������ׯ������֮�У������Ͼ�
�ǻʹ����š���ǰ����С�ţ�һ�����Ǻ��ƳǶ�����Խ��С��������ȥ��
�Ͻ��ǵ������淢�Ե���ΰ�ߴ�һ����ֱ�Ĵ����ᶫ���������ǵ�
���Ŷ��֣������ǵذ������֡�����ͨ�������š�
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"di_an3",
		"east"  : __DIR__"di_an2",
		"south" : __DIR__"hbridge",
		"north" : __DIR__"anding",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
