// houhuayuan1.c ��԰
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����һƬ�ķ��˵Ļ�԰������������һƬС����������һЩ
����֮�࣬���ڳ������Ҳ�ɺ��ˡ�����������һ����ɽ��ɽ
�ϳ�������̦�������Ѿ��ܾ�û���������ˡ�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "west" : __DIR__"houhuayuan",
        ]));
        set("objects", ([
                __DIR__"npc/wugui" : 1,
        ] ));

	set("coor/x", -3110);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}