// d/qingcheng/bingqishi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���ű��������ӡ�����ǹ������ꪵȸ��ֱ������������
���Եı������ϡ��������������ҳ�����Ȼ�Ѿ��þ�û��������
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang2",
	]));
	set("objects", ([
		__DIR__"obj/chui" : random(3),
		__DIR__"obj/zhui" : random(2),
	]) );
	set("coor/x", -8070);
	set("coor/y", -830);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}