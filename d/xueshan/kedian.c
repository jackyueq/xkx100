//      kedian.c �͵�

inherit ROOM;

void create()
{
        set("short","�͵�");
        set("long",@LONG
������һ��·�ߵ�С�͵ꡣ���������˶�������������Ϣ��������
·���Ե�����ԭ��
LONG );
        set("exits",([
                "east" : __DIR__"tulu2",
        ]));
        set("objects", ([
            __DIR__"npc/xiaoer2" :1
        ]));
	set("coor/x", -30030);
	set("coor/y", -8030);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
