// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "ɽ��");
	set("long", @LONG
��׳���ӣ��߽���ɽ���У����ﰵ�����գ�ͻȻ�䣬��
ֻ����������ǰ�ɹ����㱻������һ���亹��Խ�����߾�Խ��
Խ�ڣ��������ʧ�����ˡ�
LONG
	);
        set("exits", ([
                "east"  : __FILE__,
                "west"  : __DIR__"shandong5",
                "south" : __DIR__"shandong7",
                "north" : __FILE__,
        ]));
	set("coor/x", 1600);
	set("coor/y", -1960);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}