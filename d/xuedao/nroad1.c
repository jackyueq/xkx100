// nroad1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
ɽ·Խ��Խխ������������ǰ���ֳַ��˼�����·��
LONG );
        set("exits",([
                "westup"     : __DIR__"nroad2",
                "southup"    : __DIR__"sroad3",
                "northdown"  : __DIR__"nroad5",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -9000);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}