// ximen.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ���������ţ���ǰ��ǽ���ʣ�ǽ�ϵļ����������
��������ȥ��������������ǽ�����������׹⣬�ƺ��Ǳ��������
�Ĺ⡣���������š����š��������֣��ſ�վ��һЩ�ٱ������ֳ�
���������������������ǡ��������۶��򱱣���������ɽ���ˡ�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "east"      : __DIR__"xijie",
                "northeast" : __DIR__"shanlu",
        ]));

        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
	set("coor/x", -3170);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
