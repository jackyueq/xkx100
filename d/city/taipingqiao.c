// Room: /yangzhou/taipingqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","̫ƽ��");
	set("long",@LONG
̫ƽ�ż�Ϊ���£��ŶԳƶ�������������һСԲ�������߸�һ�繰��
���ڲ�ͬһ������ɡ�̫ƽ������Χʯ���壬�����������м���ʯ�
̫ƽ�š���̫ƽ�ź����ڹٺ�֮�ϣ�Զ��֮�����˵�������ü�����µ�
��ʱ������֮�¸�һ��Ӱ��������֮��Ŀ������ת��Ϊ����һ�澰����
��ʱ���㲻������ν��������������ҹ�����ζ��������ݡ��д����ѡ�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"caohenanjie",
		"east"  : __DIR__"nanmendajie",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}