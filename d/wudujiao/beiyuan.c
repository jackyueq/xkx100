// Room: /d/wudujiao/beiyuan.c

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǳ�Ժ��Ժ���ﾲ���ĵġ�������һ��������ԶԶƮ��һ
�ɷ��㣬���Ǹÿ����ˡ�
LONG
        );
        set("outdoors", "wudujiao");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"bingqi",
                "south" : __DIR__"lianwu",
                "north" : __DIR__"chufang",
        ]));

	set("coor/x", -44920);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}