// xiaolu1.c �ּ�С��
// by Xiang

inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�����
��Ҷ��������������������Ķ�����
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu2",
                "north" : __DIR__"houyuan",
        ]));
        set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
        ]));
        set("outdoors", "wudang");
	set("coor/x", -2050);
	set("coor/y", -940);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
