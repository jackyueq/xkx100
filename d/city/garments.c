// Room: /city/garments.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�������������¹󸾳���֮��������Ҳ��������Ҳң�֬�ۺ�ɡ�
��Ϊ��������ʱ�У�һֱ�����������Ե�װ�硣�����Ǹ��ܿ��˵�СŮ
����������һ������ʱ���������������Ů�˼���һ�𣬻�������������
    ���ſں�������д�ż�������(zi)����������С���ֱʡ�
LONG );
	set("item_desc", ([
		"zi": "list ����\"buy\" ��\n",
	]));
	set("exits", ([
		"northeast" : __DIR__"caohecexiang",
	]));
	set("objects", ([
		__DIR__"npc/zeng": 1,
	]));
	set("coor/x", -31);
	set("coor/y", -21);
	set("coor/z", 0);
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
