// Room: /yangzhou/qishi.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�����涫��麣��������ͨ�¹ۺ��ţ��м�����ξ����⡰���ҡ�
�ң����������ҿ����������(lian)�����ڳ��дɻ�����һ�̣�ʮ��Ƭ��
��ľ����ľ�š��ɻ��໨ɽˮ�����ţ����ι�Ǯ���񣬴ɻ澫����װ
�����ۣ��ı����������ʻ�������ɻ���������Ϊϡ��֮�
    ����һ��С����ľ�Ҿߺ�÷Ϊ��ӣľΪ�ţ����������Ի���ľ��
���Σ����������������С�������ʯ�����û������Ʊ��ӡ�
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
        ��        ��
        ɽ        ��
        ��        ��
        ��        ��
        ��        ��
        ��        ��
        ��        ��
\n",
	]));
	set("exits", ([
		"west"  : __DIR__"changchunling",
		"east"  : __DIR__"yueguan",
		"south" : __DIR__"qinshi1",
	]));
	set("objects", ([
		"/d/changan/obj/chess" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 110);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
