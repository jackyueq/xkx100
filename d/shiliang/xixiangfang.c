// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "���᷿");
	set("long", @LONG
���ǹ�������Ϣ���᷿�����Ӳ��󣬵��Ǻ����࣬ǽ�Ϲ�
��һЩ�ֻ����и�Ѿ����æ��Ϊ�����ݲ衣
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"yuanzi",
	]));
	set("objects", ([
            "/d/changan/obj/chairs" : 1,
            __DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", 1600);
	set("coor/y", -1960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
