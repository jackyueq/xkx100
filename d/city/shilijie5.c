// Room: /yangzhou/shiliji5.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ﳤ��");
	set("long",@LONG
ʮ�ﳤ��ԭ�������ݵ����ģ�����֮�����ֱ߲�����¥����������
��ֿ��꣬���ַǷ���ÿ��ҹ������ʱ����Ҹ߹ҵ�������ҹ��������
�𲻾�����������浽����ÿ�س���Ϧ�������ɴ���������Ի����п�
�С������ڽֱߵĵ��̶�����³ǣ�ʮ�ﳤ�ֵķ��ٽ�������ѷɫ��࣬
����Ϊ�������ݵ�Ҫ������������ӵ��������������������һ��Ǯׯ��
�����������������Ľ������������������ػ���Ԣ��
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"qianzhuang",
		"east"  : __DIR__"kedian",
		"south" : __DIR__"shilijie6",
		"north" : __DIR__"shilijie4",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}