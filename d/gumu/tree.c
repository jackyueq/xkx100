// Room: /d/gumu/tree.c
// Last Modifyed by Winder on Jan. 14 2002
 
#include <ansi.h> 
inherit ROOM;

void create()
{
	set("short", HIG"����"NOR);
	set("long", @LONG 
���������ϣ���ͻȻ������Ҷ����Щ�������ۡ�����������������
ë���Ȼ��һ����ڴ�ϸ�ľ��������������ϣ��ſ���ڣ���Ҫ������
����
LONG	);
	set("outdoors", "gumu");
	set("objects",([
		__DIR__"npc/dumang" : 1,
	]));
	set("exits", ([ 
		"down" : __DIR__"xuanya",
	]));
	set("coor/x", -3220);
	set("coor/y", 40);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

