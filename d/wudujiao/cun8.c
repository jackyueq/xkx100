// Room: /d/wudujiao/cun8.c

inherit ROOM;

void create()
{
        set("short", "�嶫��");
        set("long", @LONG
������С��Ķ�ͷ����Ϊ����չ�������һƬ��Ţ��·�ǳ������ߡ�˳
������·һֱ����һ����ʱ���Ϳɵ���ʯƺ�ˣ��������⸽���������ӡ�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "northwest" : __DIR__"cun7",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}