// zhongxin.c ���Ĺ㳡
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���Ĺ㳡");
        set("long", @LONG
�����Ǻ���������Ĺ㳡���������Ǹ�С��ֻ���������--
�ֱ��Ƕ��֣����֣��Ͻֺͱ��֣����������ϡ��ߵ����·��
�����˶���Щ�������㶼�ͺ������ع���Ϊ��
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east" : __DIR__"dongjie",
                "west" : __DIR__"xijie",
                "north" : __DIR__"beijie",
                "south" : __DIR__"nanjie",
        ]));

        set("objects", ([
                __DIR__"npc/liumang" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}