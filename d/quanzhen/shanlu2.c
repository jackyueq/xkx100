// shanlu2.c ɽ·
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ǰ�������һ����ɽ�ȣ��ߵ������ľ����Щ��ȫ���ǰ�����
������һ��������ɽ·��������ɽ�䣬Ҫ��ҹ�ﻹ�濴��������
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southwest" : __DIR__"shanlu1",
                "northup"   : __DIR__"cuipinggu",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/badou" : random(2),
        ]));

	set("coor/x", -3140);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
