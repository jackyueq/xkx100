// Room: /d/5lt/wroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���������
��ʯ·�ϣ��ϱ��¿��˼����ӣ���˵���۵Ķ���ϡ��������������м�
�����ص���乤�յ꣬�����ϰڷŵĶ���һ��һ�Ĺ���Ʒ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"gongyidian",
            "south" : __DIR__"xiaopuzi",
            "west"  : __DIR__"wroad2",
            "east"  : __DIR__"center",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}