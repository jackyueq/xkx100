// Room: /yangzhou/beiliuxiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
һ��խխ��С���ʱ��С�ν���������С�������¥���Ǹ߸�
�����ŶԺ�����������಼Ļ������������Ů��б����¥�ţ��Թ�����
����������Ц�š������������Ÿ�ľ�Ʒ����������š����������
��������ݵ���¥���ݾۼ�֮�ء�
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"south"  : __DIR__"matou",
		"north"  : __DIR__"caiyijiekou",
		"west"   : __DIR__"lichunyuan",
		"east"   : __DIR__"meixiangyuan",
	]));
	set("objects", ([
		__DIR__"npc/popi1" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}