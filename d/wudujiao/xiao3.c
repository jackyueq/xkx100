// Room: /d/wudujiao/xiao3.c

inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�������һ����ߵ�һ������С·��һ�Ծ����峺�Ľ�ˮ���а�
���಻�ϵ��һ�������ϼ������Ϯ�ˣ���������۷��ڻ�������衣
ǰ����һ��ľ��(pai)����·����,���ڷ紵��ɹ���ּ��Ѿ�ģ���ˡ�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"taohua",
                "northwest" : __DIR__"xiao2",
        ]));
        set("item_desc",([
              "pai": " ǰ���һ���......,.....����.....Σ�ա�����֮��....���롣\n�峤  ������ \n",
        ]));

	set("coor/x", -44990);
	set("coor/y", -81040);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}