// nanjie.c �Ͻ�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
�����Ǻ��е��Ͻ֣�˵�ǽ֣�������һ��С��ͬ���ѡ�·��һ��
��Ҳû�С��ֵľ�ͷ��һ��С�š����������������Ǻ�����������ˡ�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "north" : __DIR__"zhongxin",
                "southeast" : __DIR__"fu-cemen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3150);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}