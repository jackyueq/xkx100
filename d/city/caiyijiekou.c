// Room: /yangzhou/caiyijiekou.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","���½ֿ�");
	set("long",@LONG
һ��С�ػ��ӣ����е�һ�ֲ�ͬ�����ա��ӵĶ������³ǣ���Ϊ
�̼֡���ֻ���ֿڵ����ǵ��̣��ٽֶ��裬�������Ÿ߸ߵ����ġ�С��
�ؽֽ������������֡������������ͨ�������¡��������ǲ��½֣�
���ݵĳ����ñ�����ڴˡ����汱�����ǻ����̻�֮�ء�
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"kaimingqiao",
		"east"  : __DIR__"caiyixijie",
		"north" : __DIR__"tianningxiang",
		"south" : __DIR__"beiliuxiang",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}