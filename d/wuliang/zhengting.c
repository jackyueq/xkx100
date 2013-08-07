// Room: /wuliang/zhengting.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ŷ��ˡ������Ǹ���ʮ���ҵ�������ã�����������
�촽���ա������Ǹ���ʮ��������ߣ��������ų��룬�������ǵ��⡣
���˵���λ���һ�����࣬����վ�Ŷ�ʮ������Ů���ӡ�
LONG );
	set("exits", ([
		"southdown"  : __DIR__"road1",
		"east"       : __DIR__"road2",
		"west"       : __DIR__"road3",
		"north"      : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"npc/zuo"  : 1,
		__DIR__"npc/xin"  : 1,
		__DIR__"npc/gong" : 1,
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79890);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}