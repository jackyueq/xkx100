// Room: /yangzhou/ninghaiqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
��������һ���½�������ʯ�ţ�������С�ػ����ϣ�������������
�����ǵ�Ҫ��������޵ļ�Ϊ����ƽ�����ɹ�������ͬʱ���С�����
��ŷ�����ױ���д�������ŵ����ࡣ�ŵĶ��ϱ���һ����ͷ����ബֻ
ͣ���š����������ݾɳǵĸ�Ȫ�֡�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"ganquanjie",
		"east"  : __DIR__"matou",
	]));
	set("objects", ([
		SHOP_DIR"hesanqi" : 1,
		"/d/village/npc/kid" : random(5),
	]));
	set("coor/x", 30);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
