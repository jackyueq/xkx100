// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����ĳ�");
	set("long", @LONG
�����ǻ���ĳ��Ĵ�Ժ���̻����µ����ݣ���ô�����������Ժ��
������ͨ�����������ͨ����������������������ߺ���������������
ҡͷһЦ����Ҫ��������������������沫������Ҳ�Ǳ�̶����������
�ᣬ����������ǲ����ݡ�
LONG );
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
//		"/clone/misc/fifa2002" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"shaiziting",
		"west"  : __DIR__"shilijie2",
		"east"  : __DIR__"zoulang1",
		"south" : __DIR__"bobingting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("coor/x", 20);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("age")<18)
                return notify_fail("Сë���������Ϲ�պ�ʲô��\n");
        return ::valid_leave(me, dir);
}
