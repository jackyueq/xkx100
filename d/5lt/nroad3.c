// Room: /d/5lt/nroad3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ�������Ĵ��ӣ�һ���������ٵľ���������һ���ϱ����
��ʯ·�ϣ���������ë��ݣ���˵�����Ի��������������ơ������Ƿ�
ӳ�������˿�Ͼ������ϲ������һ��߿���Ӱ��߶�ҳ���
LONG);
        set("exits", ([ /* sizeof() == 3 */
            "south" : __DIR__"nroad2",
            "west"  : __DIR__"qiuguan",
            "east"  : __DIR__"fychang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}