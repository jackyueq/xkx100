// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "ɽ����");
	set("long", @LONG
������һ����ɽ������ǰ������ں����ģ������˵ģ���
�ǲ�Ҫ��ȥ�ĺá�
LONG
	);
        set("outdoors", "shiliang");
	set("exits", ([
                "southdown" : __DIR__"shandao2",
                "north"     : __DIR__"shandong1",
	]));
	set("coor/x", 1590);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}