// Room: /qingcheng/caochang.c
// Date: Aug. 10 1998 by Winder

inherit ROOM;
void create()
{
	set("short", "�����ٳ�");
	set("long", @LONG
��������ǵ�������ϰ��֮�������������š�������������������
�����ڿ�һЩ��������������ǰף��������������Ӱ�ӡ������ճ�
ɽ�꣬���������������ˡ�
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"east"  : __DIR__"zoulang2",
		"west"  : __DIR__"zoulang3",
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"songfengguan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
		__DIR__"npc/fang" : 1,
		__DIR__"npc/dizi" : random(4),
	]));
	set("coor/x", -8080);
	set("coor/y", -840);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}