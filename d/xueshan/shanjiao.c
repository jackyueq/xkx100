//      shanjiao.c ɽ��

inherit ROOM;

void create()
{
        set("short","ɽ��");
        set("long",@LONG
������ɽ���µ�һƬƽ�أ�ɽ�ϲ�Զ����������ѩӳ���µ�һ��Ƭ
��ǽ���ߴ�������Զ��������ѩɽ�¡�
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "westup" : "/d/xuedao/nroad7",
                "south"  : __DIR__"hubian4",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -29990);
	set("coor/y", -7980);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
