// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "��ʯ���");
	set("long", @LONG
����ͨ������ʯ�������ʯ���������ɽ������֮ˮ�����������
�㱱��������һ��ζ�ˡ��������ʯ���¼��ˡ�
LONG
	);
        set("outdoors", "shiliang");
	set("exits", ([
                "southdown" : __DIR__"road2",
                "north"     : __DIR__"gate",
	]));
	set("objects", ([
                __DIR__"npc/nongfu" : 1,
	]));
	set("coor/x", 1610);
	set("coor/y", -1980);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}