// Room: /beijing/tiananmen.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "�찲�Ź㳡");
	set("long", @LONG
��������찲�Ź㳡����ɫ�ĳ�ǽ������ׯ������֮�У���������
�ǻʹ��ˡ��ʹ�����ǰ����С�ţ�һ�����Ǻ��ƳǶ�����Խ��С����
��ȥ���Ͻ��ǵ������淢�Ե���ΰ�ߴ�һ����ֱ�Ĵ����ᶫ������
���Ƕ������֣��������������֡��ϱ���һ�������Ĵ��������������
һ�����ţ���˵���˺ܶࡣ
LONG );
	set("exits", ([
		"south" : __DIR__"nandaj1",
		"north" : __DIR__"bridge",
		"west"  : __DIR__"xichang1",
		"east"  : __DIR__"dongcha1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "beijing");
	set("coor/x", -200);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
