// bobing3.c �ϲ�����
// Last Modified by winder on Sep. 22 2002

#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit __DIR__"bobing.c";

void create()
{
	set("roomname","�ϼ䲫����");
	set("no_fight","1");
	set("no_magic","1");
	set("no_steal","1");
	set("no_beg","1");
	set("short","�ϲ�����");
	set("long", @LONG
����һ����ӵ��ŵĵĲ����ݡ������װ�޳�����ʢ��ʱ��ķ�ζ��
�����ӵ�������ʯ������͵Ĺ��ߣ���������ܰ�����գ����Ǹ���ů��
���ֵĵط�����������ܵ���һ�������ӣ��м�һ���ľ������Ҷ�ϯ
�ض��� (sit)������������һ�����룬�����������ת���������Ƶ�
���ӣ��ϱߵ�ǽ������һ�ŷ��Ƶĳ�ֽ(paper)��
LONG);
	set("item_desc", ([
		"paper" : "���ܺ������� help bobing��\n",
	]));
	set("objects",([
		__DIR__"npc/dog":1,
	]));
	set("exits", ([
		"north" : __DIR__"bobingting",
	]));
	set("no_clean_up",1);
	set("coor/x", 19);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
}