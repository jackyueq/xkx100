inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "Ͳ����");
        set("long", @LONG
����һ���ƾɵ�ʯ�ţ������ǻ��Ǻӻ�������ˮ��ˮ����ȥ���壬
�����ǽ��ʹ����ŵıؾ�֮·��
LONG);
        set("outdoors", "beijing");
        set("exits", ([
                "north" : __DIR__"di_anmen",
                "south" : "/d/huanggong/jingshan",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -250);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
