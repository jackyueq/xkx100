// caolianfang.c ������
// Modified by Marz 03/27/96

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ƕ�¥�������ϣ�����˷����Ǵ������䵱������ȥ�Ҵҡ�
LONG );
        set("exits", ([
                "south"     : __DIR__"caolian1",
                "north"     : __DIR__"caolian2",
                "eastdown"  : __DIR__"xilang"
        ]));
	set("no_clean_up", 0);
	set("coor/x", -2070);
	set("coor/y", -920);
	set("coor/z", 100);
	setup();
}
