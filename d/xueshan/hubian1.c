//      hubian1.c ����С·

inherit ROOM;

void create()
{
        set("short","����С·");
        set("long",@LONG
����ʥ���ߵ�С·��·��ĺ�ˮ��Ϊ�峺��������ӳ�Ű׶�ѩɽ��
��һƬ�����ĵ�������
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30010);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
