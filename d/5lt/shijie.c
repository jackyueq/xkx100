// Room: /d/5lt/shijie.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������ʯ���̳ɵ�ʯ���ϡ���Щ�������¸���ͣ��ʯ�������ɵ�
��̦޺��·����Щʪ�������������У����������ʯ�����Ƶ�һ·��
����ȥ��������һ�������������������У�ֱ�����ơ�
LONG);
        set("exits", ([ /* sizeof() == 1 */
            "northdown" : __DIR__"wroad3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -180);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}