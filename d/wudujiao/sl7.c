// Room: /d/wudujiao/sl7.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һƬ�����֣�����Ŀ�������ͷ�����ܶ��ǲ���Ĺ��ɣ���
��඼Ī������Ŀ����ˣ�ֻʣ��һЩ�Ұ׵����ɴ������������͸
����������֦��϶���䵽���У�ů����ġ�������һ��ž����㲻��һ
����š�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sl8",
                "northwest" : __DIR__"sl4",
                "west" : __DIR__"sl6",
                "northeast" : __DIR__"sl5",
                "north" : __DIR__"caodi",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81090);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}