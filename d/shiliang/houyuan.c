// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "��Ժ");
	set("long", @LONG
�����Ǹ����ĺ�Ժ���������죬֪�������ϲ�ͣ�ؽ��ţ��и�
������������ɨ�ŵ��档
LONG
	);
        set("outdoors","shiliang");
	set("exits", ([ 
            "southwest" : __DIR__"zoulang1",
            "west"      : __DIR__"zoulang2",
            "northwest" : __DIR__"zoulang3",
            "north"     : __DIR__"zoulang4",
            "southeast" : __DIR__"zoulang5",
            "east"      : __DIR__"zoulang6",
            "northeast" : __DIR__"zoulang7",
	]));
        set("objects", ([
                 __DIR__"npc/atu" : 1,
	]));
	set("coor/x", 1610);
	set("coor/y", -1930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}