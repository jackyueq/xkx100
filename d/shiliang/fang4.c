// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "�෿");
	set("long", @LONG
��������¼������·��ϵ�ס�������Ǹ�����ӹ���ŵ��ˣ���
���ű�ʫ��ҡͷ���Եض��š�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"zoulang6",
        ]));
        set("objects", ([
		__DIR__"npc/wenfangnan" : 1,
		__DIR__"npc/yahuan" : 1,
        ]));
	set("coor/x", 1630);
	set("coor/y", -1930);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}