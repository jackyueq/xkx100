//      tulu3.c ��·

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
����һ�������۵���·�����������Զ�������߲������ٵ�һ��Ƭ
����ˮ�⴦������������ʥ����
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8020);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
