// Room: /d/lingzhou/chaifang.c

inherit ROOM;
#include "room.h"
void create()
{
	set("short", "��");
	set("long", @LONG
�����Ǽ䲻С�Ĳ񷿣�������������˸ߵ��Ϻ�ľ��ɢ����ľͷ
���е����㣬����Ĳ��һ����ÿ��һ�δӳ����������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"yushanfang",
		"east"  : __DIR__"biangate",
	]));
	create_door("east","ľ��","west",DOOR_CLOSED);
	set("coor/x", -17955);
	set("coor/y", 32110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
