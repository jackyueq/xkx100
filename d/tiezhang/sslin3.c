// Room: /d/tiezhang/sslin3.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һƬ��ѹѹ�������֣����������֦��Ҷï�������������
����ա�������������Ҽ������������ڵ����������У��γ�������ɫ
�Ĺ�����ɷ�Ǻÿ������������ţ���Ȼ�����Լ�����ʧ����Ƭ�����У�
�Ҳ�����ȥ��·�ˡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"sslin4",
		"east"  : __FILE__,
		"south" : __DIR__"sslin2",
		"north" : __FILE__,
	]));
	set("objects",([
		__DIR__"npc/laohu" : 1,
	]));
	set("outdoors", "tiezhang");
	set("no_clean_up", 0);

	set("coor/x", -2040);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
