// Room: /d/jiaxing/chating.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ�����м�
�����Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG );
        set("exits", ([
		"northeast" : "/d/shiliang/road2",
		"northwest" : "/d/shiliang/shandao1",
                "west"      : __DIR__"jnroad4",
        ]));
        set("objects", ([
                CLASS_D("heimuya")+"/xiang" : 1,
        ]));
        set("outdoors", "shiliang");
	set("coor/x", 1600);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}