// Room: /d/5lt/nroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���ϱ����
��ʯ·�ϣ������Ǵ�֧�������Ϲ�һ�Ҷ����ͷ�塹�������Ǵ��ﻨ
��������Ĺ㲥վ��վ�������������ѽѽ�����㲻��Ϥ�����֡�
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"nroad3",
            "south" : __DIR__"shiqiao",
            "west"  : __DIR__"chuandashi",
            "east"  : __DIR__"guangbozhan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}