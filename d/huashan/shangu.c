// Room: /d/huashan/shangu.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����������ɽ��һ������ɽ�ȡ������Ǹ߿ɼ����ɽ�壬�������ܣ�
һ��СϪ���������������������С�Ϫ����һ�����轣�����������ŵ�
Ϊ�
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"south"     : __DIR__"pingdi",
		"northdown" : __DIR__"jzroad7",
	]));
	set("objects", ([
		CLASS_D("huashan")+"/cong-buqi": 1,
	]));
	set("outdoors", "zhongtiao");
	set("coor/x", -930);
	set("coor/y", 180);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
