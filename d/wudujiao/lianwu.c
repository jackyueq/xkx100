// Room: /d/wudujiao/lianwu.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������Ժ�ڵ����䳡�����������ϰڷ���һЩ������ʯ����ɳ����
һ��СͷĿ����ָ���������䡣
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east"  : __DIR__"dating",
                "west"  : __DIR__"damen",
                "south" : __DIR__"nanyuan",
                "north" : __DIR__"beiyuan",
        ]));
        set("objects", ([
                  CLASS_D("wudujiao")+"/jiaotou": 1,
        ]));

	set("coor/x", -44920);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}