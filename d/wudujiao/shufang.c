// Room: /d/wudujiao/shufang.c

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�����ǽ���ƽʱ����ĵط������䲻��ֻ��������һ���鰸������
���˼����飬�����ǽ������������ġ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"dating",
        ]));
        set("objects", ([
                 "/clone/book/five_force": 1,
                 "/clone/book/parry_shu": 1,
        ]));

	set("coor/x", -44910);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}