//      tulu2.c ��·

inherit ROOM;

void create()
{
        set("short","��·");
        set("long",@LONG
����һ�������۵���·��ȴ������ѩɽ������ԭ�ıؾ�֮·������
���Ĵ�����ϡ�ɼ�����������ͨ�����������ѩɽ�¡�
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8030);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
