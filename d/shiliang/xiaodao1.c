// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "����С��");
	set("long", @LONG
���������ĵ�С���ϡ��������ﻨ�㣬�ʵ��׷ɣ���ɫ���ˣ���
���з·������������ζ����
LONG
	);
        set("outdoors","shiliang");
	set("no_clean_up", 0);
	set("exits", ([ 
            "south" : __DIR__"xiaodao",
            "northeast" : __DIR__"xiaoyuan"
	]));
	set("coor/x", 1610);
	set("coor/y", -1790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}