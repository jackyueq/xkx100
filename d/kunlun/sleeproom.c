// Room: /d/kunlun/sleeproom.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@long
�����Ǻ�̫����谮�ĵ���С���õ��Է�����һ�������˱Ǳ���
һ��ҩ�������滹���ŵ�һ��ʮ�ֹŹֵ���Ϣ������Ƭ�̣�����������
Ϣ��Ũ�������������ء���������һ���ˣ����������������������
���ǳ��ŷ��䡣����(window)���ǽ������š�
long);
	set("item_desc", ([
		"window" : "������ƣ��㲻����򿪴���͸͸����\n",
	]));
	set("objects",([
		__DIR__"npc/wugu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"tieqinju",
	]));
	create_door("west", "С��", "east", DOOR_CLOSED);
	set("coor/x", -119970);
	set("coor/y", 40140);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}