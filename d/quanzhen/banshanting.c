// banshanting.c ��ɽͤ
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��ɽͤ");
        set("long", @LONG
�����ǰ�ɽ����һ��С��ͤ���ο�����ɽ�������ˣ���ת���䵽
��������һ����ЪһЪ�š������￴��ȥ���պÿ��Կ���������ķ�
����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"shijie5",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 140);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}