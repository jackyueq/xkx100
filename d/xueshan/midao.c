//      midao.c �ܵ�

inherit ROOM;

void create()
{
        set("short","�ܵ�");
        set("long",@LONG
����һ����խ�İ�������ɭ���£����������˻ҳ���������������
Ҳ��֪��ͨ���δ���
LONG );
        set("exits",([
                "north" : __DIR__"mishi",
                "east" : __DIR__"neidian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70010);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
