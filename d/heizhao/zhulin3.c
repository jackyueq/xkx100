// Room: /heizhao/zhulin3.c
// Date: Oct.28 1999 by Winder
inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
��βɭɭ������ϸϸ���͸������ݺύ���ڱ����ա�������
��������΢��������֣�����ɳɳ֮������ֻ������ɭɭ���ľ���
�ȣ����˷��׾���������һ����ʯ���̳ɵ���С����ǰ���졣
LONG );
        set("outdoors", "taoyuan");
        set("exits", ([
            "west" : __DIR__"zhulin4",
            "east" : __DIR__"zhulin2",
            "north": __DIR__"zhulin3",
            "south": __DIR__"zhulin1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -5020);
	set("coor/y", -1100);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}