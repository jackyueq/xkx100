// mishi.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵���Ϊ��ֱ����ԭ�޽������ң�����Ĺ��߷ǳ�
�谵��Ҳ���Ѿ��������ˡ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"diziju",
                "eastup" : "/d/city/shilijie4",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2730);
	set("coor/y", 100);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}