// Room: /d/huashan/pingdi.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��ƽ��");
	set("long", @LONG
����������ɽɽ��ƽ���ϡ�����ɽ������һС�ݡ����ŵ��껪ɽ��
Ů�彣�����ڴ�Ծ����мưܱ��Ľ��ڵ��Ӵ����������ɽ���ѵ�����
�����������ᴵ���졣��ʧ��ĸо���
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"xiaowu",
		"north" : __DIR__"shangu",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);

	set("coor/x", -930);
	set("coor/y", 170);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
