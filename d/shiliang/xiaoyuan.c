// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "СԺ��");
	set("long", @LONG
�����Ǹ�СԺ�ӣ���ɨ����Ϊ���࣬�Ա��пô�����Ժ����
����һЩɨ�ѵ���������Ǹ�����Ŀ�����
LONG
	);
	set("outdoors","shiliang");
	set("no_clean_up", 0);
	set("exits", ([ 
            "southwest" : __DIR__"xiaodao1",
            "north" : __DIR__"xiaoting",
	]));
	set("coor/x", 1620);
	set("coor/y", -1780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}