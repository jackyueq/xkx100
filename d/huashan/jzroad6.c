// Room: /d/huashan/jzroad6.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����⣬��Ȼվ��һ�����ӣ�����ɭɭ�����ӱ��ϣ�ƾ��һ��ɷ����
�����ǵ�ɽ��·�����߾ͽ���ɭ���ˡ�
LONG );
	set("outdoors", "zhongtiao");
	set("exits", ([ /* sizeof() == 4 */
	    "enter"   : __DIR__"jzroad5",
	    "westup"  : __DIR__"jzroad7",
	]));
	set("objects", ([
	     CLASS_D("huashan") + "/cheng-buyou": 1,
	]));

	set("coor/x", -920);
	set("coor/y", 190);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
