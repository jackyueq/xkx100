// nroad6.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
������һɽ·�ϣ�������һ����Сɽ��Զ�����Կ��������ѩ
��ɽ�⡣��Χ�������Ѿ����ѿ��õ��ˡ�
LONG );
        set("exits",([
                "north"   : __DIR__"nroad7",
                "southup" : __DIR__"nroad5",
        ]));
        set("objects",([
                __DIR__"npc/huatiegan" : 1,
        ]));
//	set("no_clean_up", 0);
        set("outdoors", "xueshan");
	set("coor/x", -30000);
	set("coor/y", -7990);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}