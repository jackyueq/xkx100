// shanlu.c ɽ·
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�Ӻ������ų�����·�Ʊ伱�ˣ�����һ����ʯ���̳ɵ�ɽ·��·
���Թ�ͺͺ�ģ�û��ʲô��ľ��ȫ��һ���Ĵ�ʯͷ������·����ͨ
��ǰ�������ɽ�ϡ�������һ��С��ׯ������������ȽȽ�Ĵ��̡�
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "eastup"    : "/d/quanzhen/shanlu1",
                "northup"   : __DIR__"xiaocun",
                "southwest" : __DIR__"ximen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
