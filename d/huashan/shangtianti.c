// shangtianti.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�˴����գ������������������̽��ǰ���������Ǹߣ�����������
�ݡ�����������ɽ��·���������ǽ����ء�������ȥ����ͨ�ﱱ����̨
�塣
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"westup"    : __DIR__"canglong",
		"southup"   : __DIR__"jinsuo",
		"northdown" : __DIR__"husun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
